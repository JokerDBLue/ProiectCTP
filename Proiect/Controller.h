#pragma once
#include "Login.h"

class Controller: public Login
{
private:
	//Repo<User> useri e in clasa Login, de aceea nu mai e declarat aici
	RepoFile<Bilet> bilete; // memoreaza din fisier biletele valabile
	RepoFile<Autobuz> autobuze; // memoreaza toate autobuzele din fisiere
public:
	Controller();
	void addAuto(const Autobuz& a);
	Repo<Autobuz> cautareAuto(string inceput, string final, string data);
	Repo<Bilet> bileteValabile();
	void cumparareBilete(int nrBilete, int nrUser, int zona, float numerar);
	Repo<Bilet> vizualizireInventar(int nrUser);
	void golireCos();
	void finalizarePlata(string cod, string codSpate, float balans, int nrUser);
	//accesare clasa login
	~Controller();
};

