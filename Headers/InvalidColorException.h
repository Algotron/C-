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
	InvalidColorException(const char *, bool, bool, bool);//initialisation
	InvalidColorException(const InvalidColorException &);//copy
	
	void setRed(bool);
	void setGreen(bool);
	void setBlue(bool);
	
	bool rougeValide() const;
	bool vertValide() const;
	bool bleuValide() const;
	
	~InvalidColorException();
	
};


#endif
