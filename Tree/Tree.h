#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "../LinkedList/Node.cpp"

class Tree
{
public:
	Tree();
	~Tree(){};
	
private:
	Node * pHeadNode;
};
#endif