#include "TesteAutobuz.h"
#include <cassert>
#include  "Autobuz.h"


void teste_Autobuz()
{

	vector<string> r;
	vector<vector<string> > o;

	r.push_back("Vivo!");
	r.push_back("Memo");
	r.push_back("Dorobanti");
	vector<string> o1;
	o1.push_back("08:19");
	o1.push_back("13:04");
	o1.push_back("15:44");

	o.push_back(o1);

	Autobuz a(1, "24", "Marti", o, r);
	assert(a.getZona() == 1);
	assert(a.getNumar() == "24");
	assert(a.getZi() == "Marti");
	assert(o[0][1] == "13:04");
	assert(r[2] == "Dorobanti");
	a.setNumar("24B");
	assert(a.getNumar() == "24B");
	a.setZi("Marti");
	assert(a.getZi() == "Marti");
	a.setZona(4);
	assert(a.getZona() == 4);





}
