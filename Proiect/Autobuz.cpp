#include "Autobuz.h"



Autobuz::Autobuz()
{
	this->zona = 1;
	this->numar = "";
	this->zi = "";
	this->orar;
	this->ruta;
}

Autobuz::Autobuz(int zona, string numar, string zi, vector<vector<string> > orar, vector<string> ruta)
{
	this->zona = zona;
	this->numar = numar;
	this->zi = zi;
	this->orar = orar;
	this->ruta = ruta;
}

Autobuz::Autobuz(const Autobuz & a)
{
	this->zona = a.zona;
	this->numar = a.numar;
	this->zi = a.zi;
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

string Autobuz::getZi()
{
	return this->zi;
}

vector<vector<string> > Autobuz::getOrar()
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

void Autobuz::setZi(string z)
{
	this->zi = z;
}

void Autobuz::setOrar(vector<vector<string> > o)
{
	this->orar = o;
}

void Autobuz::setRuta(vector<string> r)
{
	this->ruta = r;
}

ostream & operator<<(ostream & os, const Autobuz a)
{
	os << "Autobuzul " << a.numar << ": " << endl << "Zona " << a.zona << endl;
	os << "Ruta: " << endl;
	for (size_t i = 0; i < a.ruta.size(); i++)
		os << a.ruta[i] << ", ";
	os << "Orar: " << endl;
	for (size_t i = 0; i < a.orar.size(); i++)
	{
		cout << endl;
		for (size_t j = 0; j < a.orar[i].size(); j++)
			os << a.orar[i][j] << " ";
	}
	return os;
}
Autobuz::~Autobuz()
{
	this->orar.clear();
	this->ruta.clear();
}


