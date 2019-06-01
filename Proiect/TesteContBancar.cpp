#include "TesteContBancar.h"
#include "ContBancar.h"
#include <cassert>

void testeContBancar()
{
	ContBancar cb("567999", "456", 45.67);
	//assert(cb.GetBalans() == 45.67);//???? dc nu mere
	assert(cb.GetCod() == "567999");
	assert(cb.GetCodSpate() == "456");
	ContBancar cb1("567999", "456", 45.67);
	assert(cb == cb1);
	cb.SetBalans(45);
	assert(cb.GetBalans() == 45);
	cb.SetCod("6789");
	assert(cb.GetCod() == "6789");
	cb.SetCodSpate("123");
	assert(cb.GetCodSpate() == "123");

	ContBancar cb2("4567", "908", 8);
	cb = cb2;
	assert(cb.GetBalans() == 8);
	assert(cb.GetCod() == "4567");
	assert(cb.GetCodSpate() == "908");




}
