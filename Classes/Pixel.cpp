#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Pixel.h"
#include "BaseException.h"


Pixel::Pixel():Forme()//default
{
	cout << "Default constuctor Pixel" << endl;
	id = NULL;
}

Pixel::Pixel(const char * ID, const Point &obj):Forme(obj)//initialisation
{
	cout << "Partial initialisation constuctor Pixel" << endl;
	id = NULL;
	setId(ID);
}

Pixel::Pixel(const char * ID,const Point &objPoint, const Couleur * objCouleur, const int depth):Forme(objPoint, objCouleur, depth)//initialisation
{
	cout << "Initialisation constuctor Rectangle" << endl;
	
	cout << *ID << endl;
	
	id = NULL;
	setId("ID");
}

Pixel::Pixel(Pixel &obj):Forme(obj)//copy
{
	cout << "Copy constuctor Rectangle" << endl;
		
	id = NULL;
	setId(obj.getId());
}

const char* Pixel::getInfos()
{
	char Red[4], Green[4], Blue[4], x[10], y[10], prof[10];
	char * chaine;
	int lengthCouleur= 0;

	sprintf(x, "%d", getPosition().getX());
	sprintf(y, "%d", getPosition().getY());

	if(getCouleur())
	{
		sprintf(Red, "%d", getCouleur()->getRouge());
		sprintf(Green, "%d", getCouleur()->getVert());
		sprintf(Blue, "%d", getCouleur()->getBleu());
		lengthCouleur = strlen(couleur->getNom()) + strlen(Red) + strlen(Green) + strlen(Blue) + 6;
	}

	sprintf(prof, "%d", getProfondeur());
	
	chaine = new char[48 + strlen(x) + strlen(y) + lengthCouleur + strlen(prof) + 1];
	
	strcpy(chaine, "[PIXEL : Position(");
	strcat(chaine, x);
	strcat(chaine, ", ");
	strcat(chaine, y);
	strcat(chaine, "), Couleur(");
	
	if(getCouleur())
	{
		strcat(chaine, Red);
		strcat(chaine, ", ");
		strcat(chaine, Green);
		strcat(chaine, ", ");
		strcat(chaine, Blue);
		strcat(chaine, ", ");
		strcat(chaine, couleur->getNom());
	}

	strcat(chaine, "), Profondeur = ");
	strcat(chaine, prof);
	strcat(chaine, "]");
	
	if(infos)
		delete infos;
		
	infos = chaine;
	
	return infos;
}

ostream& operator<< (ostream &os, const Pixel &obj)
{
	if(obj.getId())
		os << "id : " << obj.getId() << endl;
		
	os << "Position : " << obj.position << endl;
	
	if(obj.getCouleur())
		os << "Couleur : " << obj.getCouleur() << endl;
		
	os << "Profondeur : " << obj.getProfondeur() << endl;
	
	return os;
}

void Pixel::setId(const char * ID)
{
	if(strlen(ID) != 3)
	{
		cout << *ID << endl;
		throw BaseException("id must contain 3 char");
	}
	if(ID[0] != 'P')
		throw BaseException("id must begin with 'P'");
		
	if(!isdigit(ID[1]) || !isdigit(ID[2]))
		throw BaseException("id must contain 2 digits after the letter");

	if(id)
		delete id;
	
	id = new  char[strlen(ID) + 1];
	strcpy(id, ID);
}


Pixel::~Pixel()
{
	
}






