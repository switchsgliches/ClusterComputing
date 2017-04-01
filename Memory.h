#pragma once

class Memory
{
public:
	Memory();
	Memory(double s);
	~Memory();
	void setSize(double s);
	double getSize() { return size; };
	string toString()
	{
		string theSize = std::to_string(size);
	}

private:
	double size;


};


