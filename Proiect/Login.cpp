#include "Login.h"
#include<iostream>
#include<fstream>


Login::Login()
{
}

Login::~Login()
{
}

int Login::VerifyLogin(string user, string parola) // Intoarce nr de ordine al user-ului in Repo sau intoarece -1 daca nu exista
{
	User u;
	u.SetUser(user);
	u.SetParola(parola);
	return useri.existenta(u);
}

void Login::Register(string user, string parola, string cod, string codspate, string file_name)
{
	User u;
	for (int i = 0; i < useri.getSize(); i++)
	{
		if (useri.getElem(i).GetUser() == user)
			throw "User already exist!\n";
	}
	u.SetBalans(0);
	u.SetCod(cod);
	u.SetCodSpate(codspate);
	u.SetUser(user);
	u.SetParola(parola);
	useri.addElem(u);
	useri.addusertofile(file_name);
}

void Login::WriteRegister(string file_name)
{
	useri.addusertofile(file_name);
}

void Login::ReadUseri(string file_name)
{
	useri.readFromFileUseri(file_name);
}
