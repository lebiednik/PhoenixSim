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

#include "Arbiter_BFT.h"



Arbiter_BFT::Arbiter_BFT() {

}

Arbiter_BFT::~Arbiter_BFT() {

}


bool Arbiter_BFT::isDimensionChange(int in, int out) {
	return false;
}

//returns the port num to go to
int Arbiter_BFT::route(ArbiterRequestMsg* rmsg) {
	int ret = -1;

	NetworkAddress* addr = (NetworkAddress*)rmsg->getDest();
	int destId = addr->id[level];
	int destX;
	int destY;
	destX = destId % numX;
	destY = destId / numY;

	// TODO: revisar check index - colocar on toca, inicialitzant suposo
	/*int routerLevel;
	for(i=1;i<numOfLevels;i++){
		if(index < (2^i-1)*numX*numY/2^(i+1)){
			routerLevel = i;
			break;
		}
	}
	localAddr = index%((2^(routerLevel-1)-1)*numX*numY/(2^routerLevel));

	// CHECK IF PACKET HAS TO GO DOWN
	if(routerLevel==numOfLevels){ // If address is below your area of influence

		if ( (destX%(2^(routerLevel-1) > )
		// Return the correct port
			/*if (destX > myX) {
				if (myY == 0 || myY == numY - 1) {
					if (destX - myX >= 2) {
						if (myX % 4 == 1 || myX % 4 == 0) {
							return (myY == 0) ? CM_N : CM_S;
						}
					}
				}

				return CM_E;
			} else if (destX < myX) {
				if (myY == 0 || myY == numY - 1) {
					if (myX - destX >= 2) {
						if (myX % 4 == 2 || myX % 4 == 3) {
							return (myY == 0) ? CM_N : CM_S;
						}
					}
				}

				return CM_W;
			} else //(destX == myX)
			{
				if (destY > myY) {
					if (myX == 0 || myX == numX - 1) {
						if (destY - myY >= 2) {
							if (myY % 4 == 1 || myY % 4 == 0) {
								return (myX == 0) ? CM_W : CM_E;
							}
						}
					}

					return CM_S;
				} else if (destY < myY) {
					if (myX == 0 || myX == numX - 1) {
						if (myY - destY >= 2) {
							if (myY % 4 == 2 || myY % 4 == 3) {
								return (myX == 0) ? CM_W : CM_E;
							}
						}
					}
					return CM_N;*/
	/*}
	// IF NOT, GO UP, RANDOMLY
	else {
		ret = (intrand(2) >= 1) ? FT_UP1 : FT_UP0;
	}

	/*switch(floor(intrand(4))) {
		case 0:
			ret = EM_DN0;
			break;
		case 1:
			ret = EM_DN1;
			break;
		case 2:
			ret = EM_DN2;
			break;
		default:
			ret = EM_DN3;

	}


	return ret;*/
}


int Arbiter_BFT::getBcastOutport(ArbiterRequestMsg* bmsg) {
	int ret = -1;
	NetworkAddress* addr = (NetworkAddress*) bmsg->getSrc();
	int destId = addr->id[level];
	int inport = bmsg->getPortIn();
}


int Arbiter_BFT::getDownPort(ArbiterRequestMsg* rmsg, int lev) {
	debug(name, "calling downPort.. ", UNIT_ROUTER);

	NetworkAddress* addr = (NetworkAddress*)rmsg->getDest();
	int destId = addr->id[lev];


}
