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



simple wNIF {
  	parameters:
        
       	int id;
        double O_frequency_cntrl;

        int electronicChannelWidth;
        int routerBufferSize;
        int WmaxPacketSize;
  
        int routerVirtualChannels;
        
        int processorConcentration;
                
        @display("i=block/ifcard");
    gates:
		// Pure wireless will have only one netport: from/to the wireless transceiver
		// Hybrid NIF could have two or more...
        input portIn;
        output portOut;
       

        inout procReq;
        input fromProc;
        output toProc;

    
};
