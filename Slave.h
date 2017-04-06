#pragma once
#include "Node.h"

class Slave : public Node
{
public:
	Node slav;
	bool isSlave;
	bool isMaster;
	Slave()
	{
		isSlave = true;
		isMaster = false;
	}
	Slave(Node s)
	{
		slav = s;
	}
};