#include "Node.h"
#include  <iostream>
#include <string>
#include "Processor.h"
#include "Memory.h"
#include "Storage.h"
#include "Power.h"

using namespace std;

Processor::Processor()
{
}

Processor::Processor(double m, double p, double s)
{
	dMemory = m;
	dPower = p;
	dStorage = s;
}

Processor::~Processor()
{
}



string Processor::toString() const
{
	return "Memory Usage: " + memory + "/nPower Usage: " + power + "/nStorage Usage: " + storage + "/n/n";
}

void Processor::setMemory()
{
	Memory m;
	double d = m.getSize();
	memory = to_string(d);
}

void Processor::setStorage()
{
	Storage s;
	double b = s.getSize();
	storage = to_string(b);
}

void Processor::setPower()
{
	Power p;
	double a = p.getPower();
	power = to_string(a);
}











