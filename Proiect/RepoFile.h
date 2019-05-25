#pragma once
#include <fstream>
#include "User.h"
#include "Autobuz.h"
#include "Repo.h"

template <class T> class RepoFile : public Repo<T>
{
public:
	RepoFile();
	RepoFile(vector<T> v);
	RepoFile(const RepoFile<T>& rf);
	void readFromFile(string file_name);
	void addToFile(string file_name);
	~RepoFile();
};

template <class T> RepoFile<T>::RepoFile() :Repo<T>() { }

template <class T> RepoFile<T>::RepoFile(vector<T> v) :Repo<T>(v){ }

template <class T> RepoFile<T>::RepoFile(const RepoFile<T>& rf) :Repo<T>(rf){ }

template <class T> RepoFile<T>::~RepoFile(){ }