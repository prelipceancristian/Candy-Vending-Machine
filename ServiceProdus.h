#pragma once
#include "Repo.h"
#include "ValidatorProdus.h"
class ServiceProdus
{
private:
	IRepo<Produs>& repository; // repository produs pe baza lui IRepo -  astfel poate primi orice alt repository ce mosteneste IRepo, cum ar fi Repo sau RepoFile
	ValidatorProdus validator_produs; // validator pentru produsele creeata
public:
	ServiceProdus(IRepo<Produs>& _repository, ValidatorProdus& _validator_produs) : repository{ _repository }, validator_produs{ _validator_produs }{}; // constructor explicit
	~ServiceProdus() {}; // destructor

	void adauga_produs(int, string, double);
	vector<Produs> get_all();
	void update_produs(int, string, double);
	void delete_produs(int);
	Produs find_produs(int);
	double get_sum();
	void clear_repo();
};