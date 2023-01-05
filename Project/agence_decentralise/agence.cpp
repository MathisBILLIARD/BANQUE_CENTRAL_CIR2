#include "agence.h"
#include <random>
#include <string>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;
constexpr int MIN = 0;
constexpr int MAX = 9;
constexpr int RAND_NUMS_TO_GENERATE = 10;
void AgenceD::searchJson(fstream document) {
    ptree pt_read;{
        }
    ifstream file_in("example_write_read.json");
    read_json(file_in, pt_read);
    file_in.close();
}

Customer get_a_customer_from_a_ptree(ptree& pt) {

    int number = pt.get<int>("Number", 0);

    std::string name = pt.get<std::string>("Name");
    std::string address = pt.get<std::string>("Adress");
    std::vector<int> account_numbers;

    for (ptree::value_type& account_number : pt.get_child("Account_numbers")) {
        account_numbers.push_back(account_number.second.get_value<int>());
    }

    Customer customer(number, std::move(name), std::move(account_numbers), std::move(address));
    return customer;
}

/*void AgenceD::Creation_compte_client() {
    namespace pt = boost::property_tree;

    // Create a root
    pt::ptree root;
    vector<Customer> client;
    // Load the json file in this ptree
    pt::read_json("filename.json", root);
    for (ptree::value_type& customer : root.get_child("Customers"))
    {
        auto custom = get_a_customer_from_a_ptree(customer.second);

        client.push_back(custom);
    }
    string nom;
    float argent;
    string addresse;
    vector<int>numero_compte;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);

    for (int n = 0; n < RAND_NUMS_TO_GENERATE; ++n) {
        numero_compte.push_back(distr(eng));
    }
    cout << "Veuillez saisir votre nom et prenom :" << endl;
    getline(cin, nom);
    cout << endl << "Saisissez votre adresse :" << endl;
    getline(cin, addresse);
    int number = client.size();
    Customer c(number, std::move(nom), std::move(numero_compte), std::move(addresse));
    cout << "Vous etes maintenant client chez nous !" << endl;
    client.push_back(c);
}

void AgenceD::PageAccueil() {
    namespace pt = boost::property_tree;

    // Create a root
    pt::ptree root;

    // Load the json file in this ptree
    pt::read_json("filename.json", root);
    int it;
    char c;
    int n;
    string num;
    string prenom;
    string sline;
    string sousligne;
    vector<int> chiff;
    vector<int> number;
    vector<Customer> client;
    while (c != 'c') {
        cout << "Bienvenu a la banque DAILLY de" << this->ville_ << endl;
        cout << "Si vous avez un compte chez nous (tapez a)" << endl;
        cout << "Si vous voulez creer un compte (tapez b)" << endl;
        cout << "Si vous voulez sortir du système (tapez c)" << endl;
        c = getchar();
        switch (c) {
        case 'a':
            cout << "Entrez votre numero de compte" << endl;
            getline(cin, num);
            if (num != " ") {
                for (ptree::value_type& customer : root.get_child("Customers"))
                {
                    auto custom = get_a_customer_from_a_ptree(customer.second);

                    client.push_back(custom);
                }
                stringstream numer(num);
                while (getline(numer, sline, '-')) {
                    chiff.push_back(stoi(sline));
                }
                n = 0;
                do {
                    
                    it = 0;
                    for (int i = 0; i < chiff.size(); i++) {
                        if (chiff[i] == client[n].account_numbers_[i]) {
                            it++;
                        }
                        else {
                            break;
                        }
                    }
                    n++;
                } while (it != 10 && n < client.size());
                
                EntrerBanque(client[n]);
                break;
            }
        case 'b':
            Creation_compte_client();
            break;
        case 'c':
            break;
        }
    }
}

void AgenceD::EntrerBanque(Customer client) {
    string mdp;
    string sline;
    string nom_com;
    string nom_compte;
    string nom_compte2;
    float argent;
    int i;
    int iteration;
    int iteration2;
    vector<int> chiff;
    int it;
    cout << "Vous etes " << client.name_ << endl;
    cout << "Veuillez saisir votre numero de client." << endl;
    getline(cin, mdp);
    if (mdp != " ") {
        stringstream numer(mdp);
        while (getline(numer, sline, '-')) {
            chiff.push_back(stoi(sline));
        }
        it = 0;
        for (int i = 0; i < chiff.size(); i++) {
            if (chiff[i] == client.account_numbers_[i]) {
                it++;
            }
            else {
                break;
            }
        }
        if (it == client.account_numbers_.size()) {
            char c;
            do {
                cout << "Vous voulez :" << endl;
                cout << "- Afficher vos données (tapez a)" << endl;
                cout << "- Ajouter de l'argent (tapez b)" << endl;
                cout << "- Retirer de l'argent (tapez c)" << endl;
                cout << "- Transaction inter-comptes (tapez d)" << endl;
                cout << "- Sortir du système (tapez x)" << endl;
                c = getchar();
                switch (c) {
                case 'a':
                    Afficher_donnes(donnes, client.account_numbers_);
                    break;
                case 'b':
                    cout << "Entrez le nom de votre compte" << endl;
                    getline(cin, nom_com);
                    iteration = 0;
                    for (i = 0; i < client.comptes_.size(); i++) {
                        if (client.comptes_[i].name == nom_com) {
                            client.comptes_[i].ajouter_Compte();
                        }
                        else {
                            iteration++;
                            continue;
                        }
                    }
                    if (iteration == client.comptes_.size() - 1) {
                        cout << "Votre compte est introuvable" << endl;
                    }
                    break;
                case 'c':
                    cout << "Entrez le nom de votre compte" << endl;
                    getline(cin, nom_com);
                    iteration = 0;
                    for (i = 0; i < client.comptes_.size(); i++) {
                        if (client.comptes_[i].name == nom_com) {
                            client.comptes_[i].retirer_Compte();
                        }
                        else {
                            iteration++;
                            continue;
                        }
                    }
                    if (iteration == client.comptes_.size() - 1) {
                        cout << "Votre compte est introuvable" << endl;
                    }
                    break;
                case'd':
                    cout << "Entrez le nom du compte qui fournira l'argent" << endl;
                    getline(cin, nom_compte);
                    cout << "Entrez le nom du compte qui recevra l'argent" << endl;
                    getline(cin, nom_compte2);
                    cout << "Entrez le montant a transferer" << endl;
                    cin >> argent;
                    iteration = 0;
                    iteration2 = 0;
                    for (int i = 0; i < client.comptes_.size(); i++) {
                        if (client.comptes_[i].name == nom_compte) {
                            for (int j = 0; j < client.comptes_.size(); j++) {
                                if (client.comptes_[j].name == nom_compte2) {
                                    client.comptes_[i].money -= argent;
                                    client.comptes_[j].money += argent;
                                }
                                else {
                                    iteration2++;
                                    continue;
                                }
                            }
                        }
                        else {
                            iteration++;
                            continue;
                        }
                    }
                    if (iteration == client.comptes_.size() - 1) {
                        cout << "Votre compte est introuvable" << endl;
                    }
                    if (iteration2 == client.comptes_.size() - 1) {
                        cout << "Votre compte de reception est introuvable" << endl;
                    }
                    break;
                case'x':
                    break;
                default:
                    cout << "Cette action est impossible" << endl;
                    break;
                }
            } while (c != 'x');
        }
    }
}

void AgenceD::Afficher_donnes(vector<Customer> number, vector<int> compte) {
    int it;
    Customer client;
    for (auto custo : number) {
        it = 0;
        client = custo;
        for (auto num : custo.account_numbers_) {
            if (num == compte[it]) {
                it++;
            }
            else {
                break;
            }
        }
    }
    if (it == compte.size()-1) {
        cout << client << endl;
        for (int i = 0; i < client.comptes_.size(); i++) {
            cout<< client.comptes_[i].name << "contient" << client.comptes_[i].money;
        }
    }
    else {
        cout << "Vous n'etes pas enregistrez dans notre banque" << endl;
    }
}*/

