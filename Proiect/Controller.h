#pragma once
#include "Login.h"

class Controller: public Login
{
private:
	//Repo<User> useri e in clasa Login, de aceea nu mai e declarat aici
	Repo<Bilet> bilete; // memoreaza din fisier biletele valabile
	Repo<Autobuz> autobuze; // memoreaza toate autobuzele din fisiere
public:
	Controller();
	void addAuto(const Autobuz& a);
	void readBilete(string file_name);
	void readAutobuze(string file_name);
	Repo<Autobuz> cautareAuto(string inceput, string final, string data);
	Autobuz cuatareLinie(string linie);
	Repo<Bilet> bileteValabile();
	CosCumparaturi getCos(int nrUser);
	void cumparareBilete(int nrBilete, int nrUser, int zona);
	Repo<Bilet> vizualizireInventar(int nrUser);
	void stergeBilet(int nrUser, int nrBilet);
	void schimbaCant(int nrUser, int nrBilet, int newCant);
	void golireCos(int nrUser);
	int finalizarePlata(string cod, string codSpate, int nrUser);
	//accesare clasa login
	~Controller();
};