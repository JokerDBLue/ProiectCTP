// Proiect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RepoFile.h"
#include "CosCumparaturi.h"
using namespace std;

int main()
{
	RepoFile<Bilet> rfb;
	rfb.addElem(Bilet(30.5, 20, 30));
	cout << rfb.getElem(0);
	/*
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
    */ 
}

