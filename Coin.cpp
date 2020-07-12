#include "Coin.h"

Coin::Coin(const Coin& other) // constructor copiere
{
	this->value = other.value;
	this->no_of_coins = other.no_of_coins;
}

double Coin::get_value() const // returneaza tipul monedei
{
	return this->value;
}

void Coin::set_value(double _value) // seteaza tipul monedei
{
	this->value = _value;
}// nu stiu daca ar trebui sa am asa ceva dar ok

Coin& Coin::operator=(const Coin& other) // operator de egalare - copiere
{
	this->value = other.value;
	return *this;
}

bool Coin::operator==(const Coin& other) // operator de comparare 
{
	return (this->value == other.value);
}

int Coin::get_number() const // returneaza numarul de monede al unei monezi
{
	return this->no_of_coins;
}

void Coin::set_number(int _number) // seteaza numarul de monede
{
	this->no_of_coins = _number;
}
