
/*!
 * \file Bordel.cpp contient toutes les classes (problemes d'include)
 * \author Bordet Dennis
 * \author Delaverhne Florian
 */

//Forward Declarations
class Affichage;
class  AffichageConcret1;
class BarreHoriz;
class BarreVertic;
class Colore;
class Deplacement;
class ElemGraph;
class Espace;
class FactoryBarre;
class FactoryGraphique;
class FactoryPion;
class FinduJeu;
class Game;
class InterCase;
class Matrice;
class Pion;
class PionN;
class PionV;
class PionR;
class Phase;
class Placement;
class Plateau;
class Player;

#include<string>
#include <iostream>
#include <stdlib.h> 
#include<cassert>

typedef int(*Fonction)(int);

/*!
 * \class Couleur  (d'un pion ou d'un joueur)
 */
class Colore
{
protected:
	bool estNoir;
	bool estRouge;
public:

	Colore();
	~Colore();
	Colore(bool noir, bool rouge);
	bool isBlack ();
	bool isRed ();
	bool isVide ();
	void affichage ();
	bool isEquals(Colore c);






};



Colore::~Colore()
{

}
/*!
 * \brief constructeur par defaut qui creer une couleur "vide"
 */
Colore::Colore()
{
	estNoir = false;
	estRouge = false;

}
/*!
 * \brief constructeur: 0,1 = rouge et 1,0 = noir, 0,0 et 1,1 donne "vide"
 * \param noir booleen
 * \param rouge booleen 
 */
Colore::Colore(bool noir,bool rouge)
{
	estNoir = noir;
	estRouge = rouge;
}


/*!
 * \brief getter
 * \return True if the color is red 
 */
bool Colore::isRed ()
{
	if (estRouge && !estNoir)
	{
		return true;
	}
	else { return false; }

}

/*!
 * \brief getter
 * \return True if the color is black
 */
bool Colore::isBlack ()
{
	if (!estRouge && estNoir)
	{
		return true;
	}
	else { return false; }
}

/*!
 * \brief getter
 * \return True if the color is empty
 */
bool Colore::isVide ()
{
	if ((!estRouge && !estNoir)|| (estRouge && estNoir))
	{
		return true;
	}
	else { return false; }
}
/*!
 * \brief print N R or 0 depending on the color
 * \return True if the color is red 
 */
void Colore::affichage ()
{
	if (isBlack())
	{
		std::cout<<"N";
	}
	else {
		if (isRed())
		{
			std::cout<<"R";
		}
		else
		{
			std::cout<<"0";
		}
	}

}
/*!
 * test d'egalité avec la couleur passée en parametre
 * \param c la couleur a tester
 * \return True if the color is the same 
 */
bool Colore::isEquals(Colore c)
{
	if (c.isRed()&& isRed())
	{
		return true;
	}
	else {
		if (c.isBlack() && isBlack())
		{
			return true;
		}
		else {
			if (c.isVide() && isVide())
			{
			return true;
			}
			else {
			return false;
			}
		}
	}
}

/*!
 * \class Sujet qui est l'observable abstrait
 */
class Sujet
{
public:
	Sujet(){}
	~Sujet(){}
	/*!
 	* notifie l'observer 
 	*/
	virtual void notif ()=0;
	/*!
 	* ajoute un observer 
 	*/
	virtual void add(Affichage* obs)=0;
	/*!
 	* supprime un observer 
 	*/
	virtual void supp(Affichage* obs) =0;
};


/*!
 * \class abstraite ElemGraph, Element graphique,fait parti du pattern Factory. Ses filles sont instanciée par le factory
 */
class ElemGraph
{
public:
	ElemGraph(){}
	~ElemGraph(){}
	/*!
 	* donne la couleur de l'element
 	* \return Colore de l'elem
 	*/
	virtual Colore getColore()=0;
	/*!
 	* affiche l'élément (pour le debug)
 	*/
	virtual void affichage ()=0;
	/*!
 	* transforme l'element graphique en string ( pour l'affichage concret 1)
 	* \return une string
 	*/
	virtual std::string toString ()=0;
};

/*!
 * \class abstraite InterCase, fille de ElemGraph, Element graphique n'étant pas un pion
 */
class InterCase : public ElemGraph
{
public:
	/*!
 	* affiche l'élément (pour le debug)
 	*/
	virtual void affichage ()=0;
	/*!
 	* transforme l'element graphique InterCase en string ( pour l'affichage concret 1)
 	* \return une string
 	*/
	virtual std::string toString() =0;
};




/*!
 * \class abstraite Pion, fille de ElemGraph, Element graphique qui est un Pion
 */
class Pion : public ElemGraph
{
public :
	/*!
 	* donne la couleur de l'element
 	* \return Colore de l'elem
 	*/
	virtual Colore getColore()=0;
	/*!
 	* affiche l'élément (pour le debug)
 	*/
	virtual void affichage ()=0;
	/*!
 	* transforme l'element graphique Pion en string ( pour l'affichage concret 1)
 	* \return une string
 	*/
	virtual std::string toString ()=0;


protected:
	Colore color;
};





/*!
 * \class  PionN, Pion noir fille de Pion, Element graphique qui est un Pion
 */
class PionN : public Pion
{
public:
	/*!
 	* Constructeur par défaut qui initialise la couleur a noire
 	*/
	PionN()
	{
		color = *(new Colore(true,false));
	}
	~PionN(){}
	
	/*!
 	* donne la couleur de l'element
 	* \return Colore Noire
 	*/
	Colore getColore()
	{
		return color;
	}
	
	/*!
 	* affiche l'élément (pour le debug), sa couleur
 	*/
	void affichage()
	{
		color.affichage();
	}
	
	/*!
 	* transforme l'element graphique PionN en string ( pour l'affichage concret 1)
 	* \return "N"
 	*/
	std::string toString(){
		return "N";
	}
};



/*!
 * \class  PionR, Pion rouge, fille de Pion, Element graphique qui est un Pion
 */
class PionR : public Pion
{
public:
	/*!
 	* Constructeur par défaut qui initialise la couleur a rouge
 	*/
	PionR()
	{
		color = *(new Colore(false,true));
	}
	~PionR(){}
	
	/*!
 	* donne la couleur de l'element
 	* \return Colore rouge
 	*/
	Colore getColore()
	{
		return color;
	}
	
	/*!
 	* affiche l'élément (pour le debug), sa couleur
 	*/
	void affichage()
	{
		color.affichage();
	}
	
	/*!
 	* transforme l'element graphique PionR en string ( pour l'affichage concret 1)
 	* \return "R"
 	*/
	std::string toString(){
		return "R";
	}


};


/*!
 * \class  PionV, Pion vide, fille de Pion, Element graphique qui est un Pion
 */
class PionV : public Pion
{
public:

	/*!
 	* Constructeur par défaut qui initialise la couleur a rouge
 	*/
	PionV()
	{
		color = *(new Colore(false,false));
	}
	~PionV(){}
	
	/*!
 	* donne la couleur de l'element
 	* \return Colore rouge
 	*/
	Colore getColore()
	{
		return color;
	}
	
	/*!
 	* affiche l'élément (pour le debug), sa couleur
 	*/
	void affichage()
	{
		color.affichage();
	}
	
	/*!
 	* transforme l'element graphique PionV en string ( pour l'affichage concret 1)
 	* \return "0"
 	*/
	std::string toString(){
		return "O";
	}


};


/*!
 * \class  Abstraite Factory qui fabriquera les elements graphiques du jeu
 */
class FactoryGraphique
{
public:
	/*FactoryGraphique();
	~FactoryGraphique();*/
	
	/*!
 	* instanscie un ElemGraph
 	* \param type une string qui précise ce qu'il faut instancier 
 	* \return un nouvel element graphique
 	*/
	virtual ElemGraph* factoryMethod (std::string type)=0;

};

/*!
 * \class   FactoryPion qui fabriquera les Pions du jeu
 */
class FactoryPion : FactoryGraphique
{
public:
		
	ElemGraph* factoryMethod (std::string type);

	FactoryPion();
	~FactoryPion();
};

FactoryPion ::FactoryPion(){}
FactoryPion ::~FactoryPion(){};

	/*!
 	* instanscie un Pion
 	* \param type une string qui précise  ce qu'il faut instancier
 	* \return un nouvel element graphique qui est un Pion
 	*/
ElemGraph* FactoryPion::factoryMethod (std::string type){
  ElemGraph* res(0);
	if(type == "rouge"){
		PionR* pion = new PionR();
		res = pion;
	}else if(type == "noir"){
		PionN* pion = new PionN();
		res = pion;
	}else{
		PionV* pion = new PionV();
		res = pion;
	}

	return res;
}


/*!
 * \class  Matrice  qui contient les Pions
 */
class Matrice
{
public:
	Matrice();
	~Matrice();

	bool setPion (ElemGraph*pion, int position );
	bool estVide (int position);
	int indice(ElemGraph*pion);
	ElemGraph* pion(int x);
	bool LignePleine (int num_ligne,Colore color);
private :
	ElemGraph* matr[24];
	FactoryPion* fac;
};

/*!
 * donne l'indice d'un pion
 * \param pion pointeur vers le pion duquel on veut savoir l'indice
 * \return un entier compris entre 0 et 23, -1 si on a pas trouvé
 */
int Matrice::indice(ElemGraph* pion){
	for(int i =0; i<24; i++){
		if ( pion == matr[i]){
			return i;
		}
	}
	return -1;
}
/*!
 * donne le pion situé a l'indice demandé
 * \param x un entier compris entre 0 et 23
 * \return le pointeur vers le pion situé a la Xeme case
 */
ElemGraph* Matrice::pion(int x){
	assert(x>-1 && x<24);
	return matr[x];
}
/*!
 * indique si le pion situé a l'indice demandé est un PionVide
 * \param position un entier compris entre 0 et 23
 * \return True si le pion a la position demandée est de couleur vide
 */
bool Matrice::estVide(int position)
{
	return matr[position]->getColore().isVide();
}


/*!
 * change le pion situé a l'indice demandé
 * \param position un entier compris entre 0 et 23
 * \param pion pointeur vers le pion que l'on veut mettre a la case en parametre
 * \return True
 */
bool Matrice::setPion(ElemGraph*pion,int position)
{

			//delete matr[position];
			matr[position] = pion;
			return true;
}

/*!
 * \brief Constructeur de Matrice, remplit la matrice d'element vide
 * \param
 * \return
 */	
Matrice::Matrice()
{
	fac = new FactoryPion();
	int i;
	for(i=0; i<24; ++i)
	{
		matr[i] = fac->factoryMethod("vide");
	}
}
/*!
 * \brief Deconstructeur de Matrcice
 * \param
 * \return
 */	
Matrice::~Matrice()
{
}
/*!
 * \brief renvoie true si la ligne donné est remplie d'element graphique de la couleur donné en parametre
 * \param	num_Ligne numero de la ligne a verifier color couleur a verifier
 * \return	bool
 */	
bool Matrice::LignePleine (int num_Ligne,Colore color)
{
	if (color.isBlack())
	{
		if (matr[num_Ligne*3]->getColore().isBlack())
		{
			if (matr[num_Ligne*3+1]->getColore().isBlack())
			{
				if (matr[num_Ligne*3+2]->getColore().isBlack())
				{
					return true;
				}
			}
		}
		return false;
	}
	if (color.isRed())
	{
		if (matr[num_Ligne*3]->getColore().isRed())
		{
			if (matr[num_Ligne*3+1]->getColore().isRed())
			{
				if (matr[num_Ligne*3+2]->getColore().isRed())
				{
					return true;
				}
			}
		}
		return false;
	}
	if (color.isVide())
	{
		if (matr[num_Ligne*3]->getColore().isVide())
		{
			if (matr[num_Ligne*3+1]->getColore().isVide())
			{
				if (matr[num_Ligne*3+2]->getColore().isVide())
				{
					return true;
				}
			}
		}
		return false;
	}
	return false;
}
/*!
 * \brief Convertie une position horizontal en position verticale, obliger de faire au cas par cas, renvoie l'entier position convertit
 * \param	x position a convertir
 * \return	entier 
 */	
int conv(int x){
		assert(x>-1 and x<24);
		int res = x;
		x++;
		if(x != 1 and x != 4 and x != 7 and x != 18 and x != 21 and x != 24 ){
			if(x == 8 or x == 13){
				return (res+4);
			}
			if(x == 12 or x == 17){
				return (res -4);
			}
			if(x == 2 or x == 15){
				return (res + 8);
			}
			if(x==10 or x==23){
				return (res -8);
			}
			if(x==5 or x==14){
				return (res + 6);
			}
			if(x==11 or x==20){
				return (res-6);
			}
			if(x==3){return 22-1;}
			if(x==22){return 3-1;}
			if(x==6){return 19-1;}
			if(x==9){return 16-1;}
			if(x==16){return 9-1;}
			if(x==19){return 6-1;}
		}
		return res;
	}
class BarreHoriz : public InterCase
{
public:
	void affichage ();
	std::string toString();
	Colore getColore(){return *(new Colore());}
};
class FactoryBarre : FactoryGraphique
{
public:

	ElemGraph* factoryMethod (std::string type);

	FactoryBarre();
	~FactoryBarre();
};
/*!
 * \brief Constructeur de factorybarre
 * \param
 * \return
 */	
FactoryBarre ::FactoryBarre(){}
/*!
 * \brief Deconstructeur de factorybarre
 * \param
 * \return
 */	
FactoryBarre ::~FactoryBarre(){};

class Affichage
{
public:
	 Affichage(){}
	virtual ~Affichage(){}
	virtual void update ()=0;
};
class Plateau : Sujet
{
protected:
	Matrice matriceH;
	Matrice matriceV;
	Affichage* aff;
	FactoryPion* fac;

	

public:
	Plateau();
	~Plateau();
	bool placPion(ElemGraph*p, int pos);
	void placPion(Player j, int pos);
	bool suppPion(int pos);
	bool suppPion(ElemGraph* p);
	void dep(ElemGraph*p, Fonction direction);
	void dep(int indice, Fonction direction);
	ElemGraph* getPion(int indice);
	int getIndice(ElemGraph*p);
	bool LignePleine (int indice);
	bool ColonnePleine (int indice);
	Matrice getMatrice();
	void notif ();
	void add(Affichage* obs){}
	void supp(Affichage* obs){}

};



class AffichageConcret1 : public Affichage
{
private:
	Plateau* plat;
	FactoryBarre fac;
public:
/*!
 * \brief Constructeur de Affichage Concret, prend le plateau a afficher en parametre
 * \param p plateau aa afficher
 * \return
 */	
	AffichageConcret1(Plateau* p){
		plat=p;
		fac = *(new FactoryBarre());
	}
	 ~AffichageConcret1(){delete plat;}
/*!
 * \brief affiche le plateau observer
 * \param
 * \return
 */	
	 void update (){
	 	Matrice m = plat->getMatrice();
	 	ElemGraph* vertic = fac.factoryMethod("verticale");
	 	ElemGraph* horiz = fac.factoryMethod("horizontale");
	 	ElemGraph* esp = fac.factoryMethod("espace");

	 	// mettre les indic (1-13) (A-M)
	 	std::string aff[375];
	 	int j = 0;
	 	int car;
	 	char c;
	 	std::string chaine =  "1  2  3   4   5  6  7   \n";
	 	int cptChaine = 0;

	 	for (int i=0; i<375; ++i){
	 		if(i==0||i==10||i==20||i==53||i==60||i==67||
	 		i==106||i==110||i==114||i==150||i==153||i==156||
	 		i==164||i==167||i==170||i==206||i==210||i==214||
	 		i==253||i==260||i==267||i==300||i==310||i==320){

	 			aff[i] = m.pion(j)->toString();
	 			j++;
	 		}else if((i>0 && i<20)||
	 			(i>53&&i<67)||
	 			(i>106&&i<114)||
	 			(i>150&&i<156)||
	 			(i>164&&i<170)||
	 			(i>206&&i<214)||
	 			(i>253&&i<267)||
	 			(i>300&&i<320)||
	 			(i%25==22)){


		 		aff[i]=horiz->toString();
			}else if(i%25==24){
				aff[i] = "\n";
			}else if( (i%25==0)||
				(i%25==20)||
				(i>53 && i<267 && (i%25==3||i%25==17))||
				(i==35||i==85||i==131||i==189||
				i==139||i==181||i==235||i==285)
				){

				aff[i] = vertic->toString();
			}else if(i%25==23){
				car = (i+2)/25;
				c = 64 + car;
				aff[i] = "" + c;

			}else if(i>=350){
				aff[i] = chaine.at(cptChaine);
				cptChaine++;
			}else{
				aff[i] = esp->toString();
			}
	 	}
	 	for (int i=0; i<375; ++i){
	 		std::cout<<aff[i];
	 	}

	 }
};

class BarreVertic : public InterCase
{
public:
	void affichage ();
	std::string toString();
/*!
 * \brief getteur de la couleur
 * \param
 * \return Colore
 */		
	Colore getColore(){return *(new Colore());}
};

void BarreVertic ::affichage (){
	std::cout<<"|";
}

/*!
 * \brief Renvoie la barre verticale en chaine de caractere
 * \param
 * \return string
 */	
std::string BarreVertic ::toString(){
	return "|";
}

using namespace std;


class Player
{
protected:
	Colore couleur;
	int nbPion;

public:

	~Player(){}

/*!
 * \brief Constructeur de player, sans parametre, met couleur vide
 * \param
 * \return joueur
 */	
	Player(){
		couleur = *(new Colore());
		nbPion = 0;

	}
/*!
 * \brief Constructeur de Player qui prend sa couleur en parametre
 * \param c Colroe du joueur
 * \return 
 */	
	Player(Colore c){
		couleur = c;
		nbPion = 9;
	}
/*!
 * \brief Affiche la couleur du joueur puis son nombre de pion
 * \param
 * \return
 */	
	void affichage(){
		cout << "joueur de couleur ";
		couleur.affichage();
		cout << " avec nbPion = "<< nbPion << endl;
	}
/*!
 * \brief getteur du nombre de pion
 * \param
 * \return entier
 */	
	int getNbPion ()
	{
		return nbPion;
	}
/*!
 * \brief Décrémente le nombre de pion du joueur
 * \param
 * \return
 */	
	void perdrePion ()
	{
		nbPion--;
	}
/*!
 * \brief getteur de la couleur
 * \param
 * \return colore
 */	
	Colore getColore()
	{
		return couleur;
	}


};




class Phase //(abstract)
{

protected:
	Game* game;

public :
	virtual void jouer ()=0;
  	Phase(){}
  	virtual ~Phase(){}
	Phase (Game* g) : game(g) {}


};



class Deplacement : public Phase
{
public:
	void jouer ();
	void faire_jouer(Player joueur);
	Deplacement(Game* g){
    game = g;
	}
};









class Placement : public Phase
{
public:
	void jouer ();
	void faire_jouer(Player joueur);

	Placement (Game* g){
    game = g;
	}

};





class FinduJeu : public Phase
{
public:
	void jouer ();
	FinduJeu (Game* g){
    game = g;
	}

};




class Game
{

public:
	void Play ();
protected:
	Player joueur1;
	Player joueur2;
	Plateau* plateau;
	Phase* phaseCourante;
	Placement* phasePlacement;
	Deplacement* phaseDeplacement;
	FinduJeu* phaseFinduJeu;


public :
	Game ()
	{
		joueur1 = *(new Player(*(new Colore(1,0))));
		joueur2 = *(new Player(*(new Colore(0,1))));
		AffichageConcret1* aff = new AffichageConcret1(plateau);
		plateau = new Plateau();
		phaseDeplacement = new Deplacement(this);
		phasePlacement = new Placement(this);
		phaseFinduJeu = new FinduJeu(this);
		phaseCourante = phasePlacement;
		
	}
/*!
 * \brief fais jouer la phase courante
 * \param
 * \return
 */	
	void play ()
	{
		phaseCourante->jouer();
	}
/*!
 * \brief getteur du joueur 1
 * \param
 * \return joueur
 */	
	Player getJ1(){
		return joueur1;
	}
	
/*!
 * \brief getteur du joueur 2
 * \param
 * \return joueur
 */	
	Player getJ2(){
		return joueur2;
	}
/*!
 * \brief getteur du plateau de cette game
 * \param
 * \return plateau
 */	
	Plateau* getPlateau(){
		return plateau;
	}
/*!
 * \brief getteur de la phase deplacement
 * \param
 * \return phase
 */	
	Phase* getPhaseDeplacement()
	{
		return phaseDeplacement;
	}
/*!
 * \brief getteur de la phase Findujeu
 * \param
 * \return phase
 */	
	Phase* getPhaseFinduJeu()
	{
		return phaseFinduJeu;
	}
/*!
 * \brief Mets la phase en parametre en phase courante
 * \param p phase a mettre
 * \return
 */	
	void setPhase(Phase* p){
		phaseCourante = p;
	}

};


class Espace : public InterCase
{
public:
	void affichage ();
	std::string toString();
  Colore getColore(){return *(new Colore());}

};

/*!
 * \brief Affichage de espace
 * \param
 * \return
 */	
void Espace ::affichage (){

}
std::string Espace ::toString(){
	return " ";
}

/*!
 * \brief retourne un pointeur ver un element graphique barre crée, verticale ou horizontale selon la chaine de caractere en parmaetre
 * \param type type de barre qu'on veut
 * \return	ElemGraph*
 */	
ElemGraph* FactoryBarre::factoryMethod (std::string type){
  ElemGraph* res;
	if(type == "verticale"){
		BarreVertic* b= new BarreVertic();
		res = b;
	}else if(type == "horizontale"){
		BarreHoriz* b = new BarreHoriz();
		res = b;
	}else{
		Espace* b = new Espace();
		res = b;
	}

	return res;
}


/*!
 * \brief Fais jouer la phase Fin du jeu
 * \param
 * \return
 */	
void FinduJeu::jouer()
{

	if (game->getJ2().getNbPion()<2)
	{
	std::cout<<" JOUEUR 1 VICTORIEUX"<<std::endl;
	}
	if (game->getJ1().getNbPion()>2)
	{
	std::cout<<" JOUEUR 2 VICTORIEUX"<<std::endl;
	}

}




/*!
 * \brief Affichage de barrehoriz
 * \param
 * \return
 */	
void BarreHoriz ::affichage (){

}
std::string BarreHoriz ::toString(){
	return "_";
}




/*!
 * \brief Deconstructeur de plateau
 * \param
 * \return
 */	
	Plateau::~Plateau(){
		delete &matriceH;
		delete &matriceV;
	}

/*!
 * \brief Constructeur de plateau
 * \param
 * \return
 */	
	Plateau::Plateau(){
		aff = new AffichageConcret1(this);
		matriceH = *(new Matrice());
		matriceV = *(new Matrice());
		fac = new FactoryPion();
		notif();
	}

/*!
 * \brief Place l'element en parametre a  la position en parametre, renvoie true si résussi, false sinon
 * \param p element a placer pos position a placé
 * \return bool
 */	
bool Plateau::placPion(ElemGraph*p, int pos){

		bool effectue = false;
		if(matriceH.estVide(pos)){
			delete matriceH.pion(pos);
			assert(matriceH.estVide(pos) and matriceV.estVide(conv(pos)));
			effectue = matriceH.setPion(p, pos) and matriceV.setPion(p, conv(pos));
			
		}
		return effectue;

}

/*!
 * \brief Place un pion
 * \param j propriétaire du pion pos position du pion a deplacer
 * \return
 */	
void Plateau::placPion(Player j,int pos)
	{
		Colore c = j.getColore();
	

		if(c.isBlack())
		{
			placPion(fac->factoryMethod("noir"),pos);
		}
		if(c.isRed())
		{
			placPion(fac->factoryMethod("rouge"),pos);
		}

}


/*!
 * \brief Supprime un element du plateau, renvoie vrai si supprimer, sinon faux
 * \param p position de l'element a supprimer
 * \return bool
 */	
bool Plateau::suppPion(int pos){
		bool effectue = false;
		if(!matriceH.estVide(pos)){
			delete matriceH.pion(pos);
			ElemGraph* nouvPionVide = fac->factoryMethod("vide");
			effectue = matriceH.setPion(nouvPionVide, pos) and matriceV.setPion(nouvPionVide, conv(pos));
			
		}else{
			std::cout<< " can't do that\n";
		}
		return effectue;
}

/*!
 * \brief Supprime un element du plateau, renvoie vrai si supprimer, sinon faux
 * \param p element a supprimer
 * \return bool
 */	
bool Plateau::suppPion(ElemGraph*p){
		bool effectue = false;
		int pos = matriceH.indice(p);
		if(!matriceH.estVide(pos)){
			delete p;
			ElemGraph* nouvPionVide = fac->factoryMethod("vide");
			effectue = matriceH.setPion(nouvPionVide, pos);
			effectue = effectue and matriceV.setPion(nouvPionVide, conv(pos));

		}else{
			std::cout<< " can't do that\n";
		}
		return effectue;
}

/*!
 * \brief Renvoie -1 si pas de position a droite, ou la position de l'emplacement a droite, de l'élement
 * \param x position a tester 
 * \return entier
 */	
	int getRight(int x){ // passer le code en matrice horizontale
		int res = x;
		x++;
		if( x%3 == 0){
			return -1;
		}else{
			return res+1;
		}
	}
/*!
 * \brief Renvoie -1 si pas de position en bas, ou sinon la position de l'emplacement en bas, de l'élement
 * \param x position a tester 
 * \return entier
 */	
	int getDown(int x){
		int res = x;
		x++;
		x = conv(x);

		if( x%3 == 0){
			return -1;
		}else{
			return conv (res+1);
		}

	}
/*!
 * \brief Renvoie -1 si pas de position a gauche, ou la position de l'emplacement a gauche, de l'élement
 * \param x position a tester 
 * \return entier
 */	
	int getLeft(int x){
		int res = x;
		x++;
		if( x%3 == 1){
			return -1;
		}else{
			return (res-1);
		}
	}
/*!
 * \brief Renvoie -1 si pas de position en haut, ou la position de l'emplacement en haut, de l'élement
 * \param x position a tester 
 * \return entier
 */	
	int getUp(int x){
		int res = x;
		x++;
		x = conv(x);

		if( x%3 == 1){
			return -1;
		}else{
			return conv (res-1);
		}
}

	
/*!
 * \brief deplace l'element donné dans la direction donné
 * \param	p l'element	direction direction  a deplacer 
 * \return
 */	
void Plateau::dep(ElemGraph*p, Fonction direction){
		int indice = matriceH.indice(p);
		int down = direction(indice);
		if(down != -1){
			ElemGraph* pdown = matriceH.pion(down);
			if(matriceH.estVide(matriceH.indice(pdown))){
				ElemGraph*temp = matriceH.pion(down);
				// sauvegarde du pionvide ou on va bouger

				matriceH.setPion (p, down);
				matriceH.setPion (temp, indice);

				matriceV.setPion (p, conv(down));
				matriceV.setPion (temp, conv(indice));
			}else{
				std::cout<< " can't do that\n";
			}
		}else{
			std::cout<< " can't do that\n";
		}
}
/*!
 * \brief deplace l'element a la position donné dans la direction donné
 * \param	indice position de l'element	direction direction  a deplacer 
 * \return
 */	
void Plateau::dep(int indice, Fonction direction){
		ElemGraph*p = matriceH.pion(indice);
		dep(p,direction);
}



/*!
 * \brief Renvoie l'element graphique a la position passé en paramètre
 * \param indice position de l'element cherché
 * \return element graphique a la position indice
 */	
ElemGraph* Plateau::getPion(int indice){
		return matriceH.pion(indice);
}

/*!
 * \brief Renvoie la position de l'element graphique passé en parametre
 * \param p element dont on veut la position
 * \return entier, position de p
 */	
int Plateau::getIndice(ElemGraph*p){
		return matriceH.indice(p);
	}

/*!
 * \brief Renvoie true si la ligne de l'entier en parametre est remplie de pion de la même couleur

 * \param indice position que l'on souhaite tester
 * \return un bool
 */
bool Plateau::LignePleine (int indice){
		ElemGraph* pion = matriceH.pion(indice);
		indice = indice /3;
		return matriceH.LignePleine(indice, pion->getColore());
	}

/*!
 * \brief Renvoie true si la colonne du entier en parametre est remplie de pion de la même couleur
 * \param indice position que l'on souhaite tester
 * \return un bool 
 */	
bool Plateau::ColonnePleine (int indice){
		ElemGraph* pion = matriceH.pion(indice);
		indice = conv(indice);
		indice = indice /3;

		return matriceV.LignePleine(indice,pion->getColore());
	}

/*!
 * \brief getteur de matriceH de plateau

 * \param
 * \return this.matriceH
 */	
Matrice Plateau::getMatrice(){
		return matriceH;
	}
/*!
 * \brief Notifie les observers
 * \param
 * \return
 */
void Plateau::notif (){
		/*for (Affichage a : aff){
			a.update();
		}*/
		aff->update();
	}


/*!
 * \brief Fais jouer la phase deplacement

 * \param
 * \return
 */
void Deplacement::jouer()
{
	std::cout<<"Phase de d\E9placement "<<std::endl;
	//----------------------------
	//---Tant que les deux joueur ont chacun plus de 2 pion
	//---on fait les fais jouer 1 par 1
	//---leurs nombres de pion observe plateau qui sera modifier dans faire_jouer
	//----------------------------
	while(game->getJ2().getNbPion()>2 && game->getJ1().getNbPion()>2)
	{
		faire_jouer(game->getJ1());
		faire_jouer(game->getJ2());
	}
	//----------------------------
	//---On a plus qu'a afficher le vainqueur
	//---donc celui qui a plus de 2 pion
	//----------------------------
	game->setPhase(game->getPhaseFinduJeu());
	game->play();


}



/*!
 * \brief Fais jouer un tour de Deplacement au joueur
 * \param joueur Joueur a faire jouer
 * \return
 */
void Deplacement::faire_jouer(Player joueur)
{
	int d,u,r,l; 						//contenant les entier renvoyer par getDown(i), getRight(i), ... de game->getPlateau()-> U = up, D = down,....
	std::string choix;						//le choix a chaque std::cin
	int i,j;     						//i position du pion a deplacer, j pion a supprimer
	bool still_not_move = true ;			//indique si le joueur a effectuer son deplacement
	while (still_not_move)
	{
		//----------------------------
		//----Obtention du pion a deplacer
		//----------------------------
		joueur.affichage();
		std::cout<<"Quel pion a deplacer ? "<<std::endl;
		std::cin>>choix;
		i = atoi(choix.c_str());
		//----------------------------
		//-----Stockage des valeurs des possibles deplacement du pion
		//----------------------------
		r=/*game->getPlateau()->*/getRight(i);
		l=/*game->getPlateau()->*/getLeft(i);
		u=/*game->getPlateau()->*/getUp(i);
		d=/*game->getPlateau()->*/getDown(i);
		//----------------------------
		//----Test si le pion peut au moin etre depalcer
		//----------------------------
		if(u==-1 && d==-1 && r==-1 && l==-1)
		{
			std::cout<<"Pion impossible a d\E9placer"<<std::endl;
		}
		//----------------------------
		//-----Sinon, demander le choix de deplacement, toute valeurs, non pr\E9sente, revient a recommencer la boucle a partir du choix de pion
		//----------------------------
		else
		{
				char choixchar;
				std::cout<<"d,g,b ou h (droite, gauche, bas, haut) ?"<<std::endl;
				cin>>choixchar;
				//----------------------------
				//---Si direction_choisie revient a deplacer vers un choix invalide (resultat du getRight par exemple)
				//---alors affichage d'un message d'impossiblit\E9, pas de deplacement, on retourne a la boucle \E0 choix de pion
				//---sinon on deplace le pion, on indique a still_not__move qu'on a effectuer le deplacement, on deplace le pion dans le plateau
				//--et on attribut les coordonn\E9 du nouveau pion a la variable i pour tester ensuite le cas des tois align\E9
				//----------------------------
				switch(choixchar)
				{
					//typedef int(*Fonction)(int);
					case 'd':
					{
						if(r==-1)
						{
							std::cout<<"Pion impossible a d\E9placer dans cette direction"<<std::endl;
						}
						else
						{
							still_not_move = false;
							game->getPlateau()->dep(i,getRight);
							game->getPlateau()->notif();
							i = r;
						}
						break;
					}
					case 'g':
					{
						if(l==-1)
						{
							std::cout<<"Pion impossible a d\E9placer dans cette direction"<<std::endl;
						}
						else
						{
							still_not_move = false;
							game->getPlateau()->dep(i,getLeft);
							i = l;
							game->getPlateau()->notif();
						}
						break;
					}
					case 'h':
					{
						if(u==-1)
						{
							std::cout<<"Pion impossible a d\E9placer dans cette direction"<<std::endl;
						}
						else
						{
							still_not_move = false;
							game->getPlateau()->dep(i,getUp);
							game->getPlateau()->notif();
							i = u;
						}
						break;
					}
					case 'b':
					{
							if(d==-1)
						{
							std::cout<<"Pion impossible a d\E9placer dans cette direction"<<std::endl;
						}
						else
							{
							still_not_move = false;
							game->getPlateau()->dep(i,getDown);
							game->getPlateau()->notif();
							i = d;

						}
						break;
					}
				}
			}
		}
	//----------------------------
	//---Le pion a \E9t\E9 d\E9plac\E9, et i contient la nouvelle coordon\E9e
	//----------------------------
	//---On test si le deplacment du pion a completer une ligne de 3
	//----------------------------
	if(game->getPlateau()->LignePleine(i) || game->getPlateau()->ColonnePleine(i))
	{
	//----------------------------
	//---Si oui, on peut supprimer un pion adverse
	//---On recupere donc le pion a supprimer, et on le supprime
	//----------------------------
		std::cout<<"Vous pouvez supprimer un pion, quel position ? "<<std::endl;
		cin>>j;
		Colore a_supp = game->getPlateau()->getPion(j)->getColore(); //Contient la couleur du pion a suppirmer
		//----------------------------
		//---Boucle while, qui repete le demande de la position du pion a supprimer
		//---a l'utilisateur tant que ce pion est de la meme couleur que le joueur ou
		//---que c'est un pion vide
		//----------------------------
		while((a_supp.isEquals(joueur.getColore())) || (a_supp.isVide()))
		{
			std::cout<<"Vous ne pouvez pas supprimer ce pion, prenez en un autre ! "<<std::endl;
			cin>>j;
			a_supp = game->getPlateau()->getPion(j)->getColore();
		}
		game->getPlateau()->suppPion(j);
		game->getPlateau()->notif();
		//----------------------------
		//---On diminue le nombre de pion du joueur adverse
		//----------------------------
		if(game->getJ1().getColore().isEquals(a_supp))
		{
			game->getJ1().perdrePion();
		}
		else
		{
			game->getJ2().perdrePion();
		}

	}
}

/*!
 * \brief Fais jouer la phase placement

 * \param
 * \return
 */

void Placement::jouer(){
		Player j1 = game->getJ1();
		Player j2 = game->getJ2();

		for(int i=0; i<9; ++i){
			faire_jouer(j1);
			faire_jouer(j2);
		}
		game->setPhase(game->getPhaseDeplacement());
		game->play();
	}









/*!
 * \brief Fais joueur un  joueur un tour de la phase Placement 
 * \param joueur Joueur a faire jouer
 * \return 
 */
void Placement::faire_jouer(Player joueur)
{
	int choix;
	int i,j;
	joueur.affichage();
	std::cout<<"Placer un pion \E0 quelle position ? "<<std::endl;
	//----------------------------
	//---Obtention de la position o\F9 l'on veut ajouter notre pion
	//---et stockage de la couleur du pion d\E9j\E0 pr\E9sent
	//---si il n'y a pas de pion pos\E9e par un joueur alors c'est un pion "vide"
	//----------------------------
	std::cin>>choix;
	i = choix/*atoi(choix.c_str());*/;
	Colore col_atposition = game->getPlateau()->getPion(i)->getColore();


	//----------------------------
	//---Rep\E9tition : tant que le pion d\E9j\E0 pr\E9sent a la position i n'est pas un pion vide
	//---on redemande une nouvelle position i
	//----------------------------
	while(!col_atposition.isVide())
		{
			std::cout<<"Vous ne pouvez pas ajouter ici, choissisez une autre position ! "<<std::endl;
			cin>>choix;
			//j = atoi(choix.c_str());
			i = choix;
			
			col_atposition = game->getPlateau()->getPion(i)->getColore();
		}
	//----------------------------
	//---On pose le pion, en appelant placPion de plateau
	//---qui creer un pion de la couleur du joueur en parametre
	//----------------------------
	game->getPlateau()->placPion(joueur,i);
	game->getPlateau()->notif();
	
	if(game->getPlateau()->LignePleine(i) || game->getPlateau()->ColonnePleine(i))
	{
	//----------------------------
	//---Si oui, on peut supprimer un pion adverse
	//---On recupere donc le pion a supprimer, et on le supprime
	//----------------------------
		std::cout<<"Vous pouvez supprimer un pion, quel position ? "<<std::endl;
		cin>>j;
		Colore a_supp = game->getPlateau()->getPion(j)->getColore(); //Contient la couleur du pion a suppirmer
		//----------------------------
		//---Boucle while, qui repete le demande de la position du pion a supprimer
		//---a l'utilisateur tant que ce pion est de la meme couleur que le joueur ou
		//---que c'est un pion vide
		//----------------------------
		while((a_supp.isEquals(joueur.getColore())) || (a_supp.isVide()))
		{
			std::cout<<"Vous ne pouvez pas supprimer ce pion, prenez en un autre ! "<<std::endl;
			cin>>j;
			a_supp = game->getPlateau()->getPion(j)->getColore();
		}
		game->getPlateau()->suppPion(j);
		game->getPlateau()->notif();
		//----------------------------
		//---On diminue le nombre de pion du joueur adverse
		//----------------------------
		if(game->getJ1().getColore().isEquals(a_supp))
		{
			game->getJ1().perdrePion();
		}
		else
		{
			game->getJ2().perdrePion();
		}

	}
	

}
int main(){
std::cout<<conv(15);
	Game* game = new Game();
	game->play();
	/*ElemGraph* x = new PionV();
	 x->getColore().affichage();
	//game->getPlateau()->notif();*/
	return 0;
}






