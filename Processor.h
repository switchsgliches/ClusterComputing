#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include "Storage.h"
#include "Power.h"
#include "Memory.h"

class Processor {
public:
	Processor();
	Processor(double m, double p, double s);
	~Processor();
	string toString() const;
	void setMemory();
	void setStorage();
	void setPower();
private:
	string memory;
	string power;
	string storage;
	double dMemory;
	double dPower;
	double dStorage;
};

ostream& operator<< (ostream& outs, const Processor* obj) {
	return outs << obj->toString();
}
