#pragma once

class Storage
{
private:
	double storage;
public:
	Storage() { storage = 0.0; };
	Storage(double s) { storage = s; };
	void setStorage(double s) { storage = s; };
	double getStorage() { return storage; };
}; 

