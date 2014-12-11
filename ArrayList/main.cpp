#include <iostream>
#include "ArrayList.cpp"

int main(int argc, char ** argv)
{
	ArrayList<int> example;
	
	for (int x = 1; x < 17; ++x)
		example.add(x);
	example.print();

	ArrayList<char> other;
	other.add('a'); other.add('b'); other.add('c');
	other.print();

	return 0;
}