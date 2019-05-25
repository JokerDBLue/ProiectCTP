#pragma once
#include "RepoFile.h"
#include "Bilet.h"
#include "Autobuz.h"
class Controller
{
private:
	//RepoFile user;
	Repo<Bilet> bilet;
	Repo<Autobuz> autobuz;
public:
	Controller();
	//Repo<Autobuz> cautareAuto(string inceput, string final, string data);
	//int cumparareBilete(int nrBilete, int zona, float numerar)
	//accesare clasa login
	//Reminder: creeaza cos de cumparaturi
	~Controller();
};

