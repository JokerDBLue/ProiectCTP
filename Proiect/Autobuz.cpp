#include "Autobuz.h"



Autobuz::Autobuz()
{
	this->zona = 1;
	this->numar = "";
	this->capete = "";
	this->orar;
	this->ruta;
}

Autobuz::Autobuz(int zona, string numar, string capete, vector<string> orar, vector<string> ruta)
{
	this->zona = zona;
	this->numar = numar;
	this->capete = capete;
	this->orar = orar;
	this->ruta = ruta;
}

Autobuz::Autobuz(const Autobuz & a)
{
	this->zona = a.zona;
	this->numar = a.numar;
	this->capete = a.capete;
	this->orar = a.orar;
	this->ruta = a.ruta;
}

int Autobuz::getZona()
{
	return this->zona;
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

void Autobuz::setZona(int z)
{
	this->zona = z;
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

bool Autobuz::oAnumitaRuta(string inceput, string sfarsit)
{
	size_t i = 0;
	while ((i < ruta.size()) && (ruta[i] != inceput))
	{
		i++;
	}
	for (size_t j = i + 1; j < ruta.size(); j++)
	{
		if (ruta[j] == sfarsit)
			return true;
	}
	return false;
}

ostream & operator<<(ostream & os, const Autobuz a)
{
	os << "Autobuzul " << a.numar << ": " << a.capete << endl << "Zona " << a.zona << endl;
	os << "Ruta: " << endl;
	for (size_t i = 0; i < a.ruta.size(); i++)
		os << a.ruta[i] << ", ";
	os << endl;
	os << "Orar: " << endl;
	for (size_t i = 0; i < a.orar.size(); i++)
		os << a.orar[i] << " ";
	return os;
}
Autobuz::~Autobuz()
{
	this->orar.clear();
	this->ruta.clear();
}