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
  double value;
  double total_backoff;


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
  StatObject* collisions00;
  StatObject* collisions01;
  StatObject* collisions02;
  StatObject* collisions03;
  StatObject* collisions04;
  StatObject* collisions05;
  StatObject* collisions06;
  StatObject* collisions07;
  StatObject* collisions08;
  StatObject* collisions09;
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

  StatObject* discarded00;
  StatObject* discarded01;
  StatObject* discarded02;
  StatObject* discarded03;
  StatObject* discarded04;
  StatObject* discarded05;
  StatObject* discarded06;
  StatObject* discarded07;
  StatObject* discarded08;
  StatObject* discarded09;
  StatObject* discarded10;
  StatObject* discarded11;
  StatObject* discarded12;
  StatObject* discarded13;
  StatObject* discarded14;
  StatObject* discarded15;
  StatObject* discarded16;
  StatObject* discarded17;
  StatObject* discarded18;
  StatObject* discarded19;
  StatObject* discarded20;
  StatObject* discarded21;
  StatObject* discarded22;
  StatObject* discarded23;
  StatObject* discarded24;
  StatObject* discarded25;
  StatObject* discarded26;
  StatObject* discarded27;
  StatObject* discarded28;
  StatObject* discarded29;
  StatObject* discarded30;
  StatObject* discarded31;
  StatObject* discarded32;
  StatObject* discarded33;
  StatObject* discarded34;
  StatObject* discarded35;
  StatObject* discarded36;
  StatObject* discarded37;
  StatObject* discarded38;
  StatObject* discarded39;
  StatObject* discarded40;
  StatObject* discarded41;
  StatObject* discarded42;
  StatObject* discarded43;
  StatObject* discarded44;
  StatObject* discarded45;
  StatObject* discarded46;
  StatObject* discarded47;
  StatObject* discarded48;
  StatObject* discarded49;
  StatObject* discarded50;
  StatObject* discarded51;
  StatObject* discarded52;
  StatObject* discarded53;
  StatObject* discarded54;
  StatObject* discarded55;
  StatObject* discarded56;
  StatObject* discarded57;
  StatObject* discarded58;
  StatObject* discarded59;
  StatObject* discarded60;
  StatObject* discarded61;
  StatObject* discarded62;
  StatObject* discarded63;

  StatObject* backoff00;
  StatObject* backoff01;
  StatObject* backoff02;
  StatObject* backoff03;
  StatObject* backoff04;
  StatObject* backoff05;
  StatObject* backoff06;
  StatObject* backoff07;
  StatObject* backoff08;
  StatObject* backoff09;
  StatObject* backoff10;
  StatObject* backoff11;
  StatObject* backoff12;
  StatObject* backoff13;
  StatObject* backoff14;
  StatObject* backoff15;
  StatObject* backoff16;
  StatObject* backoff17;
  StatObject* backoff18;
  StatObject* backoff19;
  StatObject* backoff20;
  StatObject* backoff21;
  StatObject* backoff22;
  StatObject* backoff23;
  StatObject* backoff24;
  StatObject* backoff25;
  StatObject* backoff26;
  StatObject* backoff27;
  StatObject* backoff28;
  StatObject* backoff29;
  StatObject* backoff30;
  StatObject* backoff31;
  StatObject* backoff32;
  StatObject* backoff33;
  StatObject* backoff34;
  StatObject* backoff35;
  StatObject* backoff36;
  StatObject* backoff37;
  StatObject* backoff38;
  StatObject* backoff39;
  StatObject* backoff40;
  StatObject* backoff41;
  StatObject* backoff42;
  StatObject* backoff43;
  StatObject* backoff44;
  StatObject* backoff45;
  StatObject* backoff46;
  StatObject* backoff47;
  StatObject* backoff48;
  StatObject* backoff49;
  StatObject* backoff50;
  StatObject* backoff51;
  StatObject* backoff52;
  StatObject* backoff53;
  StatObject* backoff54;
  StatObject* backoff55;
  StatObject* backoff56;
  StatObject* backoff57;
  StatObject* backoff58;
  StatObject* backoff59;
  StatObject* backoff60;
  StatObject* backoff61;
  StatObject* backoff62;
  StatObject* backoff63;

  StatObject* queue_time00;
  StatObject* queue_time01;
  StatObject* queue_time02;
  StatObject* queue_time03;
  StatObject* queue_time04;
  StatObject* queue_time05;
  StatObject* queue_time06;
  StatObject* queue_time07;
  StatObject* queue_time08;
  StatObject* queue_time09;
  StatObject* queue_time10;
  StatObject* queue_time11;
  StatObject* queue_time12;
  StatObject* queue_time13;
  StatObject* queue_time14;
  StatObject* queue_time15;
  StatObject* queue_time16;
  StatObject* queue_time17;
  StatObject* queue_time18;
  StatObject* queue_time19;
  StatObject* queue_time20;
  StatObject* queue_time21;
  StatObject* queue_time22;
  StatObject* queue_time23;
  StatObject* queue_time24;
  StatObject* queue_time25;
  StatObject* queue_time26;
  StatObject* queue_time27;
  StatObject* queue_time28;
  StatObject* queue_time29;
  StatObject* queue_time30;
  StatObject* queue_time31;
  StatObject* queue_time32;
  StatObject* queue_time33;
  StatObject* queue_time34;
  StatObject* queue_time35;
  StatObject* queue_time36;
  StatObject* queue_time37;
  StatObject* queue_time38;
  StatObject* queue_time39;
  StatObject* queue_time40;
  StatObject* queue_time41;
  StatObject* queue_time42;
  StatObject* queue_time43;
  StatObject* queue_time44;
  StatObject* queue_time45;
  StatObject* queue_time46;
  StatObject* queue_time47;
  StatObject* queue_time48;
  StatObject* queue_time49;
  StatObject* queue_time50;
  StatObject* queue_time51;
  StatObject* queue_time52;
  StatObject* queue_time53;
  StatObject* queue_time54;
  StatObject* queue_time55;
  StatObject* queue_time56;
  StatObject* queue_time57;
  StatObject* queue_time58;
  StatObject* queue_time59;
  StatObject* queue_time60;
  StatObject* queue_time61;
  StatObject* queue_time62;
  StatObject* queue_time63;

	StatObject* discarded;
	StatObject* switched;


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
