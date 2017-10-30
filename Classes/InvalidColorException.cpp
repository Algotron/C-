#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "InvalidColorException"

InvalidColorException::InvalidColorException():BaseException()//default
{

}

InvalidColorException::InvalidColorException(char * M, bool r, bool g, bool b):BaseException(M)//initialisation
{
	setRed(r);
	setGreen(g);
	setBlue(b);
}

InvalidColorException::InvalidColorException(const InvalidColorException &obj):BaseException(obj)//copy
{
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

bool ::InvalidColorException::bleuValide() const
{
	return Blue;
}

void setRed(bool R)
{
	Red = R;
}

void setGreen(bool G)
{
	Green = G;
}

void setBlue(bool B)
{
	Blue = B;
}

InvalidColorException::~InvalidColorException()
{

}






