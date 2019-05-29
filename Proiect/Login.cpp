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

void Login::Register(string user, string parola, string cod, string codspate)
{
	User u;
	u.SetBalans(0);
	u.SetCod(cod);
	u.SetCodSpate(codspate);
	u.SetUser(user);
	u.SetParola(parola);
	useri.addElem(u);
	useri.addusertofile("useri.txt");
}

void Login::WriteRegister()
{
	
}

void Login::ReadUseri()
{
	useri.readFromFileUseri("useri.txt");
}
