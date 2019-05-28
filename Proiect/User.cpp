#include "User.h"


User::User():ContBancar()
{
	this->user = "";
	this->parola = "";
	this->bilete;
}

User::User(string cod, string codspate, float balans, string user, string parola, vector<Bilet> bilete, CosCumparaturi cosul):ContBancar(cod,codspate, balans)
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
	cosul.adaugaInCos(b, cant);
}

CosCumparaturi User::getCosul()
{
	return cosul;
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

User::~User()
{
}

ostream & operator<<(ostream & os, const User & u)
{
	os << "Username: " << u.user << endl;
	os << "Cod: " << u.cod << endl;
	return os;
}
