# Paint-Project

Class Couleur :
	int R;
	int G;
	int B;
	char * name;
	static int cpt;
	
Class Forme (abstract) :
	char * id;
	Point position;
	const Couleur * couleur;
	int profondeur;
	static int cpt;
	char * infos;
	
Class Point :
	int x;
	int y;
	static int cpt;
	
Class Pixel (inherits of Forme) :
	No atribute

Class Ligne (inherits of Forme) :
	Point extremite;

Class Rectangle (inherits of Forme) :
	int dimX;
	int dimY;
	bool rempli;

Class BaseException:
	char * message;
	
Class InvalidColorException (inherits of BaseException) :
	bool Red;
	bool Green;
	bool Blue;







