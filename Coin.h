#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

/*
Defineste un obiect de tip Coin.
*/
class Coin
{
private:
	double value; // are rol de id, este egala cu valoarea unei monede
	int no_of_coins; // intreg, trebuie sa fie mai mare ca 0, numarul de monede existente cu acea valoare (acel tip)
public:
	Coin() : value{ 0.0 }, no_of_coins{0}{}; // constructor implicit
	Coin(double _value, int _no_of_coins) : value{ _value }, no_of_coins{ _no_of_coins }{}; // constructor explicit 
	Coin(const Coin&); // constructor de copiere
	~Coin() {}; // destructor

	double get_value() const; // returneaza valoarea unei monede
	int get_number() const; // returneaza numarul de monede existente
	void set_value(double _value); // seteaza valoarea unei monede
	void set_number(int _number); // seteaza numarul de monede
	Coin& operator=(const Coin&); 
	bool operator==(const Coin&);

	friend ostream& operator<<(ostream& os, const Coin& _coin)
	{
		os << "      " << _coin.value << " " << _coin.no_of_coins;
		return os;
	}

	friend istream& operator>>(istream& is, Coin& _coin)
	{
		is >> _coin.value >> _coin.no_of_coins;
		return is;
	}

};