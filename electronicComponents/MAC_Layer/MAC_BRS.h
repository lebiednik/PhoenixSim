/*
 * RouterCrossbar.h
 *
 *  Created on: Mar 8, 2009
 *      Author: Gilbert
 */

#ifndef MAC_BRS_H_
#define MAC_BRS_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "MACLayer.h"

using namespace std;

class MAC_BRS: public MACLayer {
public:
    MAC_BRS();
	virtual ~MAC_BRS();

protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);
	virtual void finish();

private:
	virtual void triggerTX();
	void setBackOff();
	void notifyPHY(int notification);


	bool negativeACKs;
	bool nackDetected;

	double backOffPeriod;
	simtime_t timeout;

	double clockRate;
	double clockPeriod;
	double pPersistent;
  double adjust_backoff;

	int nRetries;
  int unhealthy;//added 25 Oct 2016 by Brian Lebiednik for CSMA unhealthy node



	cMessage *backoffMsg;
	cMessage *timeoutMsgTx;
	cMessage *timeoutMsgRx;

	double lastOut;

	// HACK
    cMessage *longMessageMsgRx;
    cMessage *longMessageMsgTx;
    double channelCapacity;
    // END HACK

	StatObject* collisions;
  StatObject* collisions10;
  StatObject* collisions11;
  StatObject* collisions12;
  StatObject* collisions13;
  StatObject* collisions14;
  StatObject* collisions15;
  StatObject* collisions16;
  StatObject* collisions17;
  StatObject* collisions18;
  StatObject* collisions19;
  StatObject* collisions20;
  StatObject* collisions21;
  StatObject* collisions22;
  StatObject* collisions23;
  StatObject* collisions24;
  StatObject* collisions25;
  StatObject* collisions26;
  StatObject* collisions27;
  StatObject* collisions28;
  StatObject* collisions29;
  StatObject* collisions30;
  StatObject* collisions31;
  StatObject* collisions32;
  StatObject* collisions33;
  StatObject* collisions34;
  StatObject* collisions35;
  StatObject* collisions36;
  StatObject* collisions37;
  StatObject* collisions38;
  StatObject* collisions39;
  StatObject* collisions0;
  StatObject* collisions1;
  StatObject* collisions2;
  StatObject* collisions3;
  StatObject* collisions4;
  StatObject* collisions5;
  StatObject* collisions6;
  StatObject* collisions7;
  StatObject* collisions8;
  StatObject* collisions9;
  StatObject* collisions40;
  StatObject* collisions41;
  StatObject* collisions42;
  StatObject* collisions43;
  StatObject* collisions44;
  StatObject* collisions45;
  StatObject* collisions46;
  StatObject* collisions47;
  StatObject* collisions48;
  StatObject* collisions49;
  StatObject* collisions50;
  StatObject* collisions51;
  StatObject* collisions52;
  StatObject* collisions53;
  StatObject* collisions54;
  StatObject* collisions55;
  StatObject* collisions56;
  StatObject* collisions57;
  StatObject* collisions58;
  StatObject* collisions59;
  StatObject* collisions60;
  StatObject* collisions61;
  StatObject* collisions62;
  StatObject* collisions63;

	StatObject* discarded;
	StatObject* switched;
  //StatObject* SO_num_messages_test2;
  //StatObject* SO_num_messages_test3;

	queue<ElectronicMessage*> MACqueue;
	ElectronicMessage* inMsg;

	int state;

    enum STATEenum {
        LISTENING = 0,
        RECEIVING = 2,
        TRANSMITTING = 3,
        NACKsTx = 4,
        NACKsRx = 5
    };


};

#endif /* MAC_BRS_H_ */
