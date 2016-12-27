package processingPlane.trafficGenerator;


simple TrafficGenerator
{
    parameters:
        double clockRate;
        
        int numOfNodesX;
        int numOfNodesY;
        
       // double O_frequency_cntrl;
        double O_frequency_proc;
        
        string application;
   		int furthDest;
        
        
        double appParam1;
        double appParam2;
        double appParam3;
        double appParam4;
        string appParam5;
        double appParam6;
        
        double appParam7;
        double appParam8;
        double appParam9;
        
        @display("i=device/cpu");
    gates:
        
        output toProc[numOfNodesX*numOfNodesY];


}
