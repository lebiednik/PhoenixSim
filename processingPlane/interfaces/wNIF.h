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

#ifndef WNIF_H_
#define WNIF_H_

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

class wNIF: public cSimpleModule {
public:
	wNIF();
	virtual ~wNIF();

protected:
	virtual void initialize();
	virtual void finish();

	virtual void handleMessage(cMessage* msg);
	virtual void selfMsgArrived(cMessage* msg);
	virtual void requestMsgArrived(RouterCntrlMsg* rmsg);
	virtual void sendAck();
	virtual void procMsgArrived(ProcessorData* pdata);
	virtual void netPortMsgArrived(cMessage* msg);

	virtual void ackMsgArrived(BufferAckMsg* bmsg);

	virtual void controller();

	virtual bool request();
	virtual bool prepare();
	virtual simtime_t send();
	virtual void complete();

	virtual void printProcData(ProcessorData* pdata);

	virtual void sendDataToProcessor(ProcessorData* pdata);








	static int procDataCount;

	static int numOfNIFs;
	static int nifsDone;
	bool procIsDone;
	int numProcsDone;
	int leftToSend;

	int wBitsSent;
	int bitsSent;


	int conc;
	int id;
	simtime_t startSerTime;



	//stats
	StatObject* SO_bw;
	StatObject* SO_bwT;
	StatObject* SO_qTime;
	StatObject* SO_lat_conc;
	StatObject* SO_lat_ser;
	StatObject* SO_lat_prop;

	//processor side
	cGate* procReqIn;
	cGate* procReqOut;
	cGate* fromProc;
	cGate* toProc;

	//network side
	cGate* portIn;
    cGate* portOut;

	int concentration;

	bool sentRequest;

	ProcessorData *currData;
	ElectronicMessage* currMsg;
	cMessage* nextMsg;
	cMessage* completeMsg;

	list<ProcessorData*> waiting;
	queue<ProcessorData*> toProcQ;

	int flitWidth;

	bool stalled;

	queue<ElectronicMessage*> unacked;

	queue<cPacket*> packetQ;
	double clockPeriod_packet;
	double clockPeriod_enc;
	//want a double for the encryption overhead
	double clockPeriod_chk;
	//need a double to simulate the passage of a message explicitly for token passing over wireless

	double lastIn;

	int maxPacketSize;
	//static int pathsEstablished;
};

#endif /* WNIF_H_ */
