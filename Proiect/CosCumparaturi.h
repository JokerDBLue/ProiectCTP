#pragma once
#include "Bilet.h"
#include <vector>

class CosCumparaturi
{
private:
	vector<Bilet> b;
	vector<int> cant;
	vector<float> pret;
public:
	//Constructori
	CosCumparaturi();
	CosCumparaturi(vector<Bilet> b, vector<int> cant, vector<float> pret);
	CosCumparaturi(const CosCumparaturi& cc);

	//Get
	vector<Bilet> getB();
	vector<int> getCant();

	//Adaugarea si stergerea de elemente
	void adaugaInCos(const Bilet biletul, int c);
	void stergeElem(int i);
	void changeCant(int i, int newCant);
	float costTotal();
	float getPret(int i);
	

	//Suprascrierea operatiei de afisare
	friend ostream &operator<<(ostream& os, const CosCumparaturi);
	
	//Destructor
	~CosCumparaturi();
};

