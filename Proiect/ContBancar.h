#pragma once
#include<iostream>
#include<string>

using namespace std;

class ContBancar
{
protected:
	string cod;
	string codspate;
	float balans; //modificat, deoarece balansul ar putea fi oricand un nr real
public:
	ContBancar();
	ContBancar(string cod, string codspate, float balans);
	string GetCod();
	string GetCodSpate();
	float GetBalans();
	void SetCod(string cod);
	void SetCodSpate(string codspate);
	void SetBalans(float balans);
	bool operator==(const ContBancar & cb); //adaugat pentru atunci cand user-ul isi introduce datele
	~ContBancar();
};

