#include "User.h"


User::User():ContBancar()
{
	this->user = "";
	this->parola = "";
}
User::User(string cod, string codspate, int balans, string user, string parola):ContBancar(cod,codspate, balans)
{
	this->user = user;
	this->parola = parola;
}
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

void User::SetParola(string parola)
{
	this->parola = parola;
}

User::~User()
{
}