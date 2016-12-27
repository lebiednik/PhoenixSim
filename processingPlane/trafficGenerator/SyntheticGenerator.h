/*
 * SyntheticGenerator.h
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#ifndef SYNTHETICGENERATOR_H_
#define SYNTHETICGENERATOR_H_

#include <omnetpp.h>
#include "messages_m.h"

#include "statistics.h"
#include "sim_includes.h"
#include "TGcore.h"

using namespace std;

#define MEM_READ_SIZE 64

class SyntheticGenerator : public TGcore
{
public:

	SyntheticGenerator(int N, double freq);
	virtual ~SyntheticGenerator();

	virtual ApplicationData* NextMessage();
	virtual int getNumMessages();
	virtual int NextSource();
	virtual int NextDestination(int source);
	virtual double NextDelay();

	virtual double getFinishTime();

	virtual void finish();

	int packetsToSend;

	// Variables for synthetic traffic
	double lambda;
	double *gausscdf;
	double bcast_percent;
	double H;
	int *sourceArray;
	double *rentcdf;
	string name;




};

#endif /* SyntheticGenerator_H_ */
