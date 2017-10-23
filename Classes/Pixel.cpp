#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Pixel.h"


Pixel::Pixel():Forme()//default
{

}

Pixel::Pixel(const char * ID, const Point &obj):Forme(ID, obj)//initialisation
{

}

Pixel::Pixel(const char * ID, const Point &objPoint, const Couleur * objCouleur, const int depth):Forme(ID, objPoint, objCouleur, depth)//initialisation
{

}

Pixel::Pixel(Pixel &obj):Forme(obj)//copy
{
	
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

Pixel::~Pixel()
{
	
}






