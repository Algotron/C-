#ifndef LISTE_BASE_H
#define LISTE_BASE_H

#include "Couleur.h"
#include "Iterateur.h"

template <class T> class Iterateur;

template<class T> 
struct Cellule
{
	T valeur;
	Cellule<T> *suivant;
};

template<class T>
class ListeBase
{
	protected:
	Cellule<T> *pTete;
	
	public: 
	ListeBase();
	ListeBase(const ListeBase<T> &);
	
	bool estVide() const;
	int getNombreElements() const;
	void Affiche() const;
	virtual T* insere(const T &) = 0;
	ListeBase& operator= (const ListeBase<T> &);
	
	virtual ~ListeBase();
	
	friend class Iterateur<T>;
	
};


#endif
