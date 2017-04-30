#pragma once
#include "Processor.h"
#include "Power.h"
#include "RAM.h"
#include "Storage.h"

class Node : public Processor , public Power, public RAM, public Storage
{
private:
	Processor proc;
	RAM mem;
	Power pow;
	Storage store;

public:
	Node() {	};
	Node(Processor pr, RAM r, Power po, Storage stor)
	{
		proc = pr;
		mem = r;
		pow = po;
		store = stor;
	}
	std::string getData();
	
};