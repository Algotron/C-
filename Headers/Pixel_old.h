#ifndef PIXEL_H
#define PIXEL_H

#include <Forme.h>

class Pixel: public Forme
{

	friend ostream& operator<< (ostream &os, const Pixel &obj);
	
	private:




	public:
	
	Pixel();//default
	Pixel(const char * ID, const Point &obj);//initialisation
	Pixel(const char * ID, const Point &objPoint, const Couleur * objCouleur, const int depth);//initialisation
	Pixel(Pixel&);//copy

	const char* getInfos();

	~Pixel();
};


#endif
