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

package ioComponents.DRAM_LRL;

simple NIF_MemGW {
  	parameters:
      int numNetPorts = default(2);
        int numOfNodesX;
        int numOfNodesY;
        int id;
        
        double guardTimeGap;
          double O_frequency_cntrl;
      double O_frequency_data;

        int electronicChannelWidth;
        int maxPacketSize;
        int numOfWavelengthChannels;
        int processorConcentration;
        
        double DetectorSensitivity;
      
      	int routerBufferSize;
      	int routerVirtualChannels;
      	
      	//int memTxRxCapacity;
      	//double DRAMwriteIntervalTime @unit(s);
      	//int memoryChannelWidth;
		//double offChipClockRate;
        
        string networkName;
        
        int DRAM_chipsPerDIMM;
        double DRAM_freq;
        int DRAM_arrays;
        int DRAM_cols;
        
         string addressLevel = default("PROC");
       

        @display("i=block/ifcard");
    gates:
        input portIn[numNetPorts];
        output portOut[numNetPorts];

       inout procReq;
        input fromProc;
        output toProc;
    
};
