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
	void citesteDatele();
	void login();
	void infoBilete();
	void optiuniUtilizator();
	void optiuni();
	void comandaUtilizator(int nrUser);
	void comanda();
	~UI();
};

