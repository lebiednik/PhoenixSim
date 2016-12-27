

#include "MAC_FDMA.h"




MAC_FDMA::MAC_FDMA(int id, int N) {

	idnum = id;
	numOfNodesX = N;
	ackPolicy = 0;
	confirmationPolicy = 1;
	mediumIsFree = 1;
	txToCommit = 0;



}

MAC_FDMA::~MAC_FDMA() {

}


ElectronicMessage* MAC_FDMA::backoffExpired(){

	ElectronicMessage* result = NULL;
	//if(mediumIsFree){ // p-persistence hauria d'anar aquí si de cas.
	result = MACqueue.front();
	txToCommit = 1;
	//}

	return result;

}

simtime_t MAC_FDMA::getBackoff(){

	return 0;

}

void MAC_FDMA::prepareReTX(){

	opp_error("FDMA should not arrive to prepareReTX.\n");

}

void MAC_FDMA::commitTX() {

	MACqueue.pop();
	txToCommit = 0;

}

ElectronicMessage* MAC_FDMA::handleCollision(int type, NetworkAddress* source){

	return NULL;

}

ElectronicMessage* MAC_FDMA::confirmRX(ElectronicMessage* rcvdMsg) {

	return NULL;

}
bool MAC_FDMA::ackArrived(){

	opp_error("FDMA should not arrive to ackArrived.\n");

}

simtime_t MAC_FDMA::getTimeout() {

	opp_error("FDMA should not arrive to getTimeout.\n");

}

