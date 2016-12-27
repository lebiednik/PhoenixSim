/*
 * AppAll2All.h
 *
 *  Created on: Feb 8, 2009
 *      Author: Gilbert
 */

#ifndef AppBcast_H_
#define AppBcast_H_

#include <omnetpp.h>

#include "Application.h"


class AppBcast : public Application {
public:

	AppBcast(int i, int n, double freq, DRAM_Cfg* cfg);
	virtual ~AppBcast();

	void init();

	virtual simtime_t process(ApplicationData* pdata);  //returns the amount of time needed to process before the next message comes
	virtual ApplicationData* getFirstMsg();  //returns the next message to be processed
	virtual ApplicationData* msgCreated(ApplicationData* pdata); //generates a message to be "processed" and sent
	virtual int getFurthestDest(int id); //returns the id of the furthest node
	virtual ApplicationData* dataArrive(ApplicationData* pdata);  //data has arrived for the application
	virtual int RoundToClk(double delay);


private:

	static int bcastRcvd;
	static int responseRcvd;
	double arrival; // in seconds
	double f;
	int numMessages;
	int numOfNodesX;
	int bits;
	double bcast_percent;
	double H; // temporal burstiness
	double sigma; // spatial inbalance

	int packetsToSend;

	int procLevelAck = 0;



};

#endif /* AppBcast_H_ */
