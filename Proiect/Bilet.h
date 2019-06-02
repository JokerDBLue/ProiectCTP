#pragma once
#include <iostream>
using namespace std;

class Bilet
{
protected:
	float pret;
	int zona;
	int valabilitate;
public:
	Bilet();
	Bilet(float pret, int zona, int valabilitate);
	Bilet(const Bilet &b);
	float getPret();
	int getZona();
	int getValabilitate();
	void setPret(float p);
	void setZona(int z);
	void setValabilitate(int v);
	bool operator==(const Bilet &b);
	Bilet operator=(const Bilet &b);
	friend ostream &operator<<(ostream& os, const Bilet &b);

	~Bilet();
};