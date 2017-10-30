#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#include "BaseException.h"
	
BaseException::BaseException()//default
{
	strcpy(message, "Invalid Identifier");
}

BaseException::BaseException(BaseException &obj)//copy
{
	strcpy(message, obj.message);
}

const char * BaseException::what() const
{
	return message;
}

BaseException::~BaseException()
{
	delete message;
}

