
package topologies.electronic3DMesh;

//import topologies.electronicMesh.ElectronicMeshNode;
import electronicComponents.ElectronicRouter;
import electronicComponents.ElectronicChannel;



module Electronic3DMeshPlane
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numOfNodesZ;
        
        string networkPrefix;
        @display("i=OptNet_planes/el_plane_t");
    gates:
        input electronicGatewayIn[numOfNodesZ*numOfNodesX*numOfNodesY];
        input IOin[];
        output electronicGatewayOut[numOfNodesZ*numOfNodesX*numOfNodesY];
        output IOout[];

	types:
	    channel ElectronicVia extends electronicComponents.ElectronicChannel  //connections to the middle
        {
            isVia = true;
        }
     

    submodules:
        node[numOfNodesZ*numOfNodesX*numOfNodesY]: ElectronicRouter {
            parameters:
            	numPorts = 7;
        		numPSEports = 0;
        		type = 28;
                id = networkPrefix + string(index) + ".";
                level = "NET";
                          
                numX = numOfNodesX;
                numY = numOfNodesY;
                numZ = numOfNodesZ;
                
            
        }


    connections allowunconnected:
		// HORIZONTAL CONNECTIONS
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-2, for k=0..numOfNodesZ-1 {
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portIn[2] <-- ElectronicChannel <-- node[k*numOfNodesX*numOfNodesY+(j+1)*numOfNodesX+i].portOut[0];
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portOut[2] --> ElectronicChannel --> node[k*numOfNodesX*numOfNodesY+(j+1)*numOfNodesX+i].portIn[0];
        }
        for i=0..numOfNodesX-2, for j=0..numOfNodesY-1, for k=0..numOfNodesZ-1 {
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portIn[1] <-- ElectronicChannel <-- node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i+1].portOut[3];
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portOut[1] --> ElectronicChannel --> node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i+1].portIn[3];
        }

		// VERTICAL CONNECTIONS
		// port[4] UP
		// port[5] DOWN
		for i=0..numOfNodesX-1, for j=0..numOfNodesY-1, for k=0..numOfNodesZ-2 {
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portIn[4] <-- ElectronicChannel{ isVia = true; } <-- node[(k+1)*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portOut[5];
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portOut[4] --> ElectronicChannel{ isVia = true; } --> node[(k+1)*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portIn[5];
        }
        
		// GATEWAY CONNECTIONS
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1, for k=0..numOfNodesZ-1 {
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portIn[6]  <-- ElectronicChannel {power = false;} <-- electronicGatewayIn[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i];
            node[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i].portOut[6]  --> ElectronicChannel {power = false;} --> electronicGatewayOut[k*numOfNodesX*numOfNodesY+j*numOfNodesX+i];
         
       
        }

        //going off chip
        // assume stacked memory
        for i=0..numOfNodesX-1, for k=0..numOfNodesZ-1 {
            // LOWER X ROW
            IOin[k*numOfNodesX*2+i] --> node[k*numOfNodesX*numOfNodesY+i].portIn[0];
            IOout[k*numOfNodesX*2+i] <-- node[k*numOfNodesX*numOfNodesY+i].portOut[0];
          
          	// UPPER X ROW
            IOin[i+numOfNodesX+k*numOfNodesX*2] --> node[i+(numOfNodesY-1)*numOfNodesX+k*numOfNodesX*numOfNodesY].portIn[2];
            IOout[i+numOfNodesX+k*numOfNodesX*2] <-- node[i+(numOfNodesY-1)*numOfNodesX+k*numOfNodesX*numOfNodesY].portOut[2];
            
        }

        for j=1..numOfNodesY-2, for k=0..numOfNodesZ-1 {
			// LEFT Y COLUMN            
            IOin[(j-1)+numOfNodesX*2*numOfNodesZ+k*(numOfNodesY-2)*2] --> node[j*numOfNodesX+k*numOfNodesX*numOfNodesY].portIn[3];
            IOout[(j-1)+numOfNodesX*2*numOfNodesZ+k*(numOfNodesY-2)*2] <-- node[j*numOfNodesX+k*numOfNodesX*numOfNodesY].portOut[3];
           
			// RIGHT Y COLUMN
            IOin[(j-1)+numOfNodesX*2*numOfNodesZ+(numOfNodesY-2)+k*(numOfNodesY-2)*2] --> node[j*numOfNodesX + numOfNodesX-1 + k*numOfNodesX*numOfNodesY].portIn[1];
            IOout[(j-1)+numOfNodesX*2*numOfNodesZ+(numOfNodesY-2)+k*(numOfNodesY-2)*2] <-- node[j*numOfNodesX + numOfNodesX-1 + k*numOfNodesX*numOfNodesY].portOut[1];
        }
}

// module ElectronicMeshPlane_ConcBuffer
