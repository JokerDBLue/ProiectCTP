#include "Autobuz.h"



Autobuz::Autobuz() :Bilet()
{
	this->numar = "";
	this->capete = "";
	this->orar;
	this->ruta;
}

Autobuz::Autobuz(float pret, int zona, int valabilitate, string numar, string capete, vector<string> orar, vector<string> ruta) :Bilet(pret, zona, valabilitate)
{
	this->numar = numar;
	this->capete = capete;
	this->orar = orar;
	this->ruta = ruta;
}

Autobuz::Autobuz(const Autobuz & a) :Bilet(a)
{
	this->numar = a.numar;
	this->capete = a.capete;
	this->orar = a.orar;
	this->ruta = a.ruta;
}

string Autobuz::getNumar()
{
	return this->numar;
}

string Autobuz::getCapete()
{
	return this->capete;
}

vector<string> Autobuz::getOrar()
{
	return this->orar;
}

vector<string> Autobuz::getRuta()
{
	return this->ruta;
}

void Autobuz::setNumar(string nr)
{
	this->numar = nr;
}

void Autobuz::setCapete(string c)
{
	this->capete = c;
}

void Autobuz::setOrar(vector<string> o)
{
	this->orar = o;
}

void Autobuz::setRuta(vector<string> r)
{
	this->ruta = r;
}

ostream & operator<<(ostream & os, const Autobuz a)
{
	os << "Autobuzul " << a.numar << ": " << a.capete << endl;
	os << "Ruta: " << endl;
	for (size_t i = 0; i < a.ruta.size(); i++)
		os << a.ruta[i] << ", ";
	os << "Orar: " << endl;
	for (size_t i = 0; i < a.orar.size(); i++)
		os << a.orar[i] << endl;
	return os;
}
Autobuz::~Autobuz()
{
}