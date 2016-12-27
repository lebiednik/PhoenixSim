
#ifndef MACPROTOCOL_H_
#define MACPROTOCOL_H_



#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"
#include "NetworkAddress.h"

using namespace std;

class MACprotocol {
public:


	virtual ElectronicMessage* backoffExpired();
	virtual simtime_t getBackoff();
	virtual void prepareReTX();

	virtual void commitTX();
	virtual ElectronicMessage* handleCollision(int type, NetworkAddress* source);
	virtual ElectronicMessage* confirmRX(ElectronicMessage* rcvdMsg);
	virtual bool ackArrived(ElectronicMessage* ackMsg);
	virtual simtime_t getTimeout();
	virtual bool isAck();
	virtual void setFree(int value);
	virtual int getConfirmationPolicy();
	virtual void enqueue(ElectronicMessage *emsg);
	virtual bool moreToTX();
	virtual bool readyToTX();
	virtual ElectronicMessage* prepareCntrlMsg(int type, NetworkAddress *destId);

	int idnum;

	// 1 is free / 0 is occupied
	bool mediumIsFree;

	int nACK;
	int nRETRIES;

	// 1 if ACKs are used / 0 if NACKs are used
	bool ackPolicy;
	//0 -> CONTENTION: schedule Timeout
    //1 -> NO CONTENTION: commitTX, pop() i schedule timer.
    //2 -> TOKEN (NO CONTENTION): commitTX i schedule token.
	int confirmationPolicy;
	int maxRETRIES;
	double timeout;

	int numOfNodesX;

	// 1 mentre s'esta enviant
	bool txToCommit;

	queue<ElectronicMessage*> MACqueue;



};


#endif /* MACPROTOCOL_H_ */
