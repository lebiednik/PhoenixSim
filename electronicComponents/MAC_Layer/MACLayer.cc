
#include "MACLayer.h"
#include "statistics.h"


// include tots els fitxers de MAC
#include "MAC_FDMA.h"
#include "MAC_TDMA.h"
#include "MAC_token.h"
#include "MAC_CSMA.h"

Define_Module(MACLayer)
;


MACLayer::MACLayer() {

}

MACLayer::~MACLayer() {

}

void MACLayer::initialize() {

	// Passar paràmetres d'un ini
	idnum = par("idnum");
	numOfNodesX = par("numOfNodesX");
	coreSizeX = par("coreSizeX");
	numX = par("numX");
	numY = par("numY");
	channelCapacity = par("channelCapacity");




}

void MACLayer::finish() {

}

// Aquí es on va la teca... què fem quan arriba un missatge?
void MACLayer::handleMessage(cMessage *msg) {


	
}

void MACLayer::triggerTX(){


}




//Inicialitzar estadístiques?

/*
string statName = "Wireless Transceiver";
P_static = Statistics::registerStat(statName, StatObject::ENERGY_STATIC,
        "wireless");
E_dynamic = Statistics::registerStat(statName, StatObject::ENERGY_EVENT,
        "wireless");

// Static power of the transceiver is reported here (leakage?)
P_static->track(staticTranscPwr);

StatObject *E_count = Statistics::registerStat("Wireless Transceiver",
        StatObject::COUNT, "wireless");
*/
