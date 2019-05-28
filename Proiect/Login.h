#pragma once
#include <iostream>
#include "User.h"
#include "RepoFile.h"
using namespace std;
//Operatii logice specifice pt clasa user
class Login
{
protected:
	RepoFile<User> useri;
public:
	Login();
	int VerifyLogin(string user, string parola);
	void Register(User u);
	void WriteRegister(); // schimbat denumirea
	void ReadUseri(); // schimbat denumirea
	virtual ~Login();
};

