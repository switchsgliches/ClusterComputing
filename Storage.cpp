#include "Storage.h"
#include <iostream>
#include <string.h>

using namespace std;

Storage::Storage()
{
}

Storage::Storage(double s)
{
	storage = s;
}

Storage::~Storage()
{
}

void Storage::setSize(double s)
{
	storage = s;
}
