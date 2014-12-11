#include "ArrayList.h"

template<class T>
ArrayList<T>::ArrayList() :
	m_size(0)
{
	pElements = new T[SIZE_INCREMENT];
}

template<class T>
void ArrayList<T>::clear()
{
	delete[] pElements;//free up resources
	pElements = new T[SIZE_INCREMENT];//allocate resources
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
	}//resize the array to a decent size.
	pElements[m_size] = toPush; m_size++;
}

template<class T>
void ArrayList<T>::add(const T& toPush, int index)
{
	T * newArray = new T[m_size + 5];

	for (int x = 0; x < index; ++x)
		newArray[x] = pElements[x];
	newArray[index] = toPush;
	for (int x = index; x < m_size; ++x)
		newArray[x + 1] = pElements[x];
	delete[] pElements;
	pElements = newArray;
	m_size++;
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

		for (int x = 0; x < m_size; ++x)
			newArray[1 + x] = pElements[x];
		delete[] pElements;
		pElements = newArray;
		pElements[0] = toPush;
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

template<class T>
bool ArrayList<T>::contains(const T& object)
{
	for (int x = 0; x < m_size; ++x)
		if (pElements[x] == object)
			return true;

	return false;
}

template<class T>
int ArrayList<T>::indexOf(const T& object)
{
	int index = -1;
	for (int x = 0; x < m_size; ++x)
	{
		if (pElements[x] == object)
			index = x;
	}

	return index;
}