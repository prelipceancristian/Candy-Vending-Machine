#include "ValidatorCoin.h"

void ValidatorCoin::validate(Coin coin)
{
	if (coin.get_value() <= 0.0)
		throw ValidatorException("Valoarea monezii nu poate fi mai mica sau egala cu 0!");
}