/************************************************************************
*                                                                       *
*  POINTS - Photonic On-chip Interconnection Network Traffic Simulator  *
*                       (c) Assaf Shacham 2006-7			*
*			(c) Johnnie Chan  2008				*
*                                                                       *
* file: pse1x2.cc                                                       *
* description:                                                          *
*                                                                       *
*                                                                       *
*************************************************************************/


#include "pse1x2r3.h"

Define_Module(PSE1x2R3);

PSE1x2R3::PSE1x2R3()
{
}

PSE1x2R3::~PSE1x2R3()
{
}

void PSE1x2R3::Setup()
{
	debug(getFullPath(), "INIT: start", UNIT_INIT);

	currState = (int)PSE_OFF;



	gateIdIn[0] = gate("photonicHorizIn$i")->getId();
	gateIdIn[1] = gate("photonicVertIn$i")->getId();
	gateIdIn[2] = gate("photonicHorizOut$i")->getId();
	gateIdIn[3] = gate("photonicVertOut$i")->getId();

	gateIdOut[0] = gate("photonicHorizIn$o")->getId();
	gateIdOut[1] = gate("photonicVertIn$o")->getId();
	gateIdOut[2] = gate("photonicHorizOut$o")->getId();
	gateIdOut[3] = gate("photonicVertOut$o")->getId();

	portType[0] = in;
	portType[1] = in;
	portType[2] = out;
	portType[3] = out;

	PropagationLoss = par("PropagationLoss");
	PassByRingLoss = par("PassByRingLoss");
	PassThroughRingLoss = par("PassThroughRingLoss");
	CrossingLoss = par("CrossingLoss");
	BendingLoss = par("BendingLoss");

	Crosstalk_Cross = par("Crosstalk_Cross");

	// might be incorrectly named? On = Drop port, Off = Through Port
	RingOn_ER_1x2 = par("RingOn_ER_1x2");
	RingOff_ER_1x2 = par("RingOff_ER_1x2");

	ThroughDelay_1x2 = par("ThroughDelay_1x2");
	DropDelay_1x2 = par("DropDelay_1x2");

	vector<double> tempLatencyMatrix(numOfPorts,0);
	latencyMatrix.resize(numOfPorts,tempLatencyMatrix);
	// eventually read from file

	latencyMatrix[0][0] = 5.0e-12;
	latencyMatrix[0][1] = 4.1e-12;
	latencyMatrix[0][2] = 1.0e-12;
	latencyMatrix[0][3] = 4.1e-12;
	latencyMatrix[1][0] = 4.1e-12;
	latencyMatrix[1][1] = 0.9e-12;
	latencyMatrix[1][2] = 0.9e-12;
	latencyMatrix[1][3] = 1.0e-12;
	latencyMatrix[2][0] = 1.0e-12;
	latencyMatrix[2][1] = 0.9e-12;
	latencyMatrix[2][2] = 0.9e-12;
	latencyMatrix[2][3] = 4.1e-12;
	latencyMatrix[3][0] = 4.1e-12;
	latencyMatrix[3][1] = 1.0e-12;
	latencyMatrix[3][2] = 4.1e-12;
	latencyMatrix[3][3] = 5.0e-12;


	gateIdFromRouter = gate("fromRouter")->getId();

	RingStaticDissipation = par("RingStaticDissipation");
	RingDynamicOffOn = par("RingDynamicOffOn");
	RingDynamicOnOff = par("RingDynamicOnOff");

	debug(getFullPath(), "INIT: done", UNIT_INIT);

}


double PSE1x2R3::GetLatency(int indexIn, int indexOut)
{
	return latencyMatrix[indexIn][indexOut];
}

double PSE1x2R3::GetPropagationLoss(int indexIn, int indexOut, double wavelength)
{
	// Does not count the ring loss since included with drop #s
	double IL = 0;
	int ringSet;
	bool resonant = IsInResonance(wavelength,ringSet);

	double ringDiameter = this->ringDiameter[0];

	if(indexIn == 1 || indexIn == 2)
	{
		IL += 25;
	}

	if(indexOut == 1 || indexOut == 2)
	{
		IL += 25;
	}

	if(indexIn == 0 || indexOut == 0)
	{
		if(resonant && GetRingSetState(currState,ringSet) == 1)
		{
			IL += 5 + ringDiameter/2 + ringDiameter*(ringSet);
		}
		else
		{
			IL += 5 + (ringDiameter+5)*numOfRingSets;
		}
	}


	if(indexIn == 3 || indexOut == 3)
	{
		IL += 5 + 5 + 5 + ringDiameter + ringDiameter;

		if(resonant && GetRingSetState(currState,ringSet) == 1)
		{
			IL += 5 + ringDiameter/2 + ringDiameter*(ringSet);
		}
		else
		{
			IL += 5 + (ringDiameter+5)*numOfRingSets + ringDiameter;
		}
	}

	return PropagationLoss*IL;
}

double PSE1x2R3::GetBendingLoss(int indexIn, int indexOut, double wavelength)
{
	int ringSet;
	bool resonant = IsInResonance(wavelength,ringSet);

	if(indexIn == 3 || indexOut == 3)
	{
		if(resonant && GetRingSetState(currState,ringSet) == 1)
		{
			return BendingLoss * 3;
		}
		else
		{
			return BendingLoss * 4;
		}
	}
	return 0;
}

double PSE1x2R3::GetCrossingLoss(int indexIn, int indexOut, double wavelength)
{
	if(indexIn != indexOut)
	{
		if((indexIn+2)%4 == indexOut)
		{
			return CrossingLoss;
		}
		else if((indexIn == 0 && indexOut == 1)
			|| (indexIn == 1 && indexOut == 0)
			|| (indexIn == 1 && indexOut == 2)
			|| (indexIn == 2 && indexOut == 1)
			|| (indexIn == 2 && indexOut == 3)
			|| (indexIn == 3 && indexOut == 2))
		{
			return Crosstalk_Cross;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return MAX_INSERTION_LOSS;
	}
}

double PSE1x2R3::GetDropIntoRingLoss(int indexIn, int indexOut, double wavelength)
{
	double IL = 0;
	int ringSet;
	bool resonant = IsInResonance(wavelength,ringSet);

	if((indexIn == 0 && indexOut == 3)
			|| (indexIn == 3 && indexOut == 0))
	{
		IL += PassThroughRingLoss;

		if(resonant && GetRingSetState(currState,ringSet) == 0)
		{
			IL += RingOn_ER_1x2;
		}

	}
	return IL;
}

double PSE1x2R3::GetPassByRingLoss(int indexIn, int indexOut, double wavelength)
{
	double IL = 0;
	int ringSet;
	bool resonant = IsInResonance(wavelength,ringSet);

	if((indexIn == 1 && indexOut == 3)
			|| (indexIn == 3 && indexOut == 1)
			|| (indexIn == 0 && indexOut == 2)
			|| (indexIn == 2 && indexOut == 0))
	{
		IL += PassByRingLoss*numOfRingSets;

		if(resonant && GetRingSetState(currState,ringSet) == 1)
		{
			IL += RingOff_ER_1x2;
		}
	}

	else if(((indexIn == 0 && indexOut == 3) || (indexIn == 3 && indexOut == 0)))
	{
		IL += PassByRingLoss*2*ringSet;
	}

	return IL;
}


double PSE1x2R3::GetPowerLevel(int state)
{
	switch(state)
	{
	case 0:
		return 0;
		break;
	case 1:
		return RingStaticDissipation * 1;
		break;
	case 2:
		return RingStaticDissipation * 1;
			break;
	case 3:
		return RingStaticDissipation * 2;
			break;

	default:
		return 0;
	};
}

double PSE1x2R3::GetEnergyDissipation(int stateBefore, int stateAfter)
{
	double energyTotal = 0;

	if(stateBefore != stateAfter)
	{
		if(stateBefore&1 == 0 && stateAfter&1 == 1)
		{
			energyTotal += RingDynamicOffOn;
		}

		if(stateBefore&1 == 1 && stateAfter&1 == 0)
		{
			energyTotal += RingDynamicOnOff;
		}

		if((stateBefore>>1)&1 == 0 && (stateAfter>>1)&1 == 1)
		{
			energyTotal += RingDynamicOffOn;
		}

		if((stateBefore>>1)&1 == 1 && (stateAfter>>1)&1 == 0)
		{
			energyTotal += RingDynamicOnOff;
		}

	}
	return energyTotal;
}

void PSE1x2R3::SetRoutingTable()
{
	// off resonance case
	routingTable[0] = 2;
	routingTable[1] = 3;
	routingTable[2] = 0;
	routingTable[3] = 1;

}


int PSE1x2R3::GetMultiRingRoutingTable(int index, int ringSet)
{
	int ringState = GetRingSetState(currState,ringSet);

	if(ringState == 1)
	{
		switch(index)
		{
		case 0:
			return 3;
		case 1:
			return -1;
		case 2:
			return -1;
		case 3:
			return 0;
		}
	}
	else
	{
		return routingTable[index];
	}
}
