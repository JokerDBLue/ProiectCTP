#pragma once
#include "Controller.h"

class UI
{
private:
	Controller c;
public:
	UI();
	string citesteLinia();
	string datiComanda();
	string citesteUser();
	string citesteParola();
	string citesteCod();
	string citesteCodspate();
	string datiInceput();
	string datiSfarsit();
	int datiNrBilet();
	int datiCantNoua();
	int datiTipBilet();
	int datiCantBilete();
	void clearScreen();
	void citesteDatele();
	void login();
	void infoBilete();
	void cumparaturi(int nrUser);
	void optiuniUtilizator();
	void optiuni();
	void comandaUtilizator(int nrUser);
	void comanda();
	~UI();
};

