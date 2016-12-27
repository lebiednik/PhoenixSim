
package topologies.WirelessMesh;

import electronicComponents.WirelessTransceiver;
import electronicComponents.MAC_Layer.MacController;
import electronicComponents.ElectronicChannel;
import electronicComponents.ElectronicRouter;
import topologies.electronicRing.ElectronicRingPlane;


module WirelessMeshPlaneCSMA
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numIO;
        
        bool useIOplane;        
		
        string networkPrefix;  //?
        // @display("i=OptNet_planes/el_plane_t");   ?
    gates:
        // El gateway debe de seguir siendo la interfase entre el plano de proceso y el plano de red.
		// IO en principio es para conectar memoria.
		input electronicGatewayIn[numOfNodesX*numOfNodesY];
        input IOin[(numOfNodesX*numOfNodesY)*numIO]; // num channels = periphery nodes
        output electronicGatewayOut[numOfNodesX*numOfNodesY];
        output IOout[(numOfNodesX*numOfNodesY)*numIO];

     
	// Nuestros nodos serán Wireless Transceivers.
    submodules:
        node[numOfNodesX*numOfNodesY]: WirelessTransceiver {
            parameters:
            	// Parámetros?? MARIO??
				// Identificador para saber dirección propia?
				// AmplificationLevel?
				// MACOverhead? In time or in delay? In both?
				
				numPorts = 1;				
				numIO = numOfNodesX*2+(numOfNodesY-2)*2;
				// numPorts = 5;
        		// numPSEports = 0;
        		// type = 20;
                id = networkPrefix + string(index) + ".";
                level = "NET";
        		idnum = index;                        
                numX = index % numOfNodesX;
                numY = floor(index/numOfNodesX);
                
            
        }
        


    connections allowunconnected:
        // Conexiones a TODOS los demás nodos no existen ya que son puertos @directIn
        	
		
	    
	    // El último puerto (numPorts-1) es conexión con el gateway (NIF) 
		for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
			// No hay canal, se considera que el transceiver está inmediatamente junto el NIF
            node[i+j*numOfNodesX].portIn[0] <-- electronicGatewayIn[i+j*numOfNodesX];
            node[i+j*numOfNodesX].portOut[0] --> electronicGatewayOut[i+j*numOfNodesX];
         
        }

        // El resto de conexiones (numPorts ~ numPorts+numPortsIO-1) son a memoria (nodos periféricos)
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1, for k=1..numOfNodesX*2+(numOfNodesY-2)*2 {
           node[i+j*numOfNodesX].portIn[k] <-- IOin[(i+j*numOfNodesX)+(k-1)*numOfNodesX*numOfNodesY] if useIOplane; 
           node[i+j*numOfNodesX].portOut[k] --> IOout[(i+j*numOfNodesX)+(k-1)*numOfNodesX*numOfNodesY] if useIOplane;
        }            

}




module WirelessMeshPlaneTOKEN
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numIO;
        
                
        bool useIOplane;        
		
        string networkPrefix;  //?
        // @display("i=OptNet_planes/el_plane_t");   ?
    gates:
        // El gateway debe de seguir siendo la interfase entre el plano de proceso y el plano de red.
		// IO en principio es para conectar memoria.
		input electronicGatewayIn[numOfNodesX*numOfNodesY];
        input IOin[(numOfNodesX*numOfNodesY)*numIO]; // num channels = periphery nodes
        output electronicGatewayOut[numOfNodesX*numOfNodesY];
        output IOout[(numOfNodesX*numOfNodesY)*numIO];

     
	// Nuestros nodos serán Wireless Transceivers.
    submodules:
        node[numOfNodesX*numOfNodesY]: WirelessTransceiver {
            parameters:
            	
				numPorts = 1;				
				numIO = numOfNodesX*2+(numOfNodesY-2)*2;
				// numPorts = 5;
        		// numPSEports = 0;
        		// type = 20;
                id = networkPrefix + string(index) + ".";
                level = "NET";
        		idnum = index;                        
                numX = index % numOfNodesX;
                numY = floor(index/numOfNodesX);
                
            
        }

        
        ctrlPlane: ElectronicRingPlane {
            parameters:
    	        networkPrefix = "";
    	        
    	    gates:
    	            
        }
        


    connections allowunconnected:
        // El último puerto (numPorts-1) es conexión con el gateway (NIF) 
		for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
			// No hay canal, se considera que el transceiver está inmediatamente junto el NIF
            node[i+j*numOfNodesX].portIn[0] <-- electronicGatewayIn[i+j*numOfNodesX];
            node[i+j*numOfNodesX].portOut[0] --> electronicGatewayOut[i+j*numOfNodesX];
         
        }

        // El resto de conexiones (numPorts ~ numPorts+numPortsIO-1) son a memoria (nodos periféricos)
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1, for k=1..numOfNodesX*2+(numOfNodesY-2)*2 {
           node[i+j*numOfNodesX].portIn[k] <-- IOin[(i+j*numOfNodesX)+(k-1)*numOfNodesX*numOfNodesY] if useIOplane; 
           node[i+j*numOfNodesX].portOut[k] --> IOout[(i+j*numOfNodesX)+(k-1)*numOfNodesX*numOfNodesY] if useIOplane;
        }            


        // Connexions dels controladors a la xarxa RING pels tokens
        for i=0..(numOfNodesX*numOfNodesY)-1 {
            ctrlPlane.electronicGatewayOut[i] --> node[i].controllerIn;
            node[i].controllerOut$o --> ctrlPlane.electronicGatewayIn[i];
        }
      
		        
}




module WirelessMeshPlaneCBUF
{
    parameters:
        int numOfNodesX;
        int numOfNodesY;
        int numIO;
        
        // From Wikipedia
        int k = 4;
        int RouterLevels = ceil( (log(k-1)/log(k)) + (log(numOfNodesX*numOfNodesY)/log(k)) -1 );
        int nRouters = (pow(k,RouterLevels+1)-1)/(k-1);
        // Assumptions: perfect k-ary tree (
                
        bool useIOplane;        
		
        string networkPrefix;  //?
        // @display("i=OptNet_planes/el_plane_t");   ?
    gates:
        // El gateway debe de seguir siendo la interfase entre el plano de proceso y el plano de red.
		// IO en principio es para conectar memoria.
		input electronicGatewayIn[numOfNodesX*numOfNodesY];
        input IOin[(numOfNodesX*numOfNodesY)*numIO]; // num channels = periphery nodes
        output electronicGatewayOut[numOfNodesX*numOfNodesY];
        output IOout[(numOfNodesX*numOfNodesY)*numIO];

     
	// Nuestros nodos serán Wireless Transceivers.
    submodules:
        node[numOfNodesX*numOfNodesY]: WirelessTransceiver {
            parameters:
            	
				numPorts = 1;				
				numIO = numOfNodesX*2+(numOfNodesY-2)*2;
				// numPorts = 5;
        		// numPSEports = 0;
        		// type = 20;
                id = networkPrefix + string(index) + ".";
                level = "NET";
        		idnum = index;                        
                numX = index % numOfNodesX;
                numY = floor(index/numOfNodesX);
                
            
        }

        
        cntrl_plane[nRouters]: ElectronicRouter {
            numPorts = 5; // numMidPorts del nivell inferior (inputs) i un que va amunt (output)
        	type = 32;
        	numPSEports = 0;
            id = networkPrefix + string(index) + ".";
            level = "NET";
             
            numX = numOfNodesX;
            numY = numOfNodesY;
            numZ = 1;
        }
        
        controller: MacController {
            
        }
        


    connections allowunconnected:
        // El último puerto (numPorts-1) es conexión con el gateway (NIF) 
		for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
			// No hay canal, se considera que el transceiver está inmediatamente junto el NIF
            node[i+j*numOfNodesX].portIn[0] <-- electronicGatewayIn[i+j*numOfNodesX];
            node[i+j*numOfNodesX].portOut[0] --> electronicGatewayOut[i+j*numOfNodesX];
         
        }

        // El resto de conexiones (numPorts ~ numPorts+numPortsIO-1) son a memoria (nodos periféricos)
        for i=0..numOfNodesX-1, for j=0..numOfNodesY-1, for k=1..numOfNodesX*2+(numOfNodesY-2)*2 {
           node[i+j*numOfNodesX].portIn[k] <-- IOin[(i+j*numOfNodesX)+(k-1)*numOfNodesX*numOfNodesY] if useIOplane; 
           node[i+j*numOfNodesX].portOut[k] --> IOout[(i+j*numOfNodesX)+(k-1)*numOfNodesX*numOfNodesY] if useIOplane;
        }            





	    // Connexions de controller a cada node
		for i=0..numOfNodesX-1, for j=0..numOfNodesY-1 {
            node[i+j*numOfNodesX].controllerIn <-- controller.portOutC[i+j*numOfNodesX];
		}    
		
		// Connexions de controller a Routers
		cntrl_plane[0].portOut[4] --> controller.portInC$i;
		cntrl_plane[0].portIn[4] <-- controller.portInC$o;
		    
        // Connexions entre Routers
        for i=0..nRouters-(numOfNodesX*numOfNodesY)-1 {
            cntrl_plane[i].portIn[0] <-- ElectronicChannel <-- cntrl_plane[4*i+1].portOut[4];
            cntrl_plane[i].portIn[1] <-- ElectronicChannel <-- cntrl_plane[4*i+2].portOut[4];
            cntrl_plane[i].portIn[2] <-- ElectronicChannel <-- cntrl_plane[4*i+3].portOut[4];
			cntrl_plane[i].portIn[3] <-- ElectronicChannel <-- cntrl_plane[4*i+4].portOut[4];
        	cntrl_plane[i].portOut[0] --> ElectronicChannel --> cntrl_plane[4*i+1].portIn[4];
            cntrl_plane[i].portOut[1] --> ElectronicChannel --> cntrl_plane[4*i+2].portIn[4];
            cntrl_plane[i].portOut[2] --> ElectronicChannel --> cntrl_plane[4*i+3].portIn[4];
            cntrl_plane[i].portOut[3] --> ElectronicChannel --> cntrl_plane[4*i+4].portIn[4];
        }
        
        // Connexions de Routers a Nodes
        for i=nRouters-(numOfNodesX*numOfNodesY)..nRouters-1 {
        	cntrl_plane[i].portIn[0] <-- node[i-(nRouters-(numOfNodesX*numOfNodesY))].controllerOut$o;
        	cntrl_plane[i].portOut[0] --> node[i-(nRouters-(numOfNodesX*numOfNodesY))].controllerOut$i;
        }

		        
}


