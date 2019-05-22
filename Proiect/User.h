#pragma once
#include"ContBancar.h"
#include<iostream>
using namespace std;

class User: public ContBancar
{
private:
	string user;
	string parola;
public:
	User();
	User(string cod, string codspate, int balans, string user, string parola);
	string GetParola();
	string GetUser();
	void SetParola(string parola);
	void SetUser(string user);
	~User();
};

