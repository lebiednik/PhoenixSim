/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef PHYSICALLAYER_H_
#define PHYSICALLAYER_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

using namespace std;



class PhysicalLayer: public cSimpleModule {
public:
	PhysicalLayer();
	virtual ~PhysicalLayer();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();

	double calcDist(int dest);
	simtime_t sendIt(cMessage *msg, double dataRate);
	void notifyMAC(int notification, long source);



	
	int numX;
	int numY;
	int numOfNodesX;
	double coreSizeX;
	int type;
	int idnum;
	double channelCapacity;

	simtime_t deltaSim;
	vector<double> distances;

	queue<ElectronicMessage*> rxQueue;





};

#endif /* PHYSICALLAYER_H_ */
