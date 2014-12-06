#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
class Node {
public:
	Node(const T& data, Node<T> * pParent = NULL, Node<T> * pNext = NULL);
	Node();

	static const int & size(){ return m_size; }

	// bool operator = (const Node & other) {
	// 	delete pNextNode;

	// 	pNextNode = other.getChild();
	// 	return true;
	// }

	Node<T> * nextNode();
	Node<T> * getNode(const T& item, Node<T> * pNext = NULL);
	Node<T> * parentNode();
	Node<T> * deleteNode();
	void insertAfter(Node<T> * pBefore);

	const T & getData(){ return mData; }

	void setData(const T& data){ mData = data; }
	bool isLastElement(){ return pNextNode == NULL; }
	bool isFirstElement(){ return pParentNode == NULL; }
	//static int m_size;
	//template<class Y>
	//friend Template<Y> operator << (const LinkedList<Y> & l1, const Y& e1);
private:
	Node<T> * pNextNode;
	Node<T> * pParentNode;
	T mData;
	static int m_size;
};

template<class T>
int Node<T>::m_size = 0;
#endif
