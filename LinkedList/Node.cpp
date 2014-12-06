#include "Node.h"

template<class T>
Node<T>::Node()
{ /** Pointers make this null. Happy things, happy things. **/}

template<class T>
Node<T>::Node(const T& data, Node<T> * pParent, Node<T> * pNext)
{
	mData = data;
	pNextNode = pNext;
	pParentNode = pParent;
	m_size++;
}

template<class T>
Node<T> * Node<T>::getNode(const T& item, Node<T>* pNext)
{
	Node<T> * pLocal = new Node<T>(item, pNext);
	
	if (pLocal == NULL)
	{
		std::cerr<<"Memory allocation failed." << std::endl;
	}

	return pLocal;
}


template<class T>
Node<T> * Node<T>::deleteNode()
{
	Node<T> * tempNode = pNextNode;

	if (pNextNode != NULL)
		pNextNode = pNextNode->pNextNode;
	m_size--;
	return tempNode;
}

template<class T>
void Node<T>::insertAfter(Node<T> * pBefore)
{
	pBefore->pNextNode = this->pNextNode;
	m_size++;
	this->pNextNode = pBefore;
}

template<class T>
Node<T> * Node<T>::nextNode() { return pNextNode; }
template<class T>
Node<T> * Node<T>::parentNode() { return pParentNode; }