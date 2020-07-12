#pragma once
#include "RepoCoin.h"
#include "ValidatorCoin.h"

/*
Defineste un obiect de tip ServiceCoin care se ocupa cu operatiile logice pe un container de elemente de tip Coin.
*/
class ServiceCoin
{
private:
	RepoCoin& repository_coin; // container pentru obiecte de tip coin
	ValidatorCoin validator_coin; // validator pentru obiectele de tip Coin create in service
public:
	ServiceCoin(RepoCoin& _repository_coin, ValidatorCoin _validator_coin) : repository_coin{ _repository_coin }, validator_coin{ _validator_coin } {}; // constructor explicit
	~ServiceCoin() {}; // destructor
	void create_coin(double);
	vector<Coin> get_all();
	void empty_coin(double);
	void add_coins(double, int);
	void remove_coins(double, int);
	void delete_coin(double);
	double get_sum();

	bool calculate_rest(vector<Coin>, double);
	void add_buffer(vector<Coin>);
	void clear_repo();
	void remove_coins_for_rest(double);
};