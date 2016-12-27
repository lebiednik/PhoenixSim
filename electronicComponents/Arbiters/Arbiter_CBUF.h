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

#ifndef ARBITER_CBUF_H_
#define ARBITER_CBUF_H_

#include "ElectronicArbiter.h"

class Arbiter_CBUF: public ElectronicArbiter {
public:
	Arbiter_CBUF();
	virtual ~Arbiter_CBUF();

protected:
	virtual int route(ArbiterRequestMsg* rmsg);
	virtual bool isDimensionChange(int in, int out);
	virtual int routeLevel(ArbiterRequestMsg* rmsg);
	virtual int getOutport(ArbiterRequestMsg* bmsg);

	virtual int getDownPort(ArbiterRequestMsg* rmsg, int lev);
	virtual int getBcastOutport(ArbiterRequestMsg* bmsg);
	//bool isConc;

	enum PORTS {
			EM_DN0=0,
			EM_DN1=1,
			EM_DN2=2,
			EM_DN3=3,
			EM_UP=4
		};

};


#endif /* ARBITER_CBUF_H_ */
