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
	//User(string cod, string codspate, float balans, string user, string parola);
	string GetParola();
	string GetUser();
	void SetParola(string parola);
	void SetUser(string user);
	bool operator==(const User& u);
	~User();
};

