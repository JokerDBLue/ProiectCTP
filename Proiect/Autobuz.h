#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Autobuz
{
private:

	int zona;
	string numar;
	string capete;
	vector<string> orar;
	vector<string> ruta;

public:
	Autobuz();
	Autobuz(int zona, string numar, string capete, vector<string> orar, vector<string> ruta);
	Autobuz(const Autobuz &a);
	int getZona();
	string getNumar();
	string getCapete();
	vector<string> getOrar();
	vector<string> getRuta();
	void setZona(int z);
	void setNumar(string nr);
	void setCapete(string c);
	void setOrar(vector<string> o);
	void setRuta(vector<string> r);
	friend ostream &operator<<(ostream &os, const Autobuz a);

	~Autobuz();
};