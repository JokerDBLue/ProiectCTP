#include "TesteCosCumparaturi.h"
#include "CosCumparaturi.h"
#include <cassert>
void testeCosCumparaturi()
{
	Bilet b1(2.5, 1, 40);
	Bilet b2(4, 2, 50);
	Bilet b3(5, 3, 60);

	vector<Bilet> bb;
	bb.push_back(b1);
	bb.push_back(b2);
	bb.push_back(b3);

	vector<int> ca;
	ca.push_back(2);
	ca.push_back(4);
	ca.push_back(1);

	vector<float> pr;
	pr.push_back(2.5);
	pr.push_back(4);
	pr.push_back(5);

	CosCumparaturi cc(bb, ca, pr);
	Bilet b4(4, 6, 90);
	cc.adaugaInCos(b4, 2);
	assert(cc.getCant().size() == 3);
	assert(cc.getB().size() == 3);
	//assert(cc.getPret().size() == 3);
	assert(cc.costTotal()==31.5);
	assert(cc.getPret(1)==24);
	cc.stergeElem(0);
	assert(cc.getCant().size() == 2);
	assert(cc.getB().size() == 2);
	//assert(cc.getPret().size() == 2);
	assert( cc.costTotal()==29);
	cc.changeCant(1, 2);
	assert(cc.costTotal()==34);

}
