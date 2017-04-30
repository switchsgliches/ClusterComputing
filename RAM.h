#pragma once

class RAM 
{
private:
	double size;
public:
	RAM() { size = 0.0; };
	RAM(double s) { size = s; };
	void setSize(double s) { size = s; };
	double getSize() { return size; };

};