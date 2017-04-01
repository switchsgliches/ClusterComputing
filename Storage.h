#pragma once
#include <iostream>
#include <string>

class Storage
{
private:
	double storage;
public:
	Storage();
	Storage(double s);
	~Storage();
	void setSize(double s);
	double getSize() { return storage; };

};



