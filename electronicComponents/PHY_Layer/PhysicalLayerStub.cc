

#include "PhysicalLayer.h"
#include "PhysicalLayerStub.h"
#include "statistics.h"
#include "math.h"




Define_Module(PhysicalLayerStub)
;


PhysicalLayerStub::PhysicalLayerStub() {

}

PhysicalLayerStub::~PhysicalLayerStub() {

}

void PhysicalLayerStub::initialize() {

    PhysicalLayer::initialize();

    endRxMsg = new cMessage("endRxMsg");

}

void PhysicalLayerStub::finish() {

    PhysicalLayer::finish();

    cancelAndDelete(endRxMsg);
}

void PhysicalLayerStub::handleMessage(cMessage *msg) {

    if (msg->isSelfMessage()) {
        send(MsgIn, "phyToMac");
        // ev << "Msg rx: sending to MAC" << endl;
    } else if (msg->arrivedOn("fromNet")) {
        MsgIn = check_and_cast<ElectronicMessage*> (msg);
        if (endRxMsg->isScheduled()) {
            EV << "Error! ";
        }
        EV << "PHY: MissatgeRebut " << MsgIn->getDuration() << endl;
        scheduleAt(simTime() + MsgIn->getDuration(),endRxMsg);
        // ev << "Incoming message" << endl;
    } else if (msg->arrivedOn("deadEnd")) {
       delete msg;

    }
	// MISSATGE DE MAC
	else {
	    ElectronicMessage* aux = check_and_cast<ElectronicMessage*> (msg);
	    ev << "PHY: Sending message: " << aux->getBitLength() << endl;
	    sendIt(msg, channelCapacity);

	}
}



