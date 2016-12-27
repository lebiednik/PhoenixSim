/*
 * Processor.h
 *
 *  Created on: Feb 8, 2009
 *      Author: Gilbert
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <omnetpp.h>
#include <string.h>

#include "Application.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

#include "Arbiter.h"

#include "sim_includes.h"

#include "DRAM_Cfg.h"

#include "thermalmodel.h"
#include <queue>

using namespace std;


class Processor : public cSimpleModule {
public:
	Processor();
	virtual ~Processor();

	static AddressTranslator* translator;

	static int numOfProcs;
	int myNum;
	//int keyTime;

protected:
		virtual void initialize (int stages);
		virtual void finish();
		virtual void handleMessage (cMessage *msg);
		virtual int numInitStages() const;
		Application* app;

		int appBitsSent;
		int appBitsRcvd;

		void sendRequest(ProcessorData* pdata);

		bool isStalled;   //waiting for communication or cache

		NetworkAddress* myAddr;
		int id;

		simtime_t clockPeriod_cntrl;

		simtime_t procOverhead;   //in seconds
		simtime_t init; // this is for ack gathering time measuring.

		static DRAM_Cfg* dramcfg;
		static bool dram_init;

		static int numDone;

		bool outstandingRequest;

		StatObject* SO_latency;
		StatObject* SO_latency_bcast;
		StatObject* SO_latency_backacks;
		StatObject* SO_msg;
		StatObject* SO_load;
		StatObject* SO_bw;
		StatObject* SO_bwTX;
		StatObject* SO_bw2;
		StatObject* SO_bw3;
		StatObject* SO_num_messages_in;
		StatObject* SO_num_messages_out;
		StatObject* SO_num_messages_0;
		StatObject* SO_num_messages_1;
		StatObject* SO_num_messages_2;
		StatObject* SO_num_messages_3;
		StatObject* SO_num_messages_4;
		StatObject* SO_num_messages_5;
		StatObject* SO_num_messages_6;
		StatObject* SO_num_messages_7;
		StatObject* SO_num_messages_8;
		StatObject* SO_num_messages_9;
		StatObject* SO_num_messages_10;
		StatObject* SO_num_messages_11;
		StatObject* SO_num_messages_12;
		StatObject* SO_num_messages_13;
		StatObject* SO_num_messages_14;
		StatObject* SO_num_messages_15;
		StatObject* SO_num_messages_16;
		StatObject* SO_num_messages_17;
		StatObject* SO_num_messages_18;
		StatObject* SO_num_messages_19;
		StatObject* SO_num_messages_20;
		StatObject* SO_num_messages_21;
		StatObject* SO_num_messages_22;
		StatObject* SO_num_messages_23;
		StatObject* SO_num_messages_24;
		StatObject* SO_num_messages_25;
		StatObject* SO_num_messages_26;
		StatObject* SO_num_messages_27;
		StatObject* SO_num_messages_28;
		StatObject* SO_num_messages_29;
		StatObject* SO_num_messages_30;
		StatObject* SO_num_messages_31;
		StatObject* SO_num_messages_32;
		StatObject* SO_num_messages_33;
		StatObject* SO_num_messages_34;
		StatObject* SO_num_messages_35;
		StatObject* SO_num_messages_36;
		StatObject* SO_num_messages_37;
		StatObject* SO_num_messages_38;
		StatObject* SO_num_messages_39;
		StatObject* SO_num_messages_40;
		StatObject* SO_num_messages_41;
		StatObject* SO_num_messages_42;
		StatObject* SO_num_messages_43;
		StatObject* SO_num_messages_44;
		StatObject* SO_num_messages_45;
		StatObject* SO_num_messages_46;
		StatObject* SO_num_messages_47;
		StatObject* SO_num_messages_48;
		StatObject* SO_num_messages_49;
		StatObject* SO_num_messages_50;
		StatObject* SO_num_messages_51;
		StatObject* SO_num_messages_52;
		StatObject* SO_num_messages_53;
		StatObject* SO_num_messages_54;
		StatObject* SO_num_messages_55;
		StatObject* SO_num_messages_56;
		StatObject* SO_num_messages_57;
		StatObject* SO_num_messages_58;
		StatObject* SO_num_messages_59;
		StatObject* SO_num_messages_60;
		StatObject* SO_num_messages_61;
		StatObject* SO_num_messages_62;
		StatObject* SO_num_messages_63;
		StatObject* SO_latency_bcast_0;
		StatObject* SO_latency_bcast_1;
		StatObject* SO_latency_bcast_2;
		StatObject* SO_latency_bcast_3;
		StatObject* SO_latency_bcast_4;
		StatObject* SO_latency_bcast_5;
		StatObject* SO_latency_bcast_6;
		StatObject* SO_latency_bcast_7;
		StatObject* SO_latency_bcast_8;
		StatObject* SO_latency_bcast_9;
		StatObject* SO_latency_bcast_10;
		StatObject* SO_latency_bcast_11;
		StatObject* SO_latency_bcast_12;
		StatObject* SO_latency_bcast_13;
		StatObject* SO_latency_bcast_14;
		StatObject* SO_latency_bcast_15;
		StatObject* SO_latency_bcast_16;
		StatObject* SO_latency_bcast_17;
		StatObject* SO_latency_bcast_18;
		StatObject* SO_latency_bcast_19;
		StatObject* SO_latency_bcast_20;
		StatObject* SO_latency_bcast_21;
		StatObject* SO_latency_bcast_22;
		StatObject* SO_latency_bcast_23;
		StatObject* SO_latency_bcast_24;
		StatObject* SO_latency_bcast_25;
		StatObject* SO_latency_bcast_26;
		StatObject* SO_latency_bcast_27;
		StatObject* SO_latency_bcast_28;
		StatObject* SO_latency_bcast_29;
		StatObject* SO_latency_bcast_30;
		StatObject* SO_latency_bcast_31;
		StatObject* SO_latency_bcast_32;
		StatObject* SO_latency_bcast_33;
		StatObject* SO_latency_bcast_34;
		StatObject* SO_latency_bcast_35;
		StatObject* SO_latency_bcast_36;
		StatObject* SO_latency_bcast_37;
		StatObject* SO_latency_bcast_38;
		StatObject* SO_latency_bcast_39;
		StatObject* SO_latency_bcast_40;
		StatObject* SO_latency_bcast_41;
		StatObject* SO_latency_bcast_42;
		StatObject* SO_latency_bcast_43;
		StatObject* SO_latency_bcast_44;
		StatObject* SO_latency_bcast_45;
		StatObject* SO_latency_bcast_46;
		StatObject* SO_latency_bcast_47;
		StatObject* SO_latency_bcast_48;
		StatObject* SO_latency_bcast_49;
		StatObject* SO_latency_bcast_50;
		StatObject* SO_latency_bcast_51;
		StatObject* SO_latency_bcast_52;
		StatObject* SO_latency_bcast_53;
		StatObject* SO_latency_bcast_54;
		StatObject* SO_latency_bcast_55;
		StatObject* SO_latency_bcast_56;
		StatObject* SO_latency_bcast_57;
		StatObject* SO_latency_bcast_58;
		StatObject* SO_latency_bcast_59;
		StatObject* SO_latency_bcast_60;
		StatObject* SO_latency_bcast_61;
		StatObject* SO_latency_bcast_62;
		StatObject* SO_latency_bcast_63;


		cGate* fromNic;
		cGate* toNic;
		cGate* reqOut;
		cGate* fromTG;

		static int msgsarrived;
		int acksarrived;

		queue<ProcessorData*> theQ;

		int flit_width;

		bool isNetworkSideConcentration;

		map<int, int> msgRx;

};

#endif /* PROCESSOR_H_ */
