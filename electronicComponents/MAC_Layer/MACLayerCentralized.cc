
#include "MACLayer.h"
#include "MACLayerCentralized.h"
#include "statistics.h"


// include tots els fitxers de MAC


Define_Module(MACLayerCentralized)
;


MACLayerCentralized::MACLayerCentralized() {

}

MACLayerCentralized::~MACLayerCentralized() {

}

void MACLayerCentralized::initialize() {
    MACLayer::initialize();

    timeout = par("timeoutWireless");
    backOffPeriod = par("backOffPeriod");
    pPersistent = par("pPersistent");
    negativeACKs = par("negativeACKs");

    clockRate = (double) par("O_frequency_data");
    clockPeriod = 1.0 / clockRate;


    nackDetected = false;

}



void MACLayerCentralized::finish() {
    MACLayer::finish();


}


void MACLayerCentralized::handleMessage(cMessage *msg) {



    // MISSATGES DE: CAPA FISICA
    if (msg->arrivedOn("fromPhy")) {
        EV << "MAC: Missatge rebut de PHY, enviam a NIF" << endl;
        ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);
        send(MsgIn,"toNic");
    }

    // MISSATGES DE: CONTROLADOR MAC
    else  if (msg->arrivedOn("controllerToMac")) {
        EV << "MAC: Permis rebut de controller, enviem a PHY" << endl;

        //HACK
        ElectronicMessage *aux = check_and_cast<ElectronicMessage*> (msg);
        int len = aux->getBitLength();

        queue<ElectronicMessage*> tempQueue;
        while (MACqueue.front()->getBitLength() != len) {
            tempQueue.push(MACqueue.front());
            MACqueue.pop();
        }
        // Actual send
        send(MACqueue.front(),"macToPhy");
        MACqueue.pop();
        // Restablish queue
        while(not tempQueue.empty()) {
            MACqueue.push(tempQueue.front());
            tempQueue.pop();
        }
        delete msg;
    }

    // MISSATGES DE: INTERFICIE (tots son de dades)
    else {
        ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);
        EV << "MAC: Missatge rebut de NIF, demanem permis a controller: " <<  MsgIn->getBitLength() << endl;
        notifyController(idnum, (int) MsgIn->getBitLength());
        MACqueue.push(MsgIn);
    }

	
}


void MACLayerCentralized::notifyController(int idnum, int bitLength ) {

    // TODO

    int numLevels = 3;
    int procConc = 1;

    ElectronicMessage *msg = new ElectronicMessage();
    msg->setMsgType(idnum);
   // msg->setDuration(duration);
    msg->setBitLength(bitLength);

    // SET SOURCE
    stringstream ss1;
    ss1 << "";
    ss1 << idnum / procConc;
    ss1 << ".0.";
    ss1 << idnum % procConc << ".";
    NetworkAddress* srcAddr = new NetworkAddress(ss1.str(), numLevels);
    msg->setSrcId((long) srcAddr);

    // SET DESTINATION
    int dst = 0;
    stringstream ss2;
    ss2 << "";
    ss2 << dst / procConc;
    ss2 << ".0.";
    ss2 << dst % procConc << ".";
    NetworkAddress* dstAddr = new NetworkAddress(ss2.str(), numLevels);
    msg->setDstId((long) dstAddr);

    sendDelayed(msg, 0*clockPeriod,"macToController");
    //send(msg,"macToController");
}
