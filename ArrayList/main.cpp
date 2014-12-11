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
	other.push_back('q');
	other.print();
	other.push_front('z');
	other.print();
	char guessWhatGuys = other.remove(1);
	other.print();
	std::cout<<"Removed: "<<guessWhatGuys<<std::endl;
	ArrayList<int> testCopy;
	testCopy.add(-1); testCopy.add(-2);
	testCopy.print();
	return 0;
}