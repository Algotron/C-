#ifndef FORME_H
#define FORME_H

#include "Couleur.h"
#include "Point.h"

class Forme
{
	protected:
	char * id;
	Point position;
	const Couleur * couleur;
	int profondeur;
	static int cpt;
	char * infos;
	
	
	public:
	Forme();//default
	Forme(const char*, const Point &obj);//initialisation
	Forme(const char*, const Point &objPoint, const Couleur * objCouleur, const int);//initialisation
	Forme(const Forme &obj);//copy
	
	void setId(const char*);
	const char* getId() const;
	
	void setPosition(const Point &obj);
	Point getPosition() const;
	
	void setCouleur(const Couleur * obj);
	const Couleur* getCouleur() const;
	
	void setProfondeur(const int);
	int getProfondeur() const;
	
	void Affiche() const;
	
	static int getCompteur();
	
	virtual const char* getInfos(void) = 0;
	
	~Forme();
	
};

#endif
