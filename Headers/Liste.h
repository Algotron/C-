#ifndef LISTE_H
#define LISTE_H

#include "ListeBase.h"

template<class T>
class Liste : public ListeBase
{
	protected:

	
	public: 
	Liste();
	Liste(Liste &);

	T* insere(const T &);
};



#endif
