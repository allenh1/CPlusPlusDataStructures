#include "ArrayList.h"

/**
 * @brief      Default Constructor.
 *
 * @tparam     T     Typename
 */
template<class T>
ArrayList<T>::ArrayList() :
	m_size(0),
	m_capacity(SIZE_INCREMENT)
{
	pElements = new T[SIZE_INCREMENT];
}

/**
 * @brief      Clear the ArrayList
 *
 * @tparam     T     Typename
 */
template<class T>
void ArrayList<T>::clear()
{
	delete[] pElements;//free up resources
	m_size = 0;
	m_capacity = SIZE_INCREMENT << 4;
	pElements = new T[m_capacity];//allocate resources
}

/**
 * @brief      Adds a thing to the ArrayList
 *
 * @param[in]  toPush  The to be added.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::add(const T& toPush)
{
	if (m_size >= m_capacity) {
		m_capacity *= SIZE_INCREMENT;
		T * temp = new T[m_capacity];
		std::copy(pElements, pElements + m_size, temp);
		if (!std::is_pointer<T>::value)
			delete[] pElements;
		else
			delete pElements;
		pElements = temp;
	}

	pElements[m_size++] = toPush;
}

/**
 * @brief      Adds a thing in a specific index.
 *
 * @param[in]  toPush  Thing to add
 * @param[in]  index   Where it is to be added.
 *
 * @tparam     T       Type of thing
 */
template<class T>
void ArrayList<T>::add(const T& toPush, int index)
{
	if (m_size && index >= m_size) return;
	
	if (m_size + 1 >= m_capacity) {
		m_capacity *= SIZE_INCREMENT;
		T * temp = new T[m_capacity];
		std::copy(pElements, pElements + m_size, temp);
		if (!std::is_pointer<T>::value)
			delete[] pElements;
		else
			delete pElements;
		pElements = temp;
	}
	T * temp = new T[m_size - index];
	std::copy(pElements + index, pElements + m_size, temp);
	std::copy(temp, temp + m_size - index, pElements + index + 1);
	pElements[index] = toPush; ++m_size;
}

/**
 * @brief      Print function for things with a toString.
 *
 * @tparam     T     Typename
 */
template<class T>
void ArrayList<T>::print()
{
	std::cout<<"{";
	for (int x = 0; x < m_size; ++x)
	{
		std::cout<<pElements[x].toString();
		if (x < m_size - 1)
			std::cout<<", ";
	}

	std::cout<<"}"<<std::endl;
}

/**
 * @brief      Pushes to the back of the list.
 *
 * @param[in]  toPush  Thing to push back.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::push_back(const T& toPush){ this->add(toPush); }

/**
 * @brief      Push a thing to the front of the list.
 *
 * @param[in]  toPush  Thing to be pushed.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::push_front(const T& toPush)
{
	this->add(toPush, 0);
}

/**
 * @brief      Remove the item at a specific index.
 *
 * @param[in]  index  Index of the thing to be removed.
 *
 * @tparam     T      Typename
 *
 * @return     Shallow copy of the item we removed.
 */
template<class T>
const T ArrayList<T>::remove(int index)
{
	if (index >= m_size)
		return T();

	if (m_size == 1) {
		const T myT = pElements[index];
		--m_size;
		if (!std::is_pointer<T>::value)
			delete[] pElements;
		else if (std::is_pointer<T>::value)
			delete pElements;
		pElements = new T[SIZE_INCREMENT];
		return myT;
	}
	const T myT = pElements[index];
	std::copy(pElements + index + 1, pElements + m_size, pElements + index);

	m_size--;
	return myT;
}

/**
 * @brief      Removes a particular item from the list.
 *
 * @param[in]  toRemove  Thing to remove.
 * @param      ok        True upon successful removal.
 *
 * @tparam     T         Typename
 */
template<class T>
void ArrayList<T>::remove(const T & toRemove, bool * ok) {
	int index = indexOf(toRemove);
	if (index == -1) {
		*ok = false;
		return;
	}

	this->remove(index);
	*ok = true;
}

/**
 * @brief      Check if an item is in the ArrayList.
 *
 * @param[in]  object The thing we want to know about.
 *
 * @tparam     T       Typename
 *
 * @return     Returns true if it's there.
 */
template<class T>
bool ArrayList<T>::contains(const T& object)
{
	for (int x = 0; x < m_size; ++x)
		if (pElements[x] == object)
			return true;

	return false;
}

/**
 * @brief      Returns the first index of T.
 *
 * @param[in]  object  Thing.
 *
 * @tparam     T       Typename
 *
 * @return     The first index of thing.
 */
template<class T>
int ArrayList<T>::indexOf(const T& object)
{
	for (int x = 0; x < m_size; ++x)
	{
		if (pElements[x] == object)
			return x;
	}

	return -1;
}

/**
 * @brief      Return the ith occurance of T.
 *
 * @param[in]  object     Thing.
 * @param[in]  occurance  Occurance of thing to find.
 *
 * @tparam     T          Type of thing.
 *
 * @return     Location of thing.
 */
template<class T>
int ArrayList<T>::indexOf(const T& object, int occurance)
{
	for (int x = 0; x < m_size; ++x)
		if (pElements[x] == object && !--occurance)
			return x;
	return -1;
}

/**
 * @brief      Check for the last index of an object.
 *
 * @param[in]  object  Thing to check
 *
 * @tparam     T       Typename
 *
 * @return     Integer location of the last location, or -1.
 */
template<class T>
int ArrayList<T>::lastIndexOf(const T& object)
{
	for (int x = m_size - 1; x >= 0; --x)
		if (pElements[x] == object)
			return x;

	return -1;
}

/**
 * @brief      Sorts the given list in ascending order.
 * 
 * This sorts the list in ascending order. It is assumed
 * that the < operator has been overloaded.
 *
 * @tparam     T   type.  
 */
template<class T>
void ArrayList<T>::sort() { std::sort(pElements, pElements + m_size); }
