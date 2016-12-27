/*
 * AppNull.h
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

// This APP does nothing. It lets centralized traffic generator take over control.

#ifndef APPNULL_H_
#define APPNULL_H_

#include <omnetpp.h>

#include "Application.h"


class AppNull : public Application {
public:

    AppNull(int i, int n, DRAM_Cfg* cfg);
	virtual ~AppNull();

	virtual simtime_t process(ApplicationData* pdata);  //returns the amount of time needed to process before the next message comes
	virtual ApplicationData* getFirstMsg();  //returns the next message to be processed
	virtual ApplicationData* msgCreated(ApplicationData* pdata); //generates a message to be "processed" and sent
	virtual ApplicationData* dataArrive(ApplicationData* pdata);  //data has arrived for the application



};

#endif /* APPNULL_H_ */
