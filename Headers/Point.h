#ifndef POINT_H
#define POINT_H

class Point
{


	friend ostream& operator<< (ostream &, const Point& obj);
	
	private:
	int x;
	int y;
	static int cpt;
	
	public:
	Point();//default
	Point(const int, const int);//initialisation
	Point(const Point &obj);//copy
	
	void setX(const int);
	int getX() const;
	
	void setY(const int);
	int getY() const;
	
	void Affiche() const;
	
	static int getCompteur() ;
	
	
	~Point();
	
};

#endif
