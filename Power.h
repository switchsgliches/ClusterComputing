#pragma once
#include <iostream>
#include <string>

class Power
{
private:
	double power;
public:
	Power();
	Power(double pow) { power = pow; };
	~Power();
	void setPower(double pow) { power = pow; };
	double getPower() { return power; };
};


