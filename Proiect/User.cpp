#include "User.h"


User::User():ContBancar()
{
	this->user = "";
	this->parola = "";
	this->bilete;
}

/*User::User(string cod, string codspate, float balans, string user, string parola):ContBancar(cod,codspate, balans)
{
	this->user = user;
	this->parola = parola;
}*/

string User::GetParola()
{
	return parola;
}

string User::GetUser()
{
	return user;
}

void User::SetUser(string user)
{
	this->user = user;
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