#include "Stack.h"

template<class T>
Stack<T>::Stack() :
	m_size(0)
{ pHeadNode = new Node<T>(); }

template<class T>
void Stack<T>::push(const T& toPush)
{
	Node<T> * nextNode = new Node<T>(toPush);
	pHeadNode->insertAfter(nextNode);
	m_size++;
}

template<class T>
T Stack<T>::pop()
{
	Node<T> * removed = pHeadNode->deleteNode();
	T returned = removed->getData();
	delete removed;
	return returned;
}

template<class T>
const T & Stack<T>::peek()
{
	return pHeadNode->nextNode->getData();
}

template<class T>
bool Stack<T>::empty()
{ return pHeadNode->nextNode() == NULL; }