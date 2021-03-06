
#include "Color.hpp"


Colore::~Colore()
{

}

Colore::Colore()
{
	estNoir = false;
	estRouge = false;

}

Colore::Colore(bool noir,bool rouge)
{
	estNoir = noir;
	estRouge = rouge;
}



bool Colore::isRed ()
{
	if (estRouge && !estNoir)
	{
		return true;
	}
	else { return false; }

}


bool Colore::isBlack ()
{
	if (!estRouge && estNoir)
	{
		return true;
	}
	else { return false; }
}


bool Colore::isVide ()
{
	if ((!estRouge && !estNoir)|| (estRouge && estNoir))
	{
		return true;
	}
	else { return false; }
}

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
