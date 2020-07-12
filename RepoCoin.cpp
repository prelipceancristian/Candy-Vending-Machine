#include "RepoCoin.h"

/*
Adauga(creeaza) un obiect de tip Coin in repository
Input:
	-key: int, cheia unica a obiectului
	-elem: elementul de tip T transmis prin referinta
Output:
	-
*/
void RepoCoin::create_new_coin(Coin coin)
{
	auto it = this->elems.find(coin.get_value());
	if (it != this->elems.end())
		throw RepoException("Exista deja o moneda de acest tip!\n");
	this->elems.insert({ coin.get_value(), coin});
}

/*
Ofera toate elementele de tip Coin din repository.
Input:
	-
Output:
	-all: vector de elemente de tipul abstract T cu toate elementele stocate.
*/
vector<Coin> RepoCoin::get_all()
{
	vector<Coin> all;
	std::for_each(this->elems.begin(), this->elems.end(), [&all](const auto& elem) {all.push_back(elem.second); });
	return all;
}

/*
Ofera numarul de monede ale unui tip de moneda din repository sau lanseaza o exceptie daca nu exista
Input:
	-coin: Coin, moneda cautata
Output:
	-numarul de monede de acel tip
*/

int RepoCoin::get_coin_quantity(Coin coin)
{
	auto it = this->elems.find(coin.get_value());
	if (it == this->elems.end())
		throw RepoException("Nu exista o moneda de acest tip!\n");
	return (*it).second.get_number(); // nu stiu daca vreau functia sa faca asta
}

/*
Functia adauga un numar monede in RepoCoin.
Input:
	-coin: Coin, tipul de moneda la care se adauga numarul suplimentar
	-quantity: int, cantitatea de monede de adaugat
Output:
	-
*/

void RepoCoin::add_coins(Coin coin, int quantity)
{
	auto it = this->elems.find(coin.get_value());
	if (it == this->elems.end())
		throw RepoException("Nu exista o moneda de acest tip!\n");
	int new_quantity = quantity + (*it).second.get_number();
	this->elems.erase(coin.get_value());
	Coin new_coin = Coin(coin.get_value(), new_quantity);
	this->elems.insert({ new_coin.get_value(), new_coin});
}

/*
Functia scoate un numar monede din RepoCoin.
Input:
	-coin: Coin, tipul de moneda din care se scoate numarul suplimentar
	-quantity: int, cantitatea de monede de luat, trebuie sa fie mai mic decat numarul de monede actual
Output:
	-
*/

void RepoCoin::remove_coins(Coin coin, int quantity)
{
	auto it = this->elems.find(coin.get_value());
	if (it == this->elems.end())
		throw RepoException("Nu exista o moneda de acest tip!\n");
	int new_quantity = (*it).second.get_number() - quantity;
	if (new_quantity < 0)
		throw RepoException("Nu se pot elimina atatea monede!\n");
	this->elems.erase(coin.get_value());
	Coin new_coin = Coin(coin.get_value(), new_quantity);
	this->elems.insert({ new_coin.get_value(), new_coin });
}

/*
Functia goleste monedele de un anumit tip.
Input:
	-coin:Coin, tipul de moneda pentru care se va goli numarul
Output:
	-
*/

void RepoCoin::empty_coin(Coin coin)
{
	auto it = this->elems.find(coin.get_value());
	if (it == this->elems.end())
		throw RepoException("Nu exista o moneda de acest tip!\n");
	(*it).second.set_number(0);
}

/*
Adauga(creeaza) un obiect de tip Coin in repository
Input:
	-key: int, cheia unica a obiectului
	-elem: elementul de tip T transmis prin referinta
Output:
	-
*/

void RepoCoinFile::create_new_coin(Coin coin)
{
	this->read_all_from_file(this->file_path);
	RepoCoin::create_new_coin(coin);
	this->write_all_to_file(this->file_path);
}

/*
Ofera toate elementele de tip Coin din repository.
Input:
	-
Output:
	-all: vector de elemente de tipul abstract T cu toate elementele stocate.
*/

vector<Coin> RepoCoinFile::get_all()
{
	this->read_all_from_file(this->file_path);
	return RepoCoin::get_all();
}

/*
Ofera numarul de monede ale unui tip de moneda din repository sau lanseaza o exceptie daca nu exista
Input:
	-coin: Coin, moneda cautata
Output:
	-numarul de monede de acel tip
*/

int RepoCoinFile::get_coin_quantity(Coin coin)
{
	this->read_all_from_file(this->file_path);
	return RepoCoin::get_coin_quantity(coin);
}

/*
Functia adauga un numar monede in RepoCoin.
Input:
	-coin: Coin, tipul de moneda la care se adauga numarul suplimentar
	-quantity: int, cantitatea de monede de adaugat
Output:
	-
*/

void RepoCoinFile::add_coins(Coin coin, int quantity)
{
	this->read_all_from_file(this->file_path);
	RepoCoin::add_coins(coin, quantity);
	this->write_all_to_file(this->file_path);
}

/*
Functia scoate un numar monede din RepoCoin.
Input:
	-coin: Coin, tipul de moneda din care se scoate numarul suplimentar
	-quantity: int, cantitatea de monede de luat, trebuie sa fie mai mic decat numarul de monede actual
Output:
	-
*/

void RepoCoinFile::remove_coins(Coin coin, int quantity)
{
	this->read_all_from_file(this->file_path);
	RepoCoin::remove_coins(coin, quantity);
	this->write_all_to_file(this->file_path);
}

/*
Functia goleste monedele de un anumit tip.
Input:
	-coin:Coin, tipul de moneda pentru care se va goli numarul
Output:
	-
*/

void RepoCoinFile::empty_coin(Coin coin)
{
	this->read_all_from_file(this->file_path);
	RepoCoin::empty_coin(coin);
	this->write_all_to_file(this->file_path);
}

/*
Functia sterge complet o anumita moneda.
Input:
	-coin: Coin, moneda de sters
Output:
	-
*/

void RepoCoin::delete_coin(Coin coin)
{
	auto it = this->elems.find(coin.get_value());
	if (it == this->elems.end())
		throw RepoException("Nu exista o moneda cu aceasta valoare");
	this->elems.erase(coin.get_value());
}

/*
Functia sterge complet o anumita moneda.
Input:
	-coin: Coin, moneda de sters
Output:
	-
*/


void RepoCoinFile::delete_coin(Coin coin)
{
	this->read_all_from_file(this->file_path);
	RepoCoin::delete_coin(coin);
	this->write_all_to_file(this->file_path);
}

/*
Functia determina suma tuturor monedelor din repository.
Input:
	-
Output:
	-sum: int, suma monedelor
*/

double RepoCoin::get_sum()
{
	double sum = 0;
	std::for_each(this->elems.begin(), this->elems.end(), [&sum](const auto& elem) {sum += elem.first * elem.second.get_number(); });
	return sum;
}

/*
Functia determina suma tuturor monedelor din repository.
Input:
	-
Output:
	-sum: int, suma monedelor
*/

double RepoCoinFile::get_sum()
{
	this->read_all_from_file(this->file_path);
	double sum = RepoCoin::get_sum();
	return sum;
}

/*
Functia goleste toate monedele din repository;
Input:
	-
Output:
	-
*/

void RepoCoin::empty_all()
{
	for (auto it = this->elems.begin(); it != this->elems.end(); ++it)
	{
		(*it).second.set_number(0);
	}
}

/*
Functia goleste toate monedele din repository;
Input:
	-
Output:
	-
*/

void RepoCoinFile::empty_all()
{
	this->read_all_from_file(this->file_path);
	RepoCoin::empty_all();
	this->write_all_to_file(this->file_path);
}