package electronicComponents;

import electronicComponents.PHY_Layer.IPhysicalLayer;
import electronicComponents.MAC_Layer.IMacLayer;





module WirelessTransceiver
{
    parameters:
        string id;
        string level;
        
        int idnum;
        int numOfNodesX;
        int numOfNodesY;
        double coreSizeX;
        
        double channelCapacity;
        
        int numPorts;
        int numIO;
        double O_frequency_cntrl;
		
		double timeout = default(1);
		int maxRETRIES = default(1);
		double backOffPeriod = default(2e-8);
		double pPersistent = default(0);
		bool negativeACKs = default(false);
		
		string physicalLayer = default("PhysicalLayerGeneric");
		string macLayer = default("MACLayerGeneric");
		
		
		int numX;
		int numY;
		
		int MACtype = default(0);

		bool useIOplane;

		int dispValueX;
		int dispValueY;
        @display("i=abstract/router");
    gates:

	
        input radioIn @directIn;
        input portIn[useIOplane ? 1 + numIO : 1 ];
        output portOut[useIOplane ? 1 + numIO : 1 ];

		input controllerIn;
        inout controllerOut;
               
	
	submodules:
	    phy: <physicalLayer> like IPhysicalLayer {
	        parameters:
	            type = MACtype;
	            numOfNodesX = numOfNodesX;
	            numX = numX;
	            numY = numY;
	            coreSizeX = coreSizeX;
	            channelCapacity = channelCapacity;
	            idnum = idnum;	            
	    }
	    
	    mac: <macLayer> like IMacLayer {
	    	parameters:
	    		type = MACtype;	       
	    		numOfNodesX = numOfNodesX;
	    		numX = numX;
	            numY = numY;
	            coreSizeX = coreSizeX;
	            idnum = idnum;
	            channelCapacity = channelCapacity;
	            maxRETRIES = maxRETRIES;
	            backOffPeriod = backOffPeriod;
	            pPersistent = pPersistent;
	            negativeACKs = negativeACKs;
	    }
	    
	connections allowunconnected:
	        radioIn --> phy.fromNet;
	        mac.macToPhy --> phy.fromMac;
	        phy.phyToMac --> mac.fromPhy;
	        portIn[0] --> mac.fromNic;
	        mac.toNic --> portOut[0];
	        // IO not connected thus far
	        controllerIn --> mac.controllerToMac;
	        mac.macToController --> controllerOut$o; 
	        controllerOut$i --> phy.deadEnd; // HACK: for CBUF.
}
