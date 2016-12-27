// Sergi Abadal. September 2012
// IO considerations are maintained for future usage
// TODO: everything

package topologies.HybridWEMesh;

import processingPlane.ProcessingPlane_Hybrid;
import topologies.WirelessMesh.WirelessMeshPlaneTOKEN;
import topologies.electronicMesh.ElectronicMeshPlane;
import topologies.electronicMesh.ElectronicMeshPlane_ParallelFlowControl;

import statistics.Statistics;

//import ioComponents.IOPlane_Electronic;
import electronicComponents.VirtualChannelControl;

network HybridMeshNetworkTOKEN
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
                
        int processorConcentration;
        
        bool useIOplane;

        @display("bgb=400,489");
    submodules:
		 stat : Statistics {
		     //STATS_warmup = 0;
		     //STATS_cooldown = 0;
		     
            
        }
        vc : VirtualChannelControl {
         	   
        }
        prPlane: ProcessingPlane_Hybrid {
            parameters:
            		numNodesX = numOfNodesX;
            		numNodesY = numOfNodesY;
            		numNodesZ = 1;
            		
            		numIO = numOfNodesX*2+(numOfNodesY-2)*2;
            		networkPrefix = "";         
             		numNetPorts = 1;
                    
                    numOfWavelengthChannels = 0;

                @display("p=214,298");
         
        }
        wiPlane: WirelessMeshPlaneTOKEN {
            parameters:
				numIO = numOfNodesX*2+(numOfNodesY-2)*2;   // Num of Periphery connections.
				
				networkPrefix = "";
				
                @display("p=182,257");
    
                        
        }
        
    	elPlane: ElectronicMeshPlane {
    	    parameters:
    	        networkPrefix = "";
    	        
    	    gates:
               
                IOin[numOfNodesX*2+(numOfNodesY-2)*2];
                IOout[numOfNodesX*2+(numOfNodesY-2)*2];
   
    	}
    	
        
            
            
        

    connections allowunconnected:
  
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
            // Each hNIF has a pair of ports. First to the wireless plane and second to the electrical plane.
            prPlane.dataIn[2*(i+j*numOfNodesX)] <-- wiPlane.electronicGatewayOut[i+j*numOfNodesX];
            prPlane.dataIn[2*(i+j*numOfNodesX)+1] <-- elPlane.electronicGatewayOut[i+j*numOfNodesX];
            prPlane.dataOut[2*(i+j*numOfNodesX)] --> wiPlane.electronicGatewayIn[i+j*numOfNodesX];        
            prPlane.dataOut[2*(i+j*numOfNodesX)+1] --> elPlane.electronicGatewayIn[i+j*numOfNodesX];

           
        }




}


network HybridMeshNetworkTOKEN_ParallelFlowControl
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
                
        int processorConcentration;
        
        bool useIOplane;

        @display("bgb=400,489");
    submodules:
		 stat : Statistics {
		     //STATS_warmup = 0;
		     //STATS_cooldown = 0;
		     
            
        }
        vc : VirtualChannelControl {
         	   
        }
        prPlane: ProcessingPlane_Hybrid {
            parameters:
            		numNodesX = numOfNodesX;
            		numNodesY = numOfNodesY;
            		numNodesZ = 1;
            		
            		numIO = numOfNodesX*2+(numOfNodesY-2)*2;
            		networkPrefix = "";         
             		numNetPorts = 1;
             		
             		parallelFC = 1;
                    
                    numOfWavelengthChannels = 0;

                @display("p=214,298");
         
        }
        wiPlane: WirelessMeshPlaneTOKEN {
            parameters:
				numIO = numOfNodesX*2+(numOfNodesY-2)*2;   // Num of Periphery connections.
				
				networkPrefix = "";
				
                @display("p=182,257");
    
                        
        }
        
    	elPlane: ElectronicMeshPlane_ParallelFlowControl {
    	    parameters:
    	        networkPrefix = "";
    	        
    	    gates:
               
                IOin[numOfNodesX*2+(numOfNodesY-2)*2];
                IOout[numOfNodesX*2+(numOfNodesY-2)*2];
   
    	}
    	
        
            
            
        

    connections allowunconnected:
  
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
            // Each hNIF has a pair of ports. First to the wireless plane and second to the electrical plane.
            prPlane.dataIn[2*(i+j*numOfNodesX)] <-- wiPlane.electronicGatewayOut[i+j*numOfNodesX];
            prPlane.dataIn[2*(i+j*numOfNodesX)+1] <-- elPlane.electronicGatewayOut[i+j*numOfNodesX];
            prPlane.dataOut[2*(i+j*numOfNodesX)] --> wiPlane.electronicGatewayIn[i+j*numOfNodesX];        
            prPlane.dataOut[2*(i+j*numOfNodesX)+1] --> elPlane.electronicGatewayIn[i+j*numOfNodesX];
            prPlane.ackIn[i+j*numOfNodesX] <-- elPlane.electronicGatewayAckOut[i+j*numOfNodesX];
            prPlane.ackOut[i+j*numOfNodesX] --> elPlane.electronicGatewayAckIn[i+j*numOfNodesX];
           
        }




}
