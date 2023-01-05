#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include <map>
#include "client.h"
#include <boost/asio.hpp>
using namespace std;

class AgenceD {
	int number_;
	string ville_;
	vector<Customer>donnes;
	void Afficher_donnes(vector<Customer> number, vector<int> compte);
	AgenceD(){}
	AgenceD(int number, string ville):number_(number),ville_(ville){}
	void searchJson(fstream document);
	void EntrerBanque(Customer client);
	void Creation_compte_client();
	void PageAccueil();
};

