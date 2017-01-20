// Veure qu� passa quan un processador vol enviar a diferents llocs: com arriben ACKs, com es permet l'enviament dels paquets a diferents llocs
// mitjan�ant nextMsg. �s realment necessari aquest nextMsg? Crec que podr�em eliminar-lo... tot i que possiblement no molesti.

// TODO: Clarify getIsComplete//setIsComplete? I don't think it is important
// TODO: does the tracking of bits/sec go here? I think so, we will add overhead in the transceiver.
// TODO: Should we update the tracking of bits/sec?
// TODO: decide if broadcast messages have to acked by all the participants
// Watch out with possible deadlock in selfMsgArrived


#include "wNIF.h"

#include "packetstat.h"

Define_Module( wNIF);

wNIF::wNIF() {
	// TODO Auto-generated constructor stub

}

wNIF::~wNIF() {
	// TODO Auto-generated destructor stub
}

int wNIF::procDataCount = 0;
//int NIF::pathsEstablished = 0;

int wNIF::numOfNIFs = 0;
int wNIF::nifsDone = 0;





void wNIF::initialize() { // OK


	numOfNIFs++;
	numProcsDone = 0;
	procIsDone = false;

	concentration = par("processorConcentration");

	procReqIn = gate("procReq$i");
	procReqOut = gate("procReq$o");
	fromProc = gate("fromProc");
	toProc = gate("toProc");

	nextMsg = new cMessage();

	sentRequest = false;

	completeMsg = new cMessage();

	// init(){
	int buff = par("routerBufferSize");
	stalled = false;
	flitWidth = par("electronicChannelWidth");
	clockPeriod_packet = 1.0 / double(par("O_frequency_cntrl"));
	clockPeriod_enc = clockPeriod_packet * 0.0; //added by Brian Lebiednik 22 SEP 16 to simulate delay for encryption
	clockPeriod_chk = clockPeriod_packet * 0.0; //added by Brian Lebiednik 22 SEP 16 to simulate passing token over wireless

	//sendPacketMsg = new cMessage("send Packet Message");


	// init_packet(){
	currData = NULL;

	lastIn = 0;

	maxPacketSize = par("WmaxPacketSize");

	wBitsSent = 0;
	SO_bwT = Statistics::registerStat("Total Bandwidth NIF Out (Gb/s)", StatObject::TIME_AVG, "NIF");
	SO_bw = Statistics::registerStat("Bandwidth wNIF Out (Gb/s)", StatObject::TIME_AVG, "wNIF");

	SO_lat_ser = Statistics::registerStat("Serialization latency", StatObject::AVG, "wNIF");
	SO_lat_prop = Statistics::registerStat("Propagation latency", StatObject::AVG, "wNIF");
	SO_qTime = Statistics::registerStat("Time in wNIF Q", StatObject::AVG, "wNIF");

	id = par("id");
}

void wNIF::finish() { // OK

	if (nextMsg->isScheduled()) {
		cancelEvent(nextMsg);
	}
	delete nextMsg;

	if (completeMsg->isScheduled()) {
			cancelEvent(completeMsg);
		}
	delete completeMsg;

	list<ProcessorData*>::iterator iter;

//	 StatObject* SO_latency = Statistics::registerStat("Latency (us)", StatObject::MMA, "application");

	 for (iter = waiting.begin(); iter != waiting.end(); iter++)
	 {
		 ProcessorData* pdata = (*iter);

		 ApplicationData* adata = (ApplicationData*) pdata->decapsulate();
//		 SO_latency->track(SIMTIME_DBL(simTime() - adata->getCreationTime()) / 1e-6); //put into us
		 delete adata;
		 delete pdata;
	 }

	 //SO_bw2->track(wBitsSent / simTime() );
}

// In handle message, one function is performed per each type of arriving messages (data, ACK, etc...)
// Existing functions correspond to packet credit protocols. When implementing our first approximation of wireless, we will do plain resending.
void wNIF::handleMessage(cMessage* msg) { // OK


	cGate* arrivalGate = msg->getArrivalGate();

	// Here, the messages are sorted depending on the arrival port

	// NIF schedules nextMsg if we are allowed to send a message to the network (ack received)
	// and completeMsg to finish the message sending with complete
	if (msg->isSelfMessage()) {
		if (msg == nextMsg) {
			controller();
		} else if(msg == completeMsg){
			complete();
			controller();
		}
		else {
			selfMsgArrived(msg);
		}

	// From processor request port
	} else if (arrivalGate == procReqIn) { //schedule new message
		RouterCntrlMsg* rmsg = check_and_cast<RouterCntrlMsg*> (msg);

		requestMsgArrived(rmsg);

		delete msg;

	// From processor data port
	} else if (arrivalGate == fromProc) {

		ProcessorData* pdata = check_and_cast<ProcessorData*> (msg);
		procMsgArrived(pdata);

	// From WirelessTransceiver (formerly it came from the network router)
	} else {
		// One clock cycle delay to simulate the time required to check the address and discard the packet or pass it
		// to the processor. This eventually goes to selfMsgArrived, then to netPortMsgArrived
	    //scheduleAt(simTime(), msg);
	    scheduleAt(simTime()+clockPeriod_packet, msg);
	}
}


void wNIF::selfMsgArrived(cMessage *msg) { // OK~ WATCH OUT
// This is originally from NIF_Packet_Credit, just change it with our wireless alternative

	netPortMsgArrived(msg);
	delete msg;
	// Watch out with possible deadlock here
	//this->wNIF::selfMsgArrived(msg);

}



void wNIF::requestMsgArrived(RouterCntrlMsg* rmsg) { // OK
	// A request arrived from the processor:

	// If it's an access grant, send processor data.
	if (rmsg->getType() == proc_grant) {
		if (toProcQ.size() == 0) {
			opp_error("got a proc_grant, but nothing in the toProcQ");
		}
		// EVCON ev.printf("Proc_Grant arrived to the NIF... sending data to processor\n");
		// Send what's on top of the queue "to be sent to the processor".
		//sendDelayed(toProcQ.front(), clockPeriod_packet, toProc);
		sendDelayed(toProcQ.front(), 0, toProc);

		// ACK to the remote NIF that data has arrived and it has been relayed to the processor (below)
		sendAck();

		// Take out whatever is on the top of the queue (it has been sent)
		toProcQ.pop();

		// Access is not granted anymore. New access must be requested before sending again.
		sentRequest= false;
		// By calling to sendDataToProcessor, a new request will be sent for anything that might still be on the toProcQ queue.
		sendDataToProcessor(NULL);

	// If it's a sending request, immediately grant (?)
	} else if (rmsg->getType() == proc_req_send) {
		RouterCntrlMsg* gr = new RouterCntrlMsg();
		gr->setType(proc_grant);
		// EVCON ev.printf("Proc_Send arrived to the NIF, granting...\n");
		sendDelayed(gr, 0, procReqOut);
	}

}
void wNIF::sendAck() { // OK ~1 TODO
// This is originally from NIF_Packet_Credit (processorMsgSent), just change it with our wireless alternative

	/*
	if (unacked.size() == 0) {
		ev.printf("just in case.\n");
		opp_error("trying to ack, but nothing to ack");
	}

	ElectronicMessage* emsg = unacked.front();

	// TODO: decide if broadcast messages have to be acked by all the participants
	// If the received message is not a broadcast message, ack it. If it is, do nothing.

	if(!emsg->getBcast()){
		ev.printf("ACK back to remote processor.\n");
		BufferAckMsg* ack = new BufferAckMsg;
		ack->setVirtualChannel(emsg->getVirtualChannel());
		ack->setData(emsg->getBitLength()); // number of received bits will be the message of the ACK
		ack->setDstId(emsg->getSrcId());
		ack->setSrcId(emsg->getDstId());
		ack->setMsgType(router_bufferAck); // Type is ACK
		ack->setBitLength(int(1 + double(emsg->getBitLength() / flitWidth))); // Length is calculated
		debug(getFullPath(), "ack sent", UNIT_BUFFER);

		// ACK will be sent through the wireless transceiver
		sendDelayed(ack,0,"portOut");
	}

	delete emsg;*/
	delete unacked.front();
	unacked.pop();

}

void wNIF::procMsgArrived(ProcessorData* pdata) { //OK

	debug(getFullPath(), "proc Msg arrived ", UNIT_NIC);
	//NetworkAddress* node = (NetworkAddress*) pdata->getSrcAddr();
	//int n = node->id[AddressTranslator::convertLevel("NET")];

	if(id == 0 || id==20 ){ //4 times the traffic for nodes in quadrant 0
		for(int i=0; i<9; i++){
			ProcessorData* junk;

			junk = pdata->dup(); //generates duplicates of the data
			junk->setCreationTime(simTime());
			waiting.push_back(junk); //adds to the unhealthy node so it will keep sending
		}
	}
	/*else if((id >= 16) && (id<32) ){ //3 times the traffic for nodes in quadrant 1
		for(int i=0; i<5; i++){
			ProcessorData* junk;

			junk = pdata->dup(); //generates duplicates of the data
			junk->setCreationTime(simTime());
			waiting.push_back(junk); //adds to the unhealthy node so it will keep sending
		}
	}
	else if((id >= 32) && (id<48) ){ // times the traffic for nodes in quadrant 2
		for(int i=0; i<3; i++){
			ProcessorData* junk;

			junk = pdata->dup(); //generates duplicates of the data
			junk->setCreationTime(simTime());
			waiting.push_back(junk); //adds to the unhealthy node so it will keep sending
		}
	}
	*/
	//Regular traffic for the rest of the nodes

	// Put data into the queue "to be transmitted into the network"
	waiting.push_back(pdata);

	if(waiting.size() > 1e5)
	{
		std::cout<<"ending simulation since a NIF queue reached 100000"<<endl;
		this->endSimulation();
	}
	pdata->setNifArriveTime(simTime());

	// Send data to the network
	controller();
}

void wNIF::netPortMsgArrived(cMessage* msg) { // OK
// This is originally from NIF_Packet_Credit, just change it with our wireless alternative

/* All the messages arriving from the network are checked for number of retries.
 Any number from 0 to max means a correct remote transmission and will cause a packet to be:
 - taken into account for the throughput count (including ACKs)
 - put into the unacked queue.
 - sent to the processor (either directly or by putting it into the toProc queue)
 - When these messages are eventually relayed to the processor [through a grant in requestMsgArrived], the NIF sends the appropriate ACK through sendAck.
 A number of retries '100' means that this packet was discarded from the local MAC queue and needs to
 be rerouted through the electrical plane. This is not accounted for the throughput count or acked or relayed to the processor.
*/

    //if(simTime().dbl() - lastIn < clockPeriod_packet) opp_error("simtime %.12f, lastIn %.12f. Two messages coming from MAC within the same cycle.\n",simTime().dbl(),lastIn);
    //lastIn = simTime().dbl();
    //debug(getFullPath(), "packet arrived", UNIT_NIC);
	ElectronicMessage* emsg = check_and_cast<ElectronicMessage*> (msg);
	int type = (ElectronicMessageTypes) (emsg->getMsgType());

	if(emsg->getNumRetries() == 100) {
	    //fprintf(stderr,"%.12f: Raising flag to switch planes.\n",simTime().dbl());
	    ProcessorData* pdata = check_and_cast<ProcessorData*> (emsg->decapsulate());
	    pdata->setSwitchPlanes(1);
	    sendDelayed(pdata, 0, toProc);

	} else {
	    // wBitsSent += bitsSent;
	    SO_bw->track(emsg->getBitLength() / 1e9);
	    SO_bwT->track(emsg->getBitLength() / 1e9);

	    // We will act depending on the type of message: ACK or DATA

	    bool isBcast = emsg->getBcast();

	    if (type == router_bufferAck) {
	        ackMsgArrived(check_and_cast<BufferAckMsg*> (emsg));

	    } else if(type == pathSetup) {
	        ProcessorData* pdata = new ProcessorData();
	        pdata->setType(hybridUnblockW);
	        sendDelayed(pdata, 0, toProc);

	    } else if(type == pathTeardown) {
	        ProcessorData* pdata = new ProcessorData();
	        pdata->setType(hybridBlockW);
	        sendDelayed(pdata, 0, toProc);

	    } else if(type == wireless_ACK || type == wireless_NACK) {
	        ProcessorData* pdata = new ProcessorData();
	        pdata->setType(type);
	        pdata->setBitLength(16);
	        pdata->setSize(16);
	        pdata->setSrcAddr(emsg->getSrcId());
	        pdata->setDestAddr(emsg->getDstId());
	        pdata->setIsComplete(true);
	        //pdata->setId(globalMsgId++);
	        pdata->setCreationTime(simTime());
	        pdata->setId(emsg->getData());
	        sendDelayed(pdata, 0, toProc);

	    } else {

	        if (type == dataPacket) {
	            ProcessorData* pdata = check_and_cast<ProcessorData*> (emsg->decapsulate());
	            NetworkAddress* dest = (NetworkAddress*) pdata->getDestAddr();

	            // Track "propagation time"?
	            if(pdata->getIsComplete()){
	                SO_lat_prop->track(SIMTIME_DBL(simTime() - pdata->getSavedTime1()));
	            }


	            // Relay the arriving data to the processor (putting it into the queue)
	            // If it broadcast, or if it is not a broadcast message and if we are an intended destination
	            if (isBcast || (!isBcast && (dest->id[AddressTranslator::convertLevel("NET")] == id))) {
	                debug(getFullPath(), "pushing processor data to Q", UNIT_NIC);
	                sendDataToProcessor(pdata);
	                // Add the current packet to the stack of non-acked, sendAck() will decide if the message has to be acked or not (bcast?)
	                unacked.push(emsg->dup());
	            } else {
	                delete pdata;
	            }

	        } else {
	            opp_error("Unknown electronic message type at NIF_electronic");
	        }

	    }

	}
}

void wNIF::ackMsgArrived(BufferAckMsg* bmsg) { // I think this implements how the system gives credits to the NIF so it can transmit something.
	// ACK coming from the network arrived
	// TODO: what to do here?
	// Maybe tell processor "proc_msg_sent" here instead of in complete()
    // EVCON ev.printf("ACK arrived to the NIF...\n");

	if (stalled) {
		//let the source (processor) know we're free
		ArbiterRequestMsg* req = new ArbiterRequestMsg();
		req->setType(router_arb_unblock);
		sendDelayed(req, 0, procReqOut);
		stalled = false;
	}

	// Not needed as we are not using a packetized/credit scheme
	//if (!sendPacketMsg->isScheduled()) {
		//scheduleAt(simTime(), sendPacketMsg);
	//}

	// Arriving ACK means that remote NIF correctly received the message
	// Therefore, our NIF is allowed to send the next message??
	// I think we don't need this...
	if (!nextMsg->isScheduled()) {
		scheduleAt(simTime(), nextMsg);
	}


}


void wNIF::controller() { // OK

	if(!completeMsg->isScheduled()){
		if (request()) {
			if (prepare()) {
				simtime_t delay = send();
				scheduleAt(simTime() + delay, completeMsg);

			}
		}
	}


}

// called when a communication request arrives from the non-network side of the NIF. Returns true if communication should continue.
bool wNIF::request() { // OK

	// If there is not anything being prepared, and there is something in the queue to be transmitted:
	if (currData == NULL && waiting.size() > 0) {

		// Take it from the queue:
		currData = waiting.front();
		waiting.pop_front();
		leftToSend = currData->getSize();

		// Track the waiting time.
		SO_qTime->track(SIMTIME_DBL(simTime() - currData->getNifArriveTime()));
		startSerTime = simTime();

	}

	// We can send if data is valid, or if there is not another transmission in course
	// (nextMsg OR completeMsg being scheduled means that NIF is occupied sending something and should not be disturbed)
	// currData != NULL means something is waiting to be sent (see just above)
	if (!nextMsg->isScheduled() && !completeMsg->isScheduled() && currData != NULL) {
		return true;

	} else {
			//let the source (processor) know we're backed up
			ArbiterRequestMsg* req = new ArbiterRequestMsg();
			req->setType(router_arb_deny);
			sendDelayed(req, 0, procReqOut);
			stalled = true;
	}
	return false;
}
// called after request() returns true. Usually creates a new message to be sent on the network.
// Returns true if communication should continue, which is almost always the case
bool wNIF::prepare() { // OK

	currMsg = new ElectronicMessage();


	bitsSent = min(leftToSend + DATA_HEADER_SIZE, maxPacketSize);
	currMsg->setId(globalMsgId++);
	int tt = currData->getType();
	if(tt == wireless_ACK || tt == wireless_NACK) {
		currMsg->setMsgType(tt);
		currMsg->setData(currData->getId());
	}
	else
		currMsg->setMsgType(dataPacket);

	ProcessorData* sending;
	sending = currData->dup();

	// See if this is the last "packet" of the message
	bool comp = (bitsSent >= leftToSend + DATA_HEADER_SIZE) && currData->getIsComplete();
	sending->setIsComplete(comp);
	//currData->setIsComplete(true);

	sending->setSavedTime1(simTime());

	// Track serialization latency (time to put message into packets)
	if(comp){
		SO_lat_ser->track(SIMTIME_DBL(simTime() - startSerTime));
	}

	sending->setSize(bitsSent - DATA_HEADER_SIZE);

	// currMsg encapsulates the contents of ProcessorData* currData (by means of the copy named "sending).
	// and adds the source and destination network addresses.
	currMsg->setSrcId(sending->getSrcAddr());
	currMsg->setDstId(sending->getDestAddr());
	currMsg->encapsulate(sending);
	currMsg->setBitLength(bitsSent);
	// Important to know if the message is broadcast: the transceiver will simulate a "received by all" instead of a "sent by all"
	if(sending->getType() == snoopReq){
		currMsg->setBcast(true);
	}

	return true;

}
// called after prepare() returns true. Responsible for sending the prepared message. Again, usually always returns true
simtime_t wNIF::send() { // OK ~1 TODO

	// Send currMsg, which was prepared in "prepare()" ==> currMsg disappears at this time
	//sendDelayed(currMsg, clockPeriod_enc, "portOut");
	//previously sendDelayed(currMsg, 0, "portOut"); before encryption delay
	//SO_num_messages_test->track(1);
  sendDelayed(currMsg, clockPeriod_enc + clockPeriod_chk, "portOut");
	//message delay for sending one message over the wireless to pass the token
	// Tracking the number of bits sent through the NIF WAS DONE HERE
	// But has to be done at reception
	// "/1e9" so that the result will be in Gb.
	// [Tracking with TIME_AVG gives the result divided by simTime()]


	// Refresh left to send
	leftToSend -= (bitsSent - DATA_HEADER_SIZE);
	// EVCON ev.printf("NIF: Sending... LeftToSend is now %d\n",leftToSend);

	// Return the number of clock periods needed to perform the send (bits / flitWidth) *clockPeriod
	// after all, from NIF to the transceiver we have a wired connection
	//simtime_t ret = 0;
	simtime_t ret = bitsSent * clockPeriod_packet / flitWidth;
	return ret;

}
// called after send(). Performs anything that is required after the transmission has completed.
// Returns the amount of time that the NIF should wait before attempting to start a new transmission
void wNIF::complete() { // OK

	// If everything has been sent...
	if (leftToSend <= 0) {

		// Tell processor: "proc_msg_sent"
		RouterCntrlMsg* ackp = new RouterCntrlMsg();
		ackp->setType(proc_msg_sent);

		// The ACK must be sent to the appropriate processor.
		// If there is processor concentration, the address must be properly set to the intended receiving processor.
		// If there is no concentration, there is only one possible PROC address. This step is then not needed, but do it anyway.
		NetworkAddress* adr = (NetworkAddress*) currData->getSrcAddr();
		int p = adr->id[AddressTranslator::convertLevel("PROC")];
		ackp->setMsgId(p);
		ackp->setData((long) ((ApplicationData*) currData->decapsulate()));
		sendDelayed(ackp, 0, procReqOut);

		// currData is not useful once the sending process has been performed.
		delete currData;

		currData = NULL;
	}

	return;
}








void wNIF::printProcData(ProcessorData* pdata){
	std::cout << "----- Processor Data -----" << endl;
	std::cout << "type: " << pdata->getType() << endl;
	std::cout << "size: " << pdata->getSize() << endl;

	NetworkAddress* dest = (NetworkAddress*) pdata->getDestAddr();
	NetworkAddress* src = (NetworkAddress*) pdata->getSrcAddr();

	std::cout << "src: " << src->id[AddressTranslator::convertLevel("NET")] << endl;
	std::cout << "dest: " << dest->id[AddressTranslator::convertLevel("NET")] << endl;

}


void wNIF::sendDataToProcessor(ProcessorData* pdata) { // OK
	debug(getFullPath(), "start sendDataToProcessor", UNIT_NIC);

	// Put data to be sent into the queue
	if(pdata != NULL)
		toProcQ.push(pdata);
	else
		pdata = toProcQ.front();

	// Is there something to be sent to the processor, and has not been requested yet?
	if (!sentRequest && toProcQ.size() > 0) {

		// Then, request access to the processor
		ArbiterRequestMsg* req = new ArbiterRequestMsg();
		req->setType(proc_req_send);
		req->setVc(0);
		req->setDest(pdata->getDestAddr());
		req->setReqType(dataPacket);
		req->setPortIn(concentration);
		req->setSize(1);
		req->setTimestamp(simTime());
		req->setMsgId(pdata->getId());
		req->setStage(10000);

		debug(getFullPath(), "sending proc_req_send", UNIT_NIC);
		// EVCON ev.printf("Sending proc_req_send to processor...\n");
		//sendDelayed(req, clockPeriod_packet/2, procReqOut);
		sendDelayed(req, clockPeriod_enc, procReqOut);
		//previouslly sendDelayed(req, 0, procReqOut); changed to add delay for encryption

		// request access is already sent
		sentRequest = true;
	}

	debug(getFullPath(), "end sendDataToProcessor", UNIT_NIC);
}
