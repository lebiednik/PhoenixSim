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

#ifndef STATOBJECT_StaticTotal_H_
#define STATOBJECT_StaticTotal_H_

#include <omnetpp.h>

#include "StatObject.h"

class StatObject_StaticTotal : public StatObject_Static {
public:
	StatObject_StaticTotal(string n);
	virtual ~StatObject_StaticTotal();

	virtual void stat_track(double d);

	virtual string getHeader();
	virtual void writeValue(ofstream *of);

	virtual double getValue();

private:
	double total;
};

#endif /* STATOBJECT_StaticTotal_H_ */
