#include "TesteAutobuz.h"
#include <cassert>
#include  "Autobuz.h"


void teste_Autobuz()
{

	vector<string> r;
	vector<string> o;

	r.push_back("Vivo!");
	r.push_back("Memo");
	r.push_back("Dorobanti");

	o.push_back("08:19");
	o.push_back("13:04");
	o.push_back("15:44");

	Autobuz a(1, "24", "Vivo!-Iulius Mall", o, r);
	assert(a.getZona() == 1);
	assert(a.getNumar() == "24");
	assert(a.getCapete() == "Vivo!-Iulius Mall");
	assert(o[1] == "13:04");
	assert(r[2] == "Dorobanti");
	a.setNumar("24B");
	assert(a.getNumar() == "24B");
	a.setCapete("Piata 1 Mai - Bucium");
	assert(a.getCapete() == "Piata 1 Mai - Bucium");
	a.setZona(4);
	assert(a.getZona() == 4);





}