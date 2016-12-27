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

class MAC_FDMA: public MACprotocol {
public:
	MAC_FDMA(int id, int N);
	virtual ~MAC_FDMA();

protected:

	virtual ElectronicMessage* backoffExpired();
	virtual simtime_t getBackoff();
	virtual void prepareReTX();
	virtual void commitTX();
	virtual ElectronicMessage* handleCollision(int type, NetworkAddress* source);
	virtual ElectronicMessage* confirmRX(ElectronicMessage* rcvdMsg);
	virtual bool ackArrived();
	virtual simtime_t getTimeout();

};
