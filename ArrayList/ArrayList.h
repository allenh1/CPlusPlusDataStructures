#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

template<class T>
class ArrayList
{
public:
	ArrayList();
	~ArrayList(){ delete[] pElements; }

	
	const int & size(){ return m_size; }
	const T & get(int index){ return pElements[index]; }
	inline T& operator [](int index){ return pElements[index]; }

	void print();
	void add(const T& toPush);

	bool isEmpty(){ return m_size == 0; }

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

private:
	T * pElements;
	int m_size;
	const static int SIZE_INCREMENT = 10;
};
#endif