
package topologies.electronicRing;

import electronicComponents.ElectronicChannel;



module ElectronicRingPlane
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numOfNodesZ;
        
        string networkPrefix;
        @display("i=OptNet_planes/el_plane_t");
    gates:
        input electronicGatewayIn[numOfNodesX*numOfNodesY];
        input IOin[];
        output electronicGatewayOut[numOfNodesX*numOfNodesY];
        output IOout[];

     
     connections allowunconnected:
         
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-2 {
            electronicGatewayOut[i+j*numOfNodesX+1] <-- electronicGatewayIn[i+j*numOfNodesX];
        }
        
        for i=0..numOfNodesX-2 {
        	electronicGatewayOut[i+(numOfNodesY-1)*numOfNodesX+1] <-- electronicGatewayIn[i+(numOfNodesY-1)*numOfNodesX];
        }
        
        electronicGatewayOut[0] <-- electronicGatewayIn[numOfNodesY*numOfNodesX-1];

       
}

