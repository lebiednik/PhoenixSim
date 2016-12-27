
package topologies.electronic3DMesh;

import processingPlane.ProcessingPlane;
import processingPlane.ProcessingPlane_ProcRoute;
import topologies.electronic3DMesh.Electronic3DMeshPlane;

import statistics.Statistics;

import ioComponents.IOPlane_Electronic;

import electronicComponents.VirtualChannelControl;

network Electronic3DMeshNetwork
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numOfNodesZ;
        
        int processorConcentration;
        
        bool useIOplane;

        @display("bgb=400,489");
    submodules:
		 stat : Statistics {
            
        }
        vc : VirtualChannelControl {
         	   
        }
        prPlane: ProcessingPlane_ProcRoute{
            parameters:
            		numNodesX = numOfNodesX;
            		numNodesY = numOfNodesY;
            		numNodesZ = numOfNodesZ;
            		networkPrefix = "";         
             		numNetPorts = 1;
                    
                    numOfWavelengthChannels = 0;

                @display("p=214,298");
         
        }
        elPlane: Electronic3DMeshPlane {
            parameters:
				
				networkPrefix = "";
				
                @display("p=182,257");
            gates:
               
                IOin[numOfNodesZ*(numOfNodesX*2+(numOfNodesY-2)*2)];
                IOout[numOfNodesZ*(numOfNodesX*2+(numOfNodesY-2)*2)];
            
        }
        
    
        
        
        ioPlane[useIOplane ? 1 : 0]: IOPlane_Electronic {
            parameters:
             
                numOfPorts = numOfNodesZ*(numOfNodesX*2+(numOfNodesY-2)*2);   //io connections on periphery
            gates:
                elIn[numOfNodesZ*(numOfNodesX*2+(numOfNodesY-2)*2)];
                elOut[numOfNodesZ*(numOfNodesX*2+(numOfNodesY-2)*2)];
               
            
        }

    connections allowunconnected:
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1, for k=0..numOfNodesZ-1 {
            prPlane.dataIn[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i] <-- elPlane.electronicGatewayOut[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i];
            prPlane.dataOut[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i] --> elPlane.electronicGatewayIn[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i];

           
        }


        //going off chip
        for i=0..numOfNodesZ*(numOfNodesX*2+(numOfNodesY-2)*2)-1 {
            elPlane.IOout[i] --> ioPlane[0].elIn[i] if useIOplane;
            elPlane.IOin[i] <-- ioPlane[0].elOut[i] if useIOplane;
            
        }

}




//this version of the network is for concentration by just adding in more ports to the router,
//  as opposed to an electronic switch behind the NIF
//network ElectronicMeshNetwork_ConcBuffer
