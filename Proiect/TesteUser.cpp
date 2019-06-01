#include "TesteUser.h"
#include "User.h"
#include <cassert>

void testeUser()
{
	Bilet b1(2.5, 1, 40);
	Bilet b2(4, 2, 50);
	Bilet b3(5, 3, 60);

	vector<Bilet> bb;
	bb.push_back(b1);
	bb.push_back(b2);
	bb.push_back(b3);

	User u1("2576", "678", 89, "Ana", "mere", bb);
	assert(u1.GetBalans() == 89);
	assert(u1.GetParola() == "mere");
	assert(u1.GetUser() == "Ana");

}
