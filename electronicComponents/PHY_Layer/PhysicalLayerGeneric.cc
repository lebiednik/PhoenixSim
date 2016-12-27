
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

// Aqu� es on va la teca... qu� fem quan arriba un missatge?
void PhysicalLayerGeneric::handleMessage(cMessage *msg) {

	// TODO: fer que en esquemes de no-colisi� (FDMA, TDMA, token), els paquets entrin a MAC igualment.

	if (msg->isSelfMessage()) {
	// Quan el missatge �s propi, hi ha dues possibilitats:
		// +�s un endTxMsg indicant que s'ha acabat de transmetre un missage (si PHY �s capa� de detectar colisions a TX i n'hi ha una no arribar� aqu�)
			// Enviar transmission_OK a MAC.
		// +�s un endRxMsg indicant que s'ha acabat de rebre un missatge (si PHY �s capa� de detectar colisons a TX i n'hi ha una no arribar� mai aqu�)
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

				// Arribar aqu� significa que no es pot detectar colisio a TX: hem d'enretirar els paquets RX d'un a un...
				// HACK: FDMA pot detectar colisions per� tots entren.
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


		// Dir a MAC que el medi est� ocupat
		notifyMAC(medium_occupied, 0);

		ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);

		// EVCON ev.printf("Receiving message through wireless.\n");

		// Si s'esta enviant hi ha colisio (potser ja s'ha detectat).
		// Missatge entrant a la cua PHY. Si hi ha un endRxMsg scheduled �s colisi�
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



