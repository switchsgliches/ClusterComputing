#include "Processor.h"

Processor::Processor()
{
	name = "";
	model = "";
	socket = "";
	clockSpeed = 0.0;
	hostSpeed = 0.0;
	size = 0.0;
	logicalCores = 0;
	physicalCores = 0;
	power = 0.0;
};

Processor::Processor(std::string n, std::string m, std::string soc, double clock,
	double host, double sz, int log, int phys, double pow)
{
	name = n;
	model = m;
	socket = soc;
	clockSpeed = clock;
	hostSpeed = host;
	size = sz;
	logicalCores = log;
	physicalCores = phys;
	power = pow;
}