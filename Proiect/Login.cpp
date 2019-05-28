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

void Login::Register(User u)
{
	useri.addElem(u);
	//useri.addToFile("useri.csv");
}

void Login::WriteRegister()
{
	
}

void Login::ReadUseri()
{
	//useri.readFromFileUseri("useri.csv");
}
