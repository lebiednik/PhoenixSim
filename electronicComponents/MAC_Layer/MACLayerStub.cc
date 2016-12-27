
#include "MACLayer.h"
#include "MACLayerStub.h"
#include "statistics.h"


// include tots els fitxers de MAC


Define_Module(MACLayerStub)
;


MACLayerStub::MACLayerStub() {

}

MACLayerStub::~MACLayerStub() {

}

void MACLayerStub::initialize() {
    MACLayer::initialize();

    timeout = par("timeoutWireless");
    backOffPeriod = par("backOffPeriod");
    pPersistent = par("pPersistent");
    negativeACKs = par("negativeACKs");

    clockRate = (double) par("O_frequency_data");
    clockPeriod = 1.0 / clockRate;


    nackDetected = false;

}



void MACLayerStub::finish() {
    MACLayer::finish();


}


void MACLayerStub::handleMessage(cMessage *msg) {

    //ElectronicMessage *emsg = check_and_cast<ElectronicMessage*> (msg);
    //delete msg;

    //send(msg,"toNic");

    //return;

   // for (int i = 0; i < 1023; i++) {
   //     send(msg->dup(),"toNic");
   // }


    if (msg->arrivedOn("fromPhy")) {
        ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);
        send(MsgIn,"toNic");
    }

    // MISSATGES DE INTERFICIE (tots son de dades)
    else {
        send(msg,"macToPhy");
    }

	
}
