#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "Couleur.h"

int Couleur::cpt = 0;
const Couleur Couleur::ROUGE(255, 0, 0, "Rouge");
const Couleur Couleur::VERT(0, 255, 0, "Vert");
const Couleur Couleur::BLEU(0, 0, 255, "Bleu");

Couleur::Couleur()//default
{
	cout << "Default constuctor Couleur" << endl;
	name = NULL;
	setRouge(0);
	setVert(0);
	setBleu(0);
	setNom("default");
	cpt++;
}
Couleur::Couleur(const int red, const int green, const int blue)//initialisation
{
	cout << "Partial initialisation constuctor Couleur" << endl;
	
	invalidColor(red, green, blue);
	
	name = NULL;
	setRouge(red);
	setVert(green);
	setBleu(blue);
	setNom("default");
	cpt++;
}

Couleur::Couleur(const int red, const int green, const int blue, const char * nom)//initialisation
{
	cout << "Initialisation constuctor Couleur" << endl;
	
	invalidColor(red, green, blue);
	
	name = NULL;
	setRouge(red);
	setVert(green);
	setBleu(blue);
	setNom(nom);
	cpt++;
}

Couleur::Couleur(const Couleur &obj)//copy
{
	cout << "Copy constuctor Couleur" << endl;
	name = NULL;
	setRouge(obj.getRouge());
	setVert(obj.getVert());
	setBleu(obj.getBleu());
	setNom(obj.getNom());
	cpt++;
}

void Couleur::setRouge(const int red)
{
	if(red > 255 || red < 0)
		throw InvalidColorException("Invalid Color!", false, true, true);
	else
		R = red;
}

int Couleur::getRouge() const
{
	return R;
}

void Couleur::setVert(const int green)
{
	if(green > 255 || green < 0)
		throw InvalidColorException("Invalid Color!",true ,false , true);
	else
		G = green;
}

int Couleur::getVert() const
{
	return G;
}

void Couleur::setBleu(const int blue)
{
	if(blue > 255 || blue < 0)
		throw InvalidColorException("Invalid Color!", true, true, false);
	else
		B = blue;
}

int Couleur::getBleu() const
{
	return B;
}

void Couleur::setNom(const char * nom)
{
	if(name)
		delete name;
	
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
}

const char* Couleur::getNom() const
{
	return name;
}

void Couleur::Affiche() const
{
	cout<< "R: " << getRouge() << endl;
	cout<< "G: " << getVert() << endl;
	cout<< "B: " << getBleu() << endl;
	cout<< "Nom: " << getNom() << endl;
}

int Couleur::getCompteur()
{
	return cpt;
}

int Couleur::getLuminance() const
{
	return (int)round((getRouge() + getVert() + getBleu())/3);
}

Couleur& Couleur::operator= (const Couleur& obj)
{
	setRouge(obj.getRouge());
	setVert(obj.getVert());
	setBleu(obj.getBleu());
	setNom(obj.getNom());
	return *this;
}

Couleur operator+ (const Couleur& obj,const Couleur& obj2)
{
	Couleur objTemp;
	
	if(obj2.getRouge() + obj.getRouge() >= 255)
		objTemp.setRouge(255);
	else
		objTemp.setRouge(obj2.getRouge() + obj.getRouge());
		
	if(obj2.getVert() + obj.getVert() >= 255)
		objTemp.setVert(255);
	else
		objTemp.setVert(obj2.getVert() + obj.getVert());
		
	if(obj2.getBleu() + obj.getBleu() >= 255)
		objTemp.setBleu(255);
	else
		objTemp.setBleu(obj2.getBleu() + obj.getBleu());
		
	char * nameBuff;
		
	if(strcmp(obj2.getNom(), "default") == 0 || strcmp(obj.getNom(), "default") == 0)
	{
		nameBuff = new char[16];
		strcpy(nameBuff, "Melange inconnu");
	}
	else
	{
		nameBuff = new char[18 + strlen(obj.getNom()) + strlen(obj2.getNom()) + 1];

		strcpy(nameBuff, "Melange de ");
		strcat(nameBuff, obj2.getNom());
		strcat(nameBuff, " et ");
		strcat(nameBuff, obj.getNom());
	}
	
	objTemp.setNom(nameBuff);
	
	delete nameBuff;

	return objTemp;
}

Couleur operator+ (const Couleur& obj, const int number)
{
	Couleur objTemp;
	char numChar[4];
	
	if(obj.getRouge() + number >= 255)
		objTemp.setRouge(255);
	else
		objTemp.setRouge(obj.getRouge() + number);
		
	if(obj.getVert() + number >= 255)
		objTemp.setVert(255);
	else
		objTemp.setVert(obj.getVert() + number);
		
	if(obj.getBleu() + number >= 255)
		objTemp.setBleu(255);
	else
		objTemp.setBleu(obj.getBleu() + number);
		
	if( strcmp(obj.getNom(), "default") != 0)
	{
		char * nameBuff = new char[strlen(obj.getNom()) + 11 + 1];
		strcpy(nameBuff, obj.getNom());
		strcat(nameBuff, " clair(");
		sprintf(numChar, "%d", number);
		strcat(nameBuff, numChar);
		strcat(nameBuff, ")");
		
		objTemp.setNom(nameBuff);
		delete nameBuff;
	}
	
	return objTemp;
	
}

Couleur operator+ (const int number, const Couleur& obj)
{
	Couleur objTemp;
	char numChar[4];
	
	if(obj.getRouge() + number >= 255)
		objTemp.setRouge(255);
	else
		objTemp.setRouge(obj.getRouge() + number);
		
	if(obj.getVert() + number >= 255)
		objTemp.setVert(255);
	else
		objTemp.setVert(obj.getVert() + number);
		
	if(obj.getBleu() + number >= 255)
		objTemp.setBleu(255);
	else
		objTemp.setBleu(obj.getBleu() + number);
		
	if( strcmp(obj.getNom(), "default") != 0)
	{
		char * nameBuff = new char[strlen(obj.getNom()) + 11 + 1];
		strcpy(nameBuff, obj.getNom());
		strcat(nameBuff, " clair(");
		sprintf(numChar, "%d", number);
		strcat(nameBuff, numChar);
		strcat(nameBuff, ")");
		
		objTemp.setNom(nameBuff);
		delete nameBuff;
	}
	
	return objTemp;
	
}

Couleur operator- (const Couleur& obj, const int number)
{
	Couleur objTemp;
	char numChar[4];
	
	if(obj.getRouge() - number <= 0)
		objTemp.setRouge(0);
	else
		objTemp.setRouge(obj.getRouge() - number);
		
	if(obj.getVert() - number <= 0)
		objTemp.setVert(0);
	else
		objTemp.setVert(obj.getVert() - number);
		
	if(obj.getBleu() - number <= 0)
		objTemp.setBleu(0);
	else
		objTemp.setBleu(obj.getBleu() - number);
		
	if( strcmp(obj.getNom(), "default") != 0)
	{
		char * nameBuff = new char[strlen(obj.getNom()) + 11 + 1];
		strcpy(nameBuff, obj.getNom());
		strcat(nameBuff, " fonce(");
		sprintf(numChar, "%d", number);
		strcat(nameBuff, numChar);
		strcat(nameBuff, ")");
		
		objTemp.setNom(nameBuff);
		delete nameBuff;
	}
	
	return objTemp;
	
}

Couleur operator- (const int number, const Couleur& obj)
{
		Couleur objTemp;
	char numChar[4];
	
	if(obj.getRouge() - number <= 0)
		objTemp.setRouge(0);
	else
		objTemp.setRouge(obj.getRouge() - number);
		
	if(obj.getVert() - number <= 0)
		objTemp.setVert(0);
	else
		objTemp.setVert(obj.getVert() - number);
		
	if(obj.getBleu() - number <= 0)
		objTemp.setBleu(0);
	else
		objTemp.setBleu(obj.getBleu() - number);
		
	if( strcmp(obj.getNom(), "default") != 0)
	{
		char * nameBuff = new char[strlen(obj.getNom()) + 11 + 1];
		strcpy(nameBuff, obj.getNom());
		strcat(nameBuff, " fonce(");
		sprintf(numChar, "%d", number);
		strcat(nameBuff, numChar);
		strcat(nameBuff, ")");
		
		objTemp.setNom(nameBuff);
		delete nameBuff;
	}
	
	return objTemp;
}

int operator< (const Couleur& obj,const Couleur& obj2)
{
	if(obj.getLuminance() < obj2.getLuminance())
		return 1;
	else 
		return 0;
	
}

int operator> (const Couleur& obj,const Couleur& obj2)
{
	if(obj.getLuminance() > obj2.getLuminance())
		return 1;
	else 
		return 0;
	
}

int operator== (const Couleur& obj,const Couleur& obj2)
{
	if(obj.getLuminance() == obj2.getLuminance())
		return 1;
	else 
		return 0;
	
}

ostream& operator<< (ostream& os, const Couleur& obj)
{
	os << "(" << obj.getRouge() << ", " << obj.getVert() << ", " << obj.getBleu() << " (" << obj.getNom() << "))" << endl;
	return os;
}

istream& operator>> (istream& is, Couleur& obj)
{
	char buff[100];
	char * R, * G, * B, * Name;
	int red, green, blue;
	
	is.getline(buff, 100);
	
	R = strtok(buff, " ");
	G = strtok(NULL, " ");
	B = strtok(NULL, " ");
	Name = strtok(NULL, "\n");
	
	red = atoi(R);
	green = atoi(G);
	blue = atoi(B);
	
	if(red >= 0 && red <= 255)
		obj.setRouge(red);
	
	if(green >= 0 && green <= 255)
		obj.setVert(green);

	if(blue >= 0 && blue <= 255)
		obj.setBleu(blue);	
	
	obj.setNom(Name);
	
	return is;
}

Couleur& Couleur::operator++ ()
{
	setRouge(getRouge() + 10);
	setVert(getVert() + 10);
	setBleu(getBleu() + 10);
	
	return *this;
}

Couleur Couleur::operator++ (int)
{
	Couleur objTemp(*this);
	
	setRouge(getRouge() + 10);
	setVert(getVert() + 10);
	setBleu(getBleu() + 10);
	
	return objTemp;
}

Couleur& Couleur::operator-- ()
{
	setRouge(getRouge() - 10);
	setVert(getVert() - 10);
	setBleu(getBleu() - 10);
	
	return *this;
}

Couleur Couleur::operator-- (int)
{
	Couleur objTemp(*this);
	
	setRouge(getRouge() - 10);
	setVert(getVert() - 10);
	setBleu(getBleu() - 10);
	
	return objTemp;
}

void Couleur::invalidColor(int r, int g, int b)
{
	bool Red, Green, Blue, flag = false;
	
	if(r < 0 || r > 255)
	{
		Red = false;
		flag = true;
	}
	else
		Red = true;
		
	if(g < 0 || g > 255)
	{
		Green = false;
		flag = true;
	}
	else
		Green = true;

	if(b < 0 || b() > 255)
	{
		Blue = false;
		flag = true;
	}
	else
		Blue = true;
		
	if(flag)
		throw InvalidColorException("Invalid Color!"Red, Green, Blue);
	else
		return 1;
}


Couleur::~Couleur()
{
	delete name;
	cpt--;
}
