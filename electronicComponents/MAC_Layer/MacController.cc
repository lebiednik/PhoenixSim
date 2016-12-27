//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <MacController.h>


Define_Module(MacController);


MacController::MacController() {
    // TODO Auto-generated constructor stub

}

MacController::~MacController() {
    // TODO Auto-generated destructor stub
}


void MacController::initialize() {



    numOfNodesX = par("numOfNodesX");
    numOfNodesY = par("numOfNodesY");
    channelCapacity = par("channelCapacity");
    dieSize = par("dieSize");

    clockRate = (double) par("O_frequency_data");
    clockPeriod = 1.0 / clockRate;



    busyChannel = new cMessage("busyChannel");

    maxTau = (sqrt(2*dieSize)/1e3)/3e8;   // tau [s]



}



void MacController::finish() {
    cancelAndDelete(busyChannel);

}

void MacController::handleMessage(cMessage *msg) {



    if (msg->isSelfMessage()) {

        nodeQueue.pop();
        lengthQueue.pop();
        durationQueue.pop();

        EV << "Controller: Missatge considerat enviat (cua: " << nodeQueue.size() << ")" << endl;


        if (not nodeQueue.empty()) {
            int id = nodeQueue.front();
            double duration = durationQueue.front().dbl();
            int authoritzedLenth = lengthQueue.front();

            EV << "Controller: Donem permis a MAC per enviar MSG encuat (" << id << ") " << endl;

            notifyNode(id, authoritzedLenth);
            scheduleAt(simTime() + duration, busyChannel);

        }


    }
    else if (msg->arrivedOn("portInC$i")) {
        ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);

        int id = MsgIn->getMsgType();
        double pSize = (double) MsgIn->getBitLength();
        simtime_t duration = (simtime_t) (pSize/channelCapacity); // + maxTau);

        // ACK to router (?)
        BufferAckMsg* ack = new BufferAckMsg();
        ack->setMsgType(router_bufferAck);
        ack->setData(pSize);
        ack->setVirtualChannel(MsgIn->getVirtualChannel());
        ack->setBitLength(1);
        ack->setKind(2);
        send(ack, "portInC$o");

        // Queue or simply send "clear to send" to node.
        if (not busyChannel->isScheduled() && nodeQueue.empty()) {
            EV << "Controller: Donem permis a MAC per enviar MSG ( " << pSize << " )" << endl;

            int authoritzedLenth = (int) pSize;
            notifyNode(id, authoritzedLenth);
            scheduleAt(simTime() + duration, busyChannel);
        }
        nodeQueue.push(id);
        lengthQueue.push(pSize);
        durationQueue.push(duration);

        EV << "Controller: Peticio rebuda de MAC (" << id << "), encuem (cua: " << nodeQueue.size() << ") [" << pSize << "]" << endl;
        delete msg;



    }
    else {
        opp_error("Interficies incorrectes");
    }


}

void MacController::notifyNode(int idNum, int autLength) {

    int numLevels = 3;
    int procConc = 1;

    ElectronicMessage *msg = new ElectronicMessage();
    msg->setMsgType(idNum);
    msg->setBitLength(autLength);

    // SET SOURCE
    stringstream ss1;
    ss1 << "";
    ss1 << idnum / procConc;
    ss1 << ".0.";
    ss1 << idnum % procConc << ".";
    NetworkAddress* srcAddr = new NetworkAddress(ss1.str(), numLevels);
    msg->setSrcId((long) srcAddr);

    //msg->setBitLength(16);
    sendDelayed(msg, 0*clockPeriod, "portOutC", idNum);
}
