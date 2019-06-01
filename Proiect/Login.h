#pragma once
#include <iostream>
#include "User.h"
#include "Repo.h"
using namespace std;
//Operatii logice specifice pt clasa user
class Login
{
protected:
	Repo<User> useri;
public:
	Login();
	int VerifyLogin(string user, string parola);
	void Register(string user, string parola, string cod, string codspate, string file_name);
	void WriteRegister(); // schimbat denumirea
	void ReadUseri(string file_name); // schimbat denumirea
	virtual ~Login();
};

