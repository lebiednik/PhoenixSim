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

#ifndef PHOTONIC4X4ARBITER_H_
#define PHOTONIC4X4ARBITER_H_

#include "PhotonicNoUturnArbiter.h"

class Photonic4x4Arbiter: public PhotonicNoUturnArbiter {
public:
	Photonic4x4Arbiter();
	virtual ~Photonic4x4Arbiter();

protected:
	void PSEsetup(int inport, int outport, PSE_STATE st);



	enum PORTS {
		SW_N = 0, SW_E, SW_S, SW_W, SW_NA
	};
};

#endif /* PHOTONIC4X4ARBITER_H_ */