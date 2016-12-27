
package topologies.ButterflyFatTree;

import processingPlane.ProcessingPlane;
import topologies.ButterflyFatTree.ButterflyFatTreePlane;

import statistics.Statistics;

import ioComponents.IOPlane_Electronic;

import electronicComponents.VirtualChannelControl;

network ButterflyFatTreeNetwork
{
  
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numOfNodesZ;

        @display("bgb=400,489");
    submodules:
		 stat : Statistics {
            
        }
         vc : VirtualChannelControl {
        }
        prPlane: ProcessingPlane {
            parameters:
            
               networkPrefix = "";
               numNodesX = numOfNodesX;
               numNodesY = numOfNodesY;
                
                numOfWavelengthChannels = 0;
				numNetPorts = 1;
                @display("p=214,298");
           
        }
        elPlane: ButterflyFatTreePlane {
            parameters:
			 	networkPrefix = "";

                @display("p=182,257");
            gates:
                electronicGatewayIn[numOfNodesX*numOfNodesY];
                electronicGatewayOut[numOfNodesX*numOfNodesY];
                IOin[numOfNodesX*2+(numOfNodesY-2)*2];
                IOout[numOfNodesX*2+(numOfNodesY-2)*2];
             
        }
        ioPlane: IOPlane_Electronic {
            parameters:
            
                numOfPorts = 2*numOfNodesX+(numOfNodesY-2)*2;   //io connections on periphery
          
               
            
        }


    connections allowunconnected:
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
            prPlane.dataIn[i+j*numOfNodesX] <-- elPlane.electronicGatewayOut[i+j*numOfNodesX];
            prPlane.dataOut[i+j*numOfNodesX] --> elPlane.electronicGatewayIn[i+j*numOfNodesX];

          
        }


        //going off chip
        for i=0..numOfNodesX*2+(numOfNodesY-2)*2 -1 {
            elPlane.IOout[i] --> ioPlane.elIn[i];
            elPlane.IOin[i] <-- ioPlane.elOut[i];
         
        }

}


