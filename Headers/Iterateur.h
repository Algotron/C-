#ifndef ITERATEUR_H
#define ITERATEUR_H

#include "ListeBase.h"
#include "Couleur.h"

template <class T> struct Cellule;
template <class T> class ListeBase;

template <class T>
class Iterateur
{
	private :
	ListeBase<T> * list;
	Cellule<T> * current;

	public :
	Iterateur(ListeBase<T> &);
	Iterateur(Iterateur<T> &);
	
	void reset();
	T remove();
	bool end();
	
	bool operator++();
	bool operator++(int);
	operator T();
	T * operator&();
	
	~Iterateur();
};

#endif
