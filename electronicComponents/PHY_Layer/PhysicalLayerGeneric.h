/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef PHYSICALLAYERGENERIC_H_
#define PHYSICALLAYERGENERIC_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

using namespace std;

class PhysicalLayerGeneric: public PhysicalLayer {
public:
    PhysicalLayerGeneric();
	virtual ~PhysicalLayerGeneric();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();

	bool transmitting;

	bool collision;

	cMessage *endRxMsg;
	cMessage *endTxMsg;

	queue<ElectronicMessage*> rxQueue;


    enum TransceiverTypes {

        FDMA = 0,
        TDMA = 1,
        TOKEN_PASSING = 2,
        CSMA = 3

    };


};

#endif /* PHYSICALLAYERGENERIC_H_ */
