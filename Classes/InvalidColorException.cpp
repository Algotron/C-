#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "InvalidColorException.h"

InvalidColorException::InvalidColorException():BaseException()//default
{
	#ifdef DEBUG
	cout << "Default constuctor InvalidColorException" << endl;
	#endif
}

InvalidColorException::InvalidColorException(const char * M, bool r, bool g, bool b):BaseException(M)//initialisation
{
	#ifdef DEBUG
	cout << "Initialisation constuctor InvalidColorException" << endl;
	#endif

	setRed(r);
	setGreen(g);
	setBlue(b);
}

InvalidColorException::InvalidColorException(const InvalidColorException &obj):BaseException(obj)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor InvalidColorException" << endl;
	#endif

	setRed(obj.rougeValide());
	setGreen(obj.vertValide());
	setBlue(obj.bleuValide());
}

bool InvalidColorException::rougeValide() const
{
	return Red;
}

bool InvalidColorException::vertValide() const
{
	return Green;
}

bool InvalidColorException::bleuValide() const
{
	return Blue;
}

void InvalidColorException::setRed(bool R)
{
	Red = R;
}

void InvalidColorException::setGreen(bool G)
{
	Green = G;
}

void InvalidColorException::setBlue(bool B)
{
	Blue = B;
}

InvalidColorException::~InvalidColorException()
{

}






