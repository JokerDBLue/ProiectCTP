#include "TesteLogin.h"
#include "Login.h"
#include <cassert>

void testeLogin()
{
	Login l;
	l.ReadUseri("testeLogin.txt");
	assert(l.VerifyLogin("Maria", "1234") == -1);
	assert(l.VerifyLogin("Ronal", "Yup") == 1);
	l.Register("Andreiusca", "lime", "3456", "345", "testeLogin.txt");
	

}
