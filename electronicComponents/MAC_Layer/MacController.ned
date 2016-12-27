package electronicComponents.MAC_Layer;


simple MacController
{
    parameters:

        int numOfNodesX;
        int numOfNodesY;
                
        double channelCapacity;
        double O_frequency_data;
        double dieSize;
       
	
       @display("i=abstract/router");
    gates:

	
        inout portInC;
        output portOutC[numOfNodesX*numOfNodesY];


}
