#ifndef LISTE_TRIEE_H
#define LISTE_TRIEE_H

#include "ListeTriee.h"

template<class T>
class ListeTriee : public ListeBase
{
	protected:

	
	public: 
	ListeTriee();
	ListeTriee(ListeTriee &);

	T* insere(const T &);
};



#endif
