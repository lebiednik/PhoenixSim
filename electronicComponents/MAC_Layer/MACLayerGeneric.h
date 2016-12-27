/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef MACLAYERGEN_H_
#define MACLAYERGEN_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACLayer.h"
#include "MACprotocol.h"

using namespace std;

class MACLayerGeneric: public MACLayer {
public:
    MACLayerGeneric();
	virtual ~MACLayerGeneric();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();
	virtual void triggerTX();


    int type;

    bool negativeACKs;
    bool nackDetected;

    simtime_t backoff;
    simtime_t timeout;

    double clockRate;
    double clockPeriod;
    double backOffPeriod;
    double pPersistent;

    cMessage *backoffMsg;
    cMessage *timeoutMsg;
    cMessage *tokenMsg;

    StatObject* collisions;
    StatObject* discarded;

    MACprotocol *mac;

    int maxTokenTrips; // num maxim de voltes...
    int HopsPerCycle; // num maxim de hops sense agafar token...
    int tokenTrips;

    //queue<ElectronicMessage*> MACqueue;

    enum TransceiverTypes {

        FDMA = 0,
        TDMA = 1,
        TOKEN_PASSING = 2,
        CSMA = 3

    };


};

#endif /* MACLAYERGEN_H_ */
