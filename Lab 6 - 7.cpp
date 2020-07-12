#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "Tester.h"
#include "ServiceCoin.h"
#include "Console.h"

int main()
{
	{
		//teste
		Tester tester;
		tester.test_produs();
		tester.test_repo();
		tester.test_service();
		tester.test_coin();
		tester.test_repo_coin();
		std::cout << "All good!\n";

		Repo<Produs> repository_produs;
		RepoFile<Produs> repository_produs_file("prajituri.txt");
		RepoCoinFile reposiotry_coin_file("coins.txt");

		RepoFile<Produs> repository_produs_buffer_file("buffer_prajituri.txt");
		RepoCoinFile reposiotry_coin_buffer_file("buffer_coins.txt");

		ValidatorCoin validator_coin;
		ValidatorProdus validator_produs;

		ServiceProdus service_produs = ServiceProdus(repository_produs_file, validator_produs);
		ServiceCoin service_coin = ServiceCoin(reposiotry_coin_file, validator_coin);
		ServiceCoin service_coin_buffer = ServiceCoin(reposiotry_coin_buffer_file, validator_coin);
		ServiceProdus service_produs_buffer = ServiceProdus(repository_produs_buffer_file, validator_produs);

		Console console = Console(service_produs, service_coin, service_produs_buffer, service_coin_buffer);

		console.run();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
