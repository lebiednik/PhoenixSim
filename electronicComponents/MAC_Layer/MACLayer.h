/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef MACLAYER_H_
#define MACLAYER_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACprotocol.h"

using namespace std;

class MACLayer: public cSimpleModule {
public:
	MACLayer();
	virtual ~MACLayer();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();
	virtual void triggerTX();

	int idnum;

	int numX;
	int numY;
	int numOfNodesX;
	double coreSizeX;
	double channelCapacity;

};

#endif /* MACLAYER_H_ */
