/*
 * TraceBasedGenerator.h
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#ifndef TraceBasedGenerator_H_
#define TraceBasedGenerator_H_

#include <omnetpp.h>
#include "messages_m.h"

#include "statistics.h"
#include "sim_includes.h"
#include "TGcore.h"
#include "mat.h"

using namespace std;

#define MEM_READ_SIZE 64

class TraceBasedGenerator : public TGcore {
public:

	TraceBasedGenerator(int N, double freq);
	virtual ~TraceBasedGenerator();

	virtual ApplicationData* NextMessage();
    virtual int getNumMessages();
    virtual int NextSource();
    virtual double NextDelay();

    virtual double getFinishTime();
    virtual void finish();

	int nMessages;
	int currMsg;

    // Variables for trace
    double speed;
    int arch;
    string application;
    double appN;
    double *arrivals;
    double *sources;

    MATFile *pmat;
    mxArray *pa1, *pa2;
    char fileName[128];

};

#endif /* TraceBasedGenerator_H_ */
