/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */


#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACprotocol.h"

using namespace std;

class MAC_CSMA: public MACprotocol {
public:
	MAC_CSMA(int id, double channelCapacity, double backOffPeriodP, int numOfNodesXP,
	        double pPersistentP, bool negativeACKsP, simtime_t timeout);
	virtual ~MAC_CSMA();

protected:

	virtual ElectronicMessage* backoffExpired();
	virtual simtime_t getBackoff();
	virtual void prepareReTX();
	virtual void commitTX();
	virtual ElectronicMessage* handleCollision(int type, NetworkAddress* source);
	virtual ElectronicMessage* confirmRX(ElectronicMessage* rcvdMsg);
	virtual bool ackArrived(ElectronicMessage* ackMsg);
	virtual simtime_t getTimeout();

	void resetVector(bool *ackReceived);

	//int numOfNodesX;
	double lambdaBackOff;
	double channelCapacity;
	double backOffPeriod;
	double pPersistent;
	bool persistenceWait;
	bool* ackReceived;
	bool negativeACKs;
	simtime_t timeout;

    unsigned long int  physicalId;

};
