#include "Console.h"


/*
Preia user input-ul, il transmite catre service si prinde erorile pentru adaugarea produsului
Input:
	-
Output:
	-
*/
void Console::handle_add_produs()
{
	try
	{
		int cod;
		string nume;
		double pret;
		std::cout << "Introduceti codul produsului: ";
		std::cin >> cod;
		std::cout << "Introduceti numele produsului: ";
		std::cin >> nume;
		std::cout << "Introduceti pretul produsului: ";
		std::cin >> pret;
		this->service_produs.adauga_produs(cod, nume, pret);
		std::cout << "Succes\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Afiseaza toate produsele din service.
Input:
	-
Output:
	-
*/

void Console::handle_show_all()
{
	vector<Produs> all = this->service_produs.get_all();
	std::for_each(
		all.begin(),
		all.end(),
		[&all]
	(const auto& elem)
		{
			std::cout << elem << "\n";
		}
	);
}

/*
Afiseaza toate produsele din service ul pentru user, aka buffer.
Input:
	-
Output:
	-
*/

void Console::handle_show_all_shopper()
{
	vector<Produs> all = this->service_produs_buffer.get_all();
	std::for_each(
		all.begin(),
		all.end(),
		[&all]
	(const auto& elem)
		{
			std::cout << elem << "\n";
		}
	);
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru actualizarea produsului.
Input:
	-
Output:
	-
*/

void Console::handle_update_produs()
{
	try
	{
		int cod;
		string nume;
		double pret;
		std::cout << "Introduceti codul produsului: ";
		std::cin >> cod;
		std::cout << "Introduceti noul nume al produsului: ";
		std::cin >> nume;
		std::cout << "Introduceti noul pret al produsului: ";
		std::cin >> pret;
		this->service_produs.update_produs(cod, nume, pret);
		std::cout << "Succes\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru stergerea produsului.
Input:
	-
Output:
	-
*/
void Console::handle_delete_produs()
{
	try
	{
		int cod;
		std::cout << "Introduceti codul produsului de sters: ";
		std::cin >> cod;
		this->service_produs.delete_produs(cod);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Afiseaza meniul pentru funtionalitatile legate de produse.
Input:
	-
Output:
	-
*/

void Console::show_menu_produs()
{
	std::cout << "-- Meniu produse --\n";
	std::cout << "1. Adauga produs\n";
	std::cout << "2. Actualizeaza produs\n";
	std::cout << "3. Sterge produs\n";
	std::cout << "a. Afiseaza produse\n";
	std::cout << "x. Stop\n";
}

/*
Afiseaza meniul pentru functionalitatile legate de obiecte de tip Coin
Input:
	-
Output:
	-
*/

void Console::show_menu_coin()
{
	std::cout << "-- Meniu monede -- \n";
	std::cout << "1. Creeaza o noua moneda\n";
	std::cout << "2. Goleste o moneda\n";
	std::cout << "3. Adauga monede\n";
	std::cout << "4. Scoate monede\n";
	std::cout << "5. Sterge o moneda\n";
	std::cout << "6. Afiseaza suma tuturor monedelor\n";
	std::cout << "a. Afiseaza toate monedele\n";
	std::cout << "x. Stop\n";
}


/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru crearea unui obiect de tip Coin.
Input:
	-
Output:
	-
*/

void Console::handle_create_coin()
{
	try
	{
		double value;
		std::cout << "Introduceti valoarea monedei: ";
		std::cin >> value;
		this->service_coin.create_coin(value);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Afiseaza toate obiectele de tip Coin.
Input:
	-
Output:
	-
*/

void Console::handle_show_all_coins()
{
	vector<Coin> all = this->service_coin.get_all();
	std::for_each(
		all.begin(),
		all.end(),
		[&all]
	(const auto& elem)
		{
			std::cout << elem << "\n";
		}
	);
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru golirea unui obiect de tip Coin.
Input:
	-
Output:
	-
*/

void Console::handle_empty_coin()
{
	try
	{
		double value;
		std::cout << "Introduceti valoarea monedei: ";
		std::cin >> value;
		this->service_coin.empty_coin(value);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru adaugarea unui numar de monede la
un obiect de tip Coin
Input:
	-
Output:
	-
*/

void Console::handle_add_coins()
{
	try
	{
		double value;
		int quantity;
		std::cout << "Introduceti valoarea monedei: ";
		std::cin >> value;
		std::cout << "Introduceti numarul de monede de adaugat: ";
		std::cin >> quantity;
		this->service_coin.add_coins(value, quantity);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}


/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru adaugarea unui numar de monede la
un obiect de tip Coin intr-un buffer.
Input:
	-
Output:
	-
*/
void Console::handle_add_coins_shopper()
{
	try
	{
		double value;
		int quantity;
		std::cout << "Introduceti valoarea monedei: ";
		std::cin >> value;
		std::cout << "Introduceti numarul de monede de adaugat: ";
		std::cin >> quantity;
		this->service_coin_buffer.add_coins(value, quantity);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru scoaterea unui numar de monede dintr-un
un obiect de tip Coin
Input:
	-
Output:
	-
*/
void Console::handle_remove_coins()
{
	try
	{
		double value;
		int quantity;
		std::cout << "Introduceti valoarea monedei: ";
		std::cin >> value;
		std::cout << "Introduceti numarul de monede de luat: ";
		std::cin >> quantity;
		this->service_coin.remove_coins(value, quantity);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru stergerea unui obiect de tip Coin.
Input:
	-
Output:
	-
*/

void Console::handle_delete_coin()
{
	try
	{
		double value;
		std::cout << "Introduceti valoarea monedei: ";
		std::cin >> value;
		this->service_coin.delete_coin(value);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Se ocupa cu afisarea sumei monedelor din repo.
Input:
	-
Output:
	-
*/

void Console::handle_get_sum()
{
	std::cout << "Suma tuturor monedelor este " << this->service_coin.get_sum() << " lei\n";
}

/*
Se ocupa cu afisearea sumei monedelor din buffer.
Input:
	-
Output:
	-
*/

void Console::handle_get_sum_shopper()
{
	std::cout << "Suma tuturor monedelor este " << this->service_coin_buffer.get_sum() << " lei\n";
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru adaugarea unui produs in buffer ul de produse
Input:
	-
Output:
	-
*/

void Console::handle_add_produs_shopper()
{
	try
	{
		int cod;
		std::cout << "Introduceti codul produsului: ";
		std::cin >> cod;
		Produs test_prod = this->service_produs.find_produs(cod); // daca nu gaseste in lista de produse disponibile, lanseaza o eroare
		this->service_produs_buffer.adauga_produs(cod, test_prod.get_nume(), test_prod.get_pret()); //  daca exista duplicata da eroare
		std::cout << "Succes\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}

/*
Se ocupa cu actiunea de cumparare a produselor din lista de cumparaturi(buffer de produse) cu banii din buffer-ul de monede.
Input:
	-
Output:
	-
*/

void Console::handle_buy()
{
	double sum_coins = 0, sum_prods = 0, rest = 0;
	sum_coins = this->service_coin_buffer.get_sum();
	sum_prods = this->service_produs_buffer.get_sum();
	rest = sum_coins - sum_prods;
	//
	//std::cout << "restul este " << rest;
	if (rest < 0) // daca nu au fost suficienti bani introdusi
		std::cout << "Nu aveti fonduri suficiente pentru a efectua aceasta operatie\n";
	else
	{
		bool can_give_rest = this->service_coin.calculate_rest(this->service_coin_buffer.get_all(), rest); // verifica daca exista rest cu banii dati
		if (can_give_rest)
		{
			std::cout << "Exista rest pentru tranzactie. Procesez...\n";
			this->service_coin.add_buffer(this->service_coin_buffer.get_all()); // pune monedele din buffer in monetar
			this->service_coin_buffer.clear_repo(); // sterge monedele din buffer 
			this->service_produs_buffer.clear_repo();// sterge lista de cumparaturi
			this->service_coin.remove_coins_for_rest(rest); // sterge monedele corespunzatoare pentru rest
			std::cout << "Succes!\n";
		}
		else
			std::cout << "Nu exista rest pentru tranzactie\n";
	}
}
/*
Se ocupa cu rularea interfetei de obiecte de tip Coin pentru administrator 
Input:
	-
Output:
	-
*/
void Console::run_admin_coin()
{
	bool is_running = true;
	while (is_running)
	{
		char op;
		this->show_menu_coin();
		std::cout << "Optiune: ";
		std::cin >> op;
		switch (op)
		{
		case '1':
		{
			this->handle_create_coin();
			break;
		}
		case 'a':
		{
			this->handle_show_all_coins();
			break;
		}
		case '2':
		{
			this->handle_empty_coin();
			break;
		}
		case '3':
		{
			this->handle_add_coins();
			break;
		}
		case '4':
		{
			this->handle_remove_coins();
			break;
		}
		case '5':
		{
			this->handle_delete_coin();
			break;
		}
		case '6':
		{
			this->handle_get_sum();
			break;
		}
		case 'x':
		{
			is_running = false;
			std::cout << "bye bye!\n";
			break;
		}
		default:
		{
			std::cout << "Caracter invalid!\n";
			break;
		}
		}
	}
}

/*
Preia user input-ul, il transmite catre service-ul de produse si prinde erorile pentru stergerea unui obiect de tip Produs din lista
de cumparaturi a unui user.
Input:
	-
Output:
	-
*/

void Console::handle_delete_produs_shopper()
{
	try
	{
		int cod;
		std::cout << "Introduceti codul produsului de sters: ";
		std::cin >> cod;
		this->service_produs_buffer.delete_produs(cod);
		std::cout << "Succes!\n";
	}
	catch (RepoException repo_exception)
	{
		std::cout << "EROARE: " << repo_exception.get_message() << "\n";
	}
	catch (ValidatorException validator_exception)
	{
		std::cout << "EROARE: " << validator_exception.get_message() << "\n";
	}
}


/*
Se ocupa cu rularea interfetei de obiecte de tip Produs pentru administrator
Input:
	-
Output:
	-
*/

void Console::run_admin_produs()
{
	bool is_running = true;
	while (is_running)
	{
		char op;
		this->show_menu_produs();
		std::cout << "Optiune:";
		std::cin >> op;
		switch (op)
		{
		case '1':
		{
			this->handle_add_produs();
			break;
		}
		case '2':
		{
			this->handle_update_produs();
			break;
		}
		case '3':
		{
			this->handle_delete_produs();
			break;
		}
		case 'a':
		{
			this->handle_show_all();
			break;
		}
		case 'x':
		{
			is_running = false;
			std::cout << "Bye bye lol\n";
			break;
		}
		default:
		{
			std::cout << "Caracter invalid!\n";
			break;
		}
		}
	}
}

/*
Verifica daca parola introdusa este corecta
Input:
	-password: string, parola corecta
Output:
	-True daca parola introdusa se user este la fel ca cea memorata, False altfel
*/

bool Console::check_password(string password)
{
	string input_password;
	std::cout << "Introduceti parola: ";
	std::cin >> input_password;
	return input_password == password;
}

/*
Se ocupa cu rularea interfetei pentru utilizator
Input:
	-
Output:
	-
*/

void Console::show_menu_shopper()
{
	std::cout << "-- Meniu shopper --\n";
	std::cout << "1. Vezi produse disponibile\n";
	std::cout << "2. Vezi balanta\n";
	std::cout << "3. Vezi lista de cumparaturi\n";
	std::cout << "4. Adauga moneda\n";
	std::cout << "5. Scoate toate monedele\n";
	std::cout << "6. Adauga produs in lista de cumparaturi\n";
	std::cout << "7. Sterge lista de cumparaturi\n";
	std::cout << "8. Cumpara\n";
	std::cout << "x. Stop\n";
}


/*
Se ocupa cu rularea aplicatiei
Input:
	-
Output:
	-
*/

void Console::run()
{
	string user;
	bool big_run = true;
	string password = "1234";

	while (big_run)
	{
		std::cout << "Hello! Esti admin sau shopper?(x to escape): ";
		std::cin >> user;
		if (user == "admin")
		{
			if (check_password(password))
			{
				char op;
				bool runnin = true;
				while (runnin)
				{
					std::cout << "Acces permis!\n";
					std::cout << "1. Control produse\n" << "2. Control monede\n" << "x. Break\n" << "Optiune: ";
					std::cin >> op;
					if (op == '1')
						this->run_admin_produs();
					else if (op == '2')
						this->run_admin_coin();
					else if (op == 'x')
						runnin = false;
					else
						std::cout << "Optiune invalida!\n";
				}

			}
			else
			{
				std::cout << "Parola incorecta!\n";
			}
		}
		else if (user == "shopper")
		{
			char op;
			bool runnin = true;
			while (runnin)
			{
				this->show_menu_shopper();
				std::cout << "Optiune: ";
				std::cin >> op;
				switch (op)
				{
				case '1':
				{
					this->handle_show_all();
					break;
				}
				case '2':
				{
					this->handle_get_sum_shopper();
					break;
				}
				case '3':
				{
					this->handle_show_all_shopper();
					break;
				}
				case '4':
				{
					this->handle_add_coins_shopper();
					break;
				}
				case '5':
				{
					std::cout << "todo\n";
					break;
				}
				case '6':
				{
					this->handle_add_produs_shopper();
					break;
				}
				case '7':
				{
					this->handle_delete_produs_shopper();
					break;
				}
				case '8':
				{
					this->handle_buy();
					break;
				}
				case 'x':
				{
					runnin = false;
					break;
				}
				default:
				{
					std::cout << "Caracter invalid!\n";
					break;
				}
				}
			}

		}
		else if (user == "x")
		{
			big_run = false;
			std::cout << "bye bye!\n";
		}
		else
			std::cout << "Introduceti o varianta valida!\n";
	}


}