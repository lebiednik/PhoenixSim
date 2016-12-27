//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package electronicComponents.MAC_Layer;


moduleinterface IMacLayer
{
    parameters:
		
		int idnum;
		int type;
		int numOfNodesX;
		int numX;
		int numY;
		double coreSizeX;
		double channelCapacity;
		double O_frequency_data;
		double backOffPeriod;
		double pPersistent;
		bool negativeACKs;
		
		//double timeout;
		
		int maxRETRIES;

        @display("i=abstract/router");
    gates:
	
			input fromNic;
	        input fromPhy;
	        output macToPhy;
	        output toNic;
	        
	        output macToController;
	        input controllerToMac;
}