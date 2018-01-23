#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#include "Dessin.h"

Dessin::Dessin()
{
	setLargeur(100);
	setHauteur(100);
	setFond(Couleur(0,0,0, "Noir"));
	palette.pTete = NULL;
	formes.pTete = NULL;
}
Dessin::Dessin(int width, int height ,const Couleur& background)
{
	setLargeur(width);
	setHauteur(height);
	setFond(background);
}

void Dessin::setLargeur(int width)
{
	if(lenght > 0)
		largeur = width;
}

void Dessin::setHauteur(int height)
{
	if(height > 0)
		hauteur = height;
}

void Dessin::setFond(const Couleur& background)
{
	fond = background;
}

int Dessin::getLargeur() const
{
	return largeur;
}

int Dessin::getHauteur() const
{
	return hauteur;
}

Liste<Couleur>* Dessin::getPalette()
{
	return &palette;
}

ListeTriee<SmartPointer<Forme> >* Dessin::getFormes()
{
	return &formes;
}

Couleur Dessin::getFond()
{
	return fond;
}

void Dessin::ajouteCouleur(const Couleur& coul)
{
	Iterateur<Couleur> it(_palette);

	while (!it.end())
	{
		if (strcmp(((Couleur)it).getNom(), coul.getNom()) == 0)
			throw BaseException("Error Color Already Exists");
			
		it++;
	}
	cout << "Ajout couleur " << *(palette.insere(coul)) << endl;	
}

void Dessin::ajouteForme(Forme * f, const char * name)
{
	Iterateur<Couleur> itPal(palette);
	Iterateur<SmartPointer<Forme> > itFo(formes);

	for (itPal.reset(); !itPal.end() && (strcmp(((Couleur)itPal).getNom(), name) != 0); itPal++);

	if (itPal.end())
		throw BaseException("Cannot Find color");

	for (itFo.reset(); !itFo.end() && (strcmp( ((SmartPointer<Forme>)itFo).getVal()->getId(), f->getId()) != 0); itFo++);

	if (!itForme.end())
		throw BaseException("Id de forme existant");

	pForme->setCouleur(&itPalette);
	formes.insere(pForme);
}

void nouveauDessin()
{
	cout << "Largeur" << endl;
	cin >> largeur;
	cout << "Hauteur" << endl;
	cin >> hauteur;
	
	WindowSDL::open(largeur, hauteur);
}

void Dessine()
{
	Iterateur<SmartPointer<Forme> > it(formes);
	
	while(!it.end())
	{
	
		dynamic_cast it.valeur
		it++;
	}
}


