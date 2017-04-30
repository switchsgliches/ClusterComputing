#include "Cluster.h"

Cluster::Cluster()
{
	clust.push_back(master);
}

Cluster::Cluster(Node n)
{
	Master m(n);
	master = (Master)n;
	clust.push_back(master);
}

Node Cluster::getMaster()
{
	return master;
}

void Cluster::addSlave(Node sin)
{
	Slave s(sin);
	clust.push_back(s);
}

Node Cluster::getSlave(int index)
{
	return clust.at(index);
}

std::string Cluster::getClusterData()
{
	std::string outString;
	//int size = clust.size();
	
	for (int i = 0; i < clust.size(); i++)
	{
		outString = clust.at(i).getData() + "\n\n";
	}
	
	return outString;
}
