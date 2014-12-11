#include "ArrayList.h"

template<class T>
ArrayList<T>::ArrayList() :
	m_size(0)
{
	pElements = new T[SIZE_INCREMENT];
}

template<class T>
void ArrayList<T>::add(const T& toPush)
{
	if (m_size > 0 && (m_size) % SIZE_INCREMENT == 0)
	{
		T * newArray = new T[m_size + 1 + SIZE_INCREMENT];
		int prevSize = m_size;
		for (int x = 0; x < m_size; ++x)
			newArray[x] = pElements[x];
		delete[] pElements;
		pElements = newArray;
		//delete[] newArray;
	}//resize the array to a decent size.
	pElements[m_size] = toPush; m_size++;
}

template<class T>
void ArrayList<T>::print()
{
	std::cout<<"{";
	for (int x = 0; x < m_size; ++x)
	{
		std::cout<<pElements[x];
		if (x < m_size - 1)
			std::cout<<", ";
	}

	std::cout<<"}"<<std::endl;
}