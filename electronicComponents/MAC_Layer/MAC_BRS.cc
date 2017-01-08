
#include "MACLayer.h"
#include "MAC_BRS.h"
#include "statistics.h"


// include tots els fitxers de MAC


Define_Module(MAC_BRS)
;


MAC_BRS::MAC_BRS() {

}

MAC_BRS::~MAC_BRS() {

}

void MAC_BRS::initialize() {
    MACLayer::initialize();

    timeout = par("timeoutWireless");
    backOffPeriod = par("backOffPeriod");
    pPersistent = par("pPersistent");
    negativeACKs = par("negativeACKs");

    // HACK
    channelCapacity = par("channelCapacity");
    // END HACK

    clockRate = (double) par("O_frequency_data");
    clockPeriod = 1.0 / clockRate;


    inMsg = NULL;
    nackDetected = false;

    state = LISTENING;

    nRetries = 0;
    value = 0;

    discarded = Statistics::registerStat("Discarded Packets", StatObject::TOTAL, "MAC");
    switched = Statistics::registerStat("Switched Packets", StatObject::TOTAL, "MAC");
    collisions = Statistics::registerStat("Number of Collisions", StatObject::TOTAL, "MAC");
    collisions00 = Statistics::registerStat("Collisions node 00", StatObject::TOTAL, "MAC");
    collisions01 = Statistics::registerStat("Collisions node 01", StatObject::TOTAL, "MAC");
    collisions02 = Statistics::registerStat("Collisions node 02", StatObject::TOTAL, "MAC");
    collisions03 = Statistics::registerStat("Collisions node 03", StatObject::TOTAL, "MAC");
    collisions04 = Statistics::registerStat("Collisions node 04", StatObject::TOTAL, "MAC");
    collisions05 = Statistics::registerStat("Collisions node 05", StatObject::TOTAL, "MAC");
    collisions06 = Statistics::registerStat("Collisions node 06", StatObject::TOTAL, "MAC");
    collisions07 = Statistics::registerStat("Collisions node 07", StatObject::TOTAL, "MAC");
    collisions08 = Statistics::registerStat("Collisions node 08", StatObject::TOTAL, "MAC");
    collisions09 = Statistics::registerStat("Collisions node 09", StatObject::TOTAL, "MAC");
    collisions10 = Statistics::registerStat("Collisions node 10", StatObject::TOTAL, "MAC");
    collisions11 = Statistics::registerStat("Collisions node 11", StatObject::TOTAL, "MAC");
    collisions12 = Statistics::registerStat("Collisions node 12", StatObject::TOTAL, "MAC");
    collisions13 = Statistics::registerStat("Collisions node 13", StatObject::TOTAL, "MAC");
    collisions14 = Statistics::registerStat("Collisions node 14", StatObject::TOTAL, "MAC");
    collisions15 = Statistics::registerStat("Collisions node 15", StatObject::TOTAL, "MAC");
    collisions16 = Statistics::registerStat("Collisions node 16", StatObject::TOTAL, "MAC");
    collisions17 = Statistics::registerStat("Collisions node 17", StatObject::TOTAL, "MAC");
    collisions18 = Statistics::registerStat("Collisions node 18", StatObject::TOTAL, "MAC");
    collisions19 = Statistics::registerStat("Collisions node 19", StatObject::TOTAL, "MAC");
    collisions20 = Statistics::registerStat("Collisions node 20", StatObject::TOTAL, "MAC");
    collisions21 = Statistics::registerStat("Collisions node 21", StatObject::TOTAL, "MAC");
    collisions22 = Statistics::registerStat("Collisions node 22", StatObject::TOTAL, "MAC");
    collisions23 = Statistics::registerStat("Collisions node 23", StatObject::TOTAL, "MAC");
    collisions24 = Statistics::registerStat("Collisions node 24", StatObject::TOTAL, "MAC");
    collisions25 = Statistics::registerStat("Collisions node 25", StatObject::TOTAL, "MAC");
    collisions26 = Statistics::registerStat("Collisions node 26", StatObject::TOTAL, "MAC");
    collisions27 = Statistics::registerStat("Collisions node 27", StatObject::TOTAL, "MAC");
    collisions28 = Statistics::registerStat("Collisions node 28", StatObject::TOTAL, "MAC");
    collisions29 = Statistics::registerStat("Collisions node 29", StatObject::TOTAL, "MAC");
    collisions30 = Statistics::registerStat("Collisions node 30", StatObject::TOTAL, "MAC");
    collisions31 = Statistics::registerStat("Collisions node 31", StatObject::TOTAL, "MAC");
    collisions32 = Statistics::registerStat("Collisions node 32", StatObject::TOTAL, "MAC");
    collisions33 = Statistics::registerStat("Collisions node 33", StatObject::TOTAL, "MAC");
    collisions34 = Statistics::registerStat("Collisions node 34", StatObject::TOTAL, "MAC");
    collisions35 = Statistics::registerStat("Collisions node 35", StatObject::TOTAL, "MAC");
    collisions36 = Statistics::registerStat("Collisions node 36", StatObject::TOTAL, "MAC");
    collisions37 = Statistics::registerStat("Collisions node 37", StatObject::TOTAL, "MAC");
    collisions38 = Statistics::registerStat("Collisions node 38", StatObject::TOTAL, "MAC");
    collisions39 = Statistics::registerStat("Collisions node 39", StatObject::TOTAL, "MAC");
    collisions40 = Statistics::registerStat("Collisions node 40", StatObject::TOTAL, "MAC");
    collisions41 = Statistics::registerStat("Collisions node 41", StatObject::TOTAL, "MAC");
    collisions42 = Statistics::registerStat("Collisions node 42", StatObject::TOTAL, "MAC");
    collisions43 = Statistics::registerStat("Collisions node 43", StatObject::TOTAL, "MAC");
    collisions44 = Statistics::registerStat("Collisions node 44", StatObject::TOTAL, "MAC");
    collisions45 = Statistics::registerStat("Collisions node 45", StatObject::TOTAL, "MAC");
    collisions46 = Statistics::registerStat("Collisions node 46", StatObject::TOTAL, "MAC");
    collisions47 = Statistics::registerStat("Collisions node 47", StatObject::TOTAL, "MAC");
    collisions48 = Statistics::registerStat("Collisions node 48", StatObject::TOTAL, "MAC");
    collisions49 = Statistics::registerStat("Collisions node 49", StatObject::TOTAL, "MAC");
    collisions50 = Statistics::registerStat("Collisions node 50", StatObject::TOTAL, "MAC");
    collisions51 = Statistics::registerStat("Collisions node 51", StatObject::TOTAL, "MAC");
    collisions52 = Statistics::registerStat("Collisions node 52", StatObject::TOTAL, "MAC");
    collisions53 = Statistics::registerStat("Collisions node 53", StatObject::TOTAL, "MAC");
    collisions54 = Statistics::registerStat("Collisions node 54", StatObject::TOTAL, "MAC");
    collisions55 = Statistics::registerStat("Collisions node 55", StatObject::TOTAL, "MAC");
    collisions56 = Statistics::registerStat("Collisions node 56", StatObject::TOTAL, "MAC");
    collisions57 = Statistics::registerStat("Collisions node 57", StatObject::TOTAL, "MAC");
    collisions58 = Statistics::registerStat("Collisions node 58", StatObject::TOTAL, "MAC");
    collisions59 = Statistics::registerStat("Collisions node 59", StatObject::TOTAL, "MAC");
    collisions60 = Statistics::registerStat("Collisions node 60", StatObject::TOTAL, "MAC");
    collisions61 = Statistics::registerStat("Collisions node 61", StatObject::TOTAL, "MAC");
    collisions62 = Statistics::registerStat("Collisions node 62", StatObject::TOTAL, "MAC");
    collisions63 = Statistics::registerStat("Collisions node 63", StatObject::TOTAL, "MAC");
    discarded00 = Statistics::registerStat("discarded node 00", StatObject::TOTAL, "MAC");
    discarded01 = Statistics::registerStat("discarded node 01", StatObject::TOTAL, "MAC");
    discarded02 = Statistics::registerStat("discarded node 02", StatObject::TOTAL, "MAC");
    discarded03 = Statistics::registerStat("discarded node 03", StatObject::TOTAL, "MAC");
    discarded04 = Statistics::registerStat("discarded node 04", StatObject::TOTAL, "MAC");
    discarded05 = Statistics::registerStat("discarded node 05", StatObject::TOTAL, "MAC");
    discarded06 = Statistics::registerStat("discarded node 06", StatObject::TOTAL, "MAC");
    discarded07 = Statistics::registerStat("discarded node 07", StatObject::TOTAL, "MAC");
    discarded08 = Statistics::registerStat("discarded node 08", StatObject::TOTAL, "MAC");
    discarded09 = Statistics::registerStat("discarded node 09", StatObject::TOTAL, "MAC");
    discarded10 = Statistics::registerStat("discarded node 10", StatObject::TOTAL, "MAC");
    discarded11 = Statistics::registerStat("discarded node 11", StatObject::TOTAL, "MAC");
    discarded12 = Statistics::registerStat("discarded node 12", StatObject::TOTAL, "MAC");
    discarded13 = Statistics::registerStat("discarded node 13", StatObject::TOTAL, "MAC");
    discarded14 = Statistics::registerStat("discarded node 14", StatObject::TOTAL, "MAC");
    discarded15 = Statistics::registerStat("discarded node 15", StatObject::TOTAL, "MAC");
    discarded16 = Statistics::registerStat("discarded node 16", StatObject::TOTAL, "MAC");
    discarded17 = Statistics::registerStat("discarded node 17", StatObject::TOTAL, "MAC");
    discarded18 = Statistics::registerStat("discarded node 18", StatObject::TOTAL, "MAC");
    discarded19 = Statistics::registerStat("discarded node 19", StatObject::TOTAL, "MAC");
    discarded20 = Statistics::registerStat("discarded node 20", StatObject::TOTAL, "MAC");
    discarded21 = Statistics::registerStat("discarded node 21", StatObject::TOTAL, "MAC");
    discarded22 = Statistics::registerStat("discarded node 22", StatObject::TOTAL, "MAC");
    discarded23 = Statistics::registerStat("discarded node 23", StatObject::TOTAL, "MAC");
    discarded24 = Statistics::registerStat("discarded node 24", StatObject::TOTAL, "MAC");
    discarded25 = Statistics::registerStat("discarded node 25", StatObject::TOTAL, "MAC");
    discarded26 = Statistics::registerStat("discarded node 26", StatObject::TOTAL, "MAC");
    discarded27 = Statistics::registerStat("discarded node 27", StatObject::TOTAL, "MAC");
    discarded28 = Statistics::registerStat("discarded node 28", StatObject::TOTAL, "MAC");
    discarded29 = Statistics::registerStat("discarded node 29", StatObject::TOTAL, "MAC");
    discarded30 = Statistics::registerStat("discarded node 30", StatObject::TOTAL, "MAC");
    discarded31 = Statistics::registerStat("discarded node 31", StatObject::TOTAL, "MAC");
    discarded32 = Statistics::registerStat("discarded node 32", StatObject::TOTAL, "MAC");
    discarded33 = Statistics::registerStat("discarded node 33", StatObject::TOTAL, "MAC");
    discarded34 = Statistics::registerStat("discarded node 34", StatObject::TOTAL, "MAC");
    discarded35 = Statistics::registerStat("discarded node 35", StatObject::TOTAL, "MAC");
    discarded36 = Statistics::registerStat("discarded node 36", StatObject::TOTAL, "MAC");
    discarded37 = Statistics::registerStat("discarded node 37", StatObject::TOTAL, "MAC");
    discarded38 = Statistics::registerStat("discarded node 38", StatObject::TOTAL, "MAC");
    discarded39 = Statistics::registerStat("discarded node 39", StatObject::TOTAL, "MAC");
    discarded40 = Statistics::registerStat("discarded node 40", StatObject::TOTAL, "MAC");
    discarded41 = Statistics::registerStat("discarded node 41", StatObject::TOTAL, "MAC");
    discarded42 = Statistics::registerStat("discarded node 42", StatObject::TOTAL, "MAC");
    discarded43 = Statistics::registerStat("discarded node 43", StatObject::TOTAL, "MAC");
    discarded44 = Statistics::registerStat("discarded node 44", StatObject::TOTAL, "MAC");
    discarded45 = Statistics::registerStat("discarded node 45", StatObject::TOTAL, "MAC");
    discarded46 = Statistics::registerStat("discarded node 46", StatObject::TOTAL, "MAC");
    discarded47 = Statistics::registerStat("discarded node 47", StatObject::TOTAL, "MAC");
    discarded48 = Statistics::registerStat("discarded node 48", StatObject::TOTAL, "MAC");
    discarded49 = Statistics::registerStat("discarded node 49", StatObject::TOTAL, "MAC");
    discarded50 = Statistics::registerStat("discarded node 50", StatObject::TOTAL, "MAC");
    discarded51 = Statistics::registerStat("discarded node 51", StatObject::TOTAL, "MAC");
    discarded52 = Statistics::registerStat("discarded node 52", StatObject::TOTAL, "MAC");
    discarded53 = Statistics::registerStat("discarded node 53", StatObject::TOTAL, "MAC");
    discarded54 = Statistics::registerStat("discarded node 54", StatObject::TOTAL, "MAC");
    discarded55 = Statistics::registerStat("discarded node 55", StatObject::TOTAL, "MAC");
    discarded56 = Statistics::registerStat("discarded node 56", StatObject::TOTAL, "MAC");
    discarded57 = Statistics::registerStat("discarded node 57", StatObject::TOTAL, "MAC");
    discarded58 = Statistics::registerStat("discarded node 58", StatObject::TOTAL, "MAC");
    discarded59 = Statistics::registerStat("discarded node 59", StatObject::TOTAL, "MAC");
    discarded60 = Statistics::registerStat("discarded node 60", StatObject::TOTAL, "MAC");
    discarded61 = Statistics::registerStat("discarded node 61", StatObject::TOTAL, "MAC");
    discarded62 = Statistics::registerStat("discarded node 62", StatObject::TOTAL, "MAC");
    discarded63 = Statistics::registerStat("discarded node 63", StatObject::TOTAL, "MAC");
    backoff00 = Statistics::registerStat("Backoff Node 00(us)", StatObject::AVG,"application");
  	backoff01 = Statistics::registerStat("Backoff Node 01(us)", StatObject::AVG,"application");
  	backoff02 = Statistics::registerStat("Backoff Node 02(us)", StatObject::AVG,"application");
  	backoff03 = Statistics::registerStat("Backoff Node 03(us)", StatObject::AVG,"application");
  	backoff04 = Statistics::registerStat("Backoff Node 04(us)", StatObject::AVG,"application");
  	backoff05 = Statistics::registerStat("Backoff Node 05(us)", StatObject::AVG,"application");
  	backoff06 = Statistics::registerStat("Backoff Node 06(us)", StatObject::AVG,"application");
  	backoff07 = Statistics::registerStat("Backoff Node 07(us)", StatObject::AVG,"application");
  	backoff08 = Statistics::registerStat("Backoff Node 08(us)", StatObject::AVG,"application");
  	backoff09 = Statistics::registerStat("Backoff Node 09(us)", StatObject::AVG,"application");
  	backoff10 = Statistics::registerStat("Backoff Node 10(us)", StatObject::AVG,"application");
  	backoff11 = Statistics::registerStat("Backoff Node 11(us)", StatObject::AVG,"application");
  	backoff12 = Statistics::registerStat("Backoff Node 12(us)", StatObject::AVG,"application");
  	backoff13 = Statistics::registerStat("Backoff Node 13(us)", StatObject::AVG,"application");
  	backoff14 = Statistics::registerStat("Backoff Node 14(us)", StatObject::AVG,"application");
  	backoff15 = Statistics::registerStat("Backoff Node 15(us)", StatObject::AVG,"application");
  	backoff16 = Statistics::registerStat("Backoff Node 16(us)", StatObject::AVG,"application");
  	backoff17 = Statistics::registerStat("Backoff Node 17(us)", StatObject::AVG,"application");
  	backoff18 = Statistics::registerStat("Backoff Node 18(us)", StatObject::AVG,"application");
  	backoff19 = Statistics::registerStat("Backoff Node 19(us)", StatObject::AVG,"application");
  	backoff20 = Statistics::registerStat("Backoff Node 20(us)", StatObject::AVG,"application");
  	backoff21 = Statistics::registerStat("Backoff Node 21(us)", StatObject::AVG,"application");
  	backoff22 = Statistics::registerStat("Backoff Node 22(us)", StatObject::AVG,"application");
  	backoff23 = Statistics::registerStat("Backoff Node 23(us)", StatObject::AVG,"application");
  	backoff24 = Statistics::registerStat("Backoff Node 24(us)", StatObject::AVG,"application");
  	backoff25 = Statistics::registerStat("Backoff Node 25(us)", StatObject::AVG,"application");
  	backoff26 = Statistics::registerStat("Backoff Node 26(us)", StatObject::AVG,"application");
  	backoff27 = Statistics::registerStat("Backoff Node 27(us)", StatObject::AVG,"application");
  	backoff28 = Statistics::registerStat("Backoff Node 28(us)", StatObject::AVG,"application");
  	backoff29 = Statistics::registerStat("Backoff Node 29(us)", StatObject::AVG,"application");
  	backoff30 = Statistics::registerStat("Backoff Node 30(us)", StatObject::AVG,"application");
  	backoff31 = Statistics::registerStat("Backoff Node 31(us)", StatObject::AVG,"application");
  	backoff32 = Statistics::registerStat("Backoff Node 32(us)", StatObject::AVG,"application");
  	backoff33 = Statistics::registerStat("Backoff Node 33(us)", StatObject::AVG,"application");
  	backoff34 = Statistics::registerStat("Backoff Node 34(us)", StatObject::AVG,"application");
  	backoff35 = Statistics::registerStat("Backoff Node 35(us)", StatObject::AVG,"application");
  	backoff36 = Statistics::registerStat("Backoff Node 36(us)", StatObject::AVG,"application");
  	backoff37 = Statistics::registerStat("Backoff Node 37(us)", StatObject::AVG,"application");
  	backoff38 = Statistics::registerStat("Backoff Node 38(us)", StatObject::AVG,"application");
  	backoff39 = Statistics::registerStat("Backoff Node 39(us)", StatObject::AVG,"application");
  	backoff40 = Statistics::registerStat("Backoff Node 40(us)", StatObject::AVG,"application");
  	backoff41 = Statistics::registerStat("Backoff Node 41(us)", StatObject::AVG,"application");
  	backoff42 = Statistics::registerStat("Backoff Node 42(us)", StatObject::AVG,"application");
  	backoff43 = Statistics::registerStat("Backoff Node 43(us)", StatObject::AVG,"application");
  	backoff44 = Statistics::registerStat("Backoff Node 44(us)", StatObject::AVG,"application");
  	backoff45 = Statistics::registerStat("Backoff Node 45(us)", StatObject::AVG,"application");
  	backoff46 = Statistics::registerStat("Backoff Node 46(us)", StatObject::AVG,"application");
  	backoff47 = Statistics::registerStat("Backoff Node 47(us)", StatObject::AVG,"application");
  	backoff48 = Statistics::registerStat("Backoff Node 48(us)", StatObject::AVG,"application");
  	backoff49 = Statistics::registerStat("Backoff Node 49(us)", StatObject::AVG,"application");
  	backoff50 = Statistics::registerStat("Backoff Node 50(us)", StatObject::AVG,"application");
  	backoff51 = Statistics::registerStat("Backoff Node 51(us)", StatObject::AVG,"application");
  	backoff52 = Statistics::registerStat("Backoff Node 52(us)", StatObject::AVG,"application");
  	backoff53 = Statistics::registerStat("Backoff Node 53(us)", StatObject::AVG,"application");
  	backoff54 = Statistics::registerStat("Backoff Node 54(us)", StatObject::AVG,"application");
  	backoff55 = Statistics::registerStat("Backoff Node 55(us)", StatObject::AVG,"application");
  	backoff56 = Statistics::registerStat("Backoff Node 56(us)", StatObject::AVG,"application");
  	backoff57 = Statistics::registerStat("Backoff Node 57(us)", StatObject::AVG,"application");
  	backoff58 = Statistics::registerStat("Backoff Node 58(us)", StatObject::AVG,"application");
  	backoff59 = Statistics::registerStat("Backoff Node 59(us)", StatObject::AVG,"application");
  	backoff60 = Statistics::registerStat("Backoff Node 60(us)", StatObject::AVG,"application");
  	backoff61 = Statistics::registerStat("Backoff Node 61(us)", StatObject::AVG,"application");
  	backoff62 = Statistics::registerStat("Backoff Node 62(us)", StatObject::AVG,"application");
  	backoff63 = Statistics::registerStat("Backoff Node 63(us)", StatObject::AVG,"application");


    backoffMsg = new cMessage("backoffMsg");
    timeoutMsgTx = new cMessage("timeoutMsgTx");
    timeoutMsgRx = new cMessage("timeoutMsgRx");

    // HACK
    longMessageMsgRx = new cMessage("longMessageMsgRx");
    longMessageMsgTx = new cMessage("longMessageMsgTx");
    // END HACK

    lastOut = 0;

}



void MAC_BRS::finish() {
    MACLayer::finish();

    cancelAndDelete(backoffMsg);
    cancelAndDelete(timeoutMsgRx);
    cancelAndDelete(timeoutMsgTx);

    // HACK
    cancelAndDelete(longMessageMsgRx);
    cancelAndDelete(longMessageMsgTx);
    // END HACK
}

// TODO: poden arribar dos paquets iguals (o1 esperar no nacks)(o2 descartar rtx)

void MAC_BRS::handleMessage(cMessage *msg) {


    // MISSATGES PROPIS
    if (msg->isSelfMessage()) {

        if(msg == backoffMsg) {

            ElectronicMessage* outmsg = MACqueue.front();
            int retries = outmsg->getNumRetries();
            if (state == LISTENING) {
                //ev << "MAC: Backoff finished: start tx" << endl;
                if(outmsg->getNumRetries() == 100) opp_error("This cannot be.\n");
                send(outmsg->dup(),"macToPhy");
                state = TRANSMITTING;
                //nRetries = 0;
            }
            else {
                //ev << "MAC: Backoff finished but channel busy (State = " << state << ")" << endl;
                // Backoff si no arribem al l�mit de retries
                if(retries < 2000) {
                    //fprintf(stderr,"%.12f: Unsuccessful backoff. Changing packet retries to %d.\n",simTime().dbl(),retries+1);
                    outmsg->setNumRetries(retries+1);
                    setBackOff();
                // en el l�mit, el volem enviar per l'eNIF.
                } else {
                    //fprintf(stderr,"%.12f: Unsuccessful backoff. Packet retries is %d. Switching planes.\n",simTime().dbl(),retries);
                    outmsg->setNumRetries(100);
                    if(simTime().dbl() - lastOut < clockPeriod) {
                        sendDelayed(outmsg->dup(), clockPeriod, "toNic");
                        lastOut = simTime().dbl() + clockPeriod;
                    } else {
                        send(outmsg->dup(),"toNic");  // retornar a wNIF, ha de passar per controller i despr�s eNIF
                        lastOut = simTime().dbl();
                    }
                    delete outmsg;
                    MACqueue.pop(); // TODO: comprovar que realment cal.
                    setBackOff();// backoff mirar� si la cua MAC est� buida o no i actuar� en conseq��ncia.
                    switched->track(1);
                }


            }

        }

        // HACK MODIFIED
        else if(msg == timeoutMsgRx){
            //ev << "MAC: Time out RX finished";
            if (nackDetected) {
                //ev << ": Collisio detectada" << endl;
                if (inMsg != NULL) {
                    delete inMsg;
                }
                inMsg = NULL;
                notifyPHY(stopNACKperiod);
                state = LISTENING;
            }

            else {
                 // We make the transmission overhead progressively higher as capacities go down
                double shortTxTime = 128 / channelCapacity;
                double duration = inMsg->getBitLength()/channelCapacity;
                simtime_t remainder;
                if (shortTxTime <= 2.0*clockPeriod) { // MissatgeLlarg
                    remainder = duration - clockPeriod;
                } else if(shortTxTime < 10.0*clockPeriod) {
                    remainder = duration;
                } else if(shortTxTime < 20.0*clockPeriod) {
                    remainder = duration + clockPeriod;
                } else {
                    remainder = duration + 2*clockPeriod;
                }
                scheduleAt(simTime() + remainder, longMessageMsgRx);

            }
        }
        else if(msg == longMessageMsgRx) {
            //ev << "   longer message, end hack" << endl;
            if(inMsg->getNumRetries() == 100) opp_error("This cannot be.\n");
            if(simTime().dbl() - lastOut < clockPeriod) {
                sendDelayed(inMsg, clockPeriod, "toNic");
                lastOut = simTime().dbl() + clockPeriod;
            } else {
                send(inMsg,"toNic");
                lastOut = simTime().dbl();
            }
            inMsg = NULL;
            notifyPHY(stopNACKperiod);
            state = LISTENING;
        }

        // HACK TX
        else if(msg == timeoutMsgTx){
            ElectronicMessage* m = MACqueue.front();
            //ev << "MAC: Time out Tx finished";
            if (nackDetected) { // after collision, set retry.
                int retries = m->getNumRetries();
                if(retries < 2000) {
                    //fprintf(stderr,"%.12f: Collision. Changing packet retries to %d.\n",simTime().dbl(),retries+1);
                    m->setNumRetries(retries+1);
                    setBackOff();
                    // en el l�mit, el volem enviar per l'eNIF.
                } else {
                    //fprintf(stderr,"%.12f: Collision. Packet retries is %d. Switching planes.\n",simTime().dbl(),retries);
                    m->setNumRetries(100);
                    if(simTime().dbl() - lastOut < clockPeriod) {
                        sendDelayed(m->dup(), clockPeriod, "toNic");
                        lastOut = simTime().dbl() + clockPeriod;
                    } else {
                        send(m->dup(),"toNic");  // retornar a wNIF, ha de passar per controller i despr�s eNIF
                        lastOut = simTime().dbl();
                    }
                    delete m;
                    MACqueue.pop(); // TODO: comprovar que realment cal.
                    setBackOff();// backoff mirar� si la cua MAC est� buida o no i actuar� en conseq��ncia.
                    switched->track(1);
                }
                notifyPHY(stopNACKperiod);
                state = LISTENING;
            }
            else {
               // We make the transmission overhead progressively higher as capacities go down
               double shortTxTime = 128 / channelCapacity;
               double duration = m->getBitLength()/channelCapacity;
               simtime_t remainder;
               if (shortTxTime <= 2.0*clockPeriod) { // MissatgeLlarg
                   remainder = duration - clockPeriod;
               } else if(shortTxTime < 10.0*clockPeriod) {
                   remainder = duration;
               } else if(shortTxTime < 20.0*clockPeriod) {
                   remainder = duration + clockPeriod;
               } else {
                   remainder = duration + 2*clockPeriod;
               }
               //fprintf(stderr, "%.12f: First cycle of msg %d transmitted successfully. Now transmitting the remaining %.2f cycles.\n",simTime().dbl(),m->getId(),remainder.dbl()*clockRate);
               scheduleAt(simTime() + remainder, longMessageMsgTx);


             //   else {
             //       delete m;
              //      MACqueue.pop();
              //      setBackOff();
             //       notifyPHY(stopNACKperiod);
             //       state = LISTENING;
              //  }
            }
        }
        else if(msg == longMessageMsgTx) {
            //ev << "   longer message, end hack" << endl;
            ElectronicMessage* m = MACqueue.front();
           delete m;
           nRetries = 0;
            MACqueue.pop();
            setBackOff();
            if(MACqueue.size() < 3) {
                // notify controller.
                ElectronicMessage* unblock = new ElectronicMessage();
                unblock->setMsgType(pathSetup);
                send(unblock,"toNic");
            }
            notifyPHY(stopNACKperiod);
            state = LISTENING;
        }
        // END HACKS
        else {
            opp_error("Auto-message type not expected in MAC.\n");
        }
        // TODO s'han d'esborrar els self messages?

    // MISSATGES DE CAPA PHY
    } else if (msg->arrivedOn("fromPhy")) {

        ElectronicMessage *MsgIn = check_and_cast<ElectronicMessage*> (msg);

        // Si son dades, guardar per confirmar.
        if(MsgIn->getMsgType()==dataPacket) {
            // ev << "MAC: Data packet received from PHY (Start time out rx)" << endl;
            inMsg = MsgIn;
            state = NACKsRx;
            notifyPHY(startNACKperiod);
            scheduleAt(simTime()+timeout,timeoutMsgRx);
        }

        // Si �s de control, fer algo
        else {

            switch(MsgIn->getMsgType()) {

                case(transmission_OK): // transmissi� completada amb exit
                    // ev << "MAC: Transmission finished (Start time out tx)" << endl;
                    state = NACKsTx;
                    notifyPHY(startNACKperiod);
                    nackDetected = false;
                    scheduleAt(simTime()+timeout,timeoutMsgTx);
                    //Keeping track of the successful backoff
                    if (value > 0){
                      if (idnum == 0){
                        backoff00->track(value);
                      }
                      else if (idnum == 1){
                        backoff01->track(value);
                      }
                      else if (idnum == 2){
                        backoff02->track(value);
                      }
                      else if (idnum == 3){
                        backoff03->track(value);
                      }
                      else if (idnum == 4){
                        backoff04->track(value);
                      }
                      else if (idnum == 5){
                        backoff05->track(value);
                      }
                      else if (idnum == 6){
                        backoff06->track(value);
                      }
                      else if (idnum == 7){
                        backoff07->track(value);
                      }
                      else if (idnum == 8){
                        backoff08->track(value);
                      }
                      else if (idnum == 9){
                        backoff09->track(value);
                      }
                      else if (idnum == 10){
                        backoff10->track(value);
                      }
                      else if (idnum == 11){
                        backoff11->track(value);
                      }
                      else if (idnum == 12){
                        backoff12->track(value);
                      }
                      else if (idnum == 13){
                        backoff13->track(value);
                      }
                      else if (idnum == 14){
                        backoff14->track(value);
                      }
                      else if (idnum == 15){
                        backoff15->track(value);
                      }
                      else if (idnum == 16){
                        backoff16->track(value);
                      }
                      else if (idnum == 17){
                        backoff17->track(value);
                      }
                      else if (idnum == 18){
                        backoff18->track(value);
                      }
                      else if (idnum == 19){
                        backoff19->track(value);
                      }
                      else if (idnum == 20){
                        backoff20->track(value);
                      }
                      else if (idnum == 21){
                        backoff21->track(value);
                      }
                      else if (idnum == 22){
                        backoff22->track(value);
                      }
                      else if (idnum == 23){
                        backoff23->track(value);
                      }
                      else if (idnum == 24){
                        backoff24->track(value);
                      }
                      else if (idnum == 25){
                        backoff25->track(value);
                      }
                      else if (idnum == 26){
                        backoff26->track(value);
                      }
                      else if (idnum == 27){
                        backoff27->track(value);
                      }
                      else if (idnum == 28){
                        backoff28->track(value);
                      }
                      else if (idnum == 29){
                        backoff29->track(value);
                      }
                      else if (idnum == 30){
                        backoff30->track(value);
                      }
                      else if (idnum == 31){
                        backoff31->track(value);
                      }
                      else if (idnum == 32){
                        backoff32->track(value);
                      }
                      else if (idnum == 33){
                        backoff33->track(value);
                      }
                      else if (idnum == 34){
                        backoff34->track(value);
                      }
                      else if (idnum == 35){
                        backoff35->track(value);
                      }
                      else if (idnum == 36){
                        backoff36->track(value);
                      }
                      else if (idnum == 37){
                        backoff37->track(value);
                      }
                      else if (idnum == 38){
                        backoff38->track(value);
                      }
                      else if (idnum == 39){
                        backoff39->track(value);
                      }
                      else if (idnum == 40){
                        backoff40->track(value);
                      }
                      else if (idnum == 41){
                        backoff41->track(value);
                      }
                      else if (idnum == 42){
                        backoff42->track(value);
                      }
                      else if (idnum == 43){
                        backoff43->track(value);
                      }
                      else if (idnum == 44){
                        backoff44->track(value);
                      }
                      else if (idnum == 45){
                        backoff45->track(value);
                      }
                      else if (idnum == 46){
                        backoff46->track(value);
                      }
                      else if (idnum == 47){
                        backoff47->track(value);
                      }
                      else if (idnum == 48){
                        backoff48->track(value);
                      }
                      else if (idnum == 49){
                        backoff49->track(value);
                      }
                      else if (idnum == 50){
                        backoff50->track(value);
                      }
                      else if (idnum == 51){
                        backoff51->track(value);
                      }
                      else if (idnum == 52){
                        backoff52->track(value);
                      }
                      else if (idnum == 53){
                        backoff53->track(value);
                      }
                      else if (idnum == 54){
                        backoff54->track(value);
                      }
                      else if (idnum == 55){
                        backoff55->track(value);
                      }
                      else if (idnum == 56){
                        backoff56->track(value);
                      }
                      else if (idnum == 57){
                        backoff57->track(value);
                      }
                      else if (idnum == 58){
                        backoff58->track(value);
                      }
                      else if (idnum == 59){
                        backoff59->track(value);
                      }
                      else if (idnum == 60){
                        backoff60->track(value);
                      }
                      else if (idnum == 61){
                        backoff61->track(value);
                      }
                      else if (idnum == 62){
                        backoff62->track(value);
                      }
                      else if (idnum == 63){
                        backoff63->track(value);
                      }
                    }
                    value = 0;
                    break;

                case(collision_detected_TX):  // collisio detectada pel propi node
                    if (state == TRANSMITTING) {
                        //ev << "MAC: Collision detected after transmitting  (Start time out tx)" << endl;
                        collisions->track(1);
                        if (idnum == 0){
                          collisions00->track(1);
                        }
                        else if (idnum == 1){
                          collisions01->track(1);
                        }
                        else if (idnum == 2){
                          collisions02->track(1);
                        }
                        else if (idnum == 3){
                          collisions03->track(1);
                        }
                        else if (idnum == 4){
                          collisions04->track(1);
                        }
                        else if (idnum == 5){
                          collisions05->track(1);
                        }
                        else if (idnum == 6){
                          collisions06->track(1);
                        }
                        else if (idnum == 7){
                          collisions07->track(1);
                        }
                        else if (idnum == 8){
                          collisions08->track(1);
                        }
                        else if (idnum == 9){
                          collisions09->track(1);
                        }
                        else if (idnum == 10){
                          collisions10->track(1);
                        }
                        else if (idnum == 11){
                          collisions11->track(1);
                        }
                        else if (idnum == 12){
                          collisions12->track(1);
                        }
                        else if (idnum == 13){
                          collisions13->track(1);
                        }
                        else if (idnum == 14){
                          collisions14->track(1);
                        }
                        else if (idnum == 15){
                          collisions15->track(1);
                        }
                        else if (idnum == 16){
                          collisions16->track(1);
                        }
                        else if (idnum == 17){
                          collisions17->track(1);
                        }
                        else if (idnum == 18){
                          collisions18->track(1);
                        }
                        else if (idnum == 19){
                          collisions19->track(1);
                        }
                        else if (idnum == 20){
                          collisions20->track(1);
                        }
                        else if (idnum == 21){
                          collisions21->track(1);
                        }
                        else if (idnum == 22){
                          collisions22->track(1);
                        }
                        else if (idnum == 23){
                          collisions23->track(1);
                        }
                        else if (idnum == 24){
                          collisions24->track(1);
                        }
                        else if (idnum == 25){
                          collisions25->track(1);
                        }
                        else if (idnum == 26){
                          collisions26->track(1);
                        }
                        else if (idnum == 27){
                          collisions27->track(1);
                        }
                        else if (idnum == 28){
                          collisions28->track(1);
                        }
                        else if (idnum == 29){
                          collisions29->track(1);
                        }
                        else if (idnum == 30){
                          collisions30->track(1);
                        }
                        else if (idnum == 31){
                          collisions31->track(1);
                        }
                        else if (idnum == 32){
                          collisions32->track(1);
                        }
                        else if (idnum == 33){
                          collisions33->track(1);
                        }
                        else if (idnum == 34){
                          collisions34->track(1);
                        }
                        else if (idnum == 35){
                          collisions35->track(1);
                        }
                        else if (idnum == 36){
                          collisions36->track(1);
                        }
                        else if (idnum == 37){
                          collisions37->track(1);
                        }
                        else if (idnum == 38){
                          collisions38->track(1);
                        }
                        else if (idnum == 39){
                          collisions39->track(1);
                        }
                        else if (idnum == 40){
                          collisions40->track(1);
                        }
                        else if (idnum == 41){
                          collisions41->track(1);
                        }
                        else if (idnum == 42){
                          collisions42->track(1);
                        }
                        else if (idnum == 43){
                          collisions43->track(1);
                        }
                        else if (idnum == 44){
                          collisions44->track(1);
                        }
                        else if (idnum == 45){
                          collisions45->track(1);
                        }
                        else if (idnum == 46){
                          collisions46->track(1);
                        }
                        else if (idnum == 47){
                          collisions47->track(1);
                        }
                        else if (idnum == 48){
                          collisions48->track(1);
                        }
                        else if (idnum == 49){
                          collisions49->track(1);
                        }
                        else if (idnum == 50){
                          collisions50->track(1);
                        }
                        else if (idnum == 51){
                          collisions51->track(1);
                        }
                        else if (idnum == 52){
                          collisions52->track(1);
                        }
                        else if (idnum == 53){
                          collisions53->track(1);
                        }
                        else if (idnum == 54){
                          collisions54->track(1);
                        }
                        else if (idnum == 55){
                          collisions55->track(1);
                        }
                        else if (idnum == 56){
                          collisions56->track(1);
                        }
                        else if (idnum == 57){
                          collisions57->track(1);
                        }
                        else if (idnum == 58){
                          collisions58->track(1);
                        }
                        else if (idnum == 59){
                          collisions59->track(1);
                        }
                        else if (idnum == 60){
                          collisions60->track(1);
                        }
                        else if (idnum == 61){
                          collisions61->track(1);
                        }
                        else if (idnum == 62){
                          collisions62->track(1);
                        }
                        else if (idnum == 63){
                          collisions63->track(1);
                        }

                        nackDetected = true;
                        state = NACKsTx;
                        // no cal detectar la resta de nacks
                        notifyPHY(broadcast_NACK);
                        scheduleAt(simTime()+timeout,timeoutMsgTx);
                    }
                    else {
                        //ev << "MAC: Collision detected in an incorrect state" << endl;
                    }
                    break;

                case(collision_detected_RX):  // collisio detectada pel propi node
                    if (state == RECEIVING) {
                        //ev << "MAC: Collision detected in the receiving state  (Start time out rx)" << endl;
                        nackDetected = true;
                        state = NACKsRx;
                        // no cal detectar la resta de nacks
                        notifyPHY(broadcast_NACK);
                        scheduleAt(simTime()+timeout,timeoutMsgRx);
                    }
                    else {
                        //ev << "MAC: Collision detected in a non-receiving state" << endl;
                    }
                    break;

                case(broadcast_NACK):  // collisio no detectada pel propi node
                    if (state == NACKsRx and  not nackDetected) {
                        //ev << "MAC: NACK detected in the nack state" << endl;
                        nackDetected = true;
                    }
                    else {
                         //ev << "MAC: NACK detected out of the nack state" << endl;
                    }
                    break;

                case(medium_occupied): // incoming transmission
                    if (state == LISTENING) {
                        state = RECEIVING;
                        nackDetected = false;
                        //ev << "MAC: Starting a packet reception" << endl;
                    }
                    else {
                         //ev << "MAC ERROR: Entra una tx quan no s'esta escoltant" << endl;
                    }
                    break;
                // medium free implicit en altres missatges
                default:
                    opp_error("Unexpected type of control message at MAC layer.\n");
            }
            delete MsgIn;
        }

    }

    // MISSATGES DE INTERFICIE (tots son de dades)
    else {
        ElectronicMessage *emsg = check_and_cast<ElectronicMessage*> (msg);

        if (MACqueue.size() < 16) {
            MACqueue.push(emsg);

            // HACK
            //if (emsg->getBitLength() > 128)
             //   emsg->setBitLength(127);
            // ENd HACK
            if(MACqueue.size() > 1000) { //changed from > 1 to test a node with many messages to send
                // notify controller.
                ElectronicMessage* block = new ElectronicMessage();
                block->setMsgType(pathTeardown);
                send(block,"toNic");
            }

            // We assume that if there is a backoff there is someone in the queue already.
            if(backoffMsg->isScheduled()) {
                if(MACqueue.front() == emsg) opp_error("A new message cannot be in the front of MAC queue while a backoff msg is scheduled.\n");
            } else {
                // If not backoff and the channel is free, transmit immediately
                if (state == LISTENING) {
                    send(msg->dup(),"macToPhy");
                    state = TRANSMITTING;
                    //nRetries = 0;
                // If not backoff and the channel is not free, backoff
                } else {
                    int retries = emsg->getNumRetries();
                    if(retries!=0) opp_error("A new message should not have any retry.\n");
                    emsg->setNumRetries(retries+1);
                    //fprintf(stderr,"%.12f: New packet but channel is not free. Setting packet retries to %d.\n",simTime().dbl(),emsg->getNumRetries());
                    setBackOff();
                }
            }

        } else {
            //ev << "MAC: La cua plena, missatge descartat" << endl;
            discarded->track(1);
            if (idnum == 0){
              discarded00->track(1);
            }
            else if (idnum == 1){
              discarded01->track(1);
            }
            else if (idnum == 2){
              discarded02->track(1);
            }
            else if (idnum == 3){
              discarded03->track(1);
            }
            else if (idnum == 4){
              discarded04->track(1);
            }
            else if (idnum == 5){
              discarded05->track(1);
            }
            else if (idnum == 6){
              discarded06->track(1);
            }
            else if (idnum == 7){
              discarded07->track(1);
            }
            else if (idnum == 8){
              discarded08->track(1);
            }
            else if (idnum == 9){
              discarded09->track(1);
            }
            else if (idnum == 10){
              discarded10->track(1);
            }
            else if (idnum == 11){
              discarded11->track(1);
            }
            else if (idnum == 12){
              discarded12->track(1);
            }
            else if (idnum == 13){
              discarded13->track(1);
            }
            else if (idnum == 14){
              discarded14->track(1);
            }
            else if (idnum == 15){
              discarded15->track(1);
            }
            else if (idnum == 16){
              discarded16->track(1);
            }
            else if (idnum == 17){
              discarded17->track(1);
            }
            else if (idnum == 18){
              discarded18->track(1);
            }
            else if (idnum == 19){
              discarded19->track(1);
            }
            else if (idnum == 20){
              discarded20->track(1);
            }
            else if (idnum == 21){
              discarded21->track(1);
            }
            else if (idnum == 22){
              discarded22->track(1);
            }
            else if (idnum == 23){
              discarded23->track(1);
            }
            else if (idnum == 24){
              discarded24->track(1);
            }
            else if (idnum == 25){
              discarded25->track(1);
            }
            else if (idnum == 26){
              discarded26->track(1);
            }
            else if (idnum == 27){
              discarded27->track(1);
            }
            else if (idnum == 28){
              discarded28->track(1);
            }
            else if (idnum == 29){
              discarded29->track(1);
            }
            else if (idnum == 30){
              discarded30->track(1);
            }
            else if (idnum == 31){
              discarded31->track(1);
            }
            else if (idnum == 32){
              discarded32->track(1);
            }
            else if (idnum == 33){
              discarded33->track(1);
            }
            else if (idnum == 34){
              discarded34->track(1);
            }
            else if (idnum == 35){
              discarded35->track(1);
            }
            else if (idnum == 36){
              discarded36->track(1);
            }
            else if (idnum == 37){
              discarded37->track(1);
            }
            else if (idnum == 38){
              discarded38->track(1);
            }
            else if (idnum == 39){
              discarded39->track(1);
            }
            else if (idnum == 40){
              discarded40->track(1);
            }
            else if (idnum == 41){
              discarded41->track(1);
            }
            else if (idnum == 42){
              discarded42->track(1);
            }
            else if (idnum == 43){
              discarded43->track(1);
            }
            else if (idnum == 44){
              discarded44->track(1);
            }
            else if (idnum == 45){
              discarded45->track(1);
            }
            else if (idnum == 46){
              discarded46->track(1);
            }
            else if (idnum == 47){
              discarded47->track(1);
            }
            else if (idnum == 48){
              discarded48->track(1);
            }
            else if (idnum == 49){
              discarded49->track(1);
            }
            else if (idnum == 50){
              discarded50->track(1);
            }
            else if (idnum == 51){
              discarded51->track(1);
            }
            else if (idnum == 52){
              discarded52->track(1);
            }
            else if (idnum == 53){
              discarded53->track(1);
            }
            else if (idnum == 54){
              discarded54->track(1);
            }
            else if (idnum == 55){
              discarded55->track(1);
            }
            else if (idnum == 56){
              discarded56->track(1);
            }
            else if (idnum == 57){
              discarded57->track(1);
            }
            else if (idnum == 58){
              discarded58->track(1);
            }
            else if (idnum == 59){
              discarded59->track(1);
            }
            else if (idnum == 60){
              discarded60->track(1);
            }
            else if (idnum == 61){
              discarded61->track(1);
            }
            else if (idnum == 62){
              discarded62->track(1);
            }
            else if (idnum == 63){
              discarded63->track(1);
            }
            delete msg;
        }
    }

}

// 0 persistent!
void MAC_BRS::setBackOff() {
    if(not MACqueue.empty()) {

        if (not backoffMsg->isScheduled()) {

            if (nRetries < 8)
                nRetries++;

            //simtime_t backoff = (simtime_t) exponential(backOffPeriod);
            double maxBO = (pow(2,nRetries) - 1)*(backOffPeriod);
            //2^nRetries - 1 * 6*128/${C}

            value = uniform(clockPeriod, maxBO);
            if ( idnum == -1 ){ //1 = unhealthy
              value = clockPeriod;
            }

            int aux = (int) ((value + simTime().dbl())/clockPeriod + 0.5);
            double dbackoff = ((double) aux)*clockPeriod;
            simtime_t backoff = (simtime_t) dbackoff;

            scheduleAt(backoff,backoffMsg);

            //fprintf(stderr, "%.12f: Backoff in node %d, backOffPeriod %.2f, maxBO (retries) %.2f (%d), value %.2f.\n", simTime().dbl(),idnum, backOffPeriod*clockRate, maxBO*clockRate, nRetries, value*clockRate);
           //ev << "MAC: Back off set after: " << value << " (Retry: " << nRetries << ") (Simtime: " << backoff << ")" <<endl;

           //scheduleAt(backoff,backoffMsg);
        }
    } else {
        if (backoffMsg->isScheduled())
            cancelEvent(backoffMsg);
    }
}

void MAC_BRS::triggerTX(){

}

void MAC_BRS::notifyPHY(int notification) {

    int numLevels = 3;
    int procConc = 1;

    ElectronicMessage *msg = new ElectronicMessage();
    msg->setMsgType(notification);

    // SET SOURCE
    stringstream ss1;
    ss1 << "";
    ss1 << idnum / procConc;
    ss1 << ".0.";
    ss1 << idnum % procConc << ".";
    NetworkAddress* srcAddr = new NetworkAddress(ss1.str(), numLevels);
    msg->setSrcId((long) srcAddr);

    msg->setBitLength(16);

    send(msg,"macToPhy");
}
