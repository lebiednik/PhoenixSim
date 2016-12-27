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

#ifndef ARBITER_BFT_H_
#define ARBITER_BFT_H_

#include "ElectronicArbiter.h"

class Arbiter_BFT: public ElectronicArbiter {
public:
	Arbiter_BFT();
	virtual ~Arbiter_BFT();

protected:
	virtual int route(ArbiterRequestMsg* rmsg);
	virtual bool isDimensionChange(int in, int out);

	virtual int getDownPort(ArbiterRequestMsg* rmsg, int lev);
	virtual int getBcastOutport(ArbiterRequestMsg* bmsg);
	//bool isConc;

	enum PORTS {
			EM_DN0=0,
			EM_DN1=1,
			EM_DN2=2,
			EM_DN3=3,
			EM_UP0=4,
			EM_UP1=5
		};

};


#endif /* ARBITER_BFT_H_ */
