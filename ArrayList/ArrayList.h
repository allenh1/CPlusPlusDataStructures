#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

template<class T>
class ArrayList
{
public:
	ArrayList();
	~ArrayList(){ delete[] pElements; }

	int indexOf(const T& other);
	const int & size(){ return m_size; }
	const T & get(int index){ return pElements[index]; }
	const T remove(int index);
	inline T & operator [](int index){ return pElements[index]; }

	void print();
	void add(const T& toPush);
	void add(const T& toPush, int index);
	void clear();
	void push_back(const T& toPush);
	void push_front(const T& toPush);

	bool isEmpty(){ return m_size == 0; }
	bool contains(const T& object);
	
	bool operator =(const ArrayList& other)
    {
        delete []pElements;//empty out the array

        /** Gets operator **/
        int x = other.size();
        pElements = new T[x];
        for (int y = 0; y < x; y++)
            pElements[y] = other[y];

        m_size = x;

        return true;
    }

    bool operator ==(const ArrayList& other)
    {
    	if (other.size() != m_size)
    		return false;

    	for (int x = 0; x < size; ++x)
    		if (other[x] != pElements[x])
    			return false;

    	return true;
    }

private:
	T * pElements;
	int m_size;
	const static int SIZE_INCREMENT = 10;
};
#endif