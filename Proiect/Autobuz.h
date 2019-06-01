#pragma once
#include "Bilet.h"
#include <vector>
#include <string>
class Autobuz
{
private:

	int zona;
	string numar;
	string zi;
	vector<vector<string> > orar;
	vector<string> ruta;

public:
	Autobuz();
	Autobuz(int zona, string numar, string zi, vector<vector<string> > orar, vector<string> ruta);
	Autobuz(const Autobuz &a);
	int getZona();
	string getNumar();
	string getZi();
	vector<vector<string> > getOrar();
	vector<string> getRuta();
	void setZona(int z);
	void setNumar(string nr);
	void setZi(string z);
	void setOrar(vector<vector<string> > o);
	void setRuta(vector<string> r);
	bool oAnumitaRuta(string inceput, string sfarsit);
	bool operator==(const Autobuz & a);
	friend ostream &operator<<(ostream &os, const Autobuz a);

	~Autobuz();
};
