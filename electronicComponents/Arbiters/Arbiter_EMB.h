/*
 * Arbiter_EM.h
 *
 *  Created on: Mar 9, 2009
 *      Author: SolidSnake
 */

#ifndef ARBITER_EMB_H_
#define ARBITER_EMB_H_

#include "ElectronicArbiter.h"


class Arbiter_EMB : public ElectronicArbiter{
public:
	Arbiter_EMB();
	virtual ~Arbiter_EMB();

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
		EM_Node=4
	};

	double rndm[4];

};

#endif /* Arbiter_EMB_H_ */
