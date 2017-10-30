#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

class BaseException
{
	private:
	char * message;
	
	
	public:
	BaseException();//default
	BaseException(const char *);//initialisation
	BaseException(const BaseException &);//copy
	
	const char * what() const;
	void setMessage(const char *);
	
	virtual ~BaseException();
	
};


#endif
