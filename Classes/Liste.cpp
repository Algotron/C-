#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Liste.h"

template<class T>
Liste<T>::Liste():ListeBase<T>::ListeBase()//default
{
	#ifdef DEBUG
	cout << "Default constuctor Liste" << endl;
	#endif
}

template<class T>
Liste<T>::Liste(const Liste<T> &obj):ListeBase<T>::ListeBase(obj)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor Liste" << endl;
	#endif
}

template<class T>
T* Liste<T>::insere(const T &value)
{
	if(this->pTete == NULL)//if list is empty
	{
		this->pTete = new Cellule<T>;
		this->pTete->valeur = value;
		this->pTete->suivant = NULL;
		
		return &(this->pTete->valeur);
	}
	
	Cellule<T> * current = this->pTete;
	Cellule<T> * previous = NULL;

	while(current != NULL)
	{
		previous = current;
		current = current->suivant;
	}

	current = new Cellule<T>;
	current->valeur = value;
	current->suivant = NULL;
	previous->suivant = current;
	
	return &(current->valeur);
}

template class Liste<int>;
template class Liste<Couleur>;
