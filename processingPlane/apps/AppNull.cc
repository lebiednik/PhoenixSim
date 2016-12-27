/*
 * AppNull.cc
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

// This APP does nothing. It lets centralized traffic generator take over control.


#include "AppNull.h"


AppNull::AppNull(int i, int n, DRAM_Cfg* cfg) :
Application(i, n, cfg) {

}

AppNull::~AppNull() {

}

simtime_t AppNull::process(ApplicationData* pdata) {

    return 1;

}

ApplicationData* AppNull::getFirstMsg() {

	return NULL;

}


ApplicationData* AppNull::msgCreated(ApplicationData* pdata)
{
	return NULL;
}


ApplicationData* AppNull::dataArrive(ApplicationData* pdata) {

	return NULL;

}

