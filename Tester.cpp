#include "Tester.h"
#include "ServiceProdus.h"
#include "ValidatorProdus.h"
#include "Coin.h"
#include "RepoCoin.h"
#include "ServiceCoin.h"

#include <cassert>
#include <iostream>

void Tester::test_produs()
{
	std::cout << "Teste domain...";
	Produs p1;
	assert(p1.get_cod() == -1);
	assert(p1.get_nume() == "");
	assert(p1.get_pret() == 0.0);

	Produs p2{1, "covrig", 1.5};
	assert(p2.get_cod() == 1);
	assert(p2.get_nume() == "covrig");
	assert(p2.get_pret() == 1.5);

	Produs p3{ p2 };
	assert(p3.get_cod() == p2.get_cod());
	assert(p3.get_nume() == p2.get_nume());
	assert(p3.get_pret() == p2.get_pret());

	p3.set_pret(2.2);
	p3.set_nume("chec");

	assert(p3.get_cod() == p2.get_cod());
	assert(p3.get_nume() != p2.get_nume());
	assert(p3.get_pret() != p2.get_pret());
	assert(p3.get_nume() == "chec");
	assert(p3.get_pret() == 2.2);

	p3 = p2;
	assert(p3.get_cod() == p2.get_cod());
	assert(p3.get_nume() == p2.get_nume());
	assert(p3.get_pret() == p2.get_pret());

	assert(p3 == p2);
	assert(p1 != p2);

	//std::cin >> p2;
	//std::cout << p2;

	Produs* pp = new Produs;
	delete pp;

	std::cout << "Ok!\n";
}

void Tester::test_repo()
{
	std::cout << "Teste repo...";

	Repo<int> repo_int;
	repo_int.add(1, 36);
	repo_int.add(2, 14);
	repo_int.add(3, 5);
	repo_int.add(4, 13);

	assert(repo_int.find(1) == 36);
	assert(repo_int.find(2) == 14);
	assert(repo_int.find(3) == 5);
	assert(repo_int.find(4) == 13);

	vector<int> v1 = { 36, 14, 5, 13 };
	assert(repo_int.get_all() == v1);

	repo_int.update(3, 21);
	//std::cout << repo_int.cauta_elem(3);
	assert(repo_int.find(3) == 21);

	repo_int.remove(4);
	v1 = { 36, 14, 21 };
	assert(v1 == repo_int.get_all());

	std::cout << "Ok!\n";
}

void Tester::test_service()
{
	std::cout << "Teste service...";

	Repo<Produs> repository_produs;
	ValidatorProdus validator_produs;
	ServiceProdus service_produs{ repository_produs, validator_produs };
	service_produs.adauga_produs(1, "ecler", 5.5);
	service_produs.adauga_produs(2, "donut", 21);

	Produs p1 = Produs(1, "ecler", 5.5);
	Produs p2 = Produs(2, "donut", 21);
	vector<Produs> v1 = {p1, p2};
	assert(v1[0] == service_produs.get_all()[0]);
	assert(v1[1] == service_produs.get_all()[1]);

	service_produs.update_produs(1, "clatita", 20);
	//std::cout << service_produs.get_all()[1];
	p1.set_nume("clatita");
	p1.set_pret(20);
	assert(p1 == service_produs.get_all()[1]);

	service_produs.delete_produs(2);
	v1.pop_back();
	assert(v1[0] == service_produs.get_all()[0]);
	std::cout << "Ok\n";
}

void Tester::test_coin()
{
	std::cout << "Teste coin...";
	Coin c1;
	assert(c1.get_value() == 0.0);
	Coin c2 = Coin(0.5, 2);
	assert(c2.get_value() == 0.5);
	assert(c2.get_number() == 2);
	Coin c3 = c2;
	assert(c3.get_value() == 0.5);
	Coin c4;
	c4 = c2;
	assert(c4.get_value() == 0.5);
	c4.set_value(0.7);
	assert(c4.get_value() == 0.7);
	std::cout << "Ok!\n";
}

void Tester::test_repo_coin()
{
	std::cout << "Teste repo coin...";

	RepoCoin repo = RepoCoin();
	Coin c1, c2 = Coin(0.5, 3);

	repo.create_new_coin(c1);
	assert(repo.get_all().size() == 1);
	repo.create_new_coin(c2);
	assert(repo.get_all().size() == 2);
	assert(repo.get_sum() == 1.5);
	repo.create_new_coin(Coin(0.1, 8));
	assert(repo.get_sum() == 2.3);
	assert(repo.get_coin_quantity(c2) == c2.get_number());
	repo.remove_coins(c2, 1);
	assert(repo.get_coin_quantity(c2) == c2.get_number() - 1);
	repo.empty_coin(c2);
	assert(repo.get_coin_quantity(c2) == 0);
	repo.add_coins(c2, 10);
	assert(repo.get_coin_quantity(c2) == 10);
	repo.delete_coin(c1);
	assert(repo.get_all().size() == 2);
	repo.empty_all();
	assert(repo.get_coin_quantity(c2) == 0);
	assert(repo.get_coin_quantity(Coin(0.1, 8)) == 0);
	repo.add_coins(c2, 5);
	repo.remove_coins(c2, 3);
	assert(repo.get_coin_quantity(c2) == 2);

	std::cout << "Ok\n";
}
