#include "Memory.h"
#include <iostream>
#include <string>

using namespace std;

Memory::Memory()
{
}

Memory::Memory(double s)
{
	size = s;
}

Memory::~Memory()
{}

void Memory::setSize(double s)
{
	size = s;
}



