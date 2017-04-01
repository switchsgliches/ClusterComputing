#include "Node.h"
#include  <iostream>
#include <string.h>

using namespace std;

template<class T>
inline Node<T>::Node()
{
}

template<class T>
Node<T>::Node(int v)
{
}

template<class T>
Node<T>::Node(int v, Node * next)
{
}

template<class T>
Node<T>::~Node()
{	
}

template<class T>
int Node<T>::getValue()
{
	return value;
}

template<class T>
Node * Node<T>::getNext()
{
	return pNext;
}


