/*
 * RouterInport2.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef ROUTERINPORT2_H_
#define ROUTERINPORT2_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"

#include "StatObject.h"

#ifdef ENABLE_ORION
#include "orion/ORION_Array.h"
#include "orion/ORION_Array_Info.h"
#include "orion/ORION_Util.h"
#endif

using namespace std;

class RouterInport2 : public cSimpleModule {
public:
	RouterInport2();
	virtual ~RouterInport2();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();

	void sendRequest(ElectronicMessage* emsg, int vc);

	int numVC;
	int flit_width;
	int buffer_size;
	double clockPeriod;

	simtime_t packetTimeout;
	map<int, cMessage*> timeouts;

	StatObject* P_static;
	StatObject* E_dynamic;

	simtime_t lastTime;

	int myId;

	map<int, queue<ElectronicMessage*>* > buffs;

	cGate* inport;
	cGate* outport;
	cGate* reqportIn;
	cGate* reqportOut;
	cGate* ackport;
	cGate* ackinport;
	cGate* ackToArb;



#ifdef ENABLE_ORION
	ORION_Array* power;
	ORION_Array_Info* info;

#endif
};

#endif /* ROUTERINPORT2_H_ */
