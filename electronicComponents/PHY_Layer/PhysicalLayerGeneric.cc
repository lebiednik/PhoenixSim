
#include "PhysicalLayer.h"
#include "PhysicalLayerGeneric.h"
#include "statistics.h"
#include "math.h"




Define_Module(PhysicalLayerGeneric)
;


PhysicalLayerGeneric::PhysicalLayerGeneric() {

}

PhysicalLayerGeneric::~PhysicalLayerGeneric() {

}

void PhysicalLayerGeneric::initialize() {

    PhysicalLayer::initialize();

	collision = 0;
	transmitting = false;

	endRxMsg = new cMessage("endRxMsg");
	endTxMsg = new cMessage("endTxMsg");


}

void PhysicalLayerGeneric::finish() {

	cancelAndDelete(endRxMsg);
	cancelAndDelete(endTxMsg);

}

// Aquí es on va la teca... què fem quan arriba un missatge?
void PhysicalLayerGeneric::handleMessage(cMessage *msg) {

	// TODO: fer que en esquemes de no-colisió (FDMA, TDMA, token), els paquets entrin a MAC igualment.

	if (msg->isSelfMessage()) {
	// Quan el missatge és propi, hi ha dues possibilitats:
		// +És un endTxMsg indicant que s'ha acabat de transmetre un missage (si PHY és capaç de detectar colisions a TX i n'hi ha una no arribarà aquí)
			// Enviar transmission_OK a MAC.
		// +És un endRxMsg indicant que s'ha acabat de rebre un missatge (si PHY és capaç de detectar colisons a TX i n'hi ha una no arribarà mai aquí)
			// Si no hi ha colisio, enviem a MAC; si hi ha, seguir mirant la cua PHY.


		if(msg==endTxMsg){

			notifyMAC(transmission_OK, 0);
			notifyMAC(medium_free, 0);
			transmitting = false;

		} else { //msg==endRxMsg

			if(collision==0){

				notifyMAC(medium_free, 0);
				send(rxQueue.front(),"phyToMac");
				rxQueue.pop();

			} else {

				// Arribar aquí significa que no es pot detectar colisio a TX: hem d'enretirar els paquets RX d'un a un...
				// HACK: FDMA pot detectar colisions però tots entren.
				notifyMAC(collision_detected_RX, rxQueue.front()->getSrcId());
				if(type == FDMA)
					send(rxQueue.front(),"phyToMac");

				delete rxQueue.front();
				rxQueue.pop();
				if(!rxQueue.empty()){
					scheduleAt(rxQueue.front()->getArrivalTime() + rxQueue.front()->getDuration(),endRxMsg);
				} else {
					collision = 0;
					notifyMAC(medium_free, 0);
				}

			}

		}


	} else if (msg->arrivedOn("fromNet")) {
	// Quan el missatge arriba de la xarxa, mirem colisions i actuem


		// Dir a MAC que el medi està ocupat
		notifyMAC(medium_occupied, 0);

		ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);

		// EVCON ev.printf("Receiving message through wireless.\n");

		// Si s'esta enviant hi ha colisio (potser ja s'ha detectat).
		// Missatge entrant a la cua PHY. Si hi ha un endRxMsg scheduled és colisió
		if (transmitting and not collision) {
		    // EVCON ev.printf("Possible collision at node %d! \n",idnum);
		    scheduleAt(simTime() + MsgIn->getDuration(),endRxMsg);
		    collision = 1;
		}
		else if(!endRxMsg->isScheduled()){
			scheduleAt(simTime() + MsgIn->getDuration(),endRxMsg);
		}
		else {
		    // EVCON ev.printf("Possible collision at node %d! \n",idnum);
			collision = 1;
		}
		rxQueue.push(MsgIn);


	// Quan missatge arriba de MAC, l'enviem a tothom menys nosaltres. EndTxMsg per quan acabem d'enviar-lo.
	}
	else {


		simtime_t delay;
		notifyMAC(medium_occupied, 0);
		if(type == FDMA)
			delay = sendIt(msg, channelCapacity/(numOfNodesX*numOfNodesX));
		else
			delay = sendIt(msg, channelCapacity);

		scheduleAt(simTime() + delay, endTxMsg);
		transmitting = true;
			
	}
	
}



