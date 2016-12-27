//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef HYBRIDCONTROLLER_H_
#define HYBRIDCONTROLLER_H_

#include <omnetpp.h>
#include <queue>
#include "sim_includes.h"
#include "messages_m.h"
#include "statistics.h"

#include "NetworkAddress.h"

#include "Processor.h"

#define CONTROL_PACKET_SIZE 	32
#define ACK_LENGTH 		32
#define DATA_HEADER_SIZE	16
#define ELECTRONIC_MESSAGE_SIZE 32

using namespace std;

class HybridController: public cSimpleModule {
public:
	HybridController();
	virtual ~HybridController();

protected:
	virtual void initialize();
	virtual void finish();
	virtual void handleMessage(cMessage* msg);
	
	virtual void procMsgArrived(ProcessorData* pdata);
	virtual void requestMsgArrived(RouterCntrlMsg* rmsg);

	int id;

	bool procIsDone;
	int numProcsDone;
	int leftToSend;

	int bitsSent;
	int range;
	int fraction;


	int conc;

	simtime_t startSerTime;

	
	//processor side
	cGate* procReqIn;
	cGate* procReqOut;
	cGate* fromProc;
	cGate* toProc;

	//network side
	cGate* WprocReqIn;
    cGate* WprocReqOut;
    cGate* EprocReqIn;
    cGate* EprocReqOut;
    cGate* WfromProc;
    cGate* EfromProc;
    cGate* WtoProc;
    cGate* EtoProc;

	//stats
	StatObject* diverted;

	int hNIFtype;
	int concentration;
	int numCoresX;
	double coreSizeX;
	
	bool sentRequest;


	queue<bool> isWireless;

	int flitWidth;

	bool stalled;

	queue<ElectronicMessage*> unacked;

	queue<cPacket*> packetQ;
	double clockPeriod_packet;
	double lastOut;

	int wirelessOpen;

	int maxPacketSize;
	//static int pathsEstablished;


	int calcDist(int emitter, int receiver);

};

#endif /* HYBRIDCONTROLLER_H_ */

