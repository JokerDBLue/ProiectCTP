#include "User.h"
#include <exception>

User::User():ContBancar()
{
	this->user = "";
	this->parola = "";
	this->bilete;
}

User::User(string cod, string codspate, float balans, string user, string parola, vector<Bilet> bilete):ContBancar(cod,codspate, balans)
{
	this->user = user;
	this->parola = parola;
	this->bilete = bilete;
}

User::User(const User & u): ContBancar(u)
{
	this->user = u.user;
	this->parola = u.parola;
	this->bilete = u.bilete;
	this->cosul = u.cosul;
}

string User::GetParola()
{
	return parola;
}

string User::GetUser()
{
	return user;
}

float User::getTotal()
{
	return cosul.costTotal();
}

void User::SetUser(string user)
{
	this->user = user;
}

void User::addBilet(Bilet b)
{
	bilete.push_back(b);
}

vector<Bilet> User::inventar()
{
	return bilete;
}

void User::addInCos(Bilet b, int cant)
{
	this->cosul.adaugaInCos(b, cant);
}

void User::schimbaCant(int nrBilet, int newCant)
{
	cosul.changeCant(nrBilet, newCant);
}

void User::stergeBilet(int nrBilet)
{
	cosul.stergeElem(nrBilet);
}

CosCumparaturi User::getCosul()
{
	return this->cosul;
}

bool User::operator==(const User & u)
{
	if ((u.user == this->user) && (u.parola == this->parola))
		return true;
	return false;
}

void User::SetParola(string parola)
{
	this->parola = parola;
}

void User::cumparare()
{
	vector<Bilet> a = cosul.getB();
	vector<int> b = cosul.getCant();
	for (size_t i = 0; i < a.size(); i++)
		for (size_t j = 0; j < b[i]; j++)
			bilete.push_back(a[i]);
	cosul.~CosCumparaturi();
}

User::~User()
{
}

ostream & operator<<(ostream & os, const User & u)
{
	os << u.user << "," << u.parola;
	return os;
}
