

#include "MAC_TDMA.h"




MAC_TDMA::MAC_TDMA(int nX, int sizeX, double tSlot, int ident) {

	idnum = ident;
	numOfNodesX = nX;
	coreSizeX = sizeX / 1e6;

	ackPolicy = 0;
	confirmationPolicy = 1;
	mediumIsFree = 0;
	txToCommit = 0;

	margin = 2*nX*coreSizeX/3e8; // margin must account for the maximum propagation time
	timeSlot = tSlot + margin;
	epoch = (nX*nX)*timeSlot;

	ev.printf("Init TDMA - NumOfNodes: %d, TimeSlot: %g, Epoch interval: %g, margin: %g \n",nX*nX,timeSlot,epoch,margin);

}

MAC_TDMA::~MAC_TDMA() {

}



ElectronicMessage* MAC_TDMA::backoffExpired(){

	ElectronicMessage* result = NULL;

	result = MACqueue.front();
	txToCommit = 1;

	return result;

}

simtime_t MAC_TDMA::getBackoff(){

	simtime_t result;
	// Calculate next slot to queue it there
	double currentEpochTime = SIMTIME_DBL(simTime()) - floor(SIMTIME_DBL(simTime()) / epoch) * epoch;

	// If we are still on time to transmit the packet in the current epoch, do it.
	if(currentEpochTime < idnum*timeSlot)
		result = (simtime_t) idnum*timeSlot - currentEpochTime;
	// else, do it in the next one
	else
		result = (simtime_t) epoch + idnum*timeSlot - currentEpochTime;


	ev.printf("Current Time: %1.12g, time from last epoch start: %1.12g, last epoch started at: %1.12g, next epoch starts at: %1.12g, my id: %d, my transmission time will be in %1.12g secs\n", SIMTIME_DBL(simTime()), currentEpochTime, SIMTIME_DBL(simTime())-currentEpochTime, SIMTIME_DBL(simTime())-currentEpochTime+epoch, idnum, SIMTIME_DBL(result));

	return result;

}

void MAC_TDMA::prepareReTX(){

	opp_error("TDMA should not arrive to prepareReTX.\n");

}

void MAC_TDMA::commitTX() {

	MACqueue.pop();
	txToCommit = 0;

}

ElectronicMessage* MAC_TDMA::handleCollision(int type, NetworkAddress* source){

	opp_error("Collision should not be occuring in TDMA scheme. Aborting.");
	return NULL;

}

ElectronicMessage* MAC_TDMA::confirmRX(ElectronicMessage* rcvdMsg) {

	return NULL;

}
bool MAC_TDMA::ackArrived(){

	opp_error("TDMA should not arrive to ackArrived.\n");

}

simtime_t MAC_TDMA::getTimeout() {

	opp_error("TDMA should not arrive to getTimeout.\n");

}



