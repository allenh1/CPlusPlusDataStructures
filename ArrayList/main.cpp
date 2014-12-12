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
	testCopy.add(-3, 1);
	testCopy.add(-3);
	testCopy.add(-4, 2);
	testCopy.print();
	example = testCopy;
	std::cout<<"Replaced example: "<<std::endl;
	example.print();
	testCopy.print();
	std::cout<<"Index of -3: "<<testCopy.indexOf(-3)<<std::endl;
	std::cout<<"Last index of -3: "<<testCopy.lastIndexOf(-3)<<std::endl;
	return 0;
}