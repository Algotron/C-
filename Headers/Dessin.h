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
	Dessin();
	Dessin(int, int ,const Couleur&);
	
	void setLargeur(int lenght);
	void setHauteur(int height);
	void setFond(const Couleur& background);
	
	int getLargeur() const;
	int getHauteur() const;
	Couleur getFond() const
	getPalette();
	getForme();
	
	void ajouteCouleur(const Couleur&);
	void ajouteForme(Forme *, const char*);

	void nouveauDessin();
	
	~Dessin();
} ;

#endif
