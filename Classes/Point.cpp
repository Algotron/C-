#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;

#include "Point.h"

int Point::cpt = 0;

Point::Point()//default
{
	#ifdef DEBUG
	cout << "Default constuctor Point" << endl;
	#endif
	
	setX(0);
	setY(0);
	cpt++;
}

Point::Point(const int X, const int Y)//initialisation
{
	#ifdef DEBUG
	cout << "Initialisation constuctor Point" << endl;
	#endif
	
	setX(X);
	setY(Y);
	cpt++;
}

Point::Point(const Point &obj)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor Point" << endl;
	#endif
	
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

void Point::Save(ofstream & file) const
{	
	file.write((char*)&x, sizeof(int));
	file.write((char*)&y, sizeof(int));
}

void Point::Load(ifstream & file)
{
	
	file.read((char*)&x, sizeof(int));
	file.read((char*)&y, sizeof(int));
}

Point::~Point()
{
	cpt--;
}

