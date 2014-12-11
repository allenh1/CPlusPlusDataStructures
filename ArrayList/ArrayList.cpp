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

template<class T>
void ArrayList<T>::push_back(const T& toPush){ this->add(toPush); }

template<class T>
void ArrayList<T>::push_front(const T& toPush)
{
	if (m_size > 0 && (m_size + 1) % SIZE_INCREMENT == 0)
	{
		T * newArray = new T[m_size + 1 + SIZE_INCREMENT];
		int prevSize = m_size;
		for (int x = 0; x < m_size; ++x)
			newArray[1 + x] = pElements[x];
		delete[] pElements;
		pElements = newArray;
		pElements[0] = toPush;
		//delete[] newArray;
	}//resize the array to a decent size.
	else
	{
		T * newArray = new T[m_size + 1];
		for (int x = 0; x < m_size; ++x)
			newArray[1 + x] = pElements[x];
		newArray[0] = toPush;
		delete[] pElements;
		pElements = newArray;
	}
	m_size++;
}

template<class T>
const T ArrayList<T>::remove(int index)
{
	const T myT = pElements[index];
	T* newArray = new T[m_size - 1];

	for (int x = 0; x < index; ++x)
	{
		newArray[x] = pElements[x];
	}

	for (int x = index + 1; x < m_size; ++x)
		newArray[x - 1] = pElements[x];
	delete[] pElements;
	pElements = newArray;
	m_size--;
	return myT;
}