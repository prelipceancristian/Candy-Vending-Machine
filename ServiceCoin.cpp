#include "ServiceCoin.h"
#include <map>
#include <iterator>

/*
Creeaza un nou obiect de tip Coin si il introduce in repository
Input:
	-_value: double, tipul de moneda
Output:
	-
*/

void ServiceCoin::create_coin(double _value)
{
	Coin c = Coin(_value, 0);
	this->validator_coin.validate(c);
	this->repository_coin.create_new_coin(c);
}

/*
Confera toate obiectele de tip Coin din repository
Input:
	-
Output:
	- un vector de elemente de tip Coin
*/

vector<Coin> ServiceCoin::get_all()
{
	return this->repository_coin.get_all();
}

/*
Goleste o moneda de un anumit tip
Input:
	-_value: double, tipul de moneda
*/

void ServiceCoin::empty_coin(double _value)
{
	Coin c = Coin(_value, 0);
	this->validator_coin.validate(c);
	this->repository_coin.empty_coin(c);
}

/*
Adauga un numar de monede la un tip de moneda
Input:
	-_value: double, tipul de moneda
	-_quantity: int, numarul de monede de adaguat
*/

void ServiceCoin::add_coins(double _value, int _quantity)
{
	Coin c{ _value, 0 };
	this->validator_coin.validate(c);
	this->repository_coin.add_coins(c, _quantity);
}

/*
Scoate un numar de monede de la un tip de moneda.
Input:
	-_value: double, tipul de moneda
	-_quantity: int, numarul de monede de scos
Output:
	-
*/

void ServiceCoin::remove_coins(double _value, int _quantity)
{
	Coin c{ _value, 0 };
	this->validator_coin.validate(c);
	this->repository_coin.remove_coins(c, _quantity);
}

/*
Sterge complet o anumita moneda.
Input:
	-_value: double, tipul de moneda
Output:
	-
*/

void ServiceCoin::delete_coin(double _value)
{
	Coin c = Coin(_value, 0);
	this->validator_coin.validate(c);
	this->repository_coin.delete_coin(c);
}

/*
Confera suma tuturor monedelor din repository
Input:
	-
Output:
	-double, suma monedelor din repository
*/

double ServiceCoin::get_sum()
{
	return this->repository_coin.get_sum();
}

/*
Determina daca se poate oferi rest cu un anumit set de monede
Input:
	-vec_coins: vector<Coin>, lista de monede de folosit in calcul
	-rest: double, restul de oferit
Output:
	-True daca se poate oferi rest, false altfel
*/

bool ServiceCoin::calculate_rest(vector<Coin> vec_coins, double rest)
{
	std::map<double, int> coins;
	vector<Coin> all = this->repository_coin.get_all();
	std::for_each(vec_coins.begin(), vec_coins.end(), [&coins, &vec_coins](const auto& elem) {coins[elem.get_value()] = elem.get_number(); });
	std::for_each(all.begin(), all.end(), [&coins, &all](const auto& elem) {coins[elem.get_value()] += elem.get_number(); });

	auto it = coins.end();
	while (it != coins.begin() && rest > 0)//ruleaza cat timp nu este la inceput si restul inca mai poate sa scada. Daca este la inceput sau restul e negativ, se opreste.
	{
		if (it == coins.end())
			it--;
		while ((*it).second > 0 && rest >= (*it).first)
		{
			rest = rest - (*it).first;
			(*it).second--;
		}
		it--;
		//std::cout << rest <<  " ";
	}
	if (rest == 0)
		return true;
	return false;
}

/*
Muta monedele dintr-un buffer in repository.
Input:
	-buffer: vector<Coin>, monedele de adaugat
Output:
	-
*/

void ServiceCoin::add_buffer(vector<Coin> buffer)
{
	//std::for_each(buffer.begin(), buffer.end(), [&buffer](const auto& elem) {this->repository_coin.add_coins(elem.get_value(), elem.get_number()); });
	for (unsigned int i = 0; i < buffer.size(); i++)
	{
		this->repository_coin.add_coins(buffer[i], buffer[i].get_number());
	}
	buffer.clear();
	//std::cout << "ok";
}

/*
Sterge toate elementele din repository
Input:
	-
Output:
	-
*/

void ServiceCoin::clear_repo()
{
	this->repository_coin.empty_all();
}

/*
Functia scoate monedele din repository pentru a conferi rest
Input:
	-rest:double, restul de scos din repository
Output:
	-
*/

void ServiceCoin::remove_coins_for_rest(double rest)
{
	vector<Coin> coins = this->repository_coin.get_all();
	auto it = coins.end();
	while (rest > 0)//ruleaza cat timp nu este la inceput si restul inca mai poate sa scada. Daca este la inceput sau restul e negativ, se opreste.
	{
		if (it == coins.end())
			it--;
		while ((*it).get_number() > 0 && rest >= (*it).get_value())
		{
			this->repository_coin.remove_coins((*it), 1);
			rest = rest - (*it).get_value();
			int old_number = (*it).get_number();
			(*it).set_number(old_number - 1);
		}
		it--;
		//std::cout << rest << " ";

	}
}