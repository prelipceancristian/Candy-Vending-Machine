#include "ValidatorProdus.h"

/*
Valideaza un produs. 
Input:
	-_pr: obiectul de tip Produs, transmis ca parametru, obiectul de validat
Output:
	- (poate lansa ValidatorExceptions daca produsul nu este valid)
*/

void ValidatorProdus::valdiate(const Produs& _pr)
{
	if (_pr.get_cod() <= 0)
		throw ValidatorException("Codul introdus este negativ (sau nul)!");
	if (_pr.get_nume() == "")
		throw ValidatorException("Numele introdus este gol!");
	if (_pr.get_pret() <= 0)
		throw ValidatorException("Pretul introdus este negativ! (sau nul)");
}