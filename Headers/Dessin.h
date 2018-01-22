#ifndef DESSIN_H
#define DESSIN_H

class Dessin
{
	private :
	int largeur;
	int hauteur;
	Couleur fond;
	Liste<Couleur> palette;
	ListeTriee<SmartPointer<Forme> > formes;
	
	public :
	Dessin() ;
	Dessin(int, int ,const Couleur&) ;
	void ajouteCouleur(const Couleur&) ;
	void ajouteForme(Forme *, const char*) ;

} ;

#endif
