
package topologies.ButterflyFatTree;

//import topologies.electronicMesh.ElectronicMeshNode;
import electronicComponents.ElectronicRouter;
import electronicComponents.ElectronicChannel;



module ButterflyFatTreePlane
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numOfNodesZ;
        
        int numOfLevels;
                
        string networkPrefix;
        @display("i=OptNet_planes/el_plane_t");
    gates:
        input electronicGatewayIn[];
        input IOin[];
        output electronicGatewayOut[];
        output IOout[];


           
       
       
    submodules:
        node[numOfRouters]: ElectronicRouter {
            parameters:
            	numPorts = 6;
        		numPSEports = 0;
        		type = 261;
                id = networkPrefix + string(index) + ".";
                level = "NET";
                
                numX = numOfNodesX;
                numY = numOfNodesY;
                numZ = numOfNodesZ;
 
        }


    connections allowunconnected:
        
      
       // Concentrated connections to the baseline routers
       for i=0..(numOfNodesX/2)-1, for j=0..(numOfNodesY/2)-1, for k=0..1, for l=0..1 {
           node[i+j*(numOfNodesX/2)].portIn[k+l] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[(i+k)+(j+l)*numOfNodesX];
           node[i+j*(numOfNodesX/2)].portOut[k+l] --> ElectronicChannel{power = false;} --> electronicGatewayOut[(i+k)+(j+l)*numOfNodesX];
        }

		// Upper levels (lowest to uppest) --> revisar
		for j=1..numOfLevels-1, for i=0..numOfNodesX*numOfNodesX/2^(j+1)-1 {
			node[(2^j-1)*numOfNodesX*numOfNodesX/(2^(j+1)) + 2*floor(i/4)].portOut[i%4] --> ElectronicChannel{ spaceLengths = 2*j; } --> node[(2^(j-1)-1)*numOfNodesX*numOfNodesX/(2^j)+i].portIn[5];
			node[(2^j-1)*numOfNodesX*numOfNodesX/(2^(j+1)) + 2*floor(i/4)].portIn[i%4] <-- ElectronicChannel{ spaceLengths = 2*j; } <-- node[(2^(j-1)-1)*numOfNodesX*numOfNodesX/(2^j)+i].portOut[5];
			node[(2^j-1)*numOfNodesX*numOfNodesX/(2^(j+1)) + 2*floor(i/4) + 1].portOut[i%4] --> ElectronicChannel{ spaceLengths = 2*j; } --> node[(2^(j-1)-1)*numOfNodesX*numOfNodesX/(2^j)+i].portIn[6];
			node[(2^j-1)*numOfNodesX*numOfNodesX/(2^(j+1)) + 2*floor(i/4) + 1].portIn[i%4] <-- ElectronicChannel{ spaceLengths = 2*j; } <-- node[(2^(j-1)-1)*numOfNodesX*numOfNodesX/(2^j)+i].portOut[6];
		}
		
		
        //going off chip
        // TODO
        for i=0..numOfNodesX-1 {
            IOin[i] --> node[i].portIn[numOfNodesX + numOfNodesY - 1];
            IOout[i] <-- node[i].portOut[numOfNodesX + numOfNodesY - 1];
           
            

            IOin[i+numOfNodesX] --> node[i+(numOfNodesY-1)*numOfNodesX].portIn[numOfNodesX + numOfNodesY - 1];
            IOout[i+numOfNodesX] <-- node[i+(numOfNodesY-1)*numOfNodesX].portOut[numOfNodesX + numOfNodesY - 1];
            
        }

        for j=1..numOfNodesY-2 {
            IOin[(j-1)+numOfNodesX*2] --> node[j*numOfNodesX].portIn[numOfNodesX + numOfNodesY - 1];
            IOout[(j-1)+numOfNodesX*2] <-- node[j*numOfNodesX].portOut[numOfNodesX + numOfNodesY - 1];
           

            IOin[(j-1)+numOfNodesX*2+numOfNodesY-2] --> node[j*numOfNodesX + numOfNodesX-1].portIn[numOfNodesX + numOfNodesY - 1];
            IOout[(j-1)+numOfNodesX*2+numOfNodesY-2] <-- node[j*numOfNodesX + numOfNodesX-1].portOut[numOfNodesX + numOfNodesY - 1];
          
        }


}

