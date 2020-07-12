#pragma once
#include "Repo.h"
#include "Coin.h"	
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;


/*
Defineste interfata unui obiect de tip Repo pe obiecte de tip Coins
IRepoCoin este o clasa cu metode pur virtuale
*/
class IRepoCoin
{
public:
	virtual void create_new_coin(Coin) = 0;
	virtual vector<Coin> get_all() = 0;
	virtual int get_coin_quantity(Coin) = 0;
	//update
	virtual void add_coins(Coin, int) = 0;
	virtual void remove_coins(Coin, int) = 0;
	//delete
	virtual void empty_coin(Coin) = 0;
	virtual void delete_coin(Coin) = 0;
	virtual double get_sum() = 0;
	virtual void empty_all() = 0;
};

/*
Defineste un obiect de tip RepoCoin care mosteneste metodele virtuale ale clasei IRepoFile si confera o implementare concreta
*/
class RepoCoin: public IRepoCoin
{
protected:
	unordered_map<double, Coin> elems;
public:
	RepoCoin() {};
	~RepoCoin() {};
	virtual void create_new_coin(Coin) override;
	virtual vector<Coin> get_all() override;
	virtual int get_coin_quantity(Coin) override;
	//update
	virtual void add_coins(Coin, int) override;
	virtual void remove_coins(Coin, int) override;
	//delete
	virtual void empty_coin(Coin) override;
	virtual void delete_coin(Coin) override;
	virtual double get_sum() override;
	virtual void empty_all() override;
};

/*
O "extensie" a unui Repository de elemente de tip T, RepoFile mosteneste Repo si poate citi si scrie elementele sale in fisiere.
*/

class RepoCoinFile :public RepoCoin
{
private:
	string file_path; // path ul catre fisierul de citire/scriere
	void read_all_from_file(string file_path) // functia de citire din fisier
	{
		this->elems.clear();
		ifstream ifstr(file_path);
		Coin c;
		while (ifstr >> c)
		{
			this->elems.insert({ c.get_value(), c });
		}
	};
	void write_all_to_file(string file_path) // functia de scriere in fisier
	{
		ofstream ofstr(file_path);
		for (const std::pair<double, Coin>& c : this->elems)
		{
			ofstr << c.second << "\n";
		}
	};
public:
	RepoCoinFile(string _file_path) : file_path{ _file_path } {};
	~RepoCoinFile() {};
	void create_new_coin(Coin);
	//read
	vector<Coin> get_all() ;
	int get_coin_quantity(Coin);
	//update
	void add_coins(Coin, int);
	void remove_coins(Coin, int);
	//delete
	void empty_coin(Coin);
	void delete_coin(Coin);

	double get_sum();
	void empty_all();
};
