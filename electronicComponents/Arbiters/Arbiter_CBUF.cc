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

#include "Arbiter_CBUF.h"



Arbiter_CBUF::Arbiter_CBUF() {

}

Arbiter_CBUF::~Arbiter_CBUF() {

}


bool Arbiter_CBUF::isDimensionChange(int in, int out) {
	return false;
}

//returns the port num to go to
int Arbiter_CBUF::route(ArbiterRequestMsg* rmsg) {
    return 4;
}

int Arbiter_CBUF::routeLevel(ArbiterRequestMsg* rmsg) {
    return 4;
}

int Arbiter_CBUF::getOutport(ArbiterRequestMsg* bmsg) {
    return 4;
}

int Arbiter_CBUF::getBcastOutport(ArbiterRequestMsg* bmsg) {
    return 4;
}


int Arbiter_CBUF::getDownPort(ArbiterRequestMsg* rmsg, int lev) {
	debug(name, "calling downPort.. ", UNIT_ROUTER);

	NetworkAddress* addr = (NetworkAddress*)rmsg->getDest();
	int destId = addr->id[lev];


}
