/*
 * TrafficGenerator.h
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#ifndef TRAFFICGENERATOR_H_
#define TRAFFICGENERATOR_H_

#include <omnetpp.h>
#include "messages_m.h"
#include "sim_includes.h"

#include "statistics.h"
#include "TGcore.h"

using namespace std;

#define MEM_READ_SIZE 64

class TrafficGenerator : public cSimpleModule {
public:

	TrafficGenerator();
	virtual ~TrafficGenerator();

	virtual void initialize();
	virtual void handleMessage(cMessage *msg);

	virtual void finish();
	virtual int RoundToClk(double delay);

	TGcore* generator;

	double clockPeriod;
	cMessage *nextMessage;

	simtime_t currentTime;

	double freq;
	int currentMsgN;
	int totalMessages;
	int* msgCount;

	int numOfNodesX;
	int numOfNodesY;
	int numOfNodes;

	StatObject* Hurst;
	StatObject* Load;
	StatObject* SpatialDist;
	StatObject* HopDist;
	StatObject* Unicasts;
	StatObject* Messages;

};

#endif /* TRAFFICGENERATOR_H_ */
