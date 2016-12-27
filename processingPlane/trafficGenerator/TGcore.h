/*
 * TGCore.h
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#ifndef TGCORE_H_
#define TGCORE_H_

#include <omnetpp.h>
#include "messages_m.h"

#include "statistics.h"
#include "sim_includes.h"

using namespace std;

#define MEM_READ_SIZE 64

class TGcore : public cSimpleModule {
public:

	TGcore();
	virtual ~TGcore();

	virtual ApplicationData* NextMessage() { return NULL; };
	virtual double NextDelay() { return 0; };
	virtual int NextSource() { return 0; };
	virtual int getNumMessages() { return 0; };
	virtual int getFurthestDest(int id); //returns the id of the furthest node with respect to what's supposed to be the source

	virtual double getFinishTime() { return 0; };
	virtual void finish();

	static double param1;
	static double param2;
	static double param3;
	static double param4;
	static string param5;
	static double param6;
	static double param7;
	static double param8;
	static double param9;

	static int furthDest;

	static double clockPeriod;
	cMessage *nextMessage;

	double f;
	simtime_t currentTime;


	int currentMsgN;
	int totalMessages;
	int small_percent;

    int numOfNodes;



};

#endif /* TGcore_H_ */
