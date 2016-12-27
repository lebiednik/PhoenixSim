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

#ifndef ARBITER_ET_H_
#define ARBITER_ET_H_

#include "ElectronicArbiter.h"

class Arbiter_ET: public ElectronicArbiter {
public:
	Arbiter_ET();
	virtual ~Arbiter_ET();

	virtual int route(ArbiterRequestMsg* rmsg);

	virtual int getDownPort(ArbiterRequestMsg* rmsg, int lev);

	//bool isConc;

	enum PORTS {
		EM_N = 0,
		EM_E,
		EM_S,
		EM_W,
		EM_Node,
		EM_Mem
	};
};

#endif /* ARBITER_ET_H_ */