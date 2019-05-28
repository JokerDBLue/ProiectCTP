#include "CosCumparaturi.h"



CosCumparaturi::CosCumparaturi()
{
	this->b;
	this->cant;
	this->pret;
}

CosCumparaturi::CosCumparaturi(vector<Bilet> b, vector<int> cant, vector<float> pret)
{
	this->b = b;
	this->cant = cant;
	this->pret = pret;
}

CosCumparaturi::CosCumparaturi(const CosCumparaturi & cc)
{
	this->b = cc.b;
	this->cant = cc.cant;
	this->pret = cc.pret;
}

void CosCumparaturi::adaugaInCos(Bilet biletul, int c)
{
	//Date de intrare: biletul - tipul de bilet care cumparatorul doreste sa-l adauge
	//                 c - numarul de bilete(de tipul precizat in "biletul") adaugate
	//Precizare: Daca acel tip de bilete deja exista in cos, atunci doar se va schimba cantitatea aduagand "c"
	int sf = 0;
	for (size_t i = 0; i < b.size(); i++)
	{
		if (b[i] == biletul)
		{
			changeCant(i, cant[i] + c);
			sf = 1;
		}
	}
	if (sf == 0)
	{
		b.push_back(biletul);
		cant.push_back(c);
		pret.push_back(biletul.getPret() * c);
	}
}

void CosCumparaturi::stergeElem(int i)
{
	//Sterge elementul de pe o anumita pozitie(i) de pe lista de cumparaturi
	b.erase(b.begin() + i);
	cant.erase(cant.begin() + i);
	pret.erase(pret.begin() + i);
}

void CosCumparaturi::changeCant(int i, int newCant)
{
	//Schimba cantitate unui element de pe o anumita pozitie
	//Date de intrare: i - pozitia elementului;
	//                 newCant - noua cantitate;
	if (newCant == 0)
		stergeElem(i);
	else
	{
		cant[i] = newCant;
		pret[i] = newCant * b[i].getPret();
	}
}

float CosCumparaturi::costTotal()
{
	//Calculeaza costul total din cosul de cumparaturi
	float total = 0;
	for (size_t i = 0; i < pret.size(); i++) {
		total += pret[i];
	}
	return total;
}

float CosCumparaturi::getPret(int i)
{
	return pret[i];
}


CosCumparaturi::~CosCumparaturi()
{
	this->b.clear();
	this->cant.clear();
	this->pret.clear();
}

ostream & operator<<(ostream & os, const CosCumparaturi cc)
{
	float total = 0;
	for (size_t i = 0; i < cc.b.size(); i++)
	{
		os << i << ". " << cc.b[i] << "x" << cc.cant[i] << " = " << cc.pret[i] <<endl;
		total += cc.pret[i];
	}
	os << "                                            Total = " << total;
	return os;
}
