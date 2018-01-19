#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>


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

void Forme::Save(ofstream & file) const
{	
	int size = sizeof(id) + 1;
	
	file.write((char *)&size, sizeof(int));
	file.write(id, size);
	
	position.Save(file);
	
	if(couleur)
	{
		file.write("1", sizeof(bool));
		couleur->Save(file);
	}
	else
		file.write("0", sizeof(bool));
		
	file.write((char*)&profondeur, sizeof(int));
}



void Forme::Load(ifstream & file)
{
	int size;
	char * tempID;
	Couleur * temCouleur;
	
	file.read((char *)&size, sizeof(int));
	tempID = new char[size];
	file.read(tempID, size);
	setId(tempID);
	delete tempID;
	
	position.Load(file);
	
	file.read((char*)&size, sizeof(bool));//reading boolean for couleur
	
	if(size)
	{
		temCouleur = new Couleur;
		temCouleur->Load(file);
		couleur = temCouleur;
	}
	else
		couleur = NULL;
		
	file.read((char*)&profondeur, sizeof(int));
}

Forme::~Forme()
{
	if(getId())
		delete id;
		
	if(infos)
		delete infos;
		
	cpt--;
}












