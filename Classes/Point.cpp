#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Point.h"

int Point::cpt = 0;

Point::Point()//default
{
	setX(0);
	setY(0);
	cpt++;
}

Point::Point(const int X, const int Y)//initialisation
{
	setX(X);
	setY(Y);
	cpt++;
}

Point::Point(const Point &obj)//copy
{
	setX(obj.getX());
	setY(obj.getY());
	cpt++;
}

void Point::setX(const int X)
{
	x = X;
}

int Point::getX() const
{
	return x;
}

void Point::setY(const int Y)
{
	y = Y;
}

int Point::getY() const
{
	return y;
}

void Point::Affiche() const
{
	cout << "x: " << getX() << endl;
	cout << "y: " << getY() << endl;
}

int Point::getCompteur()
{
	return cpt;
}

ostream& operator<< (ostream &os, const Point &obj)
{
	os << "x = " << obj.getX();
	os << " y = " << obj.getY() << endl;
	
	return os;
}

Point::~Point()
{
	cpt--;
}






