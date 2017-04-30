#include "Node.h"

std::string Node::getData()
{
	std::string outString = " ";

	outString += "Node Data\n Processor Data:\n" + this->getData()
		+"RAM Data: " + std::to_string(this->getSize()) 
		+ "\nPower Data: " + std::to_string(this->getPower()) 
		+ "\nStorage Data: " + std::to_string(this->getStorage()) + "\n";

	return outString;
}
