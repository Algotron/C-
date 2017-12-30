#ifndef LISTE_TRIEE_H
#define LISTE_TRIEE_H

#include "ListeBase.h"

template<class T>
class ListeTriee : public ListeBase
{
	private:

	
	public: 
	ListeTriee();
	ListeTriee(ListeTriee &);

	T* insere(const T &);
};



#endif
