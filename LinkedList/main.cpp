#include "Node.cpp"
#include <iostream>

int main(int argc, char ** argv)
{
	//Node::m_size = 0;
	Node<char> * myNode1, *myNode2, *myNode3;

	myNode1 = new Node<char>('a');
	myNode3 = new Node<char>('c', NULL, myNode1);
	myNode2 = new Node<char>('b', NULL, myNode3);
	
	//myNode1->insertAfter(myNode2);//shove in 'dere
	
	std::cout<<"{ " << myNode2->getData() <<", "
					<< myNode2->nextNode()->getData() <<", "
					<< myNode2->nextNode()->nextNode()->getData() << " }" <<std::endl;
	std::cout<<"Size = "<<Node<char>::size()<<std::endl;
	delete myNode1;
	delete myNode2;
	delete myNode3;
	return 0;
}