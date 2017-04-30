#pragma once
#include "Node.h"

class Master : public Node
{
public:
	Node mast;
	bool isMaster;
	bool isSlave ;
	Master()
	{
		isMaster = true;
		isSlave = false;
	}
	Master(Node m)
	{
		mast = m;
	}
};