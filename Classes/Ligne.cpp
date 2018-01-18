#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Ligne.h"
#include "Point.h"
#include "BaseException.h"

Ligne::Ligne():Forme()//default
{
	#ifdef DEBUG
	cout << "Default constuctor Ligne" << endl;
	#endif
	
	id = NULL;
	extremite.setX(0);
	extremite.setY(0);
}

Ligne::Ligne(const char * ID, const Point &objPoint,const Point &objExtremite, const Couleur * objCouleur, const int depth):Forme(objPoint, objCouleur, depth)//initialisation
{
	#ifdef DEBUG
	cout << "Initialisation constuctor Ligne" << endl;
	#endif
	
	id = NULL;
	setId(ID);
	setExtremite(objExtremite);
}

Ligne::Ligne(const Ligne &obj):Forme(obj)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor Ligne" << endl;
	#endif
	
	id = NULL;
	setId(obj.getId());
	setExtremite(obj.getExtremite());
}

void Ligne::setExtremite(const Point &obj)
{
	extremite.setX(obj.getX());
	extremite.setY(obj.getY());
}

Point Ligne::getExtremite() const 
{
	return extremite;
}

const char * Ligne::getInfos()
{
	char chaine[200];

	
	if(getCouleur())
	{
		if(couleur->getNom())
		{
			sprintf(chaine, "[LIGNE : id(%s), Position(%d, %d), Extremite(%d, %d), Couleur(%d, %d, %d, %s), Profondeur(%d)]",getId(), getPosition().getX(), getPosition().getY(), getExtremite().getX(),getExtremite().getY(), getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(),getCouleur()->getNom(), getProfondeur());
		}
		else
			sprintf(chaine, "[LIGNE : id(%s), Position(%d, %d), Extremite(%d, %d), Couleur(%d, %d, %d), Profondeur(%d)]",getId(), getPosition().getX(), getPosition().getY(), getExtremite().getX(),getExtremite().getY(), getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(), getProfondeur());
	}
	else
		sprintf(chaine, "[LIGNE : id(%s), Position(%d, %d), Extremite(%d, %d), Profondeur(%d)]",getId(), getPosition().getX(), getPosition().getY(), getExtremite().getX(),getExtremite().getY(), getCouleur()->getRouge(),getCouleur()->getVert(),getCouleur()->getBleu(), getProfondeur());
	
	if(infos)
		delete infos;
	
	infos = new char[strlen(chaine) + 1];		
	
	return infos;
	
}

ostream& operator<< (ostream &os, const Ligne &obj)
{
	if(obj.getId())
		os << "id : " << obj.getId() << endl;
		
	os << "Position : " << obj.position << endl;
	os << "Extremite : " << obj.extremite << endl;
	
	if(obj.getCouleur())
		os << "Couleur : " << *(obj.getCouleur()) << endl;
		
	os << "Profondeur : " << obj.getProfondeur() << endl;
	
	return os;
}

void Ligne::setId(const char * ID)
{
	if(strlen(ID) != 3)
		throw BaseException("id must contain 3 char");
		
	if(ID[0] != 'L')
		throw BaseException("id must begin with 'L'");
		
	if(!isdigit(ID[1]) || !isdigit(ID[2]))
		throw BaseException("id must contain 2 digits after the letter");

	if(id)
		delete id;
	
	id = new  char[strlen(ID) + 1];
	strcpy(id, ID);
}



Ligne::~Ligne()
{
	
}
