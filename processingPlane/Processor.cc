/*
 * Processor.cc
 *
 *  Created on: Feb 8, 2009
 *      Author: Gilbert
 *
 *  Modified by Sergi Abadal, September 2012
 *  so as to include new functions.
 *  - Includes
 *  - Call from the initialization file (line ~335)
 *  - Check line ~500 which refers to a intermediate NIF concentratuion router
 */
#include <time.h>
#include "Processor.h"

#include "statistics.h"

#include "Application.h"
#include "AppNull.h"

#include "synthetics/AppRandom.h"
#include "synthetics/AppNeighbor.h"
#include "synthetics/AppTornado.h"
#include "synthetics/AppBitreverse.h"
#include "synthetics/AppHotspot.h"
#include "synthetics/AppBcast.h"

#include "DRAM/AppDRAMRandom.h"
#include "DRAM/AppDRAMAll2One.h"
#include "DRAM/AppDRAMOne2One.h"
#include "DRAM/AppDRAMOne2All.h"

#include "synthetics/AppRandom_FiniteQueue.h"

#include "test/AppAll2All.h"
#include "test/AppOne2One.h"

#include "trace/AppTrace_LBL.h"
#include "trace/App_LL_DepGraph.h"
//#include "trace/AppBcastTrace.h"

#include "model/AppFFT.h"
#include "model/AppFFTstream.h"
#include "model/AppDataFlow.h"


#include "DRAM_Cfg_Periphery.h"
#include "DRAM_Cfg_AllNodes.h"
#include "DRAM_Cfg_Periphery_SR16x16.h"
#include "DRAM_Cfg_Periphery_SR8x8.h"
#include "DRAM_Cfg_Periphery_SR4x4.h"

#include "SizeDistribution_Constant.h"
#include "SizeDistribution_Normal.h"
#include "SizeDistribution_Control.h"
#include "SizeDistribution_Gamma.h"
#include "SizeDistribution_InvGamma.h"

#include "AddressTranslator_Standard.h"
#include "AddressTranslator_SquareRoot.h"
#include "AddressTranslator_FatTree.h"

#include "MITUCB/App_MITUCB_Random.h"
#include "MITUCB/App_MITUCB_All2All.h"

Define_Module(Processor)
;

DRAM_Cfg* Processor::dramcfg;
bool Processor::dram_init = false;

int Processor::msgsarrived = 0;

int Processor::numDone = 0;

int Processor::numOfProcs = 0;

//int Processor::keyTime = time(0);

AddressTranslator* Processor::translator = NULL;

Processor::Processor() {
	// TODO Auto-generated constructor stub
	myNum = 0;

}

Processor::~Processor() {
	if (dramcfg != NULL) {
		delete dramcfg;
		dramcfg = NULL;
		dram_init = false;
	}

}

int Processor::numInitStages() const {
	return 2;
}

void Processor::initialize(int stage) {

	appBitsSent = 0;
	appBitsRcvd = 0;
	init = (simtime_t)0;

	if (stage == 0) {
		myNum = numOfProcs;
		numOfProcs++;
		return;
	}
	if (stage == 1) {
#ifdef ENABLE_HOTSPOT
#if HOTSPOT_GRANULARITY < 4
		if(true)
		{
			int side = floor(sqrt(numOfProcs) + 0.5);
			double sideLength = 20000;
			ThermalModel::registerThermalObject("Processor", getId(), sideLength/side, sideLength/side, int(myNum%side)*double(sideLength/side), int(myNum/side)*double(sideLength/side));
		}
		else
		{
			throw cRuntimeError("HotSpot Simulator requires definition of SizeWidth, SizeHeight, PositionLeftX, and PositionBottomY");
		}
#endif
#endif
	}
	if (stage == 2) {
		std::cout << numOfProcs << endl;
		return;
	}
	debug(getFullPath(), "INIT: start", UNIT_INIT);

	if (translator == NULL) {
		string trans_str = par("addressTranslator");

		if (trans_str.compare("standard") == 0) {
			translator = new AddressTranslator_Standard();
		} else if (trans_str.compare("square_root") == 0) {
			translator = new AddressTranslator_SquareRoot();
		} else if (trans_str.compare("fat_tree") == 0) {
			translator = new AddressTranslator_FatTree();
		} else {
			opp_error("Invalid address translator in Processor.");
		}

		translator->concentration = par("processorConcentration");
		translator->numProcs = numOfProcs;

		string str_pro = par("networkProfile");
		AddressTranslator::makeProfile(str_pro.substr(str_pro.find(";") + 1)
				+ "1." + par("processorConcentration").str() + ".",
				str_pro.substr(0, str_pro.find(";")) + "DRAM.PROC.");

	}

	string appStr = par("application");

	reqOut = gate("nicReq$o");
	fromNic = gate("fromNic");
	toNic = gate("toNic");
	fromTG = gate("fromTG");

	isNetworkSideConcentration = par("isNetworkSideConcentration");

	string str_id = par("id");


	clockPeriod_cntrl = 1.0 / (double) par("O_frequency_proc");
	flit_width = par("electronicChannelWidth");

	double ePerOp = par("energyPerOP");
	Application::ePerOp = ePerOp;
	Application::clockPeriod = SIMTIME_DBL(clockPeriod_cntrl);

	bool useioplane = par("useIOplane");

	myAddr = new NetworkAddress(str_id, translator->numLevels);

	id = translator->untranslate_pid(myAddr);

	debug(getFullPath(), "id_str: ", translator->untranslate_str(myAddr),
			UNIT_PROCESSOR);
	debug(getFullPath(), "id_pid: ", translator->untranslate_pid(myAddr),
			UNIT_PROCESSOR);

	Application::param1 = par("appParam1");
	Application::param2 = par("appParam2");
	Application::param3 = par("appParam3");
	Application::param4 = par("appParam4");

	Application::param5 = par("appParam5").str();

	Application::param6 = par("appParam6");

	Application::param7 = par("appParam7");
	Application::param8 = par("appParam8");


	//size dist
	SizeDistribution *sizedist;

	string sd = par("appSizeDist");

	if(sd.compare("constant") == 0){
		sizedist = new SizeDistribution_Constant(par("appSizeParam1"));
	}else if(sd.compare("normal") == 0){
		sizedist = new SizeDistribution_Normal(par("appSizeParam1"), par("appSizeParam2"));
	}else if(sd.compare("gamma") == 0){
		sizedist = new SizeDistribution_Gamma(par("appSizeParam1"), par("appSizeParam2"));
	}else if(sd.compare("invgamma") == 0){
		sizedist = new SizeDistribution_InvGamma(par("appSizeParam1"), par("appSizeParam2"));
	}else if(sd.compare("control") == 0){
		sizedist = new SizeDistribution_Control(par("appSizeParam1"), par("appSizeParam2"), par("appSizeParam3"),
				par("appSizeParam4"));
	}

	Application::sizeDist = sizedist;

	procOverhead = (int) par("procMsgOverhead") / (double) par("clockRate");

	numDone = 0;
	acksarrived = 0;

	SO_load = Statistics::registerStat("Load (Gb/s)", StatObject::TIME_AVG, "application");
	SO_bw = Statistics::registerStat("App RX Throughput (Gb/s)", StatObject::TIME_AVG, "application");
	SO_bwTX = Statistics::registerStat("App TX Throughput (Gb/s)", StatObject::TIME_AVG, "application");
	SO_bw2 = Statistics::registerStat("App Throughput Core Distribution (Gb/s)",
				StatObject::AVG, "application");
	SO_bw3 = Statistics::registerStat("App Throughput Time Distribution (Gb/s)",
					StatObject::AVG, "application");
	SO_latency = Statistics::registerStat("Latency (us)", StatObject::AVG,
			"application");
	SO_latency_bcast = Statistics::registerStat("Broadcast Latency (us)", StatObject::AVG,"application");
	SO_latency_backacks = Statistics::registerStat("ACKs all-to-one latency (us)", StatObject::AVG,"application");
	SO_msg = Statistics::registerStat("Msg Size (B)", StatObject::AVG,
			"application");
	//below taken from bw
	SO_num_messages_in = Statistics::registerStat("Total messages in", StatObject::TOTAL, "MAC");
	SO_num_messages_out = Statistics::registerStat("Total messages out", StatObject::TOTAL, "MAC");
	SO_num_messages_0 = Statistics::registerStat("Node 0", StatObject::TOTAL, "MAC");
	//p=0 gets all of the packets
	SO_num_messages_1 = Statistics::registerStat("Node 1 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_2 = Statistics::registerStat("Node 2 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_3 = Statistics::registerStat("Node 3 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_4 = Statistics::registerStat("Node 4 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_5 = Statistics::registerStat("Node 5 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_6 = Statistics::registerStat("Node 6 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_7 = Statistics::registerStat("Node 7 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_8 = Statistics::registerStat("Node 8 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_9 = Statistics::registerStat("Node 9 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_10 = Statistics::registerStat("Node 10 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_11 = Statistics::registerStat("Node 11 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_12 = Statistics::registerStat("Node 12 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_13 = Statistics::registerStat("Node 13 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_14 = Statistics::registerStat("Node 14 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_15 = Statistics::registerStat("Node 15 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_16 = Statistics::registerStat("Node 16 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_17 = Statistics::registerStat("Node 17 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_18 = Statistics::registerStat("Node 18 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_19 = Statistics::registerStat("Node 19 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_20 = Statistics::registerStat("Node 20 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_21 = Statistics::registerStat("Node 21 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_22 = Statistics::registerStat("Node 22 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_23 = Statistics::registerStat("Node 23 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_24 = Statistics::registerStat("Node 24 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_25 = Statistics::registerStat("Node 25 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_26 = Statistics::registerStat("Node 26 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_27 = Statistics::registerStat("Node 27 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_28 = Statistics::registerStat("Node 28 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_29 = Statistics::registerStat("Node 29 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_30 = Statistics::registerStat("Node 30 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_31 = Statistics::registerStat("Node 31 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_32 = Statistics::registerStat("Node 32 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_33 = Statistics::registerStat("Node 33 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_34 = Statistics::registerStat("Node 34 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_35 = Statistics::registerStat("Node 35 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_36 = Statistics::registerStat("Node 36 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_37 = Statistics::registerStat("Node 37 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_38 = Statistics::registerStat("Node 38 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_39 = Statistics::registerStat("Node 39 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_40 = Statistics::registerStat("Node 40 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_41 = Statistics::registerStat("Node 41 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_42 = Statistics::registerStat("Node 42 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_43 = Statistics::registerStat("Node 43 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_44 = Statistics::registerStat("Node 44 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_45 = Statistics::registerStat("Node 45 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_46 = Statistics::registerStat("Node 46 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_47 = Statistics::registerStat("Node 47 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_48 = Statistics::registerStat("Node 48 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_49 = Statistics::registerStat("Node 49 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_50 = Statistics::registerStat("Node 50 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_51 = Statistics::registerStat("Node 51 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_52 = Statistics::registerStat("Node 52 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_53 = Statistics::registerStat("Node 53 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_54 = Statistics::registerStat("Node 54 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_55 = Statistics::registerStat("Node 55 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_56 = Statistics::registerStat("Node 56 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_57 = Statistics::registerStat("Node 57 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_58 = Statistics::registerStat("Node 58 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_59 = Statistics::registerStat("Node 59 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_60 = Statistics::registerStat("Node 60 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_61 = Statistics::registerStat("Node 61 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_62 = Statistics::registerStat("Node 62 messages sent", StatObject::TOTAL, "MAC");
	SO_num_messages_63 = Statistics::registerStat("Node 63 messages sent", StatObject::TOTAL, "MAC");

	SO_latency_bcast_0 = Statistics::registerStat("Broadcast Latency Node 0 (us)", StatObject::AVG,"application");
	SO_latency_bcast_1 = Statistics::registerStat("Broadcast Latency Node 1(us)", StatObject::AVG,"application");
	SO_latency_bcast_2 = Statistics::registerStat("Broadcast Latency Node 2(us)", StatObject::AVG,"application");
	SO_latency_bcast_3 = Statistics::registerStat("Broadcast Latency Node 3(us)", StatObject::AVG,"application");
	SO_latency_bcast_4 = Statistics::registerStat("Broadcast Latency Node 4(us)", StatObject::AVG,"application");
	SO_latency_bcast_5 = Statistics::registerStat("Broadcast Latency Node 5(us)", StatObject::AVG,"application");
	SO_latency_bcast_6 = Statistics::registerStat("Broadcast Latency Node 6(us)", StatObject::AVG,"application");
	SO_latency_bcast_7 = Statistics::registerStat("Broadcast Latency Node 7(us)", StatObject::AVG,"application");
	SO_latency_bcast_8 = Statistics::registerStat("Broadcast Latency Node 8(us)", StatObject::AVG,"application");
	SO_latency_bcast_9 = Statistics::registerStat("Broadcast Latency Node 9(us)", StatObject::AVG,"application");
	SO_latency_bcast_10 = Statistics::registerStat("Broadcast Latency Node 10(us)", StatObject::AVG,"application");
	SO_latency_bcast_11 = Statistics::registerStat("Broadcast Latency Node 11(us)", StatObject::AVG,"application");
	SO_latency_bcast_12 = Statistics::registerStat("Broadcast Latency Node 12(us)", StatObject::AVG,"application");
	SO_latency_bcast_13 = Statistics::registerStat("Broadcast Latency Node 13(us)", StatObject::AVG,"application");
	SO_latency_bcast_14 = Statistics::registerStat("Broadcast Latency Node 14(us)", StatObject::AVG,"application");
	SO_latency_bcast_15 = Statistics::registerStat("Broadcast Latency Node 15(us)", StatObject::AVG,"application");
	SO_latency_bcast_16 = Statistics::registerStat("Broadcast Latency Node 16(us)", StatObject::AVG,"application");
	SO_latency_bcast_17 = Statistics::registerStat("Broadcast Latency Node 17(us)", StatObject::AVG,"application");
	SO_latency_bcast_18 = Statistics::registerStat("Broadcast Latency Node 18(us)", StatObject::AVG,"application");
	SO_latency_bcast_19 = Statistics::registerStat("Broadcast Latency Node 19(us)", StatObject::AVG,"application");
	SO_latency_bcast_20 = Statistics::registerStat("Broadcast Latency Node 20(us)", StatObject::AVG,"application");
	SO_latency_bcast_21 = Statistics::registerStat("Broadcast Latency Node 21(us)", StatObject::AVG,"application");
	SO_latency_bcast_22 = Statistics::registerStat("Broadcast Latency Node 22(us)", StatObject::AVG,"application");
	SO_latency_bcast_23 = Statistics::registerStat("Broadcast Latency Node 23(us)", StatObject::AVG,"application");
	SO_latency_bcast_24 = Statistics::registerStat("Broadcast Latency Node 24(us)", StatObject::AVG,"application");
	SO_latency_bcast_25 = Statistics::registerStat("Broadcast Latency Node 25(us)", StatObject::AVG,"application");
	SO_latency_bcast_26 = Statistics::registerStat("Broadcast Latency Node 26(us)", StatObject::AVG,"application");
	SO_latency_bcast_27 = Statistics::registerStat("Broadcast Latency Node 27(us)", StatObject::AVG,"application");
	SO_latency_bcast_28 = Statistics::registerStat("Broadcast Latency Node 28(us)", StatObject::AVG,"application");
	SO_latency_bcast_29 = Statistics::registerStat("Broadcast Latency Node 29(us)", StatObject::AVG,"application");
	SO_latency_bcast_30 = Statistics::registerStat("Broadcast Latency Node 30(us)", StatObject::AVG,"application");
	SO_latency_bcast_31 = Statistics::registerStat("Broadcast Latency Node 31(us)", StatObject::AVG,"application");
	SO_latency_bcast_32 = Statistics::registerStat("Broadcast Latency Node 32(us)", StatObject::AVG,"application");
	SO_latency_bcast_33 = Statistics::registerStat("Broadcast Latency Node 33(us)", StatObject::AVG,"application");
	SO_latency_bcast_34 = Statistics::registerStat("Broadcast Latency Node 34(us)", StatObject::AVG,"application");
	SO_latency_bcast_35 = Statistics::registerStat("Broadcast Latency Node 35(us)", StatObject::AVG,"application");
	SO_latency_bcast_36 = Statistics::registerStat("Broadcast Latency Node 36(us)", StatObject::AVG,"application");
	SO_latency_bcast_37 = Statistics::registerStat("Broadcast Latency Node 37(us)", StatObject::AVG,"application");
	SO_latency_bcast_38 = Statistics::registerStat("Broadcast Latency Node 38(us)", StatObject::AVG,"application");
	SO_latency_bcast_39 = Statistics::registerStat("Broadcast Latency Node 39(us)", StatObject::AVG,"application");
	SO_latency_bcast_40 = Statistics::registerStat("Broadcast Latency Node 40(us)", StatObject::AVG,"application");
	SO_latency_bcast_41 = Statistics::registerStat("Broadcast Latency Node 41(us)", StatObject::AVG,"application");
	SO_latency_bcast_42 = Statistics::registerStat("Broadcast Latency Node 42(us)", StatObject::AVG,"application");
	SO_latency_bcast_43 = Statistics::registerStat("Broadcast Latency Node 43(us)", StatObject::AVG,"application");
	SO_latency_bcast_44 = Statistics::registerStat("Broadcast Latency Node 44(us)", StatObject::AVG,"application");
	SO_latency_bcast_45 = Statistics::registerStat("Broadcast Latency Node 45(us)", StatObject::AVG,"application");
	SO_latency_bcast_46 = Statistics::registerStat("Broadcast Latency Node 46(us)", StatObject::AVG,"application");
	SO_latency_bcast_47 = Statistics::registerStat("Broadcast Latency Node 47(us)", StatObject::AVG,"application");
	SO_latency_bcast_48 = Statistics::registerStat("Broadcast Latency Node 48(us)", StatObject::AVG,"application");
	SO_latency_bcast_49 = Statistics::registerStat("Broadcast Latency Node 49(us)", StatObject::AVG,"application");
	SO_latency_bcast_50 = Statistics::registerStat("Broadcast Latency Node 50(us)", StatObject::AVG,"application");
	SO_latency_bcast_51 = Statistics::registerStat("Broadcast Latency Node 51(us)", StatObject::AVG,"application");
	SO_latency_bcast_52 = Statistics::registerStat("Broadcast Latency Node 52(us)", StatObject::AVG,"application");
	SO_latency_bcast_53 = Statistics::registerStat("Broadcast Latency Node 53(us)", StatObject::AVG,"application");
	SO_latency_bcast_54 = Statistics::registerStat("Broadcast Latency Node 54(us)", StatObject::AVG,"application");
	SO_latency_bcast_55 = Statistics::registerStat("Broadcast Latency Node 55(us)", StatObject::AVG,"application");
	SO_latency_bcast_56 = Statistics::registerStat("Broadcast Latency Node 56(us)", StatObject::AVG,"application");
	SO_latency_bcast_57 = Statistics::registerStat("Broadcast Latency Node 57(us)", StatObject::AVG,"application");
	SO_latency_bcast_58 = Statistics::registerStat("Broadcast Latency Node 58(us)", StatObject::AVG,"application");
	SO_latency_bcast_59 = Statistics::registerStat("Broadcast Latency Node 59(us)", StatObject::AVG,"application");
	SO_latency_bcast_60 = Statistics::registerStat("Broadcast Latency Node 60(us)", StatObject::AVG,"application");
	SO_latency_bcast_61 = Statistics::registerStat("Broadcast Latency Node 61(us)", StatObject::AVG,"application");
	SO_latency_bcast_62 = Statistics::registerStat("Broadcast Latency Node 62(us)", StatObject::AVG,"application");
	SO_latency_bcast_63 = Statistics::registerStat("Broadcast Latency Node 63(us)", StatObject::AVG,"application");


	if (useioplane) {
		if (!dram_init) {
			string dc = par("ioPlaneConfig");

			if (dc.compare("Periphery") == 0) {

				dramcfg = new DRAM_Cfg_Periphery(numOfProcs, par(
						"processorConcentration"));
				dram_init = true;
			} else if (dc.compare("SR4x4_Periphery") == 0) {

				dramcfg = new DRAM_Cfg_Periphery_SR4x4(numOfProcs, par(
						"processorConcentration"));
				dram_init = true;
			} else if (dc.compare("SR8x8_Periphery") == 0) {

				dramcfg = new DRAM_Cfg_Periphery_SR8x8(numOfProcs, par(
						"processorConcentration"));
				dram_init = true;
			} else if (dc.compare("SR16x16_Periphery") == 0) {

				dramcfg = new DRAM_Cfg_Periphery_SR16x16(numOfProcs, par(
						"processorConcentration"));
				dram_init = true;
			} else if (dc.compare("AllNodes") == 0) {

				dramcfg = new DRAM_Cfg_AllNodes(numOfProcs, par(
						"processorConcentration"));
				dram_init = true;
			} else {
				opp_error("unknown dramCfg specified.");
			}

			dramcfg->init();
		}
	} else {
		dramcfg = NULL;
	}

	//std::cout << "application: " << appStr << endl;
	if (appStr.find("fft_stream") != string::npos) {

		app = new AppFFTstream(id, numOfProcs, dramcfg);

	} else if (appStr.find("fft") != string::npos) {

		app = new AppFFT(id, numOfProcs, dramcfg);

	} else if (appStr.find("randomfq") != string::npos) {

		app = new AppRandom_FiniteQueue(id, numOfProcs, 0, 0);

	} else if (appStr.find("randomDRAM") != string::npos) { //format is random_[arrival]_[size]

		app = new AppRandomDRAM(id, numOfProcs, dramcfg);

	} else if (appStr.find("random") != string::npos) { //format is random_[arrival]_[size]

		app = new AppRandom(id, numOfProcs, 0, 0);

	} else if (appStr.find("neighbor") != string::npos) { //format is random_[arrival]_[size]

		app = new AppNeighbor(id, numOfProcs, 0, 0);

	}else if (appStr.find("tornado") != string::npos) { //format is random_[arrival]_[size]

		app = new AppTornado(id, numOfProcs, 0, 0);

	}else if (appStr.find("bitreverse") != string::npos) { //format is random_[arrival]_[size]

		app = new AppBitreverse(id, numOfProcs, 0, 0);

	}else if (appStr.find("hotspot") != string::npos) { //format is random_[arrival]_[size]

		app = new AppHotspot(id, numOfProcs, 0, 0);

	}else if (appStr.find("trace_lbl") != string::npos) {

		app = new AppTrace_LBL(id, numOfProcs, dramcfg);
	} else if (appStr.find("trace_ll") != string::npos) {

		app = new App_LL_DepGraph(id, numOfProcs, dramcfg);
	} else if (appStr.find("all2oneDRAM") != string::npos) {

		app = new AppAll2OneDRAM(id, numOfProcs, dramcfg);

	} else if (appStr.find("one2oneDRAM") != string::npos) {

		app = new AppOne2OneDRAM(id, numOfProcs, dramcfg);

	} else if (appStr.find("one2allDRAM") != string::npos) {

		app = new AppOne2AllDRAM(id, numOfProcs, dramcfg);

	} else if (appStr.find("all2all") != string::npos) {

		app = new AppAll2All(id, numOfProcs, dramcfg);

//	}else if (appStr.find("BcastTrace") != string::npos) {

//		app = new AppBcastTrace(id, numOfProcs, (double) par("O_frequency_proc"), dramcfg);

	}else if (appStr.find("Bcast") != string::npos) {

			app = new AppBcast(id, numOfProcs, (double) par("O_frequency_proc"), dramcfg);

	} else if (appStr.find("dataFlow") != string::npos) {

		app = new AppDataFlow(id, numOfProcs, dramcfg);

	} else if (appStr.find("one2one") != string::npos) {

		app = new AppOne2One(id, numOfProcs, dramcfg);

	} else if (appStr.find("MITUCBrand") != string::npos) {
		app = new App_MITUCB_Random(id, numOfProcs, 0, 0);
	} else if (appStr.find("MITUCBa2a") != string::npos) {

		app = new App_MITUCB_All2All(id, numOfProcs, dramcfg);
	} else if (appStr.find("CentralTG") != string::npos)  {

	    app = new AppNull(id, numOfProcs, dramcfg);

    }else {
		opp_error(
				"no application specified.  how am i supposed to know what kind of traffic to run?");
	}

	app->useioplane = useioplane;

	/* Processor asks for the first message */
	ApplicationData* pdata = app->getFirstMsg();
	if (pdata != NULL)
		scheduleAt(simTime() + app->process(pdata), pdata);


	outstandingRequest = false;

	debug(getFullPath(), "INIT: done", UNIT_INIT);
}

void Processor::finish() {

	debug(getFullPath(), "FINISH: start", UNIT_FINISH);

	if (app != NULL) {
		app->currentTime = simTime();
		app->finish();
		delete app;
	}

	delete myAddr;

	if (translator != NULL) {
		delete translator;
		translator = NULL;
	}
/*
	 while(theQ.size() > 0){
	 ProcessorData* pdata = theQ.front();
	 theQ.pop();
	 ApplicationData* adata = (ApplicationData*)pdata->decapsulate();
	 SO_latency->track(SIMTIME_DBL(simTime() - adata->getCreationTime()) / 1e-6); //put into us
	 delete adata;
	 delete pdata;
	 }
*/
	dram_init = false;
	numDone = 0;
	numOfProcs = 0;

	//ev.printf("%f\n",appBitsRcvd / (1e9*simTime()));
	SO_bw2->track(appBitsRcvd / simTime() / 1e9);//"App Throughput Core Distribution (Gb/s)"

	debug(getFullPath(), "FINISH: done", UNIT_FINISH);
}

void Processor::handleMessage(cMessage* msg) {

	string appStr = par("application");
	app->currentTime = simTime();
  //if (time(0)-keyTime > 10){//If key is more than 10 seconds old then change the key
		//keyTime = time(0);
		//usleep(.007);

	//}
	if (msg->isSelfMessage()) { //self messages are to be sent somewhere (these are App messages)
		ApplicationData* adata = check_and_cast<ApplicationData*> (msg);

		if (adata->getType() == CPU_op) {
			ApplicationData* next = app->dataArrive(adata);

			if (next != NULL) {
				scheduleAt(simTime() + app->process(next), next);
			}

			delete adata;

			return;
		}

		adata->setIsComplete(true);
		adata->setCreationTime(simTime());
		SO_load->track(adata->getPayloadSize() / 1e9);

		ProcessorData* pdata = new ProcessorData();

		pdata->setDestAddr((long) translator->translateAddr(adata));
		pdata->setSrcAddr((long) myAddr->dup());
		pdata->setIsComplete(true);
		pdata->setId(globalMsgId++);
		pdata->setCreationTime(simTime());

		debug(getFullPath(), " from ", translator->untranslate_str(myAddr),
				UNIT_PROCESSOR);
		debug(getFullPath(), "message to (id) ", adata->getDestId(),
				UNIT_PROCESSOR);
		debug(getFullPath(), "message to (addr) ", translator->untranslate_str(
				(NetworkAddress*) pdata->getDestAddr()), UNIT_PROCESSOR);

		pdata->setSize(adata->getPayloadSize());
		pdata->encapsulate(adata);
		pdata->setType(adata->getType());
		theQ.push(pdata);

		if (!outstandingRequest) {
			outstandingRequest = true;

			sendRequest(pdata);
		}

		ApplicationData* next = app->msgCreated(adata);
		if (next != NULL) {
			appBitsSent += adata->getPayloadSize();
			scheduleAt(simTime() + app->process(next), next);
		}

	} else if (msg->getArrivalGate() == fromNic) {
		// EVCOM ev.printf("Message arrived to the processor\n");
		ProcessorData* pdata = check_and_cast<ProcessorData*> (msg);

		//	debug(getFullPath(), "message arrived at: ",	translator->untranslate_str((NetworkAddress*) pdata->getDestAddr()), UNIT_PROCESSOR);
		// debug(getFullPath(), "from: ", translator->untranslate_str(	(NetworkAddress*) pdata->getSrcAddr()), UNIT_PROCESSOR);

		//std::cout << "messages arrived: " << ++msgsarrived << endl;


		if (pdata->getIsComplete()) {
		    // EVCOM ev.printf("Message is complete\n");
			debug(getFullPath(), "message is complete", UNIT_PROCESSOR);

			if (!((NetworkAddress*) pdata->getDestAddr())->equals(myAddr) && pdata->getType() != snoopReq) {
				ev << "id: " << translator->untranslate_str(myAddr)
						<< endl;
				ev << "dest: " << translator->untranslate_str(
						((NetworkAddress*) pdata->getDestAddr())) << endl;

				ev << pdata->getId() << endl;
				opp_error("ERROR: message delivered to the wrong processor");
			}

			//msgRx.erase(pdata->getId());

			ApplicationData* adata = (ApplicationData*) pdata->decapsulate();

			//if (adata->getIsComplete()) {


			ApplicationData* next = app->dataArrive(adata);


			// Check the latency
			if (appStr.find("Bcast") != string::npos || appStr.find("CentralTG") != string::npos){ // BROADCAST APP

				if(adata->getType() == snoopReq){ // BROADCAST PACKET
				    if(adata->getDestId() == id) {  // only count once, for the selected dist.
				        SO_latency_bcast->track(SIMTIME_DBL(simTime() //+ ceil(adata->getPayloadSize()/flit_width)*clockPeriod_cntrl
														- adata->getCreationTime()) / 1e-6); //put into us
				    }
				} else { // UNICAST PACKET
				    SO_latency->track(SIMTIME_DBL(simTime() //+ ceil(adata->getPayloadSize()/flit_width)*clockPeriod_cntrl
				                            - adata->getCreationTime()) / 1e-6); //put into us
				}
			} else { // OTHER APPS
	            SO_latency->track(SIMTIME_DBL(simTime() //+ ceil(adata->getPayloadSize()/flit_width)*clockPeriod_cntrl
	                    - adata->getCreationTime()) / 1e-6); //put into us
			}


			appBitsRcvd += adata->getPayloadSize();
			SO_bw->track(adata->getPayloadSize() / 1e9);//"App RX Throughput (Gb/s)"
			SO_num_messages_in->track(1);
			SO_bw3->track(adata->getPayloadSize() / simTime() / 1e9);//"App Throughput Time Distribution (Gb/s)"

			int destID = adata->getDestId();
			int n = adata->getSrcId();
			if (destID == id){ //check if this is the destination node
				if (n ==0 ){ //track source of message if destined for this node
					SO_num_messages_0->track(1);
					SO_latency_bcast_0->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 1){
					SO_num_messages_1->track(1);
					SO_latency_bcast_1->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==2){
					SO_num_messages_2->track(1);
					SO_latency_bcast_2->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 3){
					SO_num_messages_3->track(1);
					SO_latency_bcast_3->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==4){
					SO_num_messages_4->track(1);
					SO_latency_bcast_4->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 5){
					SO_num_messages_5->track(1);
					SO_latency_bcast_5->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==6){
					SO_num_messages_6->track(1);
					SO_latency_bcast_6->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 7){
					SO_num_messages_7->track(1);
					SO_latency_bcast_7->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==8){
					SO_num_messages_8->track(1);
					SO_latency_bcast_8->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n ==9){
					SO_num_messages_9->track(1);
					SO_latency_bcast_9->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==10){
					SO_num_messages_10->track(1);
					SO_latency_bcast_10->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 11){
					SO_num_messages_11->track(1);
					SO_latency_bcast_11->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==12){
					SO_num_messages_12->track(1);
					SO_latency_bcast_12->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 13){
					SO_num_messages_13->track(1);
					SO_latency_bcast_13->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==14){
					SO_num_messages_14->track(1);
					SO_latency_bcast_13->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 15){
					SO_num_messages_15->track(1);
					SO_latency_bcast_15->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==16){
					SO_num_messages_16->track(1);
					SO_latency_bcast_16->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 17){
					SO_num_messages_17->track(1);
					SO_latency_bcast_17->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==18){
					SO_num_messages_18->track(1);
					SO_latency_bcast_18->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n ==19){
					SO_num_messages_19->track(1);
					SO_latency_bcast_19->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==20){
					SO_num_messages_20->track(1);
					SO_latency_bcast_20->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 21){
					SO_num_messages_21->track(1);
					SO_latency_bcast_21->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==22){
					SO_num_messages_22->track(1);
					SO_latency_bcast_22->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 23){
					SO_num_messages_23->track(1);
					SO_latency_bcast_23->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==24){
					SO_num_messages_24->track(1);
					SO_latency_bcast_24->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 25){
					SO_num_messages_25->track(1);
					SO_latency_bcast_25->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==26){
					SO_num_messages_26->track(1);
					SO_latency_bcast_26->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 27){
					SO_num_messages_27->track(1);
					SO_latency_bcast_27->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==28){
					SO_num_messages_28->track(1);
					SO_latency_bcast_28->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n ==29){
					SO_num_messages_29->track(1);
					SO_latency_bcast_29->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==30){
					SO_num_messages_30->track(1);
					SO_latency_bcast_30->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 31){
					SO_num_messages_31->track(1);
					SO_latency_bcast_31->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==32){
					SO_num_messages_32->track(1);
					SO_latency_bcast_32->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 33){
					SO_num_messages_33->track(1);
					SO_latency_bcast_33->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==34){
					SO_num_messages_34->track(1);
					SO_latency_bcast_34->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 35){
					SO_num_messages_35->track(1);
					SO_latency_bcast_35->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==36){
					SO_num_messages_36->track(1);
					SO_latency_bcast_36->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 37){
					SO_num_messages_37->track(1);
					SO_latency_bcast_37->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==38){
					SO_num_messages_38->track(1);
					SO_latency_bcast_38->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n ==39){
					SO_num_messages_39->track(1);
					SO_latency_bcast_39->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==40){
					SO_num_messages_40->track(1);
					SO_latency_bcast_40->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 41){
					SO_num_messages_41->track(1);
					SO_latency_bcast_41->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==42){
					SO_num_messages_42->track(1);
					SO_latency_bcast_42->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 43){
					SO_num_messages_43->track(1);
					SO_latency_bcast_43->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==44){
					SO_num_messages_44->track(1);
					SO_latency_bcast_44->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 45){
					SO_num_messages_45->track(1);
					SO_latency_bcast_45->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==46){
					SO_num_messages_46->track(1);
					SO_latency_bcast_46->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 47){
					SO_num_messages_47->track(1);
					SO_latency_bcast_47->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==48){
					SO_num_messages_48->track(1);
					SO_latency_bcast_48->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n ==49){
					SO_num_messages_49->track(1);
					SO_latency_bcast_49->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==50){
					SO_num_messages_50->track(1);
					SO_latency_bcast_50->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 51){
					SO_num_messages_51->track(1);
					SO_latency_bcast_51->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==52){
					SO_num_messages_52->track(1);
					SO_latency_bcast_52->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 53){
					SO_num_messages_53->track(1);
					SO_latency_bcast_53->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==54){
					SO_num_messages_54->track(1);
					SO_latency_bcast_54->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 55){
					SO_num_messages_55->track(1);
					SO_latency_bcast_55->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==56){
					SO_num_messages_56->track(1);
					SO_latency_bcast_56->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n == 57){
					SO_num_messages_57->track(1);
					SO_latency_bcast_57->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==58){
					SO_num_messages_58->track(1);
					SO_latency_bcast_58->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n ==59){
					SO_num_messages_59->track(1);
					SO_latency_bcast_59->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==60){
					SO_num_messages_60->track(1);
					SO_latency_bcast_60->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==61){
					SO_num_messages_61->track(1);
					SO_latency_bcast_61->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n ==62){
					SO_num_messages_62->track(1);
					SO_latency_bcast_62->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
				else if (n==63){
					SO_num_messages_63->track(1);
					SO_latency_bcast_63->track(SIMTIME_DBL(simTime()- adata->getCreationTime()) / 1e-6);
				}
			}

			if (next != NULL) {
				scheduleAt(simTime() + app->process(next), next);
			}
			//}
			SO_msg->track(adata->getPayloadSize() / 8);

			delete adata;

			//delete (NetworkAddress*) pdata->getDestAddr();
			//delete (NetworkAddress*) pdata->getSrcAddr();

#ifdef ENABLE_HOTSPOT
	ThermalModel::addThermalObjectEnergy("Processor", getId(), 10000*1e-9);
#endif

			//}
		}

		////}
		////if (pdata->getIsComplete()) {
		//int p = myAddr->id[AddressTranslator::convertLevel("PROC")];
		////send unblock
		//// These may have to be omitted since we will not have routers before arriving to the NIF
		//XbarMsg *unblock = new XbarMsg();
		//unblock->setType(router_arb_unblock);
		//unblock->setToPort(p);


		//sendDelayed(unblock, clockPeriod_cntrl, reqOut);


		delete pdata;

	} else if (msg->getArrivalGate() == fromTG) { // similar to self-message from APP

	    ApplicationData* adata = check_and_cast<ApplicationData*> (msg);

        adata->setIsComplete(true);
        adata->setCreationTime(simTime());
        SO_load->track(adata->getPayloadSize() / 1e9);
        appBitsSent += adata->getPayloadSize();

        ProcessorData* pdata = new ProcessorData();

        pdata->setDestAddr((long) translator->translateAddr(adata));
        pdata->setSrcAddr((long) myAddr->dup());
	    pdata->setIsComplete(true);
	    pdata->setId(globalMsgId++);
	    pdata->setCreationTime(simTime());

	    debug(getFullPath(), " from ", translator->untranslate_str(myAddr),
	            UNIT_PROCESSOR);
	    debug(getFullPath(), "message to (id) ", adata->getDestId(),
	            UNIT_PROCESSOR);
	    debug(getFullPath(), "message to (addr) ", translator->untranslate_str(
	            (NetworkAddress*) pdata->getDestAddr()), UNIT_PROCESSOR);

	    pdata->setSize(adata->getPayloadSize());
	    pdata->encapsulate(adata);
	    pdata->setType(adata->getType());
	    theQ.push(pdata);

	    if (!outstandingRequest) {
	        outstandingRequest = true;
            sendRequest(pdata);
        }

	} else { //the request port -> request grant, request send, request sent
		RouterCntrlMsg* rmsg = check_and_cast<RouterCntrlMsg*> (msg);

		if (rmsg->getType() == proc_grant) { // Request grant, convey Sending(...) to app.
			ProcessorData* pdata = theQ.front();

			ApplicationData* adata = (ApplicationData*) pdata->getEncapsulatedPacket();
			SO_bwTX->track(adata->getPayloadSize() / 1e9);//"App TX Throughput (Gb/s)"
			SO_num_messages_out->track(1);


			send(pdata, toNic);

			ApplicationData* next = app->sending(
					(ApplicationData*) pdata->getEncapsulatedPacket());

			if (next != NULL) { // If more processing is to be done, wait until it is finished
				scheduleAt(simTime() + app->process(next), next);
			}

			theQ.pop();

			//if we have core-side concentration and the destination is a neighbor processor,
			// let the application know that the message was completely sent
			NetworkAddress* src = (NetworkAddress*) pdata->getSrcAddr();
			NetworkAddress* dest = (NetworkAddress*) pdata->getDestAddr();
			if (translator->concentration > 1 && !isNetworkSideConcentration
					&& src->id[AddressTranslator::convertLevel("PROC")]
							!= dest->id[AddressTranslator::convertLevel("PROC")]
					&& src->id[AddressTranslator::convertLevel("DRAM")]
							== dest->id[AddressTranslator::convertLevel("DRAM")]
					&& src->id[AddressTranslator::convertLevel("NET")]
							== dest->id[AddressTranslator::convertLevel("NET")]) {
				ApplicationData* next = app->msgSent(
						(ApplicationData*) pdata->getEncapsulatedPacket());

				if (next != NULL) {
					scheduleAt(simTime() + app->process(next), next);
				}
			}

			outstandingRequest = false;

			if (theQ.size() > 0) {
				sendRequest(theQ.front());

				outstandingRequest = true;
			}
		} else if (rmsg->getType() == proc_req_send) { //req_send from NIF, immediately grant NIF
			RouterCntrlMsg* gr = new RouterCntrlMsg();
			gr->setType(proc_grant);
			send(gr, reqOut);
		} else if (rmsg->getType() == proc_msg_sent) { // request sent, convey msgSent(...) to app.
			ApplicationData* adata = (ApplicationData*) rmsg->getData();

			ApplicationData* next = app->msgSent(adata);

			if (next != NULL) { // If more processing is to be done, wait until it is finished
				scheduleAt(simTime() + app->process(next), next);
			}

			delete adata;

		}


		delete msg;

	}

}

void Processor::sendRequest(ProcessorData* pdata) {

	ArbiterRequestMsg* req = new ArbiterRequestMsg();
	req->setStage(10000);
	req->setType(proc_req_send);
	req->setVc(0);
	req->setDest(pdata->getDestAddr());
	req->setReqType(dataPacket);
	req->setPortIn(myAddr->lastId());
	req->setSize(1);
	req->setTimestamp(simTime());
	req->setMsgId(pdata->getId());

	send(req, reqOut);
#ifdef ENABLE_HOTSPOT
	ThermalModel::addThermalObjectEnergy("Processor", getId(), 10000*1e-9);
#endif
}
