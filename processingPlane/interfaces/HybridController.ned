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



simple HybridController {
  	parameters:
        
       	int id;
        double O_frequency_cntrl;

        int electronicChannelWidth;
        int routerBufferSize;
        int maxPacketSize;
        int numOfNodesX;
        double coreSizeX;
        int range;
        int fraction;
  
  		int hNIFtype;
  
        int routerVirtualChannels;
        
        int processorConcentration;
                
        @display("i=block/ifcard");
    gates:
		
		// Processor Side		
		inout procReq;
        input fromProc;
        output toProc;
        
        // NIF Side
        inout WprocReq;
        inout EprocReq;
        output WfromProc;
        output EfromProc;
        input WtoProc;
        input EtoProc;
        
   
};
