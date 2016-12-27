

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACprotocol.h"

using namespace std;

class MAC_TDMA: public MACprotocol {
public:
	MAC_TDMA(int nX, int sizeX, double tSlot, int ident);
	virtual ~MAC_TDMA();

protected:

	virtual ElectronicMessage* backoffExpired();
	virtual simtime_t getBackoff();
	virtual void prepareReTX();
	virtual void commitTX();
	virtual ElectronicMessage* handleCollision(int type, NetworkAddress* source);
	virtual ElectronicMessage* confirmRX(ElectronicMessage* rcvdMsg);
	virtual bool ackArrived();
	virtual simtime_t getTimeout();

	double epoch;
	double timeSlot;

	double margin;

	double coreSizeX; // in meters



};
