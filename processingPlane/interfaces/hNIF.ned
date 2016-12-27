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

package processingPlane.interfaces;



module hNIF
{
    parameters:

        int id;
        double O_frequency_cntrl;

        int electronicChannelWidth;
        int routerBufferSize;
        int maxPacketSize;

		int parallelFC;
        int routerVirtualChannels;
        
        string NIF_type;
        int hNIF_type;

        int processorConcentration;
        int numNetPorts;

        @display("i=block/ifcard;bgb=447,415");
    gates:
		// Hybrid NIF has numNetPorts from "electronic" and 1 from "wireless" 
        input portIn[numNetPorts+1];
        output portOut[numNetPorts+1];


        inout procReq;
        input fromProc;
        output toProc;
        
        input ackIn;
        output ackOut;

    submodules:

        wNIF: wNIF {
            id = id;


            @display("p=316,312");
        }

        eNIF: <NIF_type> like NIF {
            id = id;
            numNetPorts = numNetPorts;
            parallelFC = parallelFC;

            @display("p=316,100");
        }



        ctrl: HybridController {
			hNIFtype = hNIF_type;
			id = id;
            @display("p=87,187");
        }

    connections allowunconnected:

        // EXTERNAL CONNECTIONS:
        procReq <--> ctrl.procReq;
        fromProc --> ctrl.fromProc;
        toProc <-- ctrl.toProc;
        // First wireless
        wNIF.portIn <-- portIn[0];
        wNIF.portOut --> portOut[0];
        // Then electronic 
        for i=0..numNetPorts-1 {
            eNIF.portIn[i] <-- portIn[i+1];
            eNIF.portOut[i] --> portOut[i+1];
        } 
        eNIF.ackIn <-- ackIn;
        eNIF.ackOut --> ackOut;
        
        
        // INTERNAL CONNECTIONS:
        ctrl.WprocReq <--> wNIF.procReq;
        ctrl.EprocReq <--> eNIF.procReq;
        ctrl.WfromProc --> wNIF.fromProc;
        ctrl.EfromProc --> eNIF.fromProc;
        ctrl.WtoProc <-- wNIF.toProc;
        ctrl.EtoProc <-- eNIF.toProc;
}

