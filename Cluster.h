#pragma once
#include <vector>
#include <string>
#include "Node.h"
#include "Master.h"
#include "Slave.h"

class Cluster
{
private:
	Master master;
	std::vector<Node> clust;
	
public:
	Cluster();
	Cluster(Node);
	Node getMaster();
	void addSlave(Node);
	Node getSlave(int);
	std::string getClusterData();
	int getSize() {
		int size = clust.size();
		return size;
	}
};