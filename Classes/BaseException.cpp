#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#include "BaseException.h"
	
BaseException::BaseException()//default
{
	#ifdef DEBUG
	cout << "Default constuctor BaseException" << endl;
	#endif
	
	message = NULL;
	setMessage("Default Error");
}

BaseException::BaseException(const char * M)//initialisation
{
	#ifdef DEBUG
	cout << "Initialisation constuctor BaseException" << endl;
	#endif
	
	message = NULL;
	setMessage(M);
}

BaseException::BaseException(const BaseException &obj)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor BaseException" << endl;
	#endif
	
	message = NULL;
	setMessage(obj.what());
}

const char * BaseException::what() const
{
	return message;
}

void BaseException::setMessage(const char * M)
{
	if(message)
		delete message;
	
	message = new char[strlen(M) + 1];
	strcpy(message, M);
}

BaseException::~BaseException()
{
	delete message;
}



