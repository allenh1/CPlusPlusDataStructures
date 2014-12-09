#ifndef STACK_H
#define STACK_H
#include "../LinkedList/Node.cpp"
#include <iostream>

template<class T>
class Stack
{
public:
	Stack();

	const int & size(){ return m_size; }

	T pop();
	const T & peek();

	bool empty();

	void push(const T& toPush);
private:
	Node<T> * pHeadNode;
	int m_size;
};
#endif