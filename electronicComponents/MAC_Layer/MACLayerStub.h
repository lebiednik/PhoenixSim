/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef MACLAYERSTUB_H_
#define MACLAYERSTUB_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACLayer.h"

using namespace std;

class MACLayerStub: public MACLayer {
public:
    MACLayerStub();
	virtual ~MACLayerStub();

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




};

#endif /* MACLAYERSTUB_H_ */
