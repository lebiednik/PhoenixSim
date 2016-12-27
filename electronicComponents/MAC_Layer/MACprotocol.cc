#include "MACprotocol.h"




// Define policy for sending when backoff expires. Returns 1 if permission to send is granted.
// mediumIsFree, p-persistance, etc...
ElectronicMessage* MACprotocol::backoffExpired(){

	ElectronicMessage* result = NULL;
	//if(mediumIsFree){ // p-persistence hauria d'anar aquí si de cas.
	result = MACqueue.front();
	//}

	return result;

	//return NULL;
}


// Defines and returns the next backoff period.
simtime_t MACprotocol::getBackoff(){

	double result;

	result = 0; // NO CONTENTION
	// PER CONTENTION-BASED, DEFINIR LA TEVA PROPIA FORMULA

	return (simtime_t) result;

}

// Defines what to do internally when your TX collided
void MACprotocol::prepareReTX(){

	/*
		nACK = 0;
		nRETRIES++;
		if(nRETRIES > maxRETRIES)
			opp_error("Message has been discarded because of too many retries.");
	*/
}

// Defines what to do internally when your TX was correctly received.
void MACprotocol::commitTX(){

	// nRETRIES = 0; nACK = 0;
}


// Define what to do in case of COLLISION. Parameter "type" is the type of collision (TX or RX).
ElectronicMessage* MACprotocol::handleCollision(int type, NetworkAddress* source){

	ElectronicMessage* result = NULL;
	// type == 0  EN TRANSMISSIO
	// prepareReTX();

	// type == 1  EN RECEPCIO
	// NACK si és contention-based i fa servir NACKs.
	//if(confirmationPolicy==0 && ackPolicy==0){
	//	result = mac->prepareCntrlMsg(wireless_NACK, source);
	//}

	return result;
}

// Defines what to do when a message from other node (rcvdMsg) was correctly received. Returns ACK is needed.
// També pot servir per actualitzar dades de backoff?
ElectronicMessage* MACprotocol::confirmRX(ElectronicMessage* rcvdMsg){

	ElectronicMessage* result = NULL;

	//	result = prepareCntrlMsg(wireless_ACK, (NetworkAddress*)rcvdMsg->getSrcId());

	return result;

}

// Defines what to do when an ACK arrives. Returns 1 if ACK implies a message commitment.
bool MACprotocol::ackArrived(ElectronicMessage* ackMsg){

	nACK = nACK+1;
	if(nACK == numOfNodesX*numOfNodesX-1){
		commitTX();
		return 1;
	}
	return 0;

}


// FUNCIONS CROSSA QUE NO CAL MODIFICAR

// Returns confirmation policy.
int MACprotocol::getConfirmationPolicy(){

	return confirmationPolicy;

}


simtime_t MACprotocol::getTimeout(){

	return timeout;
}

// Returns 1 if ACKs are used. 0 if NACKs are used.
bool MACprotocol::isAck(){

	return ackPolicy;

}

void MACprotocol::setFree(int value){

	mediumIsFree = value;

}

void MACprotocol::enqueue(ElectronicMessage *emsg) {
	MACqueue.push(emsg);
}

bool MACprotocol::moreToTX(){

	bool result = !MACqueue.empty();
	return result;
}

bool MACprotocol::readyToTX(){

	bool result = !txToCommit;
	return result;
}

// Prepares and returns a control message of type "type" (token, ACK, NACK) and using destId if required.
ElectronicMessage* MACprotocol::prepareCntrlMsg(int type, NetworkAddress *destId){

    int numLevels = 3;
	int procConc = 1;

 	ElectronicMessage* tok = new ElectronicMessage();
 	tok->setBitLength(16);
 	tok->setMsgType(type);
 	tok->setData(0);

 	// SET SOURCE
	stringstream ss1;
	ss1 << "";
	ss1 << idnum / procConc;
	ss1 << ".0.";
	ss1 << idnum % procConc << ".";
	NetworkAddress* srcAddr = new NetworkAddress(ss1.str(), numLevels);
	tok->setSrcId((long) srcAddr);

	// SET DESTINATION
	if(type == token){
		int dst = (idnum+1) % (numOfNodesX*numOfNodesX);
		stringstream ss2;
		ss2 << "";
		ss2 << dst / procConc;
		ss2 << ".0.";
		ss2 << dst % procConc << ".";
		NetworkAddress* dstAddr = new NetworkAddress(ss2.str(), numLevels);
		tok->setDstId((long) dstAddr);
	} else
		tok->setDstId((long) destId);


	return tok;

}



