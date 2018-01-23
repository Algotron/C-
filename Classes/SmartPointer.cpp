#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "SmartPointer.h"
#include "Ligne.h"
#include "Forme.h"

template <class T>
SmartPointer<T>::SmartPointer()
{
	
}

template <class T>
SmartPointer<T>::SmartPointer(T * value)
{
	setVal(value);
}

template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer &obj)
{
	setVal(obj.getVal());
}
	
template <class T>
void SmartPointer<T>::setVal(T * value)
{
	val = value;
}	

template <class T>
T* SmartPointer<T>::getVal() const
{
	return val;
}
	
template <class T>
void SmartPointer<T>::Delete()
{
	if(val)
		delete val;
}

template <class T>
SmartPointer<T> SmartPointer<T>::operator=(const SmartPointer<T> &obj)
{
	setVal(obj.getVal());
	return *this;
}

template <class T>
SmartPointer<T> SmartPointer<T>::operator=(T * value)
{
	setVal(value);
	return *this;
}

template <class T>
T& SmartPointer<T>::operator*() const
{
	return * val;
}

template <class T>
T* SmartPointer<T>::operator->() const
{
	return val;
}

template <class T>
int SmartPointer<T>::operator>(const SmartPointer<T> &obj) const
{
	if(*val > *(obj.getVal()))
		return 1;
	else
		return 0;
}

template <class T>
int SmartPointer<T>::operator<(const SmartPointer<T> &obj) const
{
	if(*val < *(obj.getVal()))
		return 1;
	else
		return 0;
}

template <class T>
int SmartPointer<T>::operator==(const SmartPointer<T> &obj) const
{
	if(*val == *(obj.getVal()))
		return 1;
	else
		return 0;
}

template <class T>
SmartPointer<T>::~SmartPointer()
{

}

template class SmartPointer<Forme>;
template class SmartPointer<int>;
template class SmartPointer<int*>;
template class SmartPointer<Ligne>;
