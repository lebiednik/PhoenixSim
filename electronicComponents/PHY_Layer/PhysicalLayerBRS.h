/*
 * PhysicalLayerBRS.h
 *
 * Physical Layer for the BRS MAC protocol
 *
 *  Created on: June, 2014
 *      Author: Albert Mestres (and Sergi Abadal)
 */

#ifndef PHYSICALLAYERBRS_H_
#define PHYSICALLAYERBRS_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

using namespace std;

class PhysicalLayerBRS: public PhysicalLayer {
public:
    PhysicalLayerBRS();
	virtual ~PhysicalLayerBRS();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual simtime_t sendIt(cMessage *msg, double dataRate);
	virtual void finish();


	bool collision;

	int state;
	int nNacks;

	double clockRate;

	cMessage *endRxMsg;
	cMessage *endTxMsg;

	cMessage *msgRx;

	queue<ElectronicMessage*> rxQueue;
	queue<ElectronicMessage*> msgRxQueue;


    enum STATEenum {
        LISTENING = 0,
        RECEIVING = 2,
        TRANSMITTING = 3,
        NACKs = 3
    };


};

#endif /* PHYSICALLAYERBRS_H_ */
