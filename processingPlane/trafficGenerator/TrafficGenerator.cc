/*
 * TrafficGenerator.cc
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#include "TrafficGenerator.h"
#include "math.h"

#include "TGcore.h"

#include "SyntheticGenerator.h"
#include "TraceBasedGenerator.h"


Define_Module(TrafficGenerator)
;

TrafficGenerator::TrafficGenerator() {

}


TrafficGenerator::~TrafficGenerator() {

}

void TrafficGenerator::initialize() {

    int recognized = 0;
    string appStr = par("application");
    currentMsgN = 0;
    numOfNodesX = par("numOfNodesX");
    numOfNodesY = par("numOfNodesY");
    numOfNodes = numOfNodesX * numOfNodesY;
    freq = par("O_frequency_proc");
    clockPeriod = 1 / freq;
    msgCount = (int *) malloc(numOfNodes *sizeof(int));
    currentTime = 0;

    for(int i=0;i<numOfNodes;i++) {
        msgCount[i] = 0;
    }

    TGcore::param1 = par("appParam1");
    TGcore::param2 = par("appParam2");
    TGcore::param3 = par("appParam3");
    TGcore::param4 = par("appParam4");
    TGcore::param5 = par("appParam5").str();
    TGcore::param6 = par("appParam6");
    TGcore::param7 = par("appParam7");
    TGcore::param8 = par("appParam8");
    TGcore::param9 = par("appParam9");
    TGcore::furthDest = par("furthDest");

    //Hurst = Statistics::registerStat("Hurst Exponent", StatObject::HURST, "trafficGen");
    Load = Statistics::registerStat("Load (flits/cycle)", StatObject::TIME_AVG, "trafficGen");
    Messages = Statistics::registerStat("Total Messages", StatObject::TOTAL, "trafficGen");
    Unicasts = Statistics::registerStat("Unicasts", StatObject::TOTAL, "trafficGen");
    HopDist = Statistics::registerStat("Total Hops", StatObject::TOTAL, "trafficGen");
    //SpatialDist = Statistics::registerStat("Spatial Distribution (CoV)", StatObject::STATIC_TOTAL, "trafficGen");


    if (appStr.find("CentralTG_synthetic") != string::npos) {
        generator = new SyntheticGenerator(numOfNodes, freq);
        recognized = 1;

    } else if (appStr.find("CentralTG_trace") != string::npos) {
        generator = new TraceBasedGenerator(numOfNodes, freq);
        recognized = 1;

    } else if (appStr.find("CentralTG") != string::npos) {
        opp_error("Central generator selected but not found.");
    }

    if(recognized) {
        totalMessages = generator->getNumMessages();
        nextMessage = new cMessage("nextMessage");
        double finish_t = generator->getFinishTime();
        int tlambda = totalMessages / finish_t;

        // Tell statistics that he should change warmup and cooldown
        //cMessage* wmsg;
        //wmsg = new cMessage("");
        //wmsg->setName("warmup");
        //cMessage* cmsg;
        //cmsg = new cMessage("");
        //cmsg->setName("cooldown");

        //cModule* statModule = simulation.getModuleByPath("stat");
        //if(statModule==NULL)
         //   opp_error("Wrong stat module search.");

        //wmsg->setTimestamp((simtime_t)0.5*numOfNodes/tlambda);
        //sendDirect(wmsg, statModule, "warm_cool");

        //cmsg->setTimestamp((simtime_t)0.75*finish_t);
        //sendDirect(cmsg, statModule, "warm_cool");

        // Start with first message...
        ApplicationData *amsg = generator->NextMessage();
        int source = amsg->getSrcId();
        msgCount[source]++;
        double delay = generator->NextDelay();
        int delayCycles = ceil(delay*freq);
        sendDelayed(amsg, (simtime_t) (delayCycles * clockPeriod), "toProc", source);
        scheduleAt(simTime()+ (simtime_t)delay,nextMessage);
    }
}

void TrafficGenerator::handleMessage(cMessage *msg) {

    // We arrive always here due to self-message, which means that we should go for the next message
    currentMsgN++;
    Messages->track(1);
   // Hurst->track(simTime().dbl());
    Load->track(1 / freq); // one flit, normalized to cycle time
    if(currentMsgN < totalMessages){
        ApplicationData *amsg = generator->NextMessage();
        int source = amsg->getSrcId();
        if(amsg->getType() == snoopResp) {
            Unicasts->track(1);
            int dest = amsg->getDestId();
            int dx = abs( (int)dest/numOfNodesX - (int)source/numOfNodesX);
            int dy = abs( (dest % numOfNodesX) - (source % numOfNodesX));
            //fprintf(stderr, "src: %d, dest: %d, dx: %d, dy: %d.\n", source, dest, dx, dy);
            HopDist->track(dx+dy);
        }
        msgCount[source]++;
        double delay = generator->NextDelay();
        int nextCycle = ceil( (simTime().dbl()+delay)*freq );
        sendDelayed(amsg, (simtime_t)(nextCycle*clockPeriod) - simTime(), "toProc", source);
        scheduleAt(simTime()+ (simtime_t)delay,nextMessage);
    }


}

void TrafficGenerator::finish() {

    // Calculate CoV and track it
    /*double avg = currentMsgN / numOfNodes;

    double stddev = 0;
    for(int i=0;i<numOfNodes;i++){
        stddev += pow((avg - msgCount[i]), 2);
    }
    stddev = stddev / numOfNodes;
    stddev = sqrt(stddev);

    SpatialDist->track(stddev/avg);*/
}

int TrafficGenerator::RoundToClk(double delay) {

    int result = ceil(delay*freq);
    return result;

}
