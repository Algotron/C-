#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "ListeTriee.h"

template<class T>
ListeTriee<T>::ListeTriee():ListeBase()//default
{

}

ListeTriee<T>::ListeTriee(const ListeTriee<T> &obj):ListeBase(obj)//copy
{

}

template<class T>
T* insere(const T &value)
{
	Cellule<T> * current = pTete;
	Cellule<T> * previous = NULL;
	
	while(current != NULL || value > current->valeur)
	{
		previous = current;
		current = current->suivant;
	}
	
	if(current == NULL)
	{
		current->valeur = value;
		previous->suivant = current;
	}
	else
	{
		Cellule<T> * insertion;
		insertion = new Cellule<T>;
		insertion->valeur = value;
		previous->suivant = insertion;
		insertion->suivant = current;
	}
	
	return current->valeur;
}

