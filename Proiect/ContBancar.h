#pragma once
#include<iostream>
#include<string>

using namespace std;

class ContBancar
{
private:
	string cod;
	string codspate;
	int balans;
public:
	ContBancar();
	ContBancar(string cod, string codspate, int balans);
	string GetCod();
	string GetCodSpate();
	void SetCod(string cod);
	void SetCodSpate(string codspate);
	int GetBalans();
	~ContBancar();
};

