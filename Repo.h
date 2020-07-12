#pragma once
#include "Produs.h"
#include <unordered_map>
#include <algorithm>
#include <vector>

#include <fstream>
#include <iterator>

using std::ifstream;
using std::ofstream;

using std::unordered_map;
using std::vector;

/*
Defineste un obiect de tip RepoException care se va ocupa cu exceptiile lansate din Repository
*/

class RepoException
{
private:
	string msg; //  mesajul transmis
public:
	RepoException(const string& _msg) : msg{ _msg } {}; // constructor explicit
	~RepoException() {}; // destructor
	const string& get_message() // functia de returnare a mesajului erorii
	{
		return this->msg;
	}
};

/*
Defineste interfata unui obiect de tip Repo pe un tip abstract de obiecte T 
IRepo este o clasa cu metode pur virtuale
*/

template <typename T>
class IRepo
{
public:
	virtual void add(int key, const T&) = 0;
	virtual const T& find(int key) = 0;
	virtual void update(int key, const T& elem) = 0;
	virtual T remove(int key) = 0;
	virtual vector<T> get_all() = 0;
	virtual void clear_all() = 0;
};


/*
Defineste un obiect de tip Repo care mosteneste metodele virtuale ale clasei IRepo si confera o implementare concreta 
*/

template <typename T> 
class Repo: public IRepo<T>
{
protected:
	unordered_map<int, T>elems; 
public:
	Repo() {};
	~Repo() {};
	virtual void add(int key, const T&) override;
	virtual const T& find(int key) override;
	virtual void update(int key, const T& elem) override;
	virtual T remove(int key) override; 
	virtual vector<T> get_all() override;
	virtual void clear_all() override;
};

/*
Adauga un obiect de tip abstract T in repository
Input:
	-key: int, cheia unica a obiectului
	-elem: elementul de tip T transmis prin referinta
Output:
	-
*/
template <typename T>
void Repo<T>::add(int key, const T& elem)
{
	auto it = this->elems.find(key);
	if (it != this->elems.end())
	{
		throw RepoException("Elementul cu id-ul dat exista deja!\n");
	}
	this->elems.insert({ key, elem });
}

/*
Cauta un obiect de tip T dupa id, daca il gaseste il returneaza, altfel lanseaza o eroare RepoException.
Input:
	-key: int, cheia unica a obiectului cautat
Output:
	-obiectul de tip T din repository identificat cu cheia data
*/

template <typename T>
const T& Repo<T>::find(int key)
{
	auto it = this->elems.find(key);
	if (it == this->elems.end())
	{
		throw RepoException("Elementul cu id-ul dat nu exista!\n");
	}
	return (*it).second;
}

/*
Actualizeaza obiectul identificat dupa o anumita cheie cu un alt obiect.
Input:
	-key: int, cheia unica a obiectului de inlocuit
	-elem: obiectul cu care se va inlocui elementul cu cheia key
Output:
	-
*/

template <typename T>
void Repo<T>::update(int key, const T& elem)
{
	auto it = this->elems.find(key);
	if (it == this->elems.end())
	{
		throw RepoException("Elementul cu id-ul dat nu exista!\n");
	}
	this->elems.erase(key);
	this->elems.insert({ key, elem });
}

/*
Sterge obiectul cu o anumita cheie.
Input:
	-key: int, cheia unica a obiectului de sters
Output:
	-
*/

template <typename T>
T Repo<T>::remove(int key)
{
	auto it = this->elems.find(key);
	if (it == this->elems.end())
	{
		throw RepoException("Elementul cu id-ul dat nu exista!\n");
	}
	T elem = (*it).second;
	this->elems.erase(key);
	return elem;
}

/*
Ofera toate elementele de tip T din repository.
Input:
	-
Output:
	-all: vector de elemente de tipul abstract T cu toate elementele stocate.
*/

template <typename T>
vector<T> Repo<T>::get_all()
{
	vector<T> all;
	std::for_each(
		this->elems.begin(),
		this->elems.end(),
		[&all](const std::pair<int, T>& elem)
		{
			all.push_back(elem.second);
		}
	);
	return all;
}

/*
O "extensie" a unui Repository de elemente de tip T, RepoFile mosteneste Repo si poate citi si scrie elementele sale in fisiere.
*/

template <typename T>
class RepoFile : public Repo<T>
{
private:
	string file_path; // path ul catre fisierul de citire/scriere
	void read_all_from_file(string file_path) // functia de citire din fisier
	{
		this->elems.clear();
		ifstream ifstr(this->file_path);
		T p;
		while (ifstr >> p)
		{
			this->elems.insert({ p.get_cod(), p });
		}
	};
	void write_all_to_file(string file_path) // functia de scriere in fisier
	{
		ofstream ofstr(this->file_path);
		for (const std::pair<int, T>& p : this->elems)
		{
			ofstr << p.second << "\n";
		}
	};
public:
	RepoFile(string _file_path) : file_path{ _file_path }, Repo<T>() {};
	virtual void add(int key, const T&) override;
	virtual const T& find(int key) override;
	virtual void update(int key, const T& elem) override;
	virtual T remove(int key) override;
	virtual vector<T> get_all() override;
	~RepoFile() {};
	virtual void clear_all() override;            
};

/*
Adauga un obiect de tip abstract T in repository
Input:
	-key: int, cheia unica a obiectului
	-elem: elementul de tip T transmis prin referinta
Output:
	-
*/

template <typename T>
void RepoFile<T>::add(int key, const T& elem)
{
	this->read_all_from_file(this->file_path);
	Repo<T>::add(key, elem);
	this->write_all_to_file(this->file_path);
}

/*
Cauta un obiect de tip T dupa id, daca il gaseste il returneaza, altfel lanseaza o eroare RepoException.
Input:
	-key: int, cheia unica a obiectului cautat
Output:
	-obiectul de tip T din repository identificat cu cheia data
*/

template <typename T>
const T& RepoFile<T>::find(int key)
{
	this->read_all_from_file(this->file_path);
	return Repo<T>::find(key);
}

/*
Actualizeaza obiectul identificat dupa o anumita cheie cu un alt obiect.
Input:
	-key: int, cheia unica a obiectului de inlocuit
	-elem: obiectul cu care se va inlocui elementul cu cheia key
Output:
	-
*/

template <typename T>
void RepoFile<T>::update(int key, const T& elem)
{
	this->read_all_from_file(this->file_path);
	Repo<T>::update(key, elem);
	this->write_all_to_file(this->file_path);
}

/*
Sterge obiectul cu o anumita cheie.
Input:
	-key: int, cheia unica a obiectului de sters
Output:
	-
*/

template <typename T>
T RepoFile<T>::remove(int key)
{
	T p;
	this->read_all_from_file(this->file_path);
	p = Repo<T>::remove(key);
	this->write_all_to_file(this->file_path);
	return p;
}

/*
Ofera toate elementele de tip T din repository.
Input:
	-
Output:
	-all: vector de elemente de tipul abstract T cu toate elementele stocate.
*/

template <typename T>
vector<T> RepoFile<T>::get_all()
{
	this->read_all_from_file(this->file_path);
	return Repo<T>::get_all();
}

/*
Sterge toate elementele din repository.
Input:
	-
Output:
	-
*/
template <typename T>
void Repo<T>::clear_all()
{
	this->elems.clear();
}

/*
Sterge toate elementele din repository.
Input:
	-
Output:
	-
*/

template <typename T>
void RepoFile<T>::clear_all()
{
	this->read_all_from_file(this->file_path);
	Repo<T>::clear_all();
	this->write_all_to_file(this->file_path);
}