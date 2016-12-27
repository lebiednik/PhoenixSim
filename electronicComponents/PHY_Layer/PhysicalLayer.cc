

#include "PhysicalLayer.h"
#include "statistics.h"
#include "math.h"




Define_Module(PhysicalLayer)
;


PhysicalLayer::PhysicalLayer() {

}

PhysicalLayer::~PhysicalLayer() {

}

void PhysicalLayer::initialize() {

	gate("fromNet")->setDeliverOnReceptionStart(TRUE);

	type = par("type");
	idnum = par("idnum");
	numOfNodesX = par("numOfNodesX");
	coreSizeX = par("coreSizeX");
	numX = par("numX");
	numY = par("numY");
	channelCapacity = par("channelCapacity");

	deltaSim = 1.0/SimTime::getScale();


	// ini distances
	distances.reserve(numOfNodesX*numOfNodesX);
	for (int i = 0; i < numOfNodesX*numOfNodesX; i++)   {
	    distances[i] = calcDist(i);
	}


}

void PhysicalLayer::finish() {


}



void PhysicalLayer::handleMessage(cMessage *msg) {

}

// Returns transmission time.
// For CBUF and TOKEN only
// For an implementation for CSMA, check """simtime_t PhysicalLayerBRS::sendIt(cMessage *msg, double dataRate)"""
simtime_t PhysicalLayer::sendIt(cMessage *msg, double dataRate){

    ElectronicMessage *MsgToSend = check_and_cast<ElectronicMessage*> (msg);

//  NetworkAddress* destAdr = (NetworkAddress*) MsgToSend->getDstId();
    NetworkAddress* srcAdr = (NetworkAddress*) MsgToSend->getSrcId();
//  int dest = destAdr->id[AddressTranslator::convertLevel("NET")];
    int src = srcAdr->id[AddressTranslator::convertLevel("NET")];

    double pktSize = MsgToSend->getBitLength();
    simtime_t full_t = (simtime_t)(pktSize/dataRate);

    cModule *targetModule;
    for (int i=0; i<src; i++)   {
        ElectronicMessage *copy = MsgToSend->dup();
        targetModule = getParentModule()->getParentModule()->getSubmodule("node",i);
        simtime_t prop_t = (simtime_t)(distances[i]/3e8 + deltaSim);
        sendDirect(copy, prop_t, full_t - prop_t, targetModule, "radioIn");
    }

    for (int j=src+1; j<numOfNodesX*numOfNodesX; j++)   {
        ElectronicMessage *copy = MsgToSend->dup();
        targetModule = getParentModule()->getParentModule()->getSubmodule("node",j);
        simtime_t prop_t = (simtime_t)(distances[j]/3e8 + deltaSim);
        sendDirect(copy, prop_t, full_t - prop_t, targetModule, "radioIn");
    }
    delete MsgToSend;

    return full_t;
}
//*/





double PhysicalLayer::calcDist(int dest){
	// Returns the distance between nodes in meters

    int destX = dest % numOfNodesX;
    int destY = floor(dest/numOfNodesX);

	// ev.printf("Distance between [%d,%d] and [%d,%d]: %f. Prop time: %1.12g\n",numX,numY,destX,destY,sqrt( pow((destX-numX)*coreSizeX,2) + pow((destY-numY)*coreSizeX,2) ) / 1000000,sqrt( pow((destX-numX)*coreSizeX,2) + pow((destY-numY)*coreSizeX,2) ) / 1000000 / 3e8);
	return sqrt( pow((destX-numX)*coreSizeX,2) + pow((destY-numY)*coreSizeX,2) ) / 1000000;


}


void PhysicalLayer::notifyMAC(int notification, long source){
	ElectronicMessage *msg = new ElectronicMessage();
	msg->setMsgType(notification);
	msg->setSrcId(source);
	send(msg,"phyToMac");
}





//Inicialitzar estadístiques?

/*
string statName = "Wireless Transceiver";
P_static = Statistics::registerStat(statName, StatObject::ENERGY_STATIC,
        "wireless");
E_dynamic = Statistics::registerStat(statName, StatObject::ENERGY_EVENT,
        "wireless");

// Static power of the transceiver is reported here (leakage?)
P_static->track(staticTranscPwr);

StatObject *E_count = Statistics::registerStat("Wireless Transceiver",
        StatObject::COUNT, "wireless");
*/
