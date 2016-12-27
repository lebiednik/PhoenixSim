
package topologies.flattenedButterfly;

//import topologies.electronicMesh.ElectronicMeshNode;
import electronicComponents.ElectronicRouter;
import electronicComponents.ElectronicChannel;



module FlattenedButterflyPlane
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

       
	types:
        channel ElectronicChannel_2_0 extends electronicComponents.ElectronicChannel  //connections to the middle
        {
            spaceLengths = 2;
            routerLengths = 0;
        }
           
       
        
        channel ElectronicChannel_4_1 extends electronicComponents.ElectronicChannel  //connections to the middle
        {
            spaceLengths = 4;
            routerLengths = 1;
        }
           
       
        
          channel ElectronicChannel_6_2 extends electronicComponents.ElectronicChannel  //connections to the middle
        {
            spaceLengths = 6;
            routerLengths = 2;
        }
           
       
       
    submodules:
        node[(numOfNodesX)*(numOfNodesY)/4]: ElectronicRouter {
            parameters:
            	numPorts = (numOfNodesX/2 -1) + (numOfNodesY/2 -1) + 4;
        		numPSEports = 0;
        		type = 26;
                id = networkPrefix + string(index) + ".";
                level = "NET";
                
                numX = numOfNodesX/2;
                numY = numOfNodesY/2;
                numZ = numOfNodesZ;
 
        }


    connections allowunconnected:
        

        //horizontal connections
        for i=0..numOfNodesX/2-1, for j=0..numOfNodesY/2-1, for q=0..numOfNodesX/2-1 {
           //node[i+j*numOfNodesX].portOut[q] --> ElectronicChannel_2_0 --> node[q+j*numOfNodesX].portIn[i-1] if (q < i) && (i-q == 1);
           // node[i+j*numOfNodesX].portOut[q] --> ElectronicChannel_4_1 --> node[q+j*numOfNodesX].portIn[i-1] if (q < i) && (i-q == 2);
            //node[i+j*numOfNodesX].portOut[q] --> ElectronicChannel_6_2 --> node[q+j*numOfNodesX].portIn[i-1] if (q < i) && (i-q == 3);
         
            node[i+j*numOfNodesX/2].portOut[q] --> ElectronicChannel --> node[q+j*numOfNodesX/2].portIn[i-1] if (q < i);
            node[i+j*numOfNodesX/2].portOut[q-1] --> ElectronicChannel --> node[q+j*numOfNodesX/2].portIn[i] if (q > i);
          
        }
        
         //vertical connections
        for i=0..numOfNodesX/2-1, for j=0..numOfNodesY/2-1, for q=0..numOfNodesY/2-1 {
            //node[i+j*numOfNodesX].portOut[numOfNodesX-1+q] --> ElectronicChannel_2_0 --> node[i+q*numOfNodesX].portIn[numOfNodesX-1+j-1] if (q < j) && (j-q == 1);
            //node[i+j*numOfNodesX].portOut[numOfNodesX-1+q-1] --> ElectronicChannel_2_0 --> node[i+q*numOfNodesX].portIn[numOfNodesX-1+j] if (q > j) && (q-j == 1);
            
            
            node[i+j*numOfNodesX/2].portOut[numOfNodesX/2-1+q] --> ElectronicChannel --> node[i+q*numOfNodesX/2].portIn[numOfNodesX/2-1+j-1] if (q < j);
            node[i+j*numOfNodesX/2].portOut[numOfNodesX/2-1+q-1] --> ElectronicChannel --> node[i+q*numOfNodesX/2].portIn[numOfNodesX/2-1+j] if (q > j);
            
            
            
            
        }
       
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {

           // node[(i>>1)+(j>>1)*numOfNodesX].portIn[2*(numOfNodesX/2 -1)] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX*2] if (j%2 == 0) && (i%2 == 0);
           // node[(i>>1)+(j>>1)*numOfNodesX].portOut[2*(numOfNodesX/2 -1)] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+j*numOfNodesX*2] if (j%2 == 0) && (i%2 == 0);
         
            //node[(i>>1)+(j>>1)*numOfNodesX].portIn[2*(numOfNodesX/2 -1) +1] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX*2] if (j%2 == 0) && (i%2 == 1);
            //node[(i>>1)+(j>>1)*numOfNodesX].portOut[2*(numOfNodesX/2 -1) +1] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+j*numOfNodesX*2] if (j%2 == 0) && (i%2 == 1);

            //node[(i>>1)+(j>>1)*numOfNodesX].portIn[2*(numOfNodesX/2 -1) +2] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX*2] if (j%2 == 1) && (i%2 == 0);
            //node[(i>>1)+(j>>1)*numOfNodesX].portOut[2*(numOfNodesX/2 -1) +2] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+(j)*numOfNodesX*2] if (j%2 == 1) && (i%2 == 0);

            //node[(i>>1)+(j>>1)*numOfNodesX].portIn[2*(numOfNodesX/2 -1) +3] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX*2] if (j%2 == 1) && (i%2 == 1);
            //node[(i>>1)+(j>>1)*numOfNodesX].portOut[2*(numOfNodesX/2 -1) +3] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+(j)*numOfNodesX*2] if (j%2 == 1) && (i%2 == 1);

       // }
       
            node[(i>>1)+(j>>1)*numOfNodesX/2].portIn[2*(numOfNodesX/2 -1)] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX] if (j%2 == 0) && (i%2 == 0);
            node[(i>>1)+(j>>1)*numOfNodesX/2].portOut[2*(numOfNodesX/2 -1)] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+j*numOfNodesX] if (j%2 == 0) && (i%2 == 0);
            
            
            node[(i>>1)+(j>>1)*numOfNodesX/2].portIn[2*(numOfNodesX/2 -1) +1] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX] if (j%2 == 0) && (i%2 == 1);
            node[(i>>1)+(j>>1)*numOfNodesX/2].portOut[2*(numOfNodesX/2 -1) +1] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+j*numOfNodesX] if (j%2 == 0) && (i%2 == 1);
              
            node[(i>>1)+(j>>1)*numOfNodesX/2].portIn[2*(numOfNodesX/2 -1) +2] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX] if (j%2 == 1) && (i%2 == 0);
            node[(i>>1)+(j>>1)*numOfNodesX/2].portOut[2*(numOfNodesX/2 -1) +2] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+(j)*numOfNodesX] if (j%2 == 1) && (i%2 == 0);
              
            node[(i>>1)+(j>>1)*numOfNodesX/2].portIn[2*(numOfNodesX/2 -1) +3] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX] if (j%2 == 1) && (i%2 == 1);
            node[(i>>1)+(j>>1)*numOfNodesX/2].portOut[2*(numOfNodesX/2 -1) +3] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+(j)*numOfNodesX] if (j%2 == 1) && (i%2 == 1);
           
        }
       
       //for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
         //  node[(i)+(j)*numOfNodesX].portIn[numOfNodesX + numOfNodesY-2] <-- ElectronicChannel{power = false;} <-- electronicGatewayIn[i+(j)*numOfNodesX];
         //  node[(i)+(j)*numOfNodesX].portOut[numOfNodesX + numOfNodesY-2] --> ElectronicChannel{power = false;} --> electronicGatewayOut[i+j*numOfNodesX];

       //}
       

        //going off chip
        //for i=0..numOfNodesX-1 {
         //   IOin[i] --> node[i].portIn[numOfNodesX + numOfNodesY - 1];
          //  IOout[i] <-- node[i].portOut[numOfNodesX + numOfNodesY - 1];
           
            

          //  IOin[i+numOfNodesX] --> node[i+(numOfNodesY-1)*numOfNodesX].portIn[numOfNodesX + numOfNodesY - 1];
          //  IOout[i+numOfNodesX] <-- node[i+(numOfNodesY-1)*numOfNodesX].portOut[numOfNodesX + numOfNodesY - 1];
            
        //}

        //for j=1..numOfNodesY-2 {
         //   IOin[(j-1)+numOfNodesX*2] --> node[j*numOfNodesX].portIn[numOfNodesX + numOfNodesY - 1];
          //  IOout[(j-1)+numOfNodesX*2] <-- node[j*numOfNodesX].portOut[numOfNodesX + numOfNodesY - 1];
           

          //  IOin[(j-1)+numOfNodesX*2+numOfNodesY-2] --> node[j*numOfNodesX + numOfNodesX-1].portIn[numOfNodesX + numOfNodesY - 1];
          //  IOout[(j-1)+numOfNodesX*2+numOfNodesY-2] <-- node[j*numOfNodesX + numOfNodesX-1].portOut[numOfNodesX + numOfNodesY - 1];
          
       // }


}

