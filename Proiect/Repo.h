#pragma once
#include <iostream>
#include <vector>
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
	bool existance(const T t);
	//void readFromFile(string file_name);
	//void addToFile(string file_name);
	vector<T> getAll();
	int getSize();
	void dltElem(int i);
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
	return v[i];
}

template <class T> bool Repo<T>::existance(const T t) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == t)
			return true;
	}
	return false;
}

template <class T> int Repo<T>::getSize() {
	return v.size();
}

template <class T> void Repo<T>::dltElem(int i) {
	this->v.erase(v.begin() + i);
}

template <class T> ostream & operator<< <>(ostream & os, const Repo<T>  r) {
	for (size_t i = 0; i < r.v.size(); i++)
		os << r.v[i] << endl;
	os << endl;
	return os;
}