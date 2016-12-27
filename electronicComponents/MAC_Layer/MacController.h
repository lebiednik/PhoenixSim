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

#ifndef MACCONTROLLER_H_
#define MACCONTROLLER_H_

#include <omnetpp.h>
#include <map>
#include <queue>
#include "messages_m.h"
#include "sim_includes.h"

#include "NetworkAddress.h"
#include "AddressTranslator.h"

using namespace std;


class MacController: public cSimpleModule {
public:
    MacController();
    virtual ~MacController();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();


private:

    queue<int> nodeQueue;
    queue<int> lengthQueue;
    queue<simtime_t> durationQueue;

    int idnum;
    int numOfNodesX;
    int numOfNodesY;
    double dieSize;
    double channelCapacity;
    double clockRate;
    double clockPeriod;

    double maxTau;

    cMessage *busyChannel;


    void notifyNode(int idNum, int autLength);
};

#endif /* MACCONTROLLER_H_ */
