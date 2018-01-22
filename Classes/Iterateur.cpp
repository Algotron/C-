#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Iterateur.h"
#include "SmartPointer.h"
#include "Forme.h"

template <class T>
Iterateur<T>::Iterateur(ListeBase<T> & lis)//initialisation
{
	#ifdef DEBUG
	cout << "Initialisation constuctor Iterateur" << endl;
	#endif
	
	list = &lis;
	current = lis.pTete;
}

template <class T>
Iterateur<T>::Iterateur(Iterateur<T> & it)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor Iterateur" << endl;
	#endif

	list = it.list;
	current = it.current;
}

template <class T>
void Iterateur<T>::reset()
{
	current = list->pTete;
}

template <class T>
T Iterateur<T>::remove()
{
	T tVal;
	Cellule<T> * tempCur = list->pTete;
	
	if(current == NULL)
		return T();
	
	if(current == list->pTete)//bigining
	{
		tVal = current->valeur;
		list->pTete = current->suivant;
		delete current;
		reset();
	}
	else //2nd->end
	{
		while(tempCur->suivant != current)
			tempCur = tempCur->suivant;
		
		tempCur->suivant = current->suivant;
		delete current;
		current = tempCur->suivant;
	}
	
	return tVal;
}

template <class T>
bool Iterateur<T>::end()
{
	return current == NULL;
}

template <class T>
bool Iterateur<T>::operator++()
{
	if(current == NULL)
		return 1;
	
	current = current->suivant;
	return 0;
	
}

template <class T>
bool Iterateur<T>::operator++(int)
{
	if(current == NULL)
		return 1;
	
	current = current->suivant;
	return 0;
	
}

template <class T>
Iterateur<T>::operator T() const
{
	return current->valeur;
}

template <class T>
T * Iterateur<T>::operator&()
{
	return &current->valeur;
}

template <class T>
Iterateur<T>::~Iterateur()
{

}

template class Iterateur<int>;
template class Iterateur<int *>;
template class Iterateur<Couleur>;
template class Iterateur<SmartPointer<Forme> >;
template class Iterateur<SmartPointer<int> >;
