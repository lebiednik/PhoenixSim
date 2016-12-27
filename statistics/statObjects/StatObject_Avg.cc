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

#include "StatObject_Avg.h"

StatObject_Avg::StatObject_Avg(string n) :
	StatObject(n) {

    type = AVG;
    total = 0;

}

StatObject_Avg::~StatObject_Avg() {
	// TODO Auto-generated destructor stub
}

void StatObject_Avg::stat_track(double d) {

	if (first) {
		min = d;
		max = d;
		first = false;
	} else {

		min = (d < min) ? d : min;
		max = (d > max) ? d : max;
	}
	total += d;
	count++;

}

string StatObject_Avg::getHeader() {
	return "Count,Min,Avg,Max";
}

void StatObject_Avg::writeValue(ofstream *of) {

	double avg = total / count;


	(*of) << count << "," << min << "," << avg << "," << max;
}
