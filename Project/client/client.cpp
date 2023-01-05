// Projet-CIR2.cpp : définit le point d'entrée de l'application.
//

#include "client.h"
#include <algorithm>
#include <random>
#include <sstream>
#include <string>
using namespace std;
constexpr int MIN = 1;
constexpr int MAX = 100;
constexpr int RAND_NUMS_TO_GENERATE = 10;

Customer::Customer() : number_(0), name_(0), comptes_(0), adresse('\0') {}

Customer::Customer(const int& number, std::string&& name,
    std::vector<Compte>&& account_numbers, string&& adress)
    : number_(number), name_(name), comptes_(account_numbers), adresse(adress) {}


Customer::Customer(size_t number, std::string&& name, std::vector<int>&& account_numbers, string&& adress) :number_(number), name_(name), account_numbers_(account_numbers), adresse(adress) {}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Name " << customer.name_ << std::endl;
    os << "Number " << customer.number_ << std::endl;
    os << "Adress" << customer.adresse << endl;
    for (auto& account : customer.account_numbers_) {
        std::cout << "Account_Number : " << account << std::endl;
    }
    return os;
}


void Compte::ajouter_Compte(float argent) {
    money += argent;
}

/*void Compte::retirer_Compte() {
    string num;
    string sline;
    vector<int> chiff;
    float retire;
    int it;
    cout << "Entrez votre numero de compte de 10 chiffres espaces de tiret comme ceci : 6-7-7-8-" << endl;
    while (getline(cin, num)) {
        if (num != " ") {
            stringstream numer(num);
            while (getline(numer, sline, '-')) {
                chiff.push_back(stoi(sline));
            }
            it = 0;
            for (int i = 0; i < chiff.size(); i++) {
                if (chiff[i] == this->numero_compte[i]) {
                    it++;
                }
                else {
                    break;
                }
            }
            if (it == numero_compte.size() - 1) {
                cout << "Vous pouvez indiquer le montant a retirer sur ce compte" << endl;
                cin >> retire;
                money -= retire;
            }
        }
    }
}*/

Compte::Compte() {
    this->money = 80;
    this->name = "Compte Courant";
    string num;
    string sline;
    vector<int> chiff;
    int it;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);
    for (int n = 0; n < RAND_NUMS_TO_GENERATE; ++n) {
        chiff.push_back(distr(eng));
    }
    int numero = 0;
    for (auto d : chiff)
    {
        numero = numero * 10 + d;
    }
    this->numero_compte = numero;
}

Compte::Compte(string nom, float argent) {
    this->money = argent;
    this->name = nom;
    string num;
    string sline;
    vector<int> chiff;
    int it;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);
    for (int n = 0; n < RAND_NUMS_TO_GENERATE; ++n) {
        chiff.push_back(distr(eng));
    }
    int numero = 0;
    for (auto d : chiff)
    {
        numero = numero * 10 + d;
    }
    this->numero_compte = numero;
}

Compte::Compte(string nom, int numero, float argent) {
    this->money = argent;
    this->name = nom;

    this->numero_compte = numero;
}