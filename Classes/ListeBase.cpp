#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "ListeBase.h"

template<class T>
ListeBase<T>::ListeBase()//default
{
	pTete = NULL;
}

template<class T>
ListeBase<T>::ListeBase(const ListeBase<T> &obj)//copy
{
	if(!obj.pTete)
		return;
		
	Cellule<T> * current = pTete = new Cellule<T>;    
	Cellule<T> * original = obj.pTete.
	
	current->valeur = original->valeur;
	
	while(original->suivant)
	{	
		current->suivant = new Cellule<T>;
		current = current->suivant;
		original = original->suivant;
		current->valeur = original->valeur;
	}
}

template<class T>
bool ListeBase<T>::estVide() const;
{
	return pTete ==  NULL;
}

template<class T>
int ListeBase<T>::getNombreElements() const;
{
	int i = 0;
	
	if(!estVide)
	{
		Cellule<T> * current = pTete;    
	
		while(current != NULL)
		{
			i++;
			current = current->suivant
	
		}
	}
	return i;
}

template<class T>
void ListeBase<T>::Affiche() const
{
	int i = 0;
	
	if(!estVide)
	{
		Cellule<T> * current = pTete;  
	
		while(current != NULL)
		{
			i++;
			cout <<"Element [" << i << "] : " << current->valeur << endl;  
			current = current->suivant
	
		}
	}
	else
		cout << "Empty list" << endl;
}

template<class T>
T* ListeBase<T>::insere(const T &obj)
{
	
}

template<class T>
ListeBase& operator= (const ListeBase &obj)
{
	if(pTete)
		~ListeBase();
		
	Cellule<T> * current = pTete = new Cellule<T>;    
	Cellule<T> * original = obj.pTete.
	
	current->valeur = original->valeur;
	
	while(original->suivant)
	{	
		current->suivant = new Cellule<T>;
		current = current->suivant;
		original = original->suivant;
		current->valeur = original->valeur;
	}
	
	return *this;
}

template<class T>
ListeBase<T>::~ListeBase()
{	
	if(!estVide)
	{
		Cellule<T> * current = pTete;
		Cellule<T> * previous;
	
		while(current != NULL)
		{
			previous = current;  
			current = current->suivant
			delete previous;
		}
	}
}
