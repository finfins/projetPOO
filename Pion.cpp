
#ifndef Pion_
#define Pion_

#include "Color.cpp"
//#include "PionN.cpp"



class Pion
{
public :
	virtual Colore getColore()=0;
	virtual void affichage()=0;
	
protected:
	Colore color;
};





#endif   
