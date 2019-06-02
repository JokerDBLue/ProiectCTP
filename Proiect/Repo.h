#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "Autobuz.h"
using namespace std;

template <class T> class Repo {
protected:
	vector<T> v;
public:
	Repo();
	Repo(vector<T> v);
	Repo(const Repo<T>&);
	virtual ~Repo();
	void addElem(T);
	T getElem(int i);
	vector<T> getAll();
	int getSize();
	void dltElem(int i);
	int existenta(const T& t);
	//functii intermediare pt User
	void addInCos(int nrUser, Bilet b, int nr);
	void stergeBilet(int nrUser, int nrBilet);
	void schimbaCant(int nrUser, int nrBilet, int newCant);
	void golireCos(int nrUser);


	void readFromFileUseri(string file_name);
	void readFromFileAutobuz(string file_name);
	void readFromFileBilete(string file_name);
	void addusertofile(string filename);
	friend ostream & operator<< <>(ostream & os, const Repo<T>  r);
};



template <class T> Repo<T>::Repo() {
	this->v;
}

template <class T> Repo<T>::Repo(vector<T> v) {
	this->v = v;
}
template <class T> Repo<T>::Repo(const Repo<T> & r) {
	this->v = r.v;
}

template <class T> Repo<T>::~Repo() {
	this->v.clear();
}

template <class T> void Repo<T>::addElem(T el) {
	this->v.push_back(el);
}

template <class T> vector<T> Repo<T>::getAll() {
	return v;
}

template <class T> T Repo<T>::getElem(int i) {
	return v.at(i);
}

template <class T> int Repo<T>::getSize() {
	return v.size();
}

template <class T> void Repo<T>::dltElem(int i) {
	this->v.erase(v.begin() + i);
}

template <class T> int Repo<T>::existenta(const T& t) {
	//Date de intreare: t - constanta care reprezinta o clasa
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == t)
			return i; // Returneaza pozitia itemului dorit
	}
	return -1; // In acset caz nu exista nici un astfel de item
}

template <class T> void Repo<T>::addInCos(int nrUser, Bilet b, int nr) {
	this->v[nrUser].addInCos(b,nr);
}

template <class T> void Repo<T>::stergeBilet(int nrUser, int nrBilet) {
	this->v[nrUser].stergeBilet(nrBilet);
}

template <class T> void Repo<T>::schimbaCant(int nrUser, int nrBilet, int newCant) {
	this->v[nrUser].schimbaCant(nrBilet, newCant);
}

template <class T> void Repo<T>::golireCos(int nrUser)
{
	this->v[nrUser].cumparare();
}

template <class T> void Repo<T>::readFromFileUseri(string file_name) {
	ifstream f(file_name);
	while (f.good()) {
		string user, parola, rep, codspate, cod;
		int nr, zona, valabilitate;
		float pret, balans;
		getline(f, user, ','); // citesc user-ul
		getline(f, parola, ','); // citesc parola
		getline(f, rep, ','); nr = stoi(rep);// citesc nr de bilete din user
		vector<Bilet> b; // vector de bilete
		for (int i = 0; i < nr; i++)
		{
			getline(f, rep, ','); pret = stof(rep); // citeste pret
			getline(f, rep, ','); zona = stoi(rep);
			getline(f, rep, ','); valabilitate = stoi(rep);
			b.push_back(Bilet(pret, zona, valabilitate));
		}
		getline(f, cod, ','); //cout << cod << endl;
		getline(f, codspate, ','); //cout << codspate << endl;
		getline(f, rep); balans = stof(rep);  //cout << rep << " " << balans;
		v.push_back(User(cod, codspate, balans, user, parola, b));
		b.clear();
	}
	f.close();
}

template <class T> void Repo<T>::readFromFileAutobuz(string file_name) {

	ifstream f(file_name);
	int n = 0, zona = 0;
	string s = "", numar = "", zi = "";
	getline(f, numar);
	getline(f, s); zona = stoi(s);
	getline(f, zi);
	getline(f, s); n = stoi(s);
	vector <string> r;

	for (int i = 0; i < n; i++)
	{
		getline(f, s, ',');
		r.push_back(s);
	}


	vector<vector<string> > o;
	vector<string> oo;

	while (!f.eof())
	{
		oo.clear();
		for (int i = 0; i < n; i++)
		{
			getline(f, s, ',');
			oo.push_back(s);

		}
		o.push_back(oo);
	}

	v.push_back(Autobuz(zona, numar, zi, o, r));
	oo.clear();
	f.close();
}

template <class T> void Repo<T>::readFromFileBilete(string file_name) {


	ifstream f(file_name);

	float pret;
	int valabilitate, zona;
	while (f >> pret >> zona >> valabilitate)
	{
		Bilet w(pret, zona, valabilitate);
		this->v.push_back(w);
	}
	f.close();
}

template<class T> void Repo<T>::addusertofile(string filename)
{
	ofstream g(filename);

	for (size_t i = 0; i < v.size() - 1; i++)
	{
		g << v[i].GetUser() << "," << v[i].GetParola() << ",";
		vector<Bilet> j;
		j = v[i].inventar();
		g << j.size() << ",";
		for (size_t k = 0; k < j.size(); k++)
			g << j[k].getPret() << "," << j[k].getValabilitate() << "," << j[k].getZona() << ",";
		g << v[i].GetCod() << "," << v[i].GetCodSpate() << ", " << v[i].GetBalans() << endl;
	}
	size_t i = v.size() - 1;
	g << v[i].GetUser() << "," << v[i].GetParola() << ",";
	vector<Bilet> j;
	j = v[i].inventar();
	g << j.size() << ",";
	for (size_t k = 0; k < j.size(); k++)
		g << j[k].getPret() << "," << j[k].getValabilitate() << "," << j[k].getZona() << ",";
	g << v[i].GetCod() << "," << v[i].GetCodSpate() << ", " << v[i].GetBalans();
	g.close();

}

template <class T> ostream & operator<< <>(ostream & os, const Repo<T>  r) {
	for (size_t i = 0; i < r.v.size(); i++)
		os << r.v[i] << endl;
	os << endl;
	return os;
}