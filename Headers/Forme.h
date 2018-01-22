#ifndef FORME_H
#define FORME_H

#include "Couleur.h"
#include "Point.h"

class Forme
{
	friend ostream& operator<<(ostream &os, const Forme &obj);
	
	protected:
	char * id;
	Point position;
	const Couleur * couleur;
	int profondeur;
	static int cpt;
	char * infos;
	
	
	public:
	Forme();//default
	Forme(const Point &obj);//initialisation
	Forme(const Point &objPoint, const Couleur * objCouleur, const int);//initialisation
	Forme(const Forme &obj);//copy
	
	virtual void setId(const char*) = 0;
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
	
	void Save(ofstream &) const;
	void Load(ifstream &);
	
	bool operator<(const Forme &);
	bool operator>(const Forme &);
	bool operator==(const Forme &);
	
	virtual ~Forme();
	
};

#endif
