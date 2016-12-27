//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "Arbiter_FB.h"

int Arbiter_FB::FB_Node = 6;
int Arbiter_FB::FB_Mem = 7;

Arbiter_FB::Arbiter_FB() {
	// TODO Auto-generated constructor stub

}

Arbiter_FB::~Arbiter_FB() {
	// TODO Auto-generated destructor stub
}

bool Arbiter_FB::isDimensionChange(int inport, int outport) {
	//this is for a mesh, or torus
	/*if (inport < 6) {
		if (outport < 6) {
			return (inport < 3) ^ (outport < 3);
		} else
			return false;
	} else if (outport < 6) {
		return true;
	} else*/
		//two NICs, which is fine
		return false;
}

//returns the port num to go to
int Arbiter_FB::route(ArbiterRequestMsg* rmsg){
	NetworkAddress* addr = (NetworkAddress*) rmsg->getDest();
	int destId = addr->id[level];

	int destX; int routerX;
	int destY; int routerY;
	int port;

	destX = destId % (numX*2);
	destY = destId / (numY*2);

	routerX = (destX >> 1);
	routerY = (destY >> 1);

	debug(name, "destId ", destId, UNIT_ROUTER);
	debug(name, "...myId ", myAddr->id[level], UNIT_ROUTER);
	debug(name, "...myX ", myX, UNIT_ROUTER);
	debug(name, "...myY ", myY, UNIT_ROUTER);

	if(routerX > myX)
	{
		return routerX-1;
	}
	else if(routerX < myX)
	{
		return routerX;
	}
	else //(destX == myX)
	{
		if(routerY > myY)
		{
			return numX-1+routerY-1;
		}
		else if(routerY < myY)
		{
			return numX-1+routerY;
		}
		else
		{
			//if(destType == node_type_memory){

			//	return numPorts-1;
			//}else
			//	return 6 + (((destId % (numX*2)) % 2) + 2*((destId / (numY*2)) % 2));
		    port = 2*(numX -1) + (((destId % (numX*2)) % 2) + 2*((destId / (numY*2)) % 2));
		    return port; // 2(numX-1) is the num of ports going to the network, the rest is to choose inside the concentration

		}
	}

}


int Arbiter_FB::getDownPort(ArbiterRequestMsg* rmsg, int lev){
	NetworkAddress* addr = (NetworkAddress*) rmsg->getDest();
	int destId = addr->id[lev];

	//if(lev == translator->convertLevel("DRAM") && destId == 1){
		//return FB_Mem;
	//}

	return route(rmsg);
}

int Arbiter_FB::getBcastOutport(ArbiterRequestMsg* bmsg) {
    int ret = -1;
    NetworkAddress* addr = (NetworkAddress*) bmsg->getSrc();
    int destId = addr->id[level];
    int inport = bmsg->getPortIn();

redo:

    // HORIZONTAL
    if(bmsg->getStage() <= numX - 2) {
        if(inport <= numX + numY - 3) { // People coming from HORT or VERT will not do hort.
            bmsg->setStage(numX-1);
            goto redo;
        }else{
            ret = bmsg->getStage();
        }
    // VERTICAL
    } else if(bmsg->getStage() <= numX + numY - 3) {
        if(inport > numX-2 && inport <= numX + numY - 3) { // People from VERT will not do vert.
            bmsg->setStage(numX+numY-2);
            goto redo;
        }else{
            ret = bmsg->getStage();
        }
     // LOCAL
     } else if(bmsg->getStage() < numX+numY+1) { // Everyone goes local except the sender.
         if(destId != myAddr->id[level]) {
             ret = bmsg->getStage();
         } else {
             bmsg->setStage(bmsg->getStage()+1);
             goto redo;
         }
     } else if(bmsg->getStage() == numX+numY+1) {
        if(destId != myAddr->id[level]) {
            ret = bmsg->getStage();
        }
     } else {
        opp_error("Arbiter_PM_Node: invalid stage in getBcastOutport");
    }

    return ret;
}

