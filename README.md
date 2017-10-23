# Paint-Project

Class Couleur :
	int R;
	int G;
	int B;
	char * name;
	static int cpt;
	
Class Forme :
	char * id;
	Point position;
	const Couleur * couleur;
	int profondeur;
	static int cpt;
	char * infos;
	
Class Ligne (inherits of Forme) :
	Point extremite;
	
Class Pixel (inherits of Forme) :
	No atribute

Class Point :
	int x;
	int y;
	static int cpt;

Class Rectangle (inherits of Forme) :






