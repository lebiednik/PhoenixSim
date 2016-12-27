/*
 * Arbiter_EM.h
 *
 *  Created on: Mar 9, 2009
 *      Author: SolidSnake
 */

#ifndef ARBITER_3DM_H_
#define ARBITER_3DM_H_

#include "ElectronicArbiter.h"


class Arbiter_3DM : public ElectronicArbiter{
public:
	Arbiter_3DM();
	virtual ~Arbiter_3DM();

protected:
	virtual int route(ArbiterRequestMsg* rmsg);


	virtual int getDownPort(ArbiterRequestMsg* rmsg, int lev);
	virtual int getBcastOutport(ArbiterRequestMsg* bmsg);
	//bool isConc;

	enum PORTS {
		EM_N=0,
		EM_E=1,
		EM_S=2,
		EM_W=3,
		EM_UP=4,
		EM_DN=5,
		EM_Node=6
	};

};

#endif /* ARBITER_3DM_H_ */
