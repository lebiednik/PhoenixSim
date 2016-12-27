/*
 * TraceBasedGenerator.cc
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#include "TraceBasedGenerator.h"
#include "math.h"


TraceBasedGenerator::TraceBasedGenerator(int N, double freq) {

    // TODO: revisar...
    f = freq;
    numOfNodes = N;

    currMsg = 0;

    speed = param1;
    arch = param2;
    small_percent = param4;
    application = param5.substr(1, param5.length() - 2);
    appN = param6;

    // Full filename with appropriate folder, number of nodes and application
    char NN[2];
    itoa(appN,NN,10);
    switch(arch) {
        case 0:
            strcpy(fileName,"../../traces/MESI/");
            break;
        case 1:
            strcpy(fileName,"../../traces/HAMMER/");
            break;
        case 2:
            strcpy(fileName,"../../traces/TOKEN/");
            break;
         default:
             opp_error("Architecture not supported.\n");
    }
    strcat(fileName,NN);
    strcat(fileName,"/");
    strcat(fileName, application.c_str());
    strcat(fileName,".stats.mat");
    //ev.printf("%s",fileName);


    // Open MAT trace and get the variables we are interested in (inter-arrival time and source address)
    pmat = matOpen(fileName, "r");
    if (pmat == NULL)
        opp_error("Cannot find the MAT file of application %s for %s nodes running over architecture %d\n", application.c_str(), N, arch);
    pa1 = matGetVariable(pmat, "iatGLOBAL");
    if (pa1 == NULL)
        opp_error("Error reading existing matrix iatGLOBAL\n");
    pa2 = matGetVariable(pmat, "sourceAddr");
    if (pa2 == NULL)
        opp_error("Error reading existing matrix sourceAddr\n");

    // Obtain the number of messages and malloc two auxiliar variables
    size_t sizepa = mxGetNumberOfElements(pa1);
    nMessages = (int)sizepa;

    //ev.printf("iatGLOBAL, sourceAddr have %d elements.\n", (int)sizepa);
    arrivals = (double *) malloc(sizeof(double) * (int)sizepa);
    arrivals = (double *) mxGetData(pa1);
    sources = (double *) malloc(sizeof(double) * (int)sizepa);
    sources = (double *) mxGetData(pa2);

}


TraceBasedGenerator::~TraceBasedGenerator() {

}

int TraceBasedGenerator::getNumMessages() {

    return nMessages;

}

ApplicationData* TraceBasedGenerator::NextMessage() {

    int source = NextSource();

    ApplicationData* adata = new ApplicationData();

    adata->setSrcId(source);
    double rndm = uniform(0,100);
        if(rndm <= small_percent) {
            adata->setPayloadSize(112);
        } else {
            adata->setPayloadSize(496);
        }
    adata->setType(snoopReq);
    int dest = getFurthestDest(source); // HACK: set destination id as the furthest destination, to measure bcast latency.
    adata->setDestId(dest);
    debug("application", "sending snoop bcast from ", source, UNIT_APP);

    currMsg++;

    return adata;

}

double TraceBasedGenerator::NextDelay() {

    return arrivals[currMsg]/speed;

}

int TraceBasedGenerator::NextSource() {

    return sources[currMsg];

}

void TraceBasedGenerator::finish() {

    // Free memory and close trace
    mxDestroyArray(pa1);
    mxDestroyArray(pa2);
    if (matClose(pmat) != 0)
            opp_error("Error closing file %s\n",fileName);
    free(arrivals);
    free(sources);


}

double TraceBasedGenerator::getFinishTime() {

    double finish_t=0;
    for(int i=0;i<nMessages;i++) {
        finish_t += arrivals[i];
    }
    return finish_t/speed;
}
