#include "Bilet.h"


Bilet::Bilet()
{
	this->pret = 2.5;
	this->zona = 1;
	this->valabilitate = 30;

}

Bilet::Bilet(float pret, int zona, int valabilitate)
{
	this->pret = pret;
	this->zona = zona;
	this->valabilitate = valabilitate;
}

Bilet::Bilet(const Bilet & b)
{
	this->pret = b.pret;
	this->zona = b.zona;
	this->valabilitate = b.valabilitate;
}

float Bilet::getPret()
{
	return pret;
}

int Bilet::getZona()
{
	return zona;
}

int Bilet::getValabilitate()
{
	return valabilitate;
}

void Bilet::setPret(float p)
{
	this->pret = p;
}

void Bilet::setZona(int z)
{
	this->zona = z;
}

void Bilet::setValabilitate(int v)
{
	this->valabilitate = v;
}

bool Bilet::operator==(Bilet & b)
{
	if (this->pret == b.pret)
		return true;
	return false;
}

Bilet Bilet::operator=(const Bilet & b)
{
	if (this != &b)
	{
		this->setPret(b.pret);
		this->setZona(b.zona);
		this->setValabilitate(b.valabilitate);
	}

	return *this;
}


Bilet::~Bilet()
{
}

ostream & operator<<(ostream & os, const Bilet& b)
{
	os << "Zona: " << b.zona << "; ";
	os << "Valabilitate: " << b.valabilitate << "; ";
	os << "Pret/calatorie: " << b.pret;
	return os;
}