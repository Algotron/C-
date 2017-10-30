#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

class BaseException
{
	private:
	char * message;
	
	
	public:
	BaseException();//default
	BaseException(BaseException &);//copy
	
	const char * what() const;
	
	~BaseException();
	
};


#endif
