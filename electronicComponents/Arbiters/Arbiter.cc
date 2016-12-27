/*
 * Arbiter.cc
 *
 *  Created on: Mar 9, 2009
 *      Author: SolidSnake
 */

#include "Arbiter.h"
#include "statistics.h"

AddressTranslator* Arbiter::translator;

Arbiter::Arbiter() {

}

Arbiter::~Arbiter() {
    for (int i = 0; i < numVC; i++) {
        delete reqs[i];
    }

    for (int i = 0; i < numPorts; i++) {
        delete credits[i];
    }

    delete myAddr;
}

void Arbiter::init(string id, int lev, int x, int y, int z, int numV, int numP,
        int numpse, int buff_size, string n) {

    myAddr = new NetworkAddress(id, translator->numLevels);

    level = lev;



    numX = x;
    numY = y;
    numZ = z;

    if(numZ<1){
        myX = myAddr->id[level] % numX;
        myY = myAddr->id[level] / numX;
        myZ = 0;
    } else {
        myZ = floor(myAddr->id[level] / (numX*numY));
        myX = (myAddr->id[level]-myZ*numX*numY) % numX;
        myY = (myAddr->id[level]-myZ*numX*numY) / numX;
    }


    numPorts = numP;
    numVC = numV;
    numPSE = numpse;

    xbar = (int**) malloc(numPorts * sizeof(int*));
    xbarIn = (int**) malloc(numPorts * sizeof(int*));
        for (int i = 0; i < numPorts; i++) {
            xbar[i] = (int*) malloc(numPorts * sizeof(int));
            xbarIn[i] = (int*) malloc(numPorts * sizeof(int));
        }

    currVC = 0;

    name = n;

    for (int i = 0; i < numVC; i++) {
        reqs[i] = new list<ArbiterRequestMsg*> ();
    }

    for (int i = 0; i < numPorts; i++) {
        blockedIn[i] = false;
        blockedOut[i] = false;
        for(int j = 0; j < numPorts; j++){
            xbar[i][j] = -1;
            xbarIn[i][j] = -1;
        }


        credits[i] = new map<int, int> ();
        for (int j = 0; j < numVC; j++) {
            (*credits[i])[j] = buff_size;
        }
    }

    stalled = false;

}

int Arbiter::routeLevel(ArbiterRequestMsg* rmsg) {
    NetworkAddress* addr = (NetworkAddress*) rmsg->getDest();

    for (int i = 0; i < translator->numLevels; i++) {

        if (myAddr->id[i] != addr->id[i]) {
            if (i < level) {
                return getUpPort(rmsg, i);
            } else if (i == level) {
                return route(rmsg);
            } else if (i > level) {
                return getDownPort(rmsg, i);
            }
        }

    }

    return route(rmsg);

}

void Arbiter::newRequest(ArbiterRequestMsg* msg, int port) {
    int vc = msg->getVc();
    msg->setNewVC(vc);

    reqs[vc]->push_back(msg);

}

list<RouterCntrlMsg*>* Arbiter::grant(double time) {

    int vc = VirtualChannelControl::control->nextVC(&reqs, currVC);
    currVC = vc;

    list<ArbiterRequestMsg*>::iterator iter;

    list<ArbiterRequestMsg*>* lst = reqs[vc];

    map<int, int> requests;
    map<int, int> grants;

    // Inicialització GRANTS per aquest cicle de rellotge
    for (int i = 0; i < numPorts; i++) {
        requests[i] = 0;
        grants[i] = NA;
    }

    list<RouterCntrlMsg*> * msgs = new list<RouterCntrlMsg*> ();

    int numGrants = 0;

    // Per cadascun dels requests per servir...
    for (iter = lst->begin(); iter != lst->end() && numGrants < maxGrants;) {
        int inport = (*iter)->getPortIn();
        //int reqType = (*iter)->getReqType();

        int outport;
        int path;
        list<RouterCntrlMsg*> *tempLst;

        // TODO: mirar de fer tots els grants possibles aquí del Bcast


        // Es mira l'outport
        if ((*iter)->getBcast()) {

            outport = getBcastOutport(*iter);
            if (outport < 0) {
                if (numGrants == 0) {

                    RouterCntrlMsg *grant = (*iter)->dup();
                    grant->setType(router_grant_destroy);
                    grant->setData(1);
                    msgs->push_back(grant);
                    delete *iter;
                    iter = lst->erase(iter);
                    goto exit;

                } else {

                    goto exit;
                }

            }
        } else {
            debug(name, "getting Outport... ", UNIT_ROUTER);
            outport = getOutport(*iter);

        }
        requests[outport] = requests[outport] | ((int) inport);

        debug(name, "inport ... ", inport, UNIT_ROUTER);
        debug(name, "outport ... ", outport, UNIT_ROUTER);

        debug(name, "destination: ", translator->untranslate_str(
                ((NetworkAddress*) (*iter)->getDest())), UNIT_ROUTER);
        debug(name, "myAddr: ", translator->untranslate_str(myAddr),
                UNIT_ROUTER);


        // Per balanced multicast, necessitem que qualsevol que vagi al sud desde el source agafi la primera meitat de VC...
        if ( outport == 2 && inport == 4 ) {
           int currNewVC = (*iter)->getNewVC();
           int forcedVC = intrand(numVC/2);
           (*iter)->setNewVC(forcedVC);
        }
        // ...I que els que van al sud i llavors girin agafin qualsevol
        if ( inport == 0 && !(outport == 2) ) {
           int newnewVC = intrand(numVC);
           (*iter)->setNewVC(newnewVC);
        }

        // Es mirar si el path de sortida es pot prendre
        path = pathStatus(*iter, outport);

        // Si és així es fa.
        if (isPathGood(path)) {
            debug(name, "...good", UNIT_ROUTER);

            tempLst = setupPath(*iter, outport);
            numGrants++;
            grants[outport] = inport;

            if (requestComplete(*iter)) {
                if (tempLst->size() > 0) {
                    RouterCntrlMsg* r = tempLst->front();
                    // Quan enrutem, si girem hem de posar els LTB i RTB a zero sempre.
                    if(inport!=4 && (outport+inport)%2 == 1 ) {
                          r->setLTB(0);
                          r->setRTB(0);
                    }

                    r->setSourceBit(0);
                    r->setData(1);
                }
                done: delete *iter;
                iter = lst->erase(iter);
            } else {
                if (tempLst->size() > 0) {
                    RouterCntrlMsg* r = tempLst->front();
                    // Quan enrutem, si girem hem de posar els LTB i RTB a zero sempre.
                    if(inport!=4 && (outport+inport)%2 == 1 ) {
                          r->setLTB(0);
                          r->setRTB(0);
                    }
                    r->setSourceBit(0);
                    r->setData(0);
                }

            }

            msgs->insert(msgs->end(), tempLst->begin(), tempLst->end());
            tempLst->clear();
            delete tempLst;

        // Si no, es prenen les accions pertinents
        } else {
            pathNotSetup(*iter, path);
            iter++;
        }
    }

    exit:
#ifdef ENABLE_ORION
    // REVIEW revisar power amb nou crossbar
    for (int i = 0; i < numPorts; i++) {
        power[i]->record(requests[i], grants[i]);
    }

#endif

    //cleanup(numGrants);

    // Es retornen tots els grants
    return msgs;
}

int Arbiter::getOutport(ArbiterRequestMsg* rmsg) {

    return routeLevel(rmsg);
}

int Arbiter::getBcastOutport(ArbiterRequestMsg* bmsg) {

    opp_error("This kind of arbiter does not support broadcasting.");

    return -1;
}

bool Arbiter::requestComplete(ArbiterRequestMsg* rmsg) {

    rmsg->setStage(rmsg->getStage() + 1);

    bool ret = rmsg->getStage() >= numPorts;

    if (ret)
        rmsg->setBcast(false);

    return ret;
}

void Arbiter::cleanup(int numG) {

    if (numG == 0)
        stalled = true;
}

bool Arbiter::isPathGood(int p) {
    return p == GO_OK;
}

list<RouterCntrlMsg*>* Arbiter::setupPath(ArbiterRequestMsg* rmsg, int outport) {

    // REVIEW: setupPath implica dues coses.
        // Només bloquejar port d'entrada si hem acabat de servir un paquet

    int vc = rmsg->getNewVC();
    (*credits[outport])[vc] -= rmsg->getSize();
    xbar[outport][rmsg->getPortIn()] = 1;
    xbarIn[rmsg->getPortIn()][outport] = 1;
    blockedOut[outport] = true;
    if(!rmsg->getBcast() || (rmsg->getBcast() && rmsg->getStage() >= numPorts)) {
        blockedIn[rmsg->getPortIn()] = true;
    }


    list<RouterCntrlMsg*> *ret = new list<RouterCntrlMsg*> ();

    RouterCntrlMsg *grant = rmsg->dup();
    grant->setType(router_arb_grant);
    ret->push_back(grant);

    ElementControlMessage* xbarmsg = new ElementControlMessage();
    xbarmsg->setType(router_xbar);
    xbarmsg->setState(outport);
    xbarmsg->setPSEid(rmsg->getPortIn());
    ret->push_back(xbarmsg);

    return ret;

}

void Arbiter::creditsUp(int port, int vc, int size) {

    (*credits[port])[vc] += size;

    debug(name, "credits up ", (*credits[port])[vc], UNIT_BUFFER);

    stalled = false;
}

void Arbiter::unblock(int outport, int inport) {
    // REVIEW aquí cal buscar quin input es relaciona amb quin output


    //if (!blockedOut[outport] || !blockedIn[inport])
        //return;
        //opp_error("trying to unblock ports that weren't blocked. something is wrong.");
    if(!blockedOut[outport])
        opp_error("trying to unblock outport that was not blocked. something is wrong.");
    else
        blockedOut[outport] = false;

    // Buscar inport relacionat amb outport
    //int inport;
    //for (int i = 0; i < numPorts; i++) {
    //    if(xbar[outport][i]==1){
    //       inport = i;
    //    }
    //}
    if(inport <0 || inport > numPorts)
        opp_error("Bad inport.");

    // Mirar si inport ha estat servit per complet abans de desbloquejar-lo (suma xbar[i][inport] == -5)
    xbar[outport][inport] = -1;

    int aux = 0;
    for (int i = 0; i < numPorts; i++)
        aux = aux + xbar[i][inport];
    if( aux <= -numPorts ) {
        //if( !blockedIn[inport] )
            //opp_error("trying to unblock inport that was not blocked. something is wrong.");
        blockedIn[inport] = false;

    }
    //blockedIn[inport] = false;
    // REVIEW Should be inport kept blocked while broadcast is being served?


    debug(name, "port unblock to port ", outport, UNIT_XBAR);

    stalled = false;
}

void Arbiter::setPowerModels(map<int, ORION_Arbiter*> p) {
    power = p;
}

bool Arbiter::serveAgain() {
    if (stalled) {
        return false;
    }

    for (int i = 0; i < numVC; i++) {
        list<ArbiterRequestMsg*>* lst = reqs[i];
        //if (i != currVC && !lst->empty()) {
        if (!lst->empty()) {
            return true;
        }
    }
    return false;
}
