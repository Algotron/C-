#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#include "Forme.h"

int Forme::cpt = 0;

Forme::Forme()//default
{
	id = NULL;
	setId("Default");
	position.setX(0);
	position.setY(0);
	setProfondeur(0);
	couleur = NULL;
	cpt++;
}

Forme::Forme(const char * ID, const Point &obj)//initialisation
{
	id = NULL;
	setId(ID);
	setPosition(obj);
	setProfondeur(0);
	couleur = NULL;
	cpt++;
}

Forme::Forme(const char * ID, const Point &objPoint, const Couleur * objCouleur, const int depth)//initialisation
{
	id = NULL;
	setId(ID);
	setPosition(objPoint);
	couleur = NULL;
	setCouleur(objCouleur);
	setProfondeur(depth);
	cpt++;
}

Forme::Forme(const Forme &obj)//copy
{
	setId(obj.getId());
	setPosition(obj.getPosition());
	setCouleur(obj.getCouleur());
	setProfondeur(obj.getProfondeur());
	cpt++;
}

void Forme::setId(const char * ID)
{
	if(!id)
		delete id;
	
	id = new  char[strlen(ID) + 1];
	strcpy(id, ID);
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
	if(!couleur)
		delete couleur;
			
	couleur = new Couleur;
	
	couleur->setRouge(obj->getRouge());
	couleur->setVert(obj->getVert());
	couleur->setBleu(obj->getBleu());
	couleur->setNom(obj->getNom());
	
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
	delete couleur;
	cpt--;
}












