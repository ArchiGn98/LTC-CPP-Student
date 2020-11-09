/*
 * Template.h
 *
 *  Created on: 22 сент. 2017 г.
 *      Author: Паша
 */

#ifndef SRC_TEMPLATE_H_
#define SRC_TEMPLATE_H_
#include <initializer_list>
template<typename T,int size=10>

class Storage
{
private:
	T *Buffer;
	int count;
public:
	Storage(std::initializer_list<T> init);
	~Storage();
	T GetSum();
};

template<typename T,int size>
Storage<T,size>::Storage(std::initializer_list<T> init) : count(0)
{
	Buffer = new T[size];
	for(auto c: init)
		Buffer[count++] = c;
}

template<typename T, int size>
Storage<T,size>::~Storage()
{
	delete []Buffer;
}

template<typename T,int size>
T Storage<T,size>::GetSum()
{
  T Sum = 0;
  for(int i=0;i<count;i++)
	  Sum+= Buffer[i];
  return Sum;
}
//-----------------------------------------------------------------------------
template<typename T>
class TestPartial
{
	T value;
public:
	TestPartial(T v) : value(v) {}
	T GetValue() { return value;}
};

template<typename T>
class TestPartial<T*>
{
	T* value;
public:
	TestPartial(T* v) : value(v) {}
	int GetValue() { return *value;}
};


#endif /* SRC_TEMPLATE_H_ */
