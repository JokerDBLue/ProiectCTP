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
	void cumparareBilete(int nrBilete, int nrUser, int zona, float numerar);
	Repo<Bilet> vizualizireInventar(int nrUser);
	void golireCos(int nrUser);
	int finalizarePlata(string cod, string codSpate, float balans, int nrUser);
	//accesare clasa login
	~Controller();
};

