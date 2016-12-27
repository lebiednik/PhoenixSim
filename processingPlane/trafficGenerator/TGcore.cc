/*
 * TGcore.cc
 *
 *  Created on: Dec. 2014
 *      Author: Abadal
 */

#include "TGcore.h"
#include "math.h"
//#include "mat.h"


double TGcore::param1;
double TGcore::param2;
double TGcore::param3;
double TGcore::param4;
string TGcore::param5;
double TGcore::param6;
double TGcore::param7;
double TGcore::param8;
double TGcore::param9;

int TGcore::furthDest;

TGcore::TGcore() {

}


TGcore::~TGcore() {

}



void TGcore::finish() {


}


int TGcore::getFurthestDest(int id)
{
    // Assume square multiprocessor
    int numOfNodesX = (int) sqrt(numOfNodes);
    int numX;
    int numY;

    int result = 0;

    numX = id % numOfNodesX;
    numY = floor(id/numOfNodesX);


    if(furthDest == 0) { // RMESH: complementary corner

        if((double) numX > ((numOfNodesX-1)/2))
            result = 0;
        else
            result = numOfNodesX-1;

        if((double) numY > ((numOfNodesX-1)/2))
            result += 0;
        else
            result += (numOfNodesX-1)*numOfNodesX;

    } else { // FBFLY: always rightmost.

        if(numX < numOfNodesX-2)
            result = numOfNodesX -1;
        else
            result = numOfNodesX -3;

        if(numY < numOfNodesX -2)
            result += (numOfNodesX-1)*numOfNodesX;
        else
            result += (numOfNodesX-3)*numOfNodesX;

    }

    return result;
}
