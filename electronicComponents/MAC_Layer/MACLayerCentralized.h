/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef MACLAYERCENTRALIZED_H_
#define MACLAYERCENTRALIZED_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACLayer.h"

using namespace std;

class MACLayerCentralized: public MACLayer {
public:
    MACLayerCentralized();
	virtual ~MACLayerCentralized();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();

private:


	bool negativeACKs;
	bool nackDetected;

	double backOffPeriod;
	simtime_t timeout;

	double clockRate;
	double clockPeriod;
	double pPersistent;

    queue<ElectronicMessage*> MACqueue;

    void notifyController(int notification, int bitLength );


};

#endif /* MACLAYERCENTRALIZED_H_ */
