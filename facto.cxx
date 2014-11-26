/* generated by dia/codegen.py */
class BarreHoriz : InterCase 
{
public:
	void affichage ();
};

class BarreVertic : InterCase 
{
public:
	void affichage ();
};

class Pion : ElemGraph 
{
public:
	Colore getColore ();
	void affichage ();
protected:
	Colore color;
};

/*(NULL)*/
class InterCase : ElemGraph 
{
public:
	void affichage ();
protected:
	int taille;
};

class PionN : Pion 
{
public:
	Colore getColore ();
	void affichage ();
protected:
	Colore color;
};

/*(NULL)*/
class Espace : InterCase 
{
public:
	void affichage ();
};

class PionR : Pion 
{
public:
	Colore getColore ();
	void affichage ();
protected:
	Colore color;
};

class PionV : Pion 
{
public:
	Colore getColore ();
	void affichage ();
protected:
	Colore color;
};

class FactoryBarre : FactoryGrapgique 
{
public:
	ElemGraph factoryMethod (String type);
};

class FactoryPion : FactoryGrapgique 
{
public:
	ElemGraph factoryMethod (String type);
};

class FactoryGrapgique 
{
public:
	ElemGraph factoryMethod (String type);
};

/*(NULL)*/
class ElemGraph 
{
public:
	void affichage ();
	string toString ();
};
