#include "TesteController.h"
#include "Controller.h"
#include <cassert>

void testController()
{
	Controller c;
	c.readAutobuze("testecitireAutobuze.txt");
	c.readBilete("testecitireBilete.txt");
	c.ReadUseri("testeRepoUser.txt");

	Repo<Autobuz> ra, ra1;
	Repo<Bilet> rb, rb1, rb2;
	ra.readFromFileAutobuz("testecitireAutobuze.txt");
	rb.readFromFileBilete("testecitireBilete.txt");

	assert(c.cuatareLinie("M31") == ra.getElem(0));
	ra1 = c.cautareAuto("Nemo", "Remo", "S-D");
	assert(ra1.getElem(0) == ra.getElem(0));
	rb1 = c.bileteValabile();
	rb2 = c.vizualizireInventar(0);
	assert(rb1.getElem(0) == rb.getElem(0));
}
