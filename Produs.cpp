#include "Produs.h"

int Produs::get_cod() const // confera codul unui produs
{
	return this->cod;
}

string Produs::get_nume() const // returneaza numele produsului
{
	return this->nume;
}

double Produs::get_pret() const // returneaza pretul produsului
{
	return this->pret;
}

void Produs::set_nume(string _nume) // seteaza numele produsului
{
	this->nume = _nume;
}

void Produs::set_pret(double _pret) // seteaza pretul produsului
{
	this->pret = _pret;
}

Produs& Produs::operator=(const Produs& _pr) // operator de egalare (copiere)
{
	this->cod = _pr.cod;
	this->nume = _pr.nume;
	this->pret = _pr.pret;
	return *this;
}

bool Produs::operator==(const Produs& _pr) // operator de egalare 
{
	return (this->cod == _pr.cod); // nu ar trebui verificate si celelalte atribute?
}

bool Produs::operator!=(const Produs& _pr) // dunno operator !=
{
	return !(*this == _pr);
}

//ostream& Produs::operator<<(ostream & os, const Produs & _pr);