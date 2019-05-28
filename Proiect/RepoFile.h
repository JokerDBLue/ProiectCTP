#pragma once
#include <fstream>
#include "User.h"
#include "Autobuz.h"
#include "Repo.h"

template <class T> class RepoFile : public Repo<T>
{
private:
	vector<T> v;
public:
	RepoFile();
	RepoFile(vector<T> v);
	RepoFile(const RepoFile<T>& rf);
	void readFromFileUseri(string file_name);
	void readFromFileBilete(string file_name);
	void readFromFileAutobuze(string file_name);
	void addToFile(string file_name);
	~RepoFile();
};

template <class T> RepoFile<T>::RepoFile() :Repo<T>() { 
	this->v;
}

template <class T> RepoFile<T>::RepoFile(vector<T> v) :Repo<T>(v){ }

template <class T> RepoFile<T>::RepoFile(const RepoFile<T>& rf) :Repo<T>(rf){ }

template <class T> void RepoFile<T>::readFromFileUseri(string file_name) {
	ifstream f(file_name);
	string user , parola , rep ;
	int nr , zona , valabilitate ;
	float pret , balans ;
	getline(f, user);
	while (f.good()) {
		getline(f, user, ',');
		getline(f, parola, ',');
		getline(f, rep, ';'); nr = stoi(rep);
		for (int i = 0; i < nr - 1; i++)
		{
			getline(f, rep, ';'); pret = stof(rep);
			getline(f, rep, ';'); zona = stoi(rep);
			getline(f, rep, ';'); valabilitate = stoi(rep);
		}
		if (nr > 0)
		{
			getline(f, rep, ';'); pret = stof(rep);
			getline(f, rep, ';'); zona = stoi(rep);
			getline(f, rep, ','); valabilitate = stoi(rep);
		}
	}
	f.close();
}

template <class T> void RepoFile<T>::readFromFileBilete(string file_name) {
	cout << "another idea";
}

template <class T> void RepoFile<T>::readFromFileAutobuze(string file_name) {
	cout << "another idea";
}

template <class T> void RepoFile<T>::addToFile(string file_name) {
	//Aceasta operatie e doar pt clasa User
}

template <class T> RepoFile<T>::~RepoFile(){ 
	this->v.clear();
}