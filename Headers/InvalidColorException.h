#ifndef INVALIDCOLOREXCEPTION_H
#define INVALIDCOLOREXCEPTION_H

#include "BaseException.h"

class InvalidColorException: public BaseException
{
	private:
	bool Red;
	bool Green;
	bool Blue;
	
	
	public:
	InvalidColorException();//default
	InvalidColorException(char *, bool, bool, bool);//initialisation
	InvalidColorException(const InvalidColorException &);//copy
	
	bool rougeValide() const;
	bool rougeValide() const;
	bool rougeValide() const;
	
	~Rectangle();
	
};


#endif
