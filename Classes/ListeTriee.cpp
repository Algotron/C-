#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "ListeTriee.h"

template<class T>
ListeTriee<T>::ListeTriee():ListeBase<T>::ListeBase()//default
{
	#ifdef DEBUG
	cout << "Default constuctor ListeTriee" << endl;
	#endif
}

template<class T>
ListeTriee<T>::ListeTriee(const ListeTriee<T> &obj):ListeBase<T>::ListeBase(obj)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor ListeTriee" << endl;
	#endif
}

template<class T>
T* ListeTriee<T>::insere(const T &value)
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
	
	while(current != NULL && value > current->valeur)
	{
		previous = current;
		current = current->suivant;
	}
	
	if(current == NULL)//if value > last of list
	{
		current = new Cellule<T>;
		current->valeur = value;
		current->suivant = NULL;
		previous->suivant = current;
	}
	else//if first of list < value < last of list
	{
		Cellule<T> * insertion = new Cellule<T>;
		insertion->valeur = value;
		insertion->suivant = current;
		
		if(previous)
			previous->suivant = insertion;
		else
			this->pTete = insertion;//if value < first of list
	}
	
	return &(current->valeur);
}

template class ListeTriee<int>;
template class ListeTriee<Couleur>;
