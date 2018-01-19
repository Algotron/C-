#ifndef LIGNE_H
#define LIGNE_H

#include "Forme.h"

class Ligne:public Forme
{

	friend ostream& operator<< (ostream &os, const Ligne &obj);

	private:
	Point extremite;
	
	
	public:
	Ligne();//default
	Ligne(const char * ID, const Point &objPoint,const Point &objExtremite, const Couleur * objCouleur, const int depth);//initialisation
	Ligne(const Ligne &obj);//copy

	void setExtremite(const Point&);
	Point getExtremite() const;
	
	void setId(const char *); 
	
	const char* getInfos(void);
	
	void Save(ofstream &) const;
	void Load(ifstream &);
	
	~Ligne();
	
};

#endif
