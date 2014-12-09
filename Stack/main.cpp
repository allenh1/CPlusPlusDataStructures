#include <iostream>
#include "Stack.cpp"

int main(int argc, char ** argv)
{
	Stack<int> m_stack;
	m_stack.push(3);
	m_stack.push(4);
	m_stack.push(5);

	while (!m_stack.empty())
		std::cout<< "Popped: " << m_stack.pop() << std::endl;
}
