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

bool Autobuz::oAnumitaRuta(string inceput, string sfarsit)
{
	int k = 0;
	for (size_t i = 0; i < ruta.size(); i++)
		if (ruta[i] == inceput)
		{
			k = i;
		}
	for (size_t i = k; i < ruta.size(); i++)
		if (ruta[i] == sfarsit)
			return true;

	return false;
}

ostream & operator<<(ostream & os, const Autobuz a)
{
	os << "Autobuzul " << a.numar << ": " << endl << "Zona " << a.zona << endl;
	os << "Orar: " << endl;

	for (size_t i = 0; i < a.orar.size(); i++)
	{
		os << a.ruta[i] << ": ";
		for (size_t j = 0; j < a.orar[i].size(); j++)
			os << a.orar[j][i] << " ";
		cout << endl;
	}
	return os;
}

Autobuz::~Autobuz()
{
	this->orar.clear();
	this->ruta.clear();
}


