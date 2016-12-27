//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
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



#include "HybridController.h"

#include "packetstat.h"
#include <math.h>

Define_Module( HybridController);

HybridController::HybridController() {
    // TODO Auto-generated constructor stub

}

HybridController::~HybridController() {
    // TODO Auto-generated destructor stub
}


void HybridController::initialize() {


    procReqIn = gate("procReq$i");
    procReqOut = gate("procReq$o");
    fromProc = gate("fromProc");
    toProc = gate("toProc");
    WprocReqIn = gate("WprocReq$i");
    WprocReqOut = gate("WprocReq$o");
    EprocReqIn = gate("EprocReq$i");
    EprocReqOut = gate("EprocReq$o");
    WfromProc = gate("WfromProc");
    EfromProc = gate("EfromProc");
    WtoProc = gate("WtoProc");
    EtoProc = gate("EtoProc");

    concentration = par("processorConcentration");

    //nextMsg = new cMessage();

    sentRequest = false;

    //completeMsg = new cMessage();

    // init(){

    stalled = false;
    flitWidth = par("electronicChannelWidth");
    clockPeriod_packet = 1.0 / double(par("O_frequency_cntrl"));

    numCoresX = par("numOfNodesX");
    coreSizeX = par("coreSizeX");
    range = par("range");
    fraction = par("fraction");
    id = par("id");

    //sendPacketMsg = new cMessage("send Packet Message");

    hNIFtype = par("hNIFtype");

    // init_packet(){
    //currData = NULL;

    maxPacketSize = par("maxPacketSize");

    lastOut = -1;

    wirelessOpen = 1;

    diverted = Statistics::registerStat("Diverted Packets", StatObject::TOTAL, "MAC");


}

void HybridController::finish() { // OK

/*  if (nextMsg->isScheduled()) {
        cancelEvent(nextMsg);
    }
    delete nextMsg;

    if (completeMsg->isScheduled()) {
            cancelEvent(completeMsg);
        }
    delete completeMsg;
*/

}


void HybridController::handleMessage(cMessage* msg) { // OK

    cGate* arrivalGate = msg->getArrivalGate();

    // Does the controller schedule self-messages?
    if (msg->isSelfMessage()) {
    /*  if (msg == nextMsg) {
            controller();
        } else if(msg == completeMsg){
            complete();
            controller();
        }
        else {
            selfMsgArrived(msg);
        } */

    // From processor request port
    } else if (arrivalGate == procReqIn) {

        RouterCntrlMsg* rmsg = check_and_cast<RouterCntrlMsg*> (msg);
        requestMsgArrived(rmsg);

    // From processor data port
    } else if (arrivalGate == fromProc) {

        ProcessorData* pdata = check_and_cast<ProcessorData*> (msg);
        procMsgArrived(pdata);

    // From the network data port: we will just bypass it into the processor
    } else if (arrivalGate == WtoProc || arrivalGate == EtoProc){

        ProcessorData* pdata = check_and_cast<ProcessorData*> (msg);
        int tt = pdata->getType();

        if(tt == hybridBlockW) {
            wirelessOpen = 0;
            delete pdata;
            return;
        } else if (tt == hybridUnblockW) {
            wirelessOpen = 1;
            delete pdata;
            return;
        }

        int switchP = pdata->getSwitchPlanes();
        NetworkAddress* dest = (NetworkAddress*) pdata->getDestAddr();
        int rx = dest->id[AddressTranslator::convertLevel("NET")];

        // TODO: make the ACKS or NACKS or whatever that needs to switch planes use the switchP functionality instead.
        if(arrivalGate == WtoProc && (tt==wireless_ACK||tt==wireless_NACK||switchP==1)) {
            //fprintf(stderr,"%.12f: Switching planes, from W to E.\n",simTime().dbl());
            pdata->setSwitchPlanes(0);
            //if(simTime().dbl() - lastOut < clockPeriod_packet/2) opp_error("lastOut: %.12f, simtime %.12f, diff %.12f, period %.12f. Two messages coming going to E within the same cycle.\n", lastOut, simTime().dbl(),simTime().dbl()-lastOut, clockPeriod_packet/2);
              //                  lastOut = simTime().dbl();
            if(simTime().dbl() - lastOut < clockPeriod_packet) {
                sendDelayed(pdata, clockPeriod_packet, "EfromProc");
                lastOut = simTime().dbl() + clockPeriod_packet;
            } else {
                send(pdata,"EfromProc");  // retornar a wNIF, ha de passar per controller i després eNIF
                lastOut = simTime().dbl();
            }

        } else if(arrivalGate == EtoProc && (tt==wireless_ACK||tt==wireless_NACK||switchP==1)) {
            //fprintf(stderr,"%.12f: Switching planes, from E to W.\n",simTime().dbl());
            pdata->setSwitchPlanes(0);
            send(pdata,WfromProc);
        } else
            send(msg,toProc);

    // From the network request port: remember which NIF did send it.
    } else if (arrivalGate == WprocReqIn || arrivalGate == EprocReqIn){

        RouterCntrlMsg* rrmsg = check_and_cast<RouterCntrlMsg*> (msg);

        if(rrmsg->getType() == proc_req_send){

            if(arrivalGate == WprocReqIn){
                // EVCON ev.printf("Pushing true\n");
                isWireless.push(true);
            } else {
                // EVCON ev.printf("Pushing false\n");
                isWireless.push(false);
            }

        }

        send(msg,procReqOut);

    }

}

void HybridController::procMsgArrived(ProcessorData* pdata) {

    NetworkAddress* dest = NULL;
    NetworkAddress* src = NULL;
    int tx, rx;
    int rndm;
    int distance;

    // Decide to which NIF it needs to be sent and do it.
    switch(hNIFtype) {

        case 0: // Everything goes through the WIRELESS PLANE
            send(pdata,WfromProc);
            break;
        case 1: // Everything goes through the ELECTRONIC PLANE
            send(pdata,EfromProc);
            break;
        case 2: // Broadcasts through W, the rest through E3
            rndm = intuniform(0,100);
            if(pdata->getType() == snoopReq && rndm < fraction && wirelessOpen == 0)
                diverted->track(1);

            if(pdata->getType() == snoopReq && rndm < fraction && wirelessOpen == 1) {
                // EVCON ev.printf("This is broadcast, send it through Wireless. \n");
                send(pdata,WfromProc);
            } else {
                // EVCON ev.printf("This is unicast, send it through Electrical. \n");
                //if(simTime().dbl() - lastOut < clockPeriod_packet/2) opp_error("lastOut: %.12f, simtime %.12f, diff %.12f, period %.12f. Two messages coming going to E within the same cycle.\n", lastOut, simTime().dbl(),simTime().dbl()-lastOut, clockPeriod_packet/2);
                //lastOut = simTime().dbl();
                if(simTime().dbl() - lastOut < clockPeriod_packet) {
                    sendDelayed(pdata, clockPeriod_packet, "EfromProc");
                    lastOut = simTime().dbl() + clockPeriod_packet;
                } else {
                    send(pdata,"EfromProc");
                    lastOut = simTime().dbl();
                }
            }
            break;
        case 3: //If distance is above a certain threshold (average hop count?), do it through W
            dest = (NetworkAddress*) pdata->getDestAddr();
            src = (NetworkAddress*) pdata->getSrcAddr();
            tx = src->id[AddressTranslator::convertLevel("NET")];
            rx = dest->id[AddressTranslator::convertLevel("NET")];
            distance = calcDist(tx,rx);

            if(distance > range && wirelessOpen == 0)
                diverted->track(1);

            if(distance > range && wirelessOpen == 1){
                // EVCON ev.printf("Distance is above threshold, send it through Wireless. \n");
                send(pdata,WfromProc);
            } else {
                // EVCON ev.printf("Distance is below threshold, send it through Electrical. \n");
                //if(simTime().dbl() - lastOut < clockPeriod_packet/2) opp_error("lastOut: %.12f, simtime %.12f, diff %.12f, period %.12f. Two messages coming going to E within the same cycle.\n", lastOut, simTime().dbl(),simTime().dbl()-lastOut, clockPeriod_packet/2);
                //lastOut = simTime().dbl();
                if(simTime().dbl() - lastOut < clockPeriod_packet) {
                    sendDelayed(pdata, clockPeriod_packet, "EfromProc");
                    lastOut = simTime().dbl() + clockPeriod_packet;
                } else {
                    send(pdata,"EfromProc");
                    lastOut = simTime().dbl();
                }
            }


            break;
        case 4: //Broadcast + If distance is above a certain threshold (average hop count?), do it through W
            if(pdata->getType() == snoopReq) {
                // EVCON ev.printf("This is broadcast, send it through Wireless. \n");
                send(pdata,WfromProc);
            } else {
                dest = (NetworkAddress*) pdata->getDestAddr();
                src = (NetworkAddress*) pdata->getSrcAddr();
                tx = src->id[AddressTranslator::convertLevel("NET")];
                rx = dest->id[AddressTranslator::convertLevel("NET")];
                if(calcDist(tx,rx) < range){
                    // EVCON ev.printf("Unicast + Distance is below threshold, send it through Electrical. \n");
                    //if(simTime().dbl() - lastOut < clockPeriod_packet/2) opp_error("lastOut: %.12f, simtime %.12f, diff %.12f, period %.12f. Two messages coming going to E within the same cycle.\n", lastOut, simTime().dbl(),simTime().dbl()-lastOut, clockPeriod_packet/2);
                    //lastOut = simTime().dbl();
                    if(simTime().dbl() - lastOut < clockPeriod_packet) {
                        sendDelayed(pdata, clockPeriod_packet, "EfromProc");
                        lastOut = simTime().dbl() + clockPeriod_packet;
                    } else {
                        send(pdata,"EfromProc");
                        lastOut = simTime().dbl();
                    }
                } else {
                    // EVCON ev.printf("Unicast but distance is above threshold, send it through Wireless. \n");
                    send(pdata,WfromProc);
                }
            }
            break;
        default: send(pdata,WfromProc);

    }

}

void HybridController::requestMsgArrived(RouterCntrlMsg* rmsg) {  // 1 TODO

    // If it's a sending request, immediately grant
    if (rmsg->getType() == proc_req_send) {

        RouterCntrlMsg* gr = new RouterCntrlMsg();
        gr->setType(proc_grant);
        // EVCON ev.printf("Proc_Send arrived to the hNIF, granting...\n");
        send(gr, procReqOut);
        delete rmsg;

    // If it's a processor grant, we will relay it to its corresponding NIF
    } else if (rmsg->getType() == proc_grant) {

        // If using hybrid: delay both "clockPeriod_packet/2"
        if(isWireless.front()){
            // EVCON ev.printf("Grant came from wireless NIF, relaying it to him.\n");
            sendDelayed(rmsg, 0, WprocReqOut);
        } else {
            // EVCON ev.printf("Grant came from electronic NIF, relaying it to him.\n");
            sendDelayed(rmsg, 0, EprocReqOut);
        }
        // EVCON ev.printf("Popping.\n");
        isWireless.pop();


    }


}

// Calculation of the hop distance between emitter and receiver.
int HybridController::calcDist(int emitter, int receiver){

    int distX;
    int distY;

    distY = abs(floor(emitter/numCoresX) - floor(receiver/numCoresX));
    distX = abs(emitter % numCoresX - receiver % numCoresX);

    return (distX+distY);


}
