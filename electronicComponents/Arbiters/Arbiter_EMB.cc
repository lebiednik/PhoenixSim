/*
 * Arbiter_EMB.cc
 *
 *  Created on: Sept. 2014
 *      Author: Abadal (based on Arbiter_EM.cc)
 */
// Created by Abadal, Sept. 2014 to (ideally) route multicasts/broadcasts like Krishna, 2011.

#include "Arbiter_EMB.h"

Arbiter_EMB::Arbiter_EMB() {
    //isConc = isC;
    //for(int i=0;i<4;i++)
    //     rndm[i] = uniform(0,1);

}

Arbiter_EMB::~Arbiter_EMB() {
    // TODO Auto-generated destructor stub
}

//returns the port num to go to
int Arbiter_EMB::route(ArbiterRequestMsg* rmsg) {

    NetworkAddress* addr = (NetworkAddress*) rmsg->getDest();
    int destId = addr->id[level];

    int destX;
    int destY;

    destX = destId % numX;
    destY = destId / numY;

    debug(name, "destId ", destId, UNIT_ROUTER);
    debug(name, "...myId ", myAddr->id[level], UNIT_ROUTER);
    debug(name, "...myX ", myX, UNIT_ROUTER);
    debug(name, "...myY ", myY, UNIT_ROUTER);

    if (destX > myX) {
        return EM_E;
    } else if (destX < myX) {
        return EM_W;
    } else //(destX == myX)
    {
        if (destY > myY) {
            return EM_S;
        } else if (destY < myY) {
            return EM_N;
        } else {

            return EM_Node;
        }
    }

}


int Arbiter_EMB::getBcastOutport(ArbiterRequestMsg* bmsg) {
    int ret = -1;
    NetworkAddress* addr = (NetworkAddress*) bmsg->getSrc();
    int destId = addr->id[level];
    int inport = bmsg->getPortIn();


    if(bmsg->getSourceBit()) {

        // Stage 0-3: for each direction > select LTBs, select RTB following Krishna's rules, (stage 3 dummy)
        // bmsg->setSourceBit(0); > això es fa quan el flit es serveix, ho comunica el grant per arbiter.cc
    redo:
        switch(bmsg->getStage()) {
            case 0: // N
                // Random LTBs for all ports
                for(int i=0;i<4;i++)
                    rndm[i] = uniform(0,1);

                // Set to North
                if (myY == 0) {
                      bmsg->setStage(bmsg->getStage() + 1);
                      goto redo;
                }else{
                    // LTB
                     if(rndm[EM_N] >= 0.5)
                          bmsg->setLTB(1);
                     else
                          bmsg->setLTB(0);

                     // RTB
                     if(rndm[EM_E] >= 0.5)
                          bmsg->setRTB(0);
                     else
                          bmsg->setRTB(1);

                    ret = EM_N;
                }
                break;
            case 1: // E

                if (myX == numX-1) {
                      bmsg->setStage(bmsg->getStage() + 1);
                      goto redo;
                }else{
                    if(rndm[EM_E] >= 0.5)
                         bmsg->setLTB(1);
                    else
                         bmsg->setLTB(0);

                    if(rndm[EM_S] >= 0.5)
                         bmsg->setRTB(0);
                    else
                         bmsg->setRTB(1);

                    ret = EM_E;
                }
                break;
            case 2: // S
                if (myY == numY-1) {
                      bmsg->setStage(bmsg->getStage() + 1);
                      goto redo;
                }else{
                    if(rndm[EM_S] >= 0.5)
                         bmsg->setLTB(1);
                    else
                         bmsg->setLTB(0);

                    if(rndm[EM_W] >= 0.5)
                         bmsg->setRTB(0);
                    else
                         bmsg->setRTB(1);


                    ret = EM_S;
                }
                break;

            case 3: // W

                if (myX == 0) {
                    bmsg->setStage(bmsg->getStage() + 1);
                    goto redo;
                } else {
                    if(rndm[EM_W] >= 0.5)
                         bmsg->setLTB(1);
                    else
                         bmsg->setLTB(0);

                    if(rndm[EM_N] >= 0.5)
                         bmsg->setRTB(0);
                    else
                         bmsg->setRTB(1);

                    ret = EM_W;
                }
                break;

            case 4:
                break;

            default: // NO LOCAL
                opp_error("Arbiter_EMB: invalid sourceBit/stage combination in getBcastOutport");

         }


    } else {
        // Other routers:
        // Go straight, turn left or right depending on LTB or RTB (deactivating them if turning).
           // Deactivation is done at arbiter.cc
        // Then to core.

        // Crossbar is made in such a way that we need to put cases in order
    redo2:
        switch(bmsg->getStage()) {
            case 0: // N
                if( myY != 0    &&   (inport == EM_S || (bmsg->getLTB() && inport == EM_W) || (bmsg->getRTB() && inport == EM_E) )) {
                        ret = EM_N;
                } else {
                    bmsg->setStage(bmsg->getStage() + 1);
                    goto redo2;
                }
                break;

            case 1: // E
                if( myX != numX-1    &&   (inport == EM_W || (bmsg->getLTB() && inport == EM_N) || (bmsg->getRTB() && inport == EM_S) )) {
                        ret = EM_E;
                } else {
                        bmsg->setStage(bmsg->getStage() + 1);
                        goto redo2;
               }
               break;

             case 2: // S
                  if( myY != numY-1    &&   (inport == EM_N || (bmsg->getLTB() && inport == EM_E) || (bmsg->getRTB() && inport == EM_W) )) {
                          ret = EM_S;
                  } else {
                          bmsg->setStage(bmsg->getStage() + 1);
                          goto redo2;
                 }
             break;

             case 3: // W
                  if( myX != 0    &&   (inport == EM_E || (bmsg->getLTB() && inport == EM_S) || (bmsg->getRTB() && inport == EM_N) )) {
                          ret = EM_W;
                  } else {
                          bmsg->setStage(bmsg->getStage() + 1);
                          goto redo2;
                 }
                 break;

           case 4: //local
                if(destId != myAddr->id[level])
                    ret = EM_Node;
                break;
            default:
                opp_error("Arbiter_EMB: invalid sourceBit/stage combination in getBcastOutport");
        }
    }

    return ret;
}


int Arbiter_EMB::getDownPort(ArbiterRequestMsg* rmsg, int lev) {
    NetworkAddress* addr = (NetworkAddress*) rmsg->getDest();
    int destId = addr->id[lev];

    if (lev == translator->convertLevel("DRAM") && destId == 1) {
        if (myY == 0) {
            return EM_N;
        } else if (myY == numY - 1) {
            return EM_S;
        } else if (myX == 0) {
            return EM_W;
        } else if (myX == numX - 1) {
            return EM_E;
        } else {
            return route(rmsg);
        }
    }else if(this->variant == 0){
        return EM_Node;
    }else if(this->variant == 1){
        int p = addr->id[translator->convertLevel("PROC")];
        return EM_Node + p;

    }
}
