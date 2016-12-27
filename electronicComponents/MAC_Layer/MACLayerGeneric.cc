
#include "MACLayerGeneric.h"
#include "statistics.h"


// include tots els fitxers de MAC
#include "MAC_FDMA.h"
#include "MAC_TDMA.h"
#include "MAC_token.h"
#include "MAC_CSMA.h"

Define_Module(MACLayerGeneric)
;


MACLayerGeneric::MACLayerGeneric() {

}

MACLayerGeneric::~MACLayerGeneric() {

}

void MACLayerGeneric::initialize() {
    MACLayer::initialize();


    type = par("type");
    timeout = par("timeout");
    backOffPeriod = par("backOffPeriod");
    pPersistent = par("pPersistent");
    negativeACKs = par("negativeACKs");
    HopsPerCycle = par("HopsPerCycle");

    //maxRETRIES = par("maxRETRIES");
    backoffMsg = new cMessage("backoffMsg");
    timeoutMsg = new cMessage("timeoutMsg");
    tokenMsg = new cMessage("tokenMsg");

    clockRate = (double) par("O_frequency_data");

    clockPeriod = 1.0 / clockRate;

    maxTokenTrips = par("maxTokenTrips");
    tokenTrips = 0;
    HopsPerCycle = par("HopsPerCycle");
    nackDetected = false;

    discarded = Statistics::registerStat("Discarded Packets", StatObject::TOTAL, "MAC");
    collisions = Statistics::registerStat("Number of Collisions", StatObject::TOTAL, "MAC");


    switch (type) {

          case FDMA:
              mac = new MAC_FDMA(idnum, numOfNodesX);
              break;

          case TDMA:
              mac = new MAC_TDMA(numOfNodesX, coreSizeX, 128/channelCapacity, idnum);
              break;

          case TOKEN_PASSING:
              mac = new MAC_token(idnum, numOfNodesX);
              if(idnum==0){
                  scheduleAt(0,tokenMsg);
                  //ElectronicMessage *tok = mac->prepareCntrlMsg(token,NULL);
                  //send(tok,"macToController");
              }
              break;
          case CSMA:
               mac = new MAC_CSMA(idnum, channelCapacity, backOffPeriod, numOfNodesX, pPersistent,
                       negativeACKs, timeout);
               break;

          default:
              opp_error("ERROR: unknown PHY+MAC type.");
      }


}

void MACLayerGeneric::finish() {
    MACLayer::finish();

	cancelAndDelete(backoffMsg);
	cancelAndDelete(timeoutMsg);
	cancelAndDelete(tokenMsg);
}

// Aquí es on va la teca... què fem quan arriba un missatge?
void MACLayerGeneric::handleMessage(cMessage *msg) {

	// backoffMsg for BACKOFF, timeoutMsg for TIMEOUT, tokenMsg per TOKEN
	if (msg->isSelfMessage()) {

		if(msg == backoffMsg) {

			// Quan backoff expira, mirem si podem enviar.
			ElectronicMessage* outmsg = mac->backoffExpired();
			if(outmsg!=NULL) {
				send(outmsg,"macToPhy"); // Un cop enviat esperem transmission_OK
			    // EVCON ev.printf("Message sent: %d\n",outmsg->getId());
			}
			else
				triggerTX();


		} else if(msg == timeoutMsg){

		    // Nomes arriba en contention-base protocols

		    if (mac->isAck() or (not mac->isAck() and nackDetected)) {
		        collisions->track(1);
		        mac->prepareReTX(); // no ack received or nack Detected
		    } else
		        mac->commitTX();  // nack not detected

			triggerTX();

		} else if(msg == tokenMsg) {

		    ElectronicMessage *tok = mac->prepareCntrlMsg(token,NULL);
			send(tok,"macToController");

		} else {
			opp_error("Auto-message type not expected in MAC.\n");
		}
	

	} else if (msg->arrivedOn("fromPhy")) {

		ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);

		// Si són dades, al NIC directe. ACK?
		if(MsgIn->getMsgType()==dataPacket){
			ElectronicMessage* wAck = mac->confirmRX(MsgIn);
			send(MsgIn,"toNic");
			if(wAck!=NULL)
				send(wAck,"toNic");
		// Si és de control, fer algo
		} else {

			switch(MsgIn->getMsgType()) {
				case(transmission_OK): // transmissió completada
					switch(mac->getConfirmationPolicy()) {
				 //0 -> CONTENTION: schedule Timeout
						case(0):
                            nackDetected = false;
							timeout = mac->getTimeout();
							scheduleAt(simTime()+timeout,timeoutMsg);
							break;
				 //1 -> NO CONTENTION: commitTX, pop() i schedule timer.
						case(1):
							mac->commitTX();
							triggerTX();
							break;
				//2 -> TOKEN (NO CONTENTION): commitTX i schedule token.
						case(2):
							mac->commitTX();
							scheduleAt(simTime(),tokenMsg);
							break;
						default:
							opp_error("Unexpected transmission confirmation policy.\n");
					}
					break;

				case(collision_detected_TX): //colisio en TX
					mac->handleCollision(0, 0);
					triggerTX();
					break;

				case(collision_detected_RX): //collisio en RX
					{
					ElectronicMessage* wNack = mac->handleCollision(1, (NetworkAddress*) MsgIn->getSrcId());
					if(wNack!=NULL)
					    send(wNack,"toNic");
					}
					break;

				case(medium_free): //medi OK
					mac->setFree(1);
					break;

				case(medium_occupied): // medi KO
					mac->setFree(0);
					break;

				default:
					opp_error("Unexpected type of control message at MAC layer.\n");
			}
			delete MsgIn;
		}

	} else {
	// What to do when message arrives from NIC or control?
		
		ElectronicMessage *emsg = check_and_cast<ElectronicMessage*> (msg);

		if(emsg->getMsgType()==token){

			if(idnum==0){
				tokenTrips++;
				if(tokenTrips==maxTokenTrips)
					endSimulation();
			}
			// Token arrived, prepare to send whatever you need or pass the token.
			if(mac->moreToTX()){
				scheduleAt(simTime(),backoffMsg);
			    delete emsg;
			}else {
			    int hops = emsg->getData()+1;
				//ElectronicMessage *tok = mac->prepareCntrlMsg(token,NULL);
				if(hops==HopsPerCycle){
				    //tok->setData(0);
				    //sendDelayed(tok,clockPeriod,"macToController");
				    emsg->setData(0);
				    sendDelayed(emsg,clockPeriod,"macToController");
				}else{
				    emsg->setData(hops);
				    sendDelayed(emsg,0,"macToController");
				    //tok->setData(hops);
				    //sendDelayed(tok,0,"macToController");
				}
				//delete emsg;
			}

		} else if(emsg->getMsgType()==wireless_ACK) {

			bool committed = mac->ackArrived(emsg);
			if(committed) {
			    cancelEvent(timeoutMsg);
			    delete emsg;
				triggerTX();
			}


		} else if(emsg->getMsgType()==wireless_NACK) {

		    EV << "NACK received" << endl;

			// TODO: algun mecanisme que asseguri que NACKs pel mateix paquet a partir del primer es descarten.
		    // mac->nackArrived(emsg);
		    nackDetected = true;
		    //    mac->prepareReTX();
		    //    triggerTX();
		    delete emsg;

		} else {

		    if (mac->MACqueue.size() < 8) {
                mac->enqueue(emsg);
                triggerTX();
		    }
		    else {
		        EV << "MAC: La cua plena, missatge descartat" << endl;
		        discarded->track(1);
		        delete emsg;
		    }
		 }
	}
	
}

void MACLayerGeneric::triggerTX(){

	// There is something to transmit, we are ready and there is no other backoff going on
    //EV << "Trigger TX-> moreToTX: " << mac->moreToTX() << " and readyToTX: " << mac->readyToTX() <<
    //        " and no backoffMsg: " << !backoffMsg->isScheduled() << endl;

	if(mac->moreToTX() && mac->readyToTX() && !backoffMsg->isScheduled() && type!=TOKEN_PASSING) {
		backoff = mac->getBackoff();
		scheduleAt(simTime()+backoff,backoffMsg);
	}

}

