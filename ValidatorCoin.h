#pragma once
#include "Coin.h"
#include "ValidatorProdus.h"

/*
Defineste clasa ValidatorCoin pentru validarea obiectelor de tip Coin
*/

class ValidatorCoin
{
public:
	ValidatorCoin() {}; // constructor implicit
	~ValidatorCoin() {}; // destructor
	void validate(Coin); // functia de validare
};
