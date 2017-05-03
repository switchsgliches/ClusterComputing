#include "stdafx.h"
#include "Processor.h"


Processor::Processor()
{
	name = "";
	model = "";
	socket = "";
	OpsPerCycle = 0;
	clockSpeed = 0.0;
	hostSpeed = 0.0;
	size = 0.0;
	logicalCores = 0;
	physicalCores = 0;
	power = 0.0;
	FLOPS = 0;
	OpEff = 0;
};

Processor::Processor(std::string n, std::string m, std::string soc,int OPSPERCYC, double clock,
	double host, double sz, int log, int phys, double pow,int flops, int OPEFF)
{
	name = n;
	model = m;
	socket = soc;
	OpsPerCycle = OPSPERCYC; //Operations Per Cycle
	clockSpeed = clock;//base speed
	hostSpeed = host; 
	size = sz;
	logicalCores = log;
	physicalCores = phys;
	power = pow;
	FLOPS = (((clockSpeed*physicalCores)*OpsPerCycle));
	OpEff = OPEFF; // processor Operational Eff%
}