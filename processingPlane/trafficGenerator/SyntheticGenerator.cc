/*
 * SyntheticGenerator.cc
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#include "SyntheticGenerator.h"
#include "math.h"
#include <crng.h>


SyntheticGenerator::SyntheticGenerator(int N, double freq) : TGcore() {


    f = freq;
    numOfNodes = N;
    packetsToSend = 0;

    // lambda gives generic load (mean interarrival time is 1/lambda)
    lambda = param1;
    small_percent = param4;
    bcast_percent = param6;
    H = param7;
    double sigma = param8;
    double p = param9;

    name = param5.substr(1, param5.length() - 2);

    fprintf(stderr, "App is %s \n", name.c_str());

    // SPATIAL INJECTION DISTRIBUTION
    // gausscdf gives the CDF of each node to transmit.
    // sourceArray gives the source indexes for each point in the CDF
        // Calculating spatial distribution of the load:
    gausscdf = (double *) malloc(numOfNodes *sizeof(double));
    double gausspdf = 0;
    // Recreate a gaussian CDF
    double k = 0;
    gausscdf[0] = exp( -pow( (k-0.5)/sigma, 2));
    for(int j=1;j<numOfNodes;j++){
        gausscdf[j] = gausscdf[j-1] + exp( -pow( (k-0.5)/sigma, 2));
        k++;
    }
    // Normalize it
    for(int j=0;j<numOfNodes;j++){
        gausscdf[j] = gausscdf[j]/gausscdf[numOfNodes-1];
        ev.printf("CDF for node %d is %f\n",j,gausscdf[j]);
     }
    // Randomizing indices
    int* taken;
    taken = (int *) malloc(numOfNodes *sizeof(int));
    sourceArray = (int *) malloc(numOfNodes *sizeof(int));
    for(int i=0;i<numOfNodes;i++) {
            taken[i]=0;
    }
    for(int i=0;i<numOfNodes;i++) {
        int rndm = intuniform(0,numOfNodes-1);
        while(taken[rndm]==1)
            rndm = intuniform(0,numOfNodes-1);
        taken[rndm]=1;
        sourceArray[i]=rndm;
        ev.printf("Index %d goes to node %d.\n",i,rndm);
    }

    // DESTINATION DISTRIBUTION
    // rentcdf gives the cdf of the distance to the destination
    int m = (int) sqrt(numOfNodes);
    double maxd = 2*m-2;
    double ff;
    rentcdf = (double *) malloc(maxd *sizeof(double));
    double sum = 0;

    for(double d=1.0;d<=maxd;d++) {
        if(d>=1 && d<m) {
            ff = d*d*d/3 - 2*m*d*d + d*(6*m*m-1)/3;
        } else {
            ff = 2*m*d*d - d*(12*m*m-1)/3 + 2*m*(4*m*m-1)/3 - d*d*d/3;
        }
        rentcdf[(int)(d-1)] = ff/d * ( pow(d*(d-1)+1,p) - pow(d*(d-1),p) + pow(d*(d+1),p) - pow(1+d*(d+1),p) );
        //ev.printf("p %f, ff %f, d %f, maxd %f.\n", p, ff, d, maxd);
        sum +=  rentcdf[(int)(d-1)];
    }

    rentcdf[0] /= sum;
   //fprintf(stderr,"rentcdf[0] is %f\n",rentcdf[0]);

    for(int i=1; i<maxd; i++) {
        rentcdf[i] = rentcdf[i]/sum + rentcdf[i-1];
     //   fprintf(stderr,"rentcdf[%d] is %f\n",i,rentcdf[i]);
    }

}

SyntheticGenerator::~SyntheticGenerator() {

}

int SyntheticGenerator::getNumMessages() {

    return param2;
}

ApplicationData* SyntheticGenerator::NextMessage() {

    int source = 0;
    int dest = -1;

    ApplicationData* adata = new ApplicationData();

    // Message size
    double rndm = uniform(0,100);
    if(rndm <= small_percent) {
        adata->setPayloadSize(112);
    } else {
        adata->setPayloadSize(496);
    }

    // Message source
    source = NextSource();
    adata->setSrcId(source);

    // Message type and destination
    rndm = uniform(0,100);
    if(rndm <= bcast_percent) {
        adata->setType(snoopReq);
        dest = getFurthestDest(source); // HACK: set destination id as the furthest destination, to measure bcast latency.
        adata->setDestId(dest);
        debug("application", "sending snoop bcast from ", source, UNIT_APP);
    } else {
        adata->setType(snoopResp);
        while(dest == -1)
            dest = NextDestination(source);
        adata->setDestId(dest);
        debug("application", "sending snoop unicast from ", source, UNIT_APP);
    }

    return adata;
}


void SyntheticGenerator::finish() {


}

double SyntheticGenerator::NextDelay() {

    double delay;
    double Tinburst = 1/(numOfNodes*f); // temps entre paquets d'un burst.
    double arrival = 1/(lambda*f);

    if ( H == 0.5 ) {
        delay = exponential(arrival);
    } else {
        // Si estem dins un burst, Tinburst
        if(packetsToSend > 0) {
            packetsToSend--;
            delay = Tinburst;

                // Si no, calculem la mida del pròxim burst i retornem el T_OFF
        } else {
            double aON = 3 - 2*H;
            double bON = 1; // b is the minimum value of x


            packetsToSend = nearbyint( pareto_shifted(aON,bON,0,0) );

            double L = Tinburst/arrival;
            if (L>0.97)
                L = 0.97;    // limitar L per no donar valors negatius de temps.

            // aOFF normally the same than aON...
            double aOFF = aON; //double aOFF = 1.04 + pow(aON-1.04, 1/(aON-1));

            double bOFF = Tinburst * bON *(1/L-1);
            //double EON = Tinburst * aON*bON / (aON-1);

            // If we ever use different aON and aOFF
            //double min = 1/intRandMax();
            //double correctionFactorON = (1-pow(min,(aON-1)/aON));
            //double correctionFactorOFF = (1-pow(min,(aOFF-1)/aOFF));
            //double bOFF = bON * (aON/aOFF) * (aOFF-1)/(aON-1) * (correctionFactorON/correctionFactorOFF) * (1/L - 1);



            delay = pareto_shifted(aOFF, bOFF, 0);
            if (delay <= 0) {
                opp_error("ERROR temps negatiu!");

            }

        }
    }

    return delay;
}

int SyntheticGenerator::NextSource() {

    double rndm = uniform(0,1);
    for(int i=0;i<numOfNodes;i++){
        if(rndm<=gausscdf[i])
            return sourceArray[i];
    }
}

int SyntheticGenerator::NextDestination(int source) {

    int des = 0;
    int mask;

    if(name.compare("uniform") == 0) {
        des = source;
        while(des == source)
            des = intuniform(0, numOfNodes-1);
        ev.printf("uniform, src: %d, dest: %d.\n", source, des);
    } else if(name.compare("bitComp") == 0) {
        if(numOfNodes == 64) {  mask = 0x3F;    }
        else if(numOfNodes == 256){      mask = 0xFF;   }
        des = source ^ mask;
        ev.printf("bitComp, src: %d, dest: %d.\n", source, des);
    } else if(name.compare("transp") == 0) {
        int row = source / sqrt(numOfNodes);
        int col = source % (int) sqrt(numOfNodes);
        des = col * sqrt(numOfNodes) + row;
        ev.printf("transp, src: %d, dest: %d.\n", source, des);
    } else if(name.compare("neigh") == 0) {
        int which = uniform(0, 4);
        int row = source / sqrt(numOfNodes);
        int col = source % (int) sqrt(numOfNodes);

        switch(which) {
            case 0: //N
                if(row == sqrt(numOfNodes)-1) {
                    des = (row-1) * sqrt(numOfNodes) + col;
                } else {
                    des = (row+1) * sqrt(numOfNodes) + col;
                }
                break;
            case 1: //E
                if(col == sqrt(numOfNodes)-1) {
                    des = row * sqrt(numOfNodes) + (col-1);
                } else {
                    des = row * sqrt(numOfNodes) + (col+1);
                }
                break;
            case 2: //S
                if(row == 0) {
                    des = (row+1) * sqrt(numOfNodes) + col;
                } else {
                    des = (row-1) * sqrt(numOfNodes) + col;
                }
                break;
            case 3: //W
                if(col == 0) {
                    des = row * sqrt(numOfNodes) + (col+1);
                } else {
                    des = row * sqrt(numOfNodes) + (col-1);
                }
                break;
            default:
                opp_error("neigh app should not be arriving here.");
                break;
        }
        ev.printf("neigh, src: %d, dest: %d.\n", source, des);
    } else if(name.compare("rent") == 0) {
        // source coordinates
        int row = source / sqrt(numOfNodes);
        int col = source % (int) sqrt(numOfNodes);
        // Take distance
        int distance;
        double rndm = uniform(0,1);
        int k = (int) sqrt(numOfNodes);
        int maxd = 2*k + 2;
        for(int d=0;d<maxd;d++){
                if(rndm<=rentcdf[d]) {
                    distance = d+1;
                    break;
                }
        }
        // check if source has destinations satisfying the distance, exit if so.
        int maxX = (col < k/2) ? (k-1-col) : col;
        int maxY = (row < k/2) ? (k-1-row) : row;
        if(maxX + maxY < distance) {
            return -1;
        }
        // calculate "x" and "y" movements
        int x = uniform(max(distance-maxY,0), min(distance, maxX)+1);
        int y = distance - x;
        // check possible quadrants.
        int ns = uniform(0, 2); // north or south
        int ew = uniform(0, 2); // east or west
        // Calculate destination
        if(ns == 0){ // go north if you can
            if(row + y >= sqrt(numOfNodes)) {
                des = (row - y) * sqrt(numOfNodes);
            } else {
                des = (row + y) * sqrt(numOfNodes);
            }
        } else { // go south if you can
            if(row - y < 0) {
                des = (row + y) * sqrt(numOfNodes);
            } else {
                des = (row - y) * sqrt(numOfNodes);
            }
        }
        if(ew == 0){ // go east if you can
            if(col + x >= sqrt(numOfNodes)) {
                des += (col - x);
            } else {
                des += (col + x);
            }
        } else { // go west if you can
            if(col - x < 0) {
                des += (col + x);
            } else {
                des += (col - x);
            }
        }
        ev.printf("rent, src: %d, dest: %d.\n", source, des);
    } else {
        opp_error("Hop distribution not recongnized.");
    }
    return des;
}



double SyntheticGenerator::getFinishTime() {

    return param2/param1/f;

}
