#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

/*
Defineste un obiect de tip Produs.
*/
class Produs
{
private:
	int cod; // numar intreg, mai mare ca 0, id unic pentru produse
	string nume; // string, numele produsului
	double pret; // double, pretul produsului
public:
	Produs():cod{ -1 }, nume{ "" }, pret{ 0.0 }{}; // constructor implicit
	Produs(int _cod, string _nume, double _pret) :cod{ _cod }, nume{ _nume }, pret{ _pret }{}; // constructor explicit
	Produs(const Produs& _pr) :cod{ _pr.cod }, nume{ _pr.nume }, pret{ _pr.pret }{}; // constructor de copiere
	~Produs(){}; // destructor

	int get_cod() const;
	string get_nume() const;
	double get_pret() const;
	void set_nume(string _nume);
	void set_pret(double _pret);

	Produs& operator=(const Produs& _pr);
	bool operator==(const Produs& _pr);
	bool operator!=(const Produs& _pr);

	friend ostream& operator<<(ostream& os, const Produs& _pr) // operatorul << pentru afisare
	{
		os << "      " << _pr.cod << " " << _pr.nume << " " << _pr.pret;
		return os;
	}

	friend istream& operator>>(istream& is, Produs& _pr) // operatorul >> pentru citire
	{
		is >> _pr.cod >> _pr.nume >> _pr.pret;
		return is;
	}
};