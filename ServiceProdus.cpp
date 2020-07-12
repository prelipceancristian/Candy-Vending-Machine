#pragma once
#include "ServiceProdus.h"

/*
Adauga un obiect de tip service in repo.
Input:
	-cod: int, codul produsului
	-nume: string, numele produsului
	-pret: double, pretul produsului
Output:
	-
*/

void ServiceProdus::adauga_produs(int cod, string nume, double pret)
{
	Produs pr{ cod, nume, pret };
	this->validator_produs.valdiate(pr);
	this->repository.add(pr.get_cod(), pr);
	//std::cout << "Succes!\n";
}

/*
Retureaza toate obiectele de tip Produs din repo.
Input:
	-
Output:
	- un vector<Produs> cu toate produsele.
*/

vector<Produs> ServiceProdus::get_all()
{ 
	return this->repository.get_all();
}

/*
Actualizeaza un obiect de tip produs din repo.
Input:
	-cod: int, codul produsului de actualizat
	-new_nume: string, noul nume al produsului
	-new_pret: double, noul pret al produsului
Output:
	-
*/

void ServiceProdus::update_produs(int cod, string new_nume, double new_pret)
{
	Produs new_produs{cod, new_nume, new_pret};
	this->validator_produs.valdiate(new_produs);
	this->repository.update(cod, new_produs);
}

/*
Sterge un anumit produs din repo.
Input:
	-cod: int, codul produsului de sters
Output:
	-
*/

void ServiceProdus::delete_produs(int cod)
{
	this->repository.remove(cod);
}

/*
Returneaza un produs din repo dupa codul sau
Input:
	-cod: int, codul produsului cautat
Output:
	-obiectul de tip Produs care are id-ul dat
*/

Produs ServiceProdus::find_produs(int cod)
{
	return this->repository.find(cod);
}

/*
Determina suma tuturor produselor dintr-un repo
Input:
	-
Output:
	-sum: double, suma tuturor produselor 
*/

double ServiceProdus::get_sum()
{
	double sum = 0;
	vector<Produs> all = this->repository.get_all();
	std::for_each(all.begin(), all.end(), [&sum](auto& prod) {sum += prod.get_pret(); });
	return sum;
}

/*
Elimina toate produsele dintr-un repo
Input:
	-
Output:
	-
*/
void ServiceProdus::clear_repo()
{
	this->repository.clear_all();
}
