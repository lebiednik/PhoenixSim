
package processingPlane;

import processingPlane.ProcessorNode;
import processingPlane.interfaces.NIF;
import processingPlane.interfaces.wNIF;
import processingPlane.interfaces.hNIF;
import processingPlane.trafficGenerator.TrafficGenerator;


// One processor per NIF ==> network router will be concentrated.
module ProcessingPlane
{
    parameters:
        int numNetPorts;
        
        int numNodesX;
        int numNodesY;
        int numNodesZ;
     
        
        string networkPrefix;
      	int processorConcentration;
      	
      	string NIF_type;
        
 		double O_frequency_cntrl;
        
        int numOfWavelengthChannels;
        
        @display("i=planes/pe_plane");
    gates:
        input dataIn[numNodesX*numNodesY*processorConcentration*numNetPorts];
        output dataOut[numNodesX*numNodesY*processorConcentration*numNetPorts];
       
        input ackIn[numNodesZ*numNodesX*numNodesY*processorConcentration];
        output ackOut[numNodesZ*numNodesX*numNodesY*processorConcentration];
        
        inout laserIn[numNodesX*numNodesY * numOfWavelengthChannels*processorConcentration];
        inout laserOut[numNodesX*numNodesY*processorConcentration];

     
    submodules:
        proc[numNodesX*numNodesY*processorConcentration]: Processor{
            parameters:
                id = networkPrefix + string(int(index / processorConcentration)) + ".0." + string(index % processorConcentration) + ".";
             	
          		clockRate = O_frequency_cntrl;
                @display("p=100,100,m,$numNodesX,100,100;i=components/cellnode");
               
        }
        
        nic[numNodesX*numNodesY*processorConcentration]: <NIF_type> like NIF {
        	id = index;
        	numNetPorts = numNetPorts;
            @display("p=80,80,m,$numNodesX,100,100");
        }
        
   
 
    connections allowunconnected:
       for j=0..numNetPorts-1, for i=0..numNodesX*numNodesY*processorConcentration -1 {
            dataIn[i*numNetPorts + j] --> { @display("ls=,0"); } --> nic[i].portIn[j];
            dataOut[i*numNetPorts + j] <-- { @display("ls=,0"); } <-- nic[i].portOut[j];
     
        }
        
        for i=0..numNodesX*numNodesY*processorConcentration -1 {
       		proc[i].nicReq <--> nic[i].procReq;
     		proc[i].toNic --> nic[i].fromProc;
     		proc[i].fromNic <-- nic[i].toProc;
           
            nic[i].ackIn <-- ackIn[i];
            nic[i].ackOut --> ackOut[i];
        }
        
     
}


// One processor per hNIF (which outputs to two different networks: for instance, wireless and electronic)
// Concentration is in the network side.
module ProcessingPlane_Hybrid
{
    parameters:
        int numNetPorts;
        
        int numNodesX;
        int numNodesY;
        int numNodesZ;
        
        int numIO;
     
        int parallelFC = default(0);
        int furthDest = default(0);
        
        string networkPrefix;
      	int processorConcentration;
      	
      	string NIF_type;
        
 		double O_frequency_cntrl;
        
        int numOfWavelengthChannels;
        
        @display("i=planes/pe_plane");
    gates:
        input dataIn[2*numNodesZ*numNodesX*numNodesY*processorConcentration];
        output dataOut[2*numNodesZ*numNodesX*numNodesY*processorConcentration];
       
        input ackIn[numNodesZ*numNodesX*numNodesY*processorConcentration];
        output ackOut[numNodesZ*numNodesX*numNodesY*processorConcentration];


     
    submodules:
        proc[numNodesZ*numNodesX*numNodesY*processorConcentration]: Processor {
            parameters:
                id = networkPrefix + string(int(index)) + ".0." + string(index % processorConcentration) + ".";
             	
          		clockRate = O_frequency_cntrl;
                @display("p=100,100,m,$numNodesX,100,100;i=components/cellnode");
               
        }
        
        // Hybrid NIF will have two NetPorts  
        nic[numNodesZ*numNodesX*numNodesY*processorConcentration]: hNIF {
        	id = index;
        	numNetPorts = numNetPorts;
        	parallelFC = parallelFC;
            @display("p=80,80,m,$numNodesX,100,100");
        }
        
        centralTG: TrafficGenerator {
            clockRate = O_frequency_cntrl;
            furthDest = furthDest;
        }
        
              
    connections allowunconnected:
        // Each hNIF has a pair of ports. First to the wireless plane and second to the electrical plane.
       	for j=0..1, for i=0..numNodesZ*numNodesX*numNodesY*processorConcentration -1 {
            dataIn[i*2 + j] --> { @display("ls=,0"); } --> nic[i].portIn[j];
            dataOut[i*2 + j] <-- { @display("ls=,0"); } <-- nic[i].portOut[j];
        }
        
        for i=0..numNodesZ*numNodesX*numNodesY*processorConcentration -1 {
       		proc[i].nicReq <--> nic[i].procReq;
     		proc[i].toNic --> nic[i].fromProc;
     		proc[i].fromNic <-- nic[i].toProc;
            nic[i].ackIn <-- ackIn[i];
            nic[i].ackOut --> ackOut[i];
            centralTG.toProc[i] --> proc[i].fromTG;
        }
        
     
}


// N processors with one processor router, one NIF
module ProcessingPlane_ProcRoute
{
    parameters:
        int numNetPorts;
        
        int numNodesX;
        int numNodesY;
        int numNodesZ;
     
      	bool autounblock = default(false);
        string networkPrefix;
        
        int processorConcentration;
        
 		double O_frequency_cntrl;
        
        int numOfWavelengthChannels;
        
        @display("i=planes/pe_plane");
    gates:
        input dataIn[numNodesZ*numNodesX*numNodesY*numNetPorts];
        output dataOut[numNodesZ*numNodesX*numNodesY*numNetPorts];
    
        input ackIn[numNodesZ*numNodesX*numNodesY*numNetPorts];
        output ackOut[numNodesZ*numNodesX*numNodesY*numNetPorts]; 
        
        inout laserIn[numNodesX*numNodesY * numOfWavelengthChannels];
        inout laserOut[numNodesX*numNodesY];

     
    submodules:
        tx[numNodesX*numNodesY*numNodesZ]: ProcessorNode {
            parameters:
                id = networkPrefix + string(index) + ".";
               numNetPorts = numNetPorts;
          		clockRate = O_frequency_cntrl;
          		autounblock = autounblock;
          		number = index;
            

                @display("p=100,100,m,$numNodesX,100,100;i=components/cellnode");
               

        }
    connections allowunconnected:
        for j=0..numNetPorts-1, for i=0..numNodesX*numNodesY*numNodesZ -1 {
            dataIn[i*numNetPorts + j] --> { @display("ls=,0"); } --> tx[i].portIn[j];
           dataOut[i*numNetPorts + j] <-- { @display("ls=,0"); } <-- tx[i].portOut[j];
        }
        
        
            
            
            
        for i=0..numNodesX*numNodesY -1 {
            laserOut[i] <--> tx[i].laserOut;
           
        }
        
       for i=0..numNodesX*numNodesY -1, for j=0..numOfWavelengthChannels-1 {
			laserIn[i*numOfWavelengthChannels + j] <--> tx[i].laserIn[j];           
       }
}
