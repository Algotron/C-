#ifndef LISTE_H
#define LISTE_H

#include "ListeBase.h"

template<class T>
class Liste : public ListeBase<T>
{
	private:

	
	public: 
	Liste();
	Liste(Liste<T> &);

	T* insere(const T &);
};

#endif
