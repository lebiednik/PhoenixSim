/*
 * AppBcast.cc
 *
 * All cores send broadcast packets following two distributions:
 * 	- SPATIAL: following a gaussian spatial distribution
 *  - TEMPORAL: following a bursty distribution with Hurst exponent H.
 *
 *  Created on: April, 2014
 *  Last modified on: April, 2014
 *
 *      Author: Abadal
 *      Based on AppBcastTest on PhoenixSim
 */

#include "AppBcast.h"
#include "math.h"

int AppBcast::bcastRcvd = 0;
int AppBcast::responseRcvd = 0;


AppBcast::AppBcast(int i, int n, double freq, DRAM_Cfg* cfg) :
	Application(i, n, cfg) {

	f = freq;
	packetsToSend = 0;

	double lambdaT = param1;
	int totalMessages = param2;
	numOfNodesX = param3;
	bits = param4;
	bcast_percent = param6;
	H = param7;
	sigma = param8;

	id = i;

	// Calculating spatial distribution of the load:
		double *gausspdf;
		gausspdf = (double *) malloc(numOfNodesX*numOfNodesX *sizeof(double));
		double gausssum = 0;

		// Recreate a gaussian pdf
		double k = 0;
		for(int j=0;j<numOfNodesX*numOfNodesX;j++){
			k = (double) j/(numOfNodesX*numOfNodesX-1);
			gausspdf[j] = exp( -pow( (k-0.5)/sigma, 2));
			gausssum = gausssum + exp( -pow( (k-0.5)/sigma, 2));
		}

		// Normalize it
		for(int j=0;j<numOfNodesX*numOfNodesX;j++){
			gausspdf[j] = gausspdf[j]/gausssum;
		}

	// Number of messages of this node according to the spatial distribution
	numMessages = (int) nearbyint(totalMessages * gausspdf[id]);
	// Time between arrivals is also modified by the gaussian distribution.
	double lambda = lambdaT * gausspdf[id];
	arrival = 1/(lambda*f);

	// EVCON ev.printf("Messages for node %d: %d. Lambda: %1.8f (instead of %1.8f)\n",id,numMessages,lambda,lambdaT/(numOfNodesX*numOfNodesX));
	init();
}

void AppBcast::init() {


}

AppBcast::~AppBcast() {

}

// Retornem el temps que ha de passar fins el pròxim paquet
simtime_t AppBcast::process(ApplicationData* pdata) {


    double Tinburst = (2/f); // temps entre paquets d'un burst.

    if ( H == 0.5 ) {

        double delay = exponential(arrival);
        return (simtime_t) (RoundToClk(delay)/f);


    } else {

        // Here goes self-similar traffic generation...
        // Enviem bursts de paquets de llargària fixa (podem posar petita separació entre paquets en un burst)
            // El num de paquets per burst ve donat per una distribució Pareto (T_ON)
        // Entre bursts, hi ha períodes de silenci
            // El temps d'aquest període ve donat per una distribució Pareto (T_OFF)
        // Les distribucions Pareto han de ser independents, farem servir una llavor diferent per cada una.

        // Si estem dins un burst, Tinburst
        if(packetsToSend > 0) {
            packetsToSend--;
            return (simtime_t) Tinburst;

        // Si no, calculem la mida del pròxim burst i retornem el T_OFF
        } else {
            // H = (3 - a) / 2 de la distribucio Pareto, per tant 2H = 3 - a, a = 3 - 2H
            double aON = 3 - 2*H;
            // T_ON > generar bursts de paquets, amb llargada [1,inf) paquets per burst.
            double bON = 1; // b is the minimum value of x

            packetsToSend = nearbyint( pareto_shifted(aON,bON,0,0) );

            // bOFF s'ha d'escollir per coincidir amb la càrrega (lambda)
            // arrival és el temps mitjà entre arribades en segons, de manera que tenim lambda = 1/arrival pkts/seg
            // Necessitem la càrrega oferida (0 < L < 1), per tant, L = lambda/f
            // (normalitzat a freqüència: el màxim és un paquet per cicle de rellotge)
            double L = Tinburst/arrival;
            if (L>0.97)
                L = 0.97;    // limitar L per no donar valors negatius de temps.


            // L = E[t_ON] / (E[t_ON] + E[t_OFF]), E[t_OFF] = E[t_ON] *(1/L - 1)
            // E[t_ON] és la mitjana de paquets per burst pel temps entre paquets d'un burst, per tant: E[t_ON] = Tinburst*E[paq]
            // E[paq] al ser pareto serà, aprox, E[paq] = a*bON / (a-1)
            double EON = Tinburst * aON*bON / (aON-1);
            // E[t_OFF] correspondria a la mitjana d'una pareto.
            // idealment: E[t_OFF] = aOFF*bOFF/(aOFF-1), aillem b:
            // E[t_OFF]*(aOFF-1) = aOFF*bOFF -> bOFF = E[t_OFF]*(aOFF-1)/aOFF = E[t_ON]*(1/L-1)*(aOFF-1)/aOFF
            //double aOFF = aON - (aON-1)/2;
            double aOFF = 1.04 + pow(aON-1.04, 1/(aON-1));
            double bOFF = EON*(1/L-1)*(aOFF-1)/aOFF;
            //double Umin = pow(2,-32);
            //double bOFF = EON*(1/L-1)*(aOFF-1)/aOFF * (1-pow(Umin,(aON-1)/aON))/(1-pow(Umin,(aOFF-1)/aOFF));

            double timeP = pareto_shifted(aOFF, bOFF, 0);
            if (timeP <= 0) {
                 opp_error("ERROR temps negatiu!");
            }


            return (simtime_t) (RoundToClk(timeP)/f);
        }
    }
}

ApplicationData* AppBcast::getFirstMsg() {

	return msgCreated(NULL);

}


ApplicationData* AppBcast::msgCreated(ApplicationData* pdata)
{

		int dest = id;

		if(numMessages==0)
		{
			return NULL;
		}

		// EVCON ev.printf("%1.10f",simTime().dbl());




		ApplicationData* adata = new ApplicationData();


		adata->setSrcId(id);
		adata->setPayloadSize(bits);

		double rndm = uniform(0,100);
		if(rndm <= bcast_percent) {
			adata->setType(snoopReq);
			// HACK: set destination id as the furthest destination, to measure bcast latency.
			dest = getFurthestDest(id);
			adata->setDestId(dest);
			debug("application", "sending snoop bcast from ", id, UNIT_APP);
		} else {
			adata->setType(snoopResp);
			while(dest == id)
					dest = intuniform(0, numOfProcs-1);
			adata->setDestId(dest);
			debug("application", "sending snoop unicast from ", id, UNIT_APP);
		}

		//ev.printf("Sending %d bits of data\n", bits);



		if(numMessages > 0)
		{
			//std::cout<<numMessages<<endl;
			numMessages--;
		}

		return adata;
}

int AppBcast::getFurthestDest(int id)
{
	int numX;
	int numY;
	int result;

	numX = id % numOfNodesX;
	numY = floor(id/numOfNodesX);

	if((double) numX > ((numOfNodesX-1)/2))
			result = 0;
		else
			result = numOfNodesX-1;

	if((double) numY > ((numOfNodesX-1)/2))
			result += 0;
		else
			result += (numOfNodesX-1)*numOfNodesX;

	//ev.printf("I am processor %d and I'm sending a broadcast with destination %d \n",id,dest);
	return result;
}


ApplicationData* AppBcast::dataArrive(ApplicationData* pdata) {

	int type = pdata->getType();


	bytesTransferred += pdata->getPayloadSize();

	debug("app", "message received at", id, UNIT_APP);
	debug("app", "... from ", pdata->getSrcId(), UNIT_APP);


	if (type == snoopReq) {
		bcastRcvd++;

		if(procLevelAck == 1) {

		    // EVCON ev.printf("Send snoop response.\n");
		    ApplicationData* adata = new ApplicationData();

		    adata->setType(snoopResp);
		    adata->setDestId(pdata->getSrcId());
		    adata->setSrcId(id);
		    adata->setPayloadSize(16);

		    debug("application", "sending snoop response from ", id, UNIT_APP);

		    return adata;

		}

	} else if (type == snoopResp) {
	    responseRcvd++;

	    // EVCON ev.printf("Snoop response received. Do nothing.\n");
	    debug("app", "response received = ", responseRcvd, UNIT_APP);

	}

	return NULL;

}

int AppBcast::RoundToClk(double delay) {

    int result = ceil(delay*f);
    return result;

}

