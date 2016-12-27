

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACprotocol.h"

using namespace std;

class MAC_token: public MACprotocol {
public:
	MAC_token(int ident, int nX);
	virtual ~MAC_token();

protected:

	virtual ElectronicMessage* backoffExpired();
	virtual void prepareReTX();
	virtual void commitTX();
	virtual ElectronicMessage* handleCollision(int type, NetworkAddress* source);
	virtual ElectronicMessage* confirmRX(ElectronicMessage* rcvdMsg);
	virtual bool ackArrived();
	virtual simtime_t getTimeout();



};
