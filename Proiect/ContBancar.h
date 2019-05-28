#pragma once
#include<iostream>
#include<string>

using namespace std;

class ContBancar
{
protected:
	string cod; //codul de pe partea din fata a cardului
	string codspate; //codul de pe spatele cardului
	float balans; //modificat, deoarece balansul ar putea fi oricand un nr real
public:
	ContBancar();
	ContBancar(string cod, string codspate, float balans);
	ContBancar(const ContBancar& cb);
	string GetCod();
	string GetCodSpate();
	float GetBalans();
	void SetCod(string cod);
	void SetCodSpate(string codspate);
	void SetBalans(float balans);
	bool operator==(const ContBancar & cb); //adaugat pentru atunci cand user-ul isi introduce datele
	virtual ~ContBancar();
};

