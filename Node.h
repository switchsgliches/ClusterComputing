#pragma once


template <class T>
class Node
{
	friend class Processor;
public:
	Node();
	Node(int v);
	Node(int v, Node* next);
	~Node();

	int getValue();
	Node* getNext();

private:
	int value;
	Node *pNext;
	
};


