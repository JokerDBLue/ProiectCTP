#pragma once
#include"ContBancar.h"
#include "CosCumparaturi.h"
#include <vector>
//#include<iostream>
//using namespace std;

class User: public ContBancar
{
private:
	string user;
	string parola;
	vector<Bilet> bilete;
	CosCumparaturi cosul;
public:
	User();
	User(string cod, string codspate, float balans, string user, string parola, vector<Bilet> bilete, CosCumparaturi cosul);
	User(const User& u);
	string GetParola();
	string GetUser();
	float getTotal();
	void SetParola(string parola);
	void SetUser(string user);
	void addBilet(Bilet b);
	vector<Bilet> inventar();
	void addInCos(Bilet b, int cant);
	CosCumparaturi getCosul();
	bool operator==(const User& u);
	friend ostream & operator<<(ostream & os, const User& u);
	~User();
};

