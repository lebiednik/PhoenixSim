/*
 * Arbiter_3DM.cc
 *
 *  Created on: Mar 9, 2009
 *      Author: SolidSnake
 *
 *  Modified on: January, 2013
 *  	Author: Sergi Abadal
 */

#include "Arbiter_3DM.h"

Arbiter_3DM::Arbiter_3DM() {
	//isConc = isC;
}

Arbiter_3DM::~Arbiter_3DM() {
	// TODO Auto-generated destructor stub
}

//returns the port num to go to
int Arbiter_3DM::route(ArbiterRequestMsg* rmsg) {

	NetworkAddress* addr = (NetworkAddress*) rmsg->getDest();
	int destId = addr->id[level];

	int destX;
	int destY;
	int destZ;

	destZ = floor(destId / (numX*numY));
	destX = (destId - destZ*numX*numY) % numX;
	destY = (destId - destZ*numX*numY) / numY;


	debug(name, "destId ", destId, UNIT_ROUTER);
	debug(name, "...myId ", myAddr->id[level], UNIT_ROUTER);
	debug(name, "...myX ", myX, UNIT_ROUTER);
	debug(name, "...myY ", myY, UNIT_ROUTER);
	debug(name, "...myZ ", myZ, UNIT_ROUTER);

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
		} else // destX == myX && destY == myY
		{
			if(destZ > myZ) {
				return EM_UP;
			} else if (destZ < myZ) {
				return EM_DN;
			} else
				return EM_Node;
		}
	}

}

int Arbiter_3DM::getBcastOutport(ArbiterRequestMsg* bmsg) {
	int ret = -1;
	NetworkAddress* addr = (NetworkAddress*) bmsg->getSrc();
	int destId = addr->id[level];
	int inport = bmsg->getPortIn();
redo:
	switch (bmsg->getStage()) {
	case 0: //N
		if (myY == 0 || inport == EM_N || inport == EM_UP || inport == EM_DN) {
			bmsg->setStage(bmsg->getStage() + 1);
			goto redo;
		}else{
			ret = EM_N;
		}
		break;
	case 1: //E
		if (myX == numX-1 || inport == EM_E  || inport == EM_N  || inport == EM_S || inport == EM_UP || inport == EM_DN) {
			bmsg->setStage(bmsg->getStage() + 1);
			goto redo;
		}else{
			ret = EM_E;
		}
		break;
	case 2: //S
		if (myY == numY-1 || inport == EM_S || inport == EM_UP || inport == EM_DN) {
			bmsg->setStage(bmsg->getStage() + 1);
			goto redo;
		}else{
			ret = EM_S;
		}
		break;
	case 3: //W
		if (myX == 0 || inport == EM_W  || inport == EM_N  || inport == EM_S || inport == EM_UP || inport == EM_DN) {
			bmsg->setStage(bmsg->getStage() + 1);
			goto redo;
		}else{
			ret = EM_W;
		}
		break;
	case 4: //UP
		if (myZ == numZ-1 || inport == EM_UP) {
			bmsg->setStage(bmsg->getStage() + 1);
			goto redo;
		}else{
			ret = EM_UP;
		}
		break;
	case 5: //DOWN
		if (myZ == 0 || inport == EM_DN) {
			bmsg->setStage(bmsg->getStage() + 1);
			goto redo;
		}else{
			ret = EM_DN;
		}
		break;
	case 6: //local
		if(destId != myAddr->id[level])
			ret = EM_Node;
		break;
	default:
		opp_error("Arbiter_PM_Node: invalid stage in getBcastOutport");
	}

	return ret;
}

// TODO
// Nothing to do if we consider stacked memory
int Arbiter_3DM::getDownPort(ArbiterRequestMsg* rmsg, int lev) {
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
