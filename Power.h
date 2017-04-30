#pragma once

class Power
{
private:
	double power;
public:
	Power() { power = 0.0; };
	Power(double pow) { power = pow; };
	void setPower(double pow) { power = pow; };
	double getPower() { return power; };
};