// Proiect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RepoFile.h"
#include "Controller.h"
#include "CosCumparaturi.h"
using namespace std;

void sometest() {
	vector<string> r;
	vector<string> o;

	r.push_back("Vivo!");
	r.push_back("Memo");
	r.push_back("Dorobanti");

	o.push_back("08:19");
	o.push_back("13:04");
	o.push_back("15:44");

	Autobuz a(1, "24", "Vivo!-Iulius Mall", o, r);
	Controller c;
	c.addAuto(a);
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> v2 = vector<int>(v1.begin() + 1, v1.end() - 0);
	c.ReadUseri();
}

int main()
{
	sometest();
	RepoFile<Bilet> rfb;
	rfb.addElem(Bilet(30.5, 20, 30));
	//cout << rfb.getElem(0);
	//Controller c;
	//User u;
	//u.SetUser("Vadim");
	//u.SetParola("444");
	//u.SetBalans(200);
	//u.SetCod("9000");
	//u.SetCodSpate("909");
	//c.addUser(u);
	//c.finalizarePlata("9000", "909", 200, 0);

	
	Bilet b1(30.5, 20, 30);
	Bilet b2(20.5, 42, 30);
	Bilet b3(30.5, 20, 30);
	CosCumparaturi cc;
	cc.adaugaInCos(b1, 5);
	cc.adaugaInCos(b2, 6);
	cout << cc << endl;
	cc.~CosCumparaturi();
	cc.adaugaInCos(b3, 2);
	cout << cc; 
}

