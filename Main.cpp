#include <string>
#include <iostream>
#include "Cluster.h"
#include "Node.h"

using namespace std;

int main()
{
	Processor pros("first","second","third",1.0,1.0,2.0,1,1,1.1);
	RAM r(12);
	Power pow(12);
	Storage st(1.5);
	Node n(pros, r, pow, st);
	Cluster c1(n);
	//Print processor data
	int count = 0;
	do {
		cout << pros.getData();
		count++;
	} while (c1.getSize() != count);

	cin.ignore();
	//Print cluster data;
	int count2 = 0;
	do {
		cout << c1.getClusterData();
		count++;
	} while (c1.getSize() != count2);
	cin.ignore();
	system("pause");
	return 0;
}