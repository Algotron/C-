#ifndef Rectangle_H
#define Rectangle_H

#include "Forme.h"
#include "Point.h"

class Rectangle: public Forme
{
	friend ostream& operator<< (ostream &os, const Rectangle &obj);

	private:
	int dimX;
	int dimY;
	bool rempli;
	
	
	public:
	Rectangle();//default
	Rectangle(const char * ID, const Point &objPoint,int xDim, int yDim, bool filled, const Couleur * objCouleur, const int depth);//initialisation
	Rectangle(const Rectangle &obj);//copy
	
	int getDimX() const;
	void setDimX(int dim);
	
	int getDimY() const;
	void setDimY(int dim);
	
	bool isRempli() const;
	void setRempli(bool filled);
	
	void setId(const char *);
	
	const char* getInfos(void);
	
	~Rectangle();
	
};

#endif
