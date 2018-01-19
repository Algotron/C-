#ifndef COULEUR_H
#define COULEUR_H

using namespace std;

class Couleur
{
	friend Couleur operator+ (const Couleur&, const Couleur&);
	friend Couleur operator+ (const Couleur&, const int);
	friend Couleur operator+ (const int, const Couleur&);
	friend Couleur operator- (const Couleur&, const int);
	friend Couleur operator- (const int, const Couleur&);
	friend int operator< (const Couleur&, const Couleur&);
	friend int operator> (const Couleur&, const Couleur&);
	friend int operator== (const Couleur&, const Couleur&);
	friend ostream& operator<< (ostream&, const Couleur&);
	friend istream& operator>> (istream&, Couleur&);

	
	
	private:
	int R;
	int G;
	int B;
	char * name;
	static int cpt;
	
	void invalidColor(int, int, int);
	
	public:
	Couleur();//default
	Couleur(const int, const int, const int);//initialisation
	Couleur(const int, const int, const int, const char*);//initialisation
	Couleur(const Couleur &obj);//copy
	
	void setRouge(const int);
	int getRouge() const;
	
	void setVert(const int);
	int getVert() const;
	
	void setBleu(const int);
	int getBleu() const;
	
	void setNom(const char *);
	const char* getNom() const;
	
	void Affiche() const;
	
	static int getCompteur();
	
	static const Couleur ROUGE;
	static const Couleur VERT;
	static const Couleur BLEU;
	
	int getLuminance() const;

	Couleur& operator= (const Couleur&);
	Couleur& operator++ ();
	Couleur operator++ (int);
	Couleur& operator-- ();
	Couleur operator-- (int);

	void Save(ofstream &) const;
	void Load(ifstream &);
	
	~Couleur();
	
};

#endif
