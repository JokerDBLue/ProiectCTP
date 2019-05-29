#include "Controller.h"



Controller::Controller() : Login()
{
}

void Controller::addAuto(const Autobuz & a)
{
	autobuze.addElem(a);
}

void Controller::readBilete(string file_name)
{
	bilete.readFromFileBilete(file_name);
}

void Controller::readAutobuze(string file_name)
{
	autobuze.readFromFileAutobuz(file_name);
}


Repo<Autobuz> Controller::cautareAuto(string inceput, string final, string data)
{
	Repo<Autobuz> a1; // memoreaza lista de autobuze care merge de la o statie la alta
	/*for (int i = 0; i < autobuze.getSize(); i++)
	{
		if (autobuze.getElem(i).oAnumitaRuta(inceput, final) == true)
		{
			a1.addElem(autobuze.getElem(i));
		}
	}*/
	return a1;
}

Autobuz Controller::cuatareLinie(string linie)
{
	for (int i = 0; i < autobuze.getSize(); i++)
	{	
		if (autobuze.getElem(i).getNumar() == linie)
				return autobuze.getElem(i);
	}
}

Repo<Bilet> Controller::bileteValabile()
{
	return bilete;
}

void Controller::cumparareBilete(int nrBilete, int nrUser, int zona, float numerar)
{
	int i = 0; 
	while((i < bilete.getSize()) && (bilete.getElem(i).getZona() != zona))
	{
		i++;
	}
	if (i < bilete.getSize())
		useri.getElem(nrUser).addInCos(bilete.getElem(i), nrBilete);
	//else
	//	throw 0;//mesaj care zice ca nu exista bilete pt aceasta zona
}

Repo<Bilet> Controller::vizualizireInventar(int nrUser)
{
	Repo<Bilet> b1(useri.getElem(nrUser).inventar());
	return b1;
}

void Controller::golireCos(int nrUser)
{
	useri.getElem(nrUser).cumparare();
}

int Controller::finalizarePlata(string cod, string codSpate, float balans, int nrUser)
{
	cout << useri.getElem(nrUser);
	if ((useri.getElem(nrUser).GetCod() == cod) && (useri.getElem(nrUser).GetCodSpate() == codSpate))
	{
		cout << useri.getElem(nrUser).GetCod() << " " << useri.getElem(nrUser).GetCodSpate();
		if (useri.getElem(nrUser).getTotal() <= balans)
		{
			golireCos(nrUser);
			return 0;
		}
		else
			return 2;
	}
	else
		return 1; //Datele introduse nu sunt corecte
}


Controller::~Controller()
{
}
