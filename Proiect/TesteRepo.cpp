#include "TesteRepo.h"
#include "Repo.h"
#include <cassert>

void testeRepo()
{
	Repo<Bilet> bil;
	Bilet b1(2.5, 1, 40);
	Bilet b2(4, 2, 50);
	Bilet b3(5, 3, 60);

	bil.addElem(b1);
	bil.addElem(b2);
	bil.addElem(b3);
	
	assert(bil.getSize() == 3);
	assert(bil.getElem(1) == b2);
	bil.dltElem(1);
	assert(bil.getElem(1) == b3);
	bil.~Repo();

	Repo<Autobuz> autob;
	vector <string > r;
	r.push_back("Memo");
	r.push_back("Spitalul de copii");
	r.push_back("Fabrica de bere");

	vector<vector<string> > o;

	vector<string> o1;
	o1.push_back("14:23");
	o1.push_back("15:45");
	o1.push_back("16:78");

	vector<string> o2;
	o2.push_back("11:23");
	o2.push_back("95:45");
	o2.push_back("16:78");

	o.push_back(o1);
	o.push_back(o2);


	Autobuz a1(1, "24B", "marti", o, r);
	
	vector <string > r1;
	r1.push_back("Remo");
	r1.push_back("Spital");
	r1.push_back("Fabrica");

	vector<vector<string> > w;

	vector<string> l1;
	l1.push_back("14:00");
	l1.push_back("15:00");
	l1.push_back("16:00");

	vector<string> l2;
	l2.push_back("11:00");
	l2.push_back("95:00");
	l2.push_back("16:00");

	w.push_back(l1);
	w.push_back(l2);


	Autobuz a2(2, "M26", "vineri", w, r1);

	autob.addElem(a1);
	autob.addElem(a2);

	//assert(autob.getElem(1) == a2);
	autob.dltElem(0);
	//assert(autob.getElem(0) == a2);
	assert(autob.existenta(a2) == 0);
	assert(autob.getSize() == 1);
	autob.~Repo();

	Repo<User> us;
	vector<Bilet> bb;
	bb.push_back(b1);
	bb.push_back(b2);
	bb.push_back(b3);
	assert(bb[0] == b1);

	User u1("78654", "345", 234.56, "Mariuca", "floricelepecampii", bb);

	vector<Bilet> bbb;
	bb.push_back(b1);
	bb.push_back(b2);
	bb.push_back(b3);

	User u2("5677", "566", 12.09, "Alin", "kaname", bbb);

	us.addElem(u1);
	us.addElem(u2);
	us.addusertofile("testeRepouser.txt");
	us.existenta(u2);

	Repo<Bilet> z;
	z.readFromFileBilete("testecitireBilet.txt");
	assert(z.getElem(0).getPret() == 3);
	assert(z.getElem(0).getValabilitate() == 6);
	assert(z.getElem(0).getZona() == 30);
	assert(z.getSize() == 3);
	z.dltElem(1);
	assert(z.getSize() == 2);

	Repo<Autobuz> y;
	y.readFromFileAutobuz("testecitireAutobuze.txt");
	assert(y.getElem(0).getNumar() == "M31");
	assert(y.getElem(0).getZi() == "S-D");
	assert(y.getElem(0).getZona() == 2);
	vector <string> rr;
	rr = y.getElem(0).getRuta();
	assert(y.getElem(0).getRuta() == rr);
	vector<vector<string> >  orr;
	orr = y.getElem(0).getOrar();
	assert(y.getElem(0).getOrar() == orr);
	assert(y.getSize() == 1);

	r.clear();
	o1.clear();
	o.clear();
	w.clear();
	r1.clear();
	l1.clear();
	l2.clear();
	rr.clear();
	orr.clear();

}
