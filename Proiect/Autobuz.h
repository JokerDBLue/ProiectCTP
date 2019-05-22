#pragma once
#include "Bilet.h"
#include <vector>
#include <string>
class Autobuz : public Bilet
{
private:
	string numar;
	string capete;
	vector<string> orar;
	vector<string> ruta;

public:
	Autobuz();
	Autobuz(float pret, int zona, int valabilitate, string numar, string capete, vector<string> orar, vector<string> ruta);
	Autobuz(const Autobuz &a);
	string getNumar();
	string getCapete();
	vector<string> getOrar();
	vector<string> getRuta();
	void setNumar(string nr);
	void setCapete(string c);
	void setOrar(vector<string> o);
	void setRuta(vector<string> r);
	friend ostream &operator<<(ostream &os, const Autobuz a);

	~Autobuz();
};