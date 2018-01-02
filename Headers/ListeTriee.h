#ifndef LISTE_TRIEE_H
#define LISTE_TRIEE_H

#include "ListeBase.h"

template<class T>
class ListeTriee : public ListeBase<T>
{
	private:

	
	public: 
	ListeTriee();
	ListeTriee(const ListeTriee<T> &);

	T* insere(const T &);
};



#endif
