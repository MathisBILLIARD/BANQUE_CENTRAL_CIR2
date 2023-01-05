// Projet-CIR2.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Compte {
public:
	int numero_compte;
	float money;
	string name;
	Compte();
	Compte(string nom, float argent);
	Compte(string nom, int numero, float argent);
	void ajouter_Compte(float argent);
	void retirer_Compte();
};

class Customer :public Compte {
public:
	std::vector<int> account_numbers_;
	vector<Compte> comptes_;
	int number_ = 0;
	std::string name_;
	string adresse;
	Customer();
	Customer(const int& number, std::string&& name, std::vector<Compte>&& account_numbers, string&& adress);
	Customer(size_t number, std::string&& name, std::vector<int>&& account_numbers, string&& adress);
	friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
	template <class Archive>
	void serialize(Archive& ar, unsigned int version)
	{
		ar& name_& number_& adresse& account_numbers_;
	}
};