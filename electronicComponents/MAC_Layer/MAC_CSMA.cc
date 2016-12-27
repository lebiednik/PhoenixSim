

#include "MAC_CSMA.h"




MAC_CSMA::MAC_CSMA(int id, double channelCapacityP, double backOffPeriodP, int numOfNodesXP,
        double pPersistentP, bool negativeACKsP, simtime_t timeoutP) {

	idnum = id;
	channelCapacity = channelCapacityP;
	timeout = timeoutP;
	backOffPeriod = backOffPeriodP;
	pPersistent = pPersistentP;
	numOfNodesX = numOfNodesXP;
	negativeACKs = negativeACKsP;

	ackPolicy = not negativeACKs;
	confirmationPolicy = 0;
	mediumIsFree = 1;
	txToCommit = 0;
	persistenceWait = false;

	nACK = 0;
	nRETRIES = 0;

    physicalId = 0;

	ackReceived = new bool [numOfNodesX*numOfNodesX];
	resetVector(ackReceived);


//	ev << "Basic backoff period: " << backOffPeriod << endl;
//	ev << "Channel capacity: " << channelCapacity << endl;



}

MAC_CSMA::~MAC_CSMA() {
    delete ackReceived;

}


// Torna el missatge que s'ha de transmetre un cop acaba el backoff. Nul en cas que no s'hagi de transmetre
ElectronicMessage* MAC_CSMA::backoffExpired(){

	ElectronicMessage* result = NULL;
	if(mediumIsFree){ // p-persistence hauria d'anar aquí si de cas.
	  result = MACqueue.front()->dup();
	  result->setId(++physicalId);
	  txToCommit = 1;
	  nRETRIES = 0;

	  persistenceWait = (pPersistent < uniform(0,1));
	  // if pPersistent = 0  -> persistenceWait = true
	  // if pPersistent = 1  -> persistenceWait = false
	  // ev << "Ppersistent: " << pPersistent << "  Wait?: " << persistenceWait << endl;
	}
	else {
	    if (nRETRIES < 8)
	        nRETRIES++;
	}


	return result;

}

// Retorna el temps de Backoff que s'ha d'esperar abans de transmetre
simtime_t MAC_CSMA::getBackoff(){

    // en funcio de cicles de rellotge
    // Returns a random variable from the exponential distribution with the given mean
    // (that is, with parameter lambda=1/mean).


    double boTime;
    if (nRETRIES == 0 and not persistenceWait) {
        boTime = 0;
    } else {
        //boTime = exponential(backOffPeriod);
        double maxBO = (pow(2,nRETRIES) - 1)*backOffPeriod;
        boTime = uniform(0,maxBO);
    }
    ev << "MAC: Back off set after: " << boTime << " (Retry: " << nRETRIES << ")" << endl;

    return (simtime_t) boTime;

//    double result;
//    result = 0; // NO CONTENTION
//     return (simtime_t) result;



}

// Defines what to do internally when your TX collided
// El paquet es torna a posar en cua automaticament
void MAC_CSMA::prepareReTX(){

    // Suposem que el timeout es prou llarg per incloure tots els acks que no es perden
    nACK = 0;
    resetVector(ackReceived);
    txToCommit = false;

    // ev << "TimeOut: ReTX needed" << endl;
    /*
        nRETRIES++;
        if(nRETRIES > maxRETRIES)
            opp_error("Message has been discarded because of too many retries.");
    */

}


// Defines what to do internally when your TX was correctly received.
void MAC_CSMA::commitTX() {

    // reinicialitzar variables de control

    ElectronicMessage *Msg = MACqueue.front();
    delete Msg;
	MACqueue.pop();
	txToCommit = 0;
	// ev << "Commit TX. Queue size: " << MACqueue.size() << endl;

}

// Define what to do in case of COLLISION. Parameter "type" is the type of collision (TX(0) or RX(1)).
ElectronicMessage* MAC_CSMA::handleCollision(int type, NetworkAddress* source){

    ElectronicMessage* result = NULL;
    if (type == 1 and negativeACKs) {
//            result = prepareCntrlMsg(wireless_NACK, rcvdMsg->getSrcId());
        result = prepareCntrlMsg(wireless_NACK, source);
        // ev << "Collision detected, sending NACK" << endl;
    }
	return result;

}


// Defines what to do when a message from other node (rcvdMsg) was correctly received. Returns ACK is needed.
ElectronicMessage* MAC_CSMA::confirmRX(ElectronicMessage* rcvdMsg) {

    ElectronicMessage* result = NULL;

    if (not negativeACKs) {
        result = prepareCntrlMsg(wireless_ACK,  (NetworkAddress*) rcvdMsg->getSrcId());

        result->setData(rcvdMsg->getId());
        // ev << "ACK sent ( id: " <<  result->getData() << ") (from message: " << rcvdMsg->getId() << ")" << endl;
    }

	return result;

}

// Defines what to do when an ACK arrives. Returns 1 if ACK implies a message commitment.
bool MAC_CSMA::ackArrived(ElectronicMessage* ackMsg){

    // TODO: pot arribar un ack d'un intent anterior més tard!
    // TODO: pot arribar un altre cop el mateix paquet



    NetworkAddress* srcAdr = (NetworkAddress*) ackMsg->getSrcId();
    int src = srcAdr->id[AddressTranslator::convertLevel("NET")];
    unsigned long int dataAckPacket = ackMsg->getData();
    delete ackMsg;


    if (ackReceived[src] or dataAckPacket != physicalId) {
        // ev << "ACK of a previous message received" << endl;
        // opp_error("ACK of a previous message received");
        return false;
    }

    ackReceived[src] = true;
    nACK = nACK+1;
    // ev << "ACK received (id msg: " << dataAckPacket << " of node: " << src << "): "
     //       << nACK << " of " << numOfNodesX*numOfNodesX-1 << endl;
    if(nACK == numOfNodesX*numOfNodesX-1){
        commitTX();
        // ev << "Message complete ACK" << endl;
        nACK = 0;
        resetVector(ackReceived);
        return true;
    }
    return false;

}

simtime_t MAC_CSMA::getTimeout() {

    //ev << "Timeout set after: " << timeout << " s" << endl;
    return timeout;

}



// Private
void MAC_CSMA::resetVector(bool *ackReceived) {
    for (int i = 0; i < numOfNodesX*numOfNodesX; i++) {
        ackReceived[i] = false;
    }
}
