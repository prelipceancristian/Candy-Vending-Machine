#pragma once
#include "Produs.h"

/*
Defineste clasa de ValidatorProdus, se ocupa de validarea obiectelor de tip Produs.
*/
class ValidatorProdus
{
public:
	ValidatorProdus() {}; // constructor implicit
	~ValidatorProdus() {}; // destructor
	void valdiate(const Produs& _pr); // functia de validare
};

/*
Defineste clasa de ValidatorException, acesta va fi tipul obiectelor lansate ca exceptii
*/

class ValidatorException
{
private:
	string msg; // mesajul de eroare
public:
	ValidatorException(const string& _msg) : msg{ _msg } {}; // constructor implicit
	ValidatorException() {}; // destructor
	const string& get_message() // functia de returnare a mesajului
	{
		return this->msg;
	}
};