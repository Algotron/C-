#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Liste.h"

template<class T>
Liste<T>::Liste():ListeBase()//default
{

}

Liste<T>::Liste(const Liste<T> &obj):ListeBase(obj)//copy
{

}

template<class T>
T* insere(const T &value)
{
	Cellule<T> * current = pTete;
	Cellule<T> * previous = NULL;
	
	while(current != NULL)
	{
		previous = current;
		current = current->suivant;
	}
	
	current = new Cellule<T>;
	
	current->valeur = value;
	previous->suivant = current;
	
	return current->valeur;
}

