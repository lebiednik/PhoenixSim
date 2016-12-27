#include "electronic_channel.h"
#include "statistics.h"
#include "math.h"

#include "RouterStat.h"

Register_Class( ElectronicChannel)
;

ElectronicChannel::ElectronicChannel() {

}

ElectronicChannel::~ElectronicChannel() {

}

void ElectronicChannel::finish() {

	debug(getFullPath(), "FINISH: start", UNIT_FINISH);

	debug(getFullPath(), "FINISH: done", UNIT_FINISH);
}

int ElectronicChannel::numInitStages() const {
	return 2;
}

void ElectronicChannel::initialize(int stage) {

	if (stage < 1)
		return;

	debug(getFullPath(), "INIT: start", UNIT_INIT);

	bool isData = par("isDataChannel");


	isThru = par("isThroughChannel");

	double clockRate;
	if (isData)
		clockRate = (double) par("O_frequency_data");
	else
		clockRate = (double) par("O_frequency_cntrl");

	datarate = clockRate * (int) par("electronicChannelWidth");
	clockPeriod = 1.0 / clockRate;

	if (par("wireDoublePumping")) {
		clockPeriod /= 2.0; //double pumping
		datarate *= 2;
	}

	spaceLengths = par("spaceLengths");
	routerLengths = par("routerLengths"); //number of router widths

	unitWireLength = par("coreSizeX");
	//unitWireLength *= 1e-3;  //it's in microns, put it into mm
	//routerWidth = 0;


	power = par("power");
	isVia = par("isVia");
	lowswing = par("lowswing");


	ePerBit = 0; //J/bit/mm
	staticPwr = 0;

	propDelay = 0;

	//loosely based of slides from v. stojanovic


	/*if(l < 2){
	 del = 0;
	 }
	 else if(l < 3){
	 del = 1;
	 ePerBit = 100e-15;
	 }
	 else if(l < 6){
	 del = 3;
	 ePerBit = 175e-15;
	 }
	 else if(l < 10){
	 del = 4;
	 ePerBit = 260e-15;
	 }
	 else{
	 del = 5;
	 ePerBit = 350e-15;
	 }*/

	energyInit = false;

	lastReport = 0;

	if (isData) {
		conf = Statistics::DEFAULT_ORION_CONFIG_DATA;
	} else {
		conf = Statistics::DEFAULT_ORION_CONFIG_CNTRL;
	}

	string statName = "Electronic Wire";
	P_static = Statistics::registerStat(statName, StatObject::ENERGY_STATIC,
			"electronic");
	E_dynamic = Statistics::registerStat(statName, StatObject::ENERGY_EVENT,
			"electronic");
	linked = Statistics::registerStat("Flits through links", StatObject::TOTAL,
            "electronic");

	StatObject *E_count = Statistics::registerStat(statName, StatObject::COUNT,
			"electronic");

	debug(getFullPath(), "INIT: done", UNIT_INIT);

}

/*bool ElectronicChannel::deliver(cMessage *msg, simtime_t at) {
 cPacket* p = (cPacket*) msg;

 //std::cout << "wire length is " << l << " mm " << endl;

 if (!energyInit) {

 double area = RouterStat::area;
 double side = sqrt(area);

 if (side > unitWireLength) {

 std::cout << "area: " << area << endl;
 std::cout << "side: " << side << endl;
 std::cout << "coreX: " << unitWireLength << endl;
 opp_error("Routers are too large for the chip");
 } else
 unitWireLength -= side;

 routerWidth = side;

 double l = spaceLengths * unitWireLength + routerLengths * routerWidth;

 if (l > 0) {
 if (power) {
 ePerBit = ORION_Link::LinkDynamicEnergyPerBitPerMeter(l * 1e-6,
 conf);
 staticPwr = ORION_Link::LinkLeakagePowerPerMeter(l * 1e-6,
 conf);

 ePerBit *= (l * 1e-6) / (lowswing ? 2 : 1);
 staticPwr *= (l * 1e-6) / (lowswing ? 2 : 1);

 P_static->track(staticPwr);

 //std::cout << "eperbit: " << ePerBit << endl;
 //std::cout << "static: " << staticPwr << endl;
 //std::cout << "Len: " << l << endl;
 //std::cout << "power: " << power << endl;
 //std::cout << "space: " << spaceLengths << endl;
 //std::cout << "router: " << routerLengths << endl;
 }

 int del;
 double h;
 ORION_Link::getOptBuffering(&del, &h, l, conf);
 delay = del * clockPeriod;
 }

 energyInit = true;
 }

 if (power) {

 E_dynamic->track(p->getBitLength() * ePerBit);
 lastReport = simTime();

 }

 simtime_t duration = isThru ? 0 : p->getBitLength() / datarate;
 txfinishtime = at + duration;
 p->setDuration(duration);

 //copied from cDatarateChannel.cc
 EVCB.messageSendHop(msg, getSourceGate(), delay, duration);
 return getSourceGate()->getNextGate()->deliver(msg, at);
 }
 */

void ElectronicChannel::processMessage(cMessage *msg, simtime_t t, result_t& result) {
	cPacket* p = (cPacket*) msg;
	//std::cout << "wire length is " << l << " mm " << endl;

	if (!energyInit) {



		if(!isVia){
			double area = RouterStat::area;
			double side = 0; //sqrt(area);

			if (side > unitWireLength) {

				std::cout << "area: " << area << endl;
				std::cout << "side: " << side << endl;
				std::cout << "coreX: " << unitWireLength << endl;
				opp_error("Routers are too large for the chip");
			} else
				unitWireLength -= side;

			routerWidth = side;
			//ev.printf("WireLength = %f, RouterWidth = %f\n",unitWireLength,routerWidth);

			l = spaceLengths * unitWireLength + routerLengths * routerWidth;
		} else {
			l = 20; // vias are approximately 20 micrometers long
		}

		if (l > 0) {
			if (power) {
				ePerBit = ORION_Link::LinkDynamicEnergyPerBitPerMeter(l * 1e-6,
						conf);
				staticPwr
						= ORION_Link::LinkLeakagePowerPerMeter(l * 1e-6, conf);

				//ePerBit *= (l * 1e-6) / (lowswing ? 2 : 1);
				//staticPwr *= (l * 1e-6) / (lowswing ? 2 : 1);

				ePerBit *= (l * 1e-6);
				staticPwr *= (l * 1e-6);;

				P_static->track(staticPwr);

				//std::cout << "eperbit: " << ePerBit << endl;
				//std::cout << "static: " << staticPwr << endl;
				//std::cout << "Len: " << l << endl;
				//std::cout << "power: " << power << endl;
				//std::cout << "space: " << spaceLengths << endl;
				//std::cout << "router: " << routerLengths << endl;
			}

			int del;
			double h;
			ORION_Link::getOptBuffering(&del, &h, l * 1e-6, conf);

			//if(del==0)
			del=1;

			propDelay = del * clockPeriod;
			// EVCON ev.printf("Link clock cycles: %d",del);
		}

		energyInit = true;
	}

	if (power) {

		E_dynamic->track(p->getBitLength() * ePerBit);
		lastReport = simTime();
		int numF = ceil(((cPacket *) msg)->getBitLength() / (int) par("electronicChannelWidth"));
		    linked->track(numF);

	}



	// datarate modeling
	if (datarate != 0 && msg->isPacket()) {
	    //int flits = ceil(((cPacket *) msg)->getBitLength() / (int) par("electronicChannelWidth"));
	    //if(flits<1)
	      //  flits = 1;
	    //simtime_t duration = flits * clockPeriod;
		//result.duration = duration;
		//txfinishtime = t + duration;
        simtime_t duration = ((cPacket *) msg)->getBitLength() / datarate;
        result.duration = 0;
        txfinishtime = t + 0;

	} else {
		txfinishtime = t;
	}

	// propagation delay modeling
	result.delay = propDelay;

}
