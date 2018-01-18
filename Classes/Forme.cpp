#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#include "Forme.h"
#include "BaseException.h"

int Forme::cpt = 0;

Forme::Forme()//default
{
	#ifdef DEBUG
	cout << "Default constuctor Forme" << endl;
	#endif
	
	infos = NULL;
	position.setX(0);
	position.setY(0);
	setProfondeur(0);
	couleur = NULL;
	cpt++;
}

Forme::Forme(const Point &obj)//initialisation
{
	#ifdef DEBUG
	cout << "Partial initialisation constuctor Forme" << endl;
	#endif
	
	infos = NULL;
	setPosition(obj);
	setProfondeur(0);
	couleur = NULL;
	cpt++;
}

Forme::Forme(const Point &objPoint, const Couleur * objCouleur, const int depth)//initialisation
{
	#ifdef DEBUG
	cout << "Initialisation constuctor Forme" << endl;
	#endif
	
	infos = NULL;
	setPosition(objPoint);
	setCouleur(objCouleur);
	setProfondeur(depth);
	cpt++;
}

Forme::Forme(const Forme &obj)//copy
{
	#ifdef DEBUG
	cout << "Copy constuctor Forme" << endl;
	#endif
	
	infos = NULL;
	setPosition(obj.getPosition());
	setCouleur(obj.getCouleur());
	setProfondeur(obj.getProfondeur());
	cpt++;
}

const char* Forme::getId() const
{
	return id;
}

void Forme::setPosition(const Point &obj)
{
	position.setX(obj.getX());
	position.setY(obj.getY());
}

Point Forme::getPosition() const
{
	return position;
}

void Forme::setCouleur(const Couleur * obj)
{			
	couleur = obj;
	
}

const Couleur* Forme::getCouleur() const
{
	return couleur;
}

void Forme::setProfondeur(const int depth)
{
	if(depth <= 0)
		profondeur = depth;
}

int Forme::getProfondeur() const
{
	return profondeur;
}

void Forme::Affiche() const
{
	cout<< "id: " << id << endl;
	position.Affiche();
	if(couleur)
		couleur->Affiche();
	cout<< "Profondeur: " << profondeur << endl;
}

int Forme::getCompteur()
{
	return cpt;
}

Forme::~Forme()
{
	if(getId())
		delete id;
		
	if(infos)
		delete infos;
		
	cpt--;
}












