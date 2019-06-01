#include "Bilet.h"
#include <cassert>

void teste_Bilet()
{
	Bilet b(5, 4, 26);
	assert(b.getPret() == 5);
	assert(b.getZona() == 4);
	assert(b.getValabilitate() == 26);

	b.setPret(7);
	b.setZona(5);
	b.setValabilitate(14);
	assert(b.getPret() == 7);
	assert(b.getZona() == 5);
	assert(b.getValabilitate() == 14);

	Bilet c(5, 4, 26);
	//assert(b == c);
	c.setValabilitate(5);
	b = c;
	assert(b.getValabilitate() == 5);

}