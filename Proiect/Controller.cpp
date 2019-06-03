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
	for (int i = 0; i < autobuze.getSize(); i++)
	{
		if ((autobuze.getElem(i).oAnumitaRuta(inceput, final) == true) && (autobuze.getElem(i).getZi() == data))
		{
			a1.addElem(autobuze.getElem(i));
		}
	}
	if (a1.getSize() == 0)
		throw exception("Nu exista autobuze cu drum direct in data aleasa\n");
	return a1;
}

Autobuz Controller::cuatareLinie(string linie)
{
	for (int i = 0; i < autobuze.getSize(); i++)
	{	
		if (autobuze.getElem(i).getNumar() == linie)
				return autobuze.getElem(i);
	}
	throw exception("Nu s-a gasit aceasta linie\n");
}

Repo<Bilet> Controller::bileteValabile()
{
	return bilete;
}

CosCumparaturi Controller::getCos(int nrUser)
{
	return useri.getElem(nrUser).getCosul();
}

void Controller::cumparareBilete(int nrBilete, int nrUser, int zona)
{
	int i = 0;
	if (nrBilete < 0)
		throw exception("Cantitatea nu poate fi negativa\n");
	while((i < bilete.getSize()) && (bilete.getElem(i).getZona() != zona))
	{
		i++;
	}
	if (i < bilete.getSize())
	{
		useri.addInCos(nrUser, bilete.getElem(i), nrBilete);
	}
	else
		throw exception("Nu exista astefel de bilete\n");//mesaj care zice ca nu exista bilete pt aceasta zona
}

Repo<Bilet> Controller::vizualizireInventar(int nrUser)
{
	Repo<Bilet> b1(useri.getElem(nrUser).inventar());
	return b1;
}

void Controller::stergeBilet(int nrUser, int nrBilet)
{
	useri.stergeBilet(nrUser, nrBilet);
}

void Controller::schimbaCant(int nrUser, int nrBilet, int newCant)
{
	if (newCant < 0)
		throw exception("Cantitatea nu poate fi negativa\n");
	useri.schimbaCant(nrUser, nrBilet, newCant);
}

void Controller::golireCos(int nrUser)
{
	useri.golireCos(nrUser);
}

int Controller::finalizarePlata(string cod, string codSpate, int nrUser)
{
	if ((useri.getElem(nrUser).GetCod() == cod) && (useri.getElem(nrUser).GetCodSpate() == codSpate))
	{
		if (useri.getElem(nrUser).getTotal() <= useri.getElem(nrUser).GetBalans())
		{
			golireCos(nrUser);
			return 0;
		}
		else
			return 2; //utilizatorul nu are destui bani in contul bancar
	}
	else
		return 1; //Datele introduse nu sunt corecte
}


Controller::~Controller()
{
}
