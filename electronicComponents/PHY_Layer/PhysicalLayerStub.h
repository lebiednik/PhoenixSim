/*
 * PhysicalLayerStub.h
 *
 * Physical Layer that simply relies messages
 *
 *  Created on: June, 2014
 *      Author: Albert Mestres (and Sergi Abadal)
 */

#ifndef PHYSICALLAYERSTUB_H_
#define PHYSICALLAYERSTUB_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

using namespace std;

class PhysicalLayerStub: public PhysicalLayer {
public:
    PhysicalLayerStub();
	virtual ~PhysicalLayerStub();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();


	bool collision;

	int state;
	int nNacks;

	cMessage *endRxMsg;


	ElectronicMessage* MsgIn;



    enum STATEenum {
        LISTENING = 0,
        RECEIVING = 2,
        TRANSMITTING = 3,
        NACKs = 3
    };


};

#endif /* PHYSICALLAYERSTUB_H_ */
