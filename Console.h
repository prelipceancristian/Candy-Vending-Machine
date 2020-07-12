#pragma once
#include "ServiceProdus.h"
#include "ServiceCoin.h"

/*
Defineste clasa de tip Console, acesta rol de UI si face legatura dintre user si functionalitatile aplicatiei.
*/

class Console
{
private: 
	// Aceasta clasa are la dispozitie 4 service-uri pentru a nu amesteca datele introduse de utilizator si datele introduse de administrator
	ServiceProdus& service_produs; // service ul de produse pentru administrator
	ServiceCoin& service_coin; // service ul de Coins pentru administrator
	ServiceProdus& service_produs_buffer; // service de produse pentru user, permite mentinerea produselor introduse de user intr-un buffer 
	ServiceCoin& service_coin_buffer; // service de Coin pentru user, permite stocarea temporara a monedelor introduse intr-un buffer pana la actiunea de cumparare
public:
	Console(ServiceProdus& _service_produs, ServiceCoin& _service_coin, ServiceProdus& _service_produs_buffer, ServiceCoin& _service_coin_buffer) :
		service_produs{ _service_produs },
		service_coin{ _service_coin },
		service_produs_buffer{ _service_produs_buffer },
		service_coin_buffer{ _service_coin_buffer }{}; // constructor implicit
	~Console() {}; // destructor
	void handle_add_produs();
	void handle_show_all();
	void handle_update_produs();
	void handle_delete_produs();
	void run();
	void show_menu_produs();
	void run_admin_produs();
	bool check_password(string);
	void run_admin_coin();
	void show_menu_coin();

	void handle_create_coin();
	void handle_show_all_coins();
	void handle_empty_coin();
	void handle_add_coins();
	void handle_remove_coins();
	void handle_delete_coin();
	void handle_get_sum();

	void show_menu_shopper();
	void handle_get_sum_shopper();
	void handle_show_all_shopper();
	void handle_add_coins_shopper();
	void handle_add_produs_shopper();
	void handle_delete_produs_shopper();
	void handle_buy();
};