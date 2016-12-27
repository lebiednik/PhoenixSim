

#include "PhysicalLayer.h"
#include "PhysicalLayerBRS.h"
#include "statistics.h"
#include "math.h"




Define_Module(PhysicalLayerBRS)
;


PhysicalLayerBRS::PhysicalLayerBRS() {

}

PhysicalLayerBRS::~PhysicalLayerBRS() {

}

void PhysicalLayerBRS::initialize() {

    PhysicalLayer::initialize();

    collision = false;
    state = LISTENING;

    endRxMsg = new cMessage("endRxMsg");
    endTxMsg = new cMessage("endTxMsg");

    clockRate = (double) par("O_frequency_data");


    msgRx = new cMessage("msgRx");

    //cMessage *msgRx;
    //queue<ElectronicMessage*> msgRxQueue;
}

void PhysicalLayerBRS::finish() {

    PhysicalLayer::finish();

	cancelAndDelete(endRxMsg);
	cancelAndDelete(endTxMsg);
	cancelAndDelete(msgRx);

}

void PhysicalLayerBRS::handleMessage(cMessage *msg) {

    // MISSATGE PROPI
	if (msg->isSelfMessage()) {
	// Quan el missatge és propi, hi ha dues possibilitats:
		// +És un endTxMsg indicant que s'ha acabat de transmetre un missage
			// Enviar transmission_OK a MAC.
		// +És un endRxMsg indicant que s'ha acabat de rebre un missatge
			// Si no hi ha colisio, enviem a MAC; si hi ha, seguir mirant la cua PHY.

	    if(msg == msgRx){
	        while (not msgRxQueue.empty()) {
	            ElectronicMessage *MsgIn;
                MsgIn = msgRxQueue.front();
	            msgRxQueue.pop();


	            if (state == LISTENING) {
	                //  ev << "Receiving" << endl;
	                state = RECEIVING;
	                notifyMAC(medium_occupied, 0);
	                //if(idnum == 0)
	                  //  fprintf(stderr, "%.12f: Receiving message %d.\n", simTime().dbl(),MsgIn->getId());
	                scheduleAt(simTime() + MsgIn->getDuration(),endRxMsg);
	            }
	            else if (state == RECEIVING) {
	                 //  ev << " cause a collision" << endl;
	                 ev.printf("Collision at node %d! \n",idnum);
	                 //fprintf(stderr, "%.12f: Collision at node %d!\n",simTime().dbl(),idnum);
	                 collision = true;
	            }
	            else if (state == TRANSMITTING) {
	                 //  ev << " node was transmitting: not detected yet" << endl;
	                 ev.printf("Collision at node %d! when the packet is completely transmitted \n",idnum);
	                 //fprintf(stderr, "%.12f: Collision at node %d! when the packet is completely transmitted\n",simTime().dbl(),idnum);
	                 if (not endRxMsg->isScheduled())
	                     scheduleAt(simTime() + MsgIn->getDuration(),endRxMsg);
	                 collision = true;
	            }
	            else { // lisening for ACKs
	                 // ev << "PHY ERROR: No hauria d'arribar mai un paquet mentre s'escolten ACKs" << endl;
	                 // opp_error("PHY ERROR: No es poden enviar missatges en un periode NACK");
	                 // ev << "PHY: Missatge rebut en ACK period (en principi despres de transmetre)" << endl;
	            }
	            rxQueue.push(MsgIn);
	        }


	    } else if(msg == endTxMsg){
		    //  ev << "PHY: Message completely transmitted: ";
			if (collision) {
			    notifyMAC(collision_detected_TX,0);
			    // ev << "Collision detected after a tx" << endl;
			}
			else
	            notifyMAC(transmission_OK, 0);

            state = NACKs;  // Ho fa el MAC, pero aixi evitem que es coli algun missatge entremig

			if(!rxQueue.empty())   {
			    //  ev << "(Receiving another message)" << endl;
			}


		} else if (msg == endRxMsg) { //msg==endRxMsg

		    if (state != RECEIVING) {
		        //  ev << "PHY: Message received out of the receiving state (State: " <<  state << ")" << endl;
		    }
		    //  ev << "PHY: message completely received: ";

		    if (not collision) {
		        // notifyMAC(medium_free, 0); implicit amb el paquet
	            if (state == RECEIVING)
	                send(rxQueue.front(),"phyToMac");
	            else {
	                //opp_error("Message received in a non receiving state.\n");
	                 ev << "Message received while transmitting, collision not detected but message not received" << endl;
	                 delete rxQueue.front();
	            }
		        rxQueue.pop();
		        //  ev << "No collision detected" << endl;
		        if (endRxMsg->isScheduled())
		              opp_error("endRxMsg encara programat1");
		    }
		    else {
		        //  ev << "Collision detected" << endl;
		        // Un cop detecta la col·lisio, la resta s'ignora (mac canvia l'estat)
                if (state == RECEIVING)
                    notifyMAC(collision_detected_RX, rxQueue.front()->getSrcId());
		        delete rxQueue.front();
		        rxQueue.pop();

		        // Si encara queden paquets per rebre
		        if(!rxQueue.empty()){
		            //  ev << "PHY: Receiving another message" << endl;
		            simtime_t schTime = rxQueue.front()->getArrivalTime() + rxQueue.front()->getDuration();
		            simtime_t simt = simTime();
		            if (schTime >=  simt)
		                scheduleAt(schTime,endRxMsg);
		            else {
		                 opp_error("ERROR: programant un missatge pel passat: Ghh");
		                // Possiblement un missatge de 127?
		                delete rxQueue.front();
		                rxQueue.pop();
		                //goto GUARRADA;
		            }
		        } else {
		            state = LISTENING;
		            //  ev << "PHY: No more messages" << endl;
		            collision = false;
		            if (endRxMsg->isScheduled())
		                opp_error("endRxMsg encara programat2");
		        }
		    }
		}
		else {
		    opp_error("Missatge de control desconegut");
		}
		// TODO Esborrar missatge(?) S'esborren quan s'acaben les respectives col·lisions

	// MISSATGE WIRELESS
	} else if (msg->arrivedOn("fromNet")) {

        ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);

        // Paquet de dades rebut
        if (MsgIn->getMsgType() == dataPacket){

            //cMessage *msgRx;
            //queue<ElectronicMessage*> msgRxQueue;
            msgRxQueue.push(MsgIn);
            if (not msgRx->isScheduled()) {
                scheduleAt(simTime(),msgRx);
            }





            //  ev << "PHY: Data packet incoming: ";
  /*          if (state == LISTENING) {
                //  ev << "Receiving" << endl;
                state = RECEIVING;
                notifyMAC(medium_occupied, 0);
                scheduleAt(simTime() + MsgIn->getDuration(),endRxMsg);
            }
            else if (state == RECEIVING) {
                //  ev << " cause a collision" << endl;
                ev.printf("Collision at node %d! \n",idnum);
                collision = true;
            }
            else if (state == TRANSMITTING) {
                //  ev << " node was transmitting: not detected yet" << endl;
                ev.printf("Collision at node %d! when the packet is completely transmitted \n",idnum);
                if (not endRxMsg->isScheduled())
                    scheduleAt(simTime() + MsgIn->getDuration(),endRxMsg);
                collision = true;
            }
            else { // lisening for ACKs
                // ev << "PHY ERROR: No hauria d'arribar mai un paquet mentre s'escolten ACKs" << endl;
                // opp_error("PHY ERROR: No es poden enviar missatges en un periode NACK");
                // ev << "PHY: Missatge rebut en ACK period (en principi despres de transmetre)" << endl;
            }
            rxQueue.push(MsgIn);
            */
        }
        // NACK rebut
        else if (MsgIn->getMsgType() == broadcast_NACK)  {
            // ev << "PHY: NACK received: ";
            if (state == NACKs) {
                // ev << " in the NACK state" << endl;
                if (nNacks++ == 0) // notificar a mac només el primer nack rebut
                    notifyMAC(broadcast_NACK, 0);
            }
            else if (state == RECEIVING) {
                // ev << " in the receiving state (cause collision)" << endl;
                collision = true; // colisiona pero no detectem el nack
            }
            else if (state == TRANSMITTING) {
                // ev << " in the transmitting state (NACK not detected)" << endl;
            }
            else { // state == Listening
                // ev << "NACK ignorat (el protocol mac ja sap que hi ha collisio)" << endl;
            }
            delete MsgIn;
        }
        else {
            // ev << "PHY ERROR: No hauria cap altre tipus de paquet" << endl;
            opp_error("PHY ERROR: No hauria cap altre tipus de paquet");
            delete MsgIn;
        }


	// MISSATGE DE MAC
	} else {
	    ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);

	    // Quan missatge arriba de MAC, l'enviem a tothom menys nosaltres. EndTxMsg per quan acabem d'enviar-lo.
	    if (MsgIn->getMsgType() == dataPacket) {

	        // ev << "PHY: Start a transmission of a packet" << endl;
            //notifyMAC(medium_occupied, 0);
	        //fprintf(stderr, "%.12f: PHY %d sending message %d of length %d\n",simTime().dbl(),idnum,MsgIn->getId(),MsgIn->getBitLength());
            simtime_t delay = sendIt(msg, channelCapacity);
            scheduleAt(simTime() + delay, endTxMsg);
            //transmitting = true;
            state = TRANSMITTING;
	    }
	    // Quan demana enviar un nack l'enviem a tothom
	    else if (MsgIn->getMsgType() == broadcast_NACK)  {
	        // TODO enviar NACKs deshabilitat, son masses missatges per omnet i ara per ara es detecten totes les colisions
	        // ev << "PHY: Transmit a NACK" << endl;
	        //sendIt(msg, channelCapacity);
	        delete MsgIn;
	    }
	    // CONTROL
	    else if (MsgIn->getMsgType() == startNACKperiod)  {
	        // ev << "PHY: Start a NACK period" << endl;
	        nNacks = 0;
	        state = NACKs;
	        delete MsgIn;
	    }
	    else if (MsgIn->getMsgType() == stopNACKperiod)  {
	        // ev << "PHY: Stop a NACK period" << endl;
	        state = LISTENING;
            if (endRxMsg->isScheduled())
                opp_error("endRxMsg encara programat3");
	        delete MsgIn;
	    }
	    else {
            opp_error("PHY ERROR: No hauria cap altre tipus de paquet");
	        delete MsgIn;
	    }
	}
}

// Returns transmission time.
// CSMA needs all messages to be short, and then decide to transmit the rest if they are long.
simtime_t PhysicalLayerBRS::sendIt(cMessage *msg, double dataRate){

    ElectronicMessage *MsgToSend = check_and_cast<ElectronicMessage*> (msg);

//  NetworkAddress* destAdr = (NetworkAddress*) MsgToSend->getDstId();
    NetworkAddress* srcAdr = (NetworkAddress*) MsgToSend->getSrcId();
//  int dest = destAdr->id[AddressTranslator::convertLevel("NET")];
    int src = srcAdr->id[AddressTranslator::convertLevel("NET")];

    // We only send one cycle at first. The MAC will send (or not) the rest.
    simtime_t full_t = (simtime_t) (1.0 / clockRate);

    simtime_t a =  (simtime_t)(0.029/3e8 + deltaSim);
    cModule *targetModule;
    for (int i=0; i<src; i++)   {
        ElectronicMessage *copy = MsgToSend->dup();
        targetModule = getParentModule()->getParentModule()->getSubmodule("node",i);
        simtime_t prop_t = (simtime_t)(distances[i]/3e8 + deltaSim);
        sendDirect(copy, prop_t, full_t - 3.1*a - deltaSim, targetModule, "radioIn");
    }

    for (int j=src+1; j<numOfNodesX*numOfNodesX; j++)   {
        ElectronicMessage *copy = MsgToSend->dup();
        targetModule = getParentModule()->getParentModule()->getSubmodule("node",j);
        simtime_t prop_t = (simtime_t)(distances[j]/3e8 + deltaSim);
        sendDirect(copy, prop_t, full_t - 3.1*a - deltaSim, targetModule, "radioIn");
    }
    // ev.printf("Message of %f bits wirelessly sent at %1.12g bps.\n",pktSize,dataRate);
    delete MsgToSend;

    return full_t - 3.1*a;
}//


