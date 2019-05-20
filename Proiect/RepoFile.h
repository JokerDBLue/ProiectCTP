#pragma once
#include <fstream>
#include "Repo.h"

template <class T> class RepoFile : public Repo<T>
{
private:
	vector<T> v;
public:
	RepoFile();
	RepoFile(vector<T> v);
	RepoFile(const RepoFile<T>&);
	void readFromFile(string file_name);
	void addToFile(string file_name);
	~RepoFile();
};

template <class T> RepoFile<T>::RepoFile() : Repo()
{
}

template <class T> RepoFile<T>::RepoFile(vector<T> v) : Repo(v)
{
}

template <class T> RepoFile<T>::RepoFile(const RepoFile<T>& rf) : Repo(rf)
{
}

template <class T> void RepoFile<T>::readFromFile(string file_name)
{
	/*int code, price;
	char nume[30];*/
	ifstream f(file_name);
	//this->d.clear();
	/*while () {
		Dulciuri e(name, code, price);
		this->d.push_back(e);
	}
	*/
	f.close();
}


template <class T> void RepoFile<T>::addToFile(string file_name)
{
	ofstream g(file_name);
	for (size_t i = 0; i < v.size(); i++) {
		g << v[i] << endl;
	}
	g.close();
}

template <class T> RepoFile<T>::~RepoFile()
{
}
