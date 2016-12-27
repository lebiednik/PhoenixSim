

#include "MAC_token.h"


MAC_token::MAC_token(int ident, int nX) {

	idnum = ident;
	numOfNodesX = nX;

	ackPolicy = 0;
	confirmationPolicy = 2;
	mediumIsFree = 0;
	txToCommit = 0;
}

MAC_token::~MAC_token() {

}


ElectronicMessage* MAC_token::backoffExpired(){

	ElectronicMessage* result = NULL;

	result = MACqueue.front();
	txToCommit = 1;

	return result;

}


void MAC_token::prepareReTX(){

	opp_error("Token should not arrive to prepareReTX.\n");

}

void MAC_token::commitTX() {

	MACqueue.pop();
	txToCommit = 0;

}

ElectronicMessage* MAC_token::handleCollision(int type, NetworkAddress* source){

	opp_error("Collision should not be occuring in token scheme. Aborting.");
	return NULL;

}

ElectronicMessage* MAC_token::confirmRX(ElectronicMessage* rcvdMsg) {

	return NULL;

}

bool MAC_token::ackArrived(){

	opp_error("Token should not arrive to ackArrived.\n");

}

simtime_t  MAC_token::getTimeout() {

	opp_error("Token should not arrive to getTimeout.\n");

}







