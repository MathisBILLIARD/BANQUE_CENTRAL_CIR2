#pragma once
#include <wx/wx.h>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>
#include <wx/datetime.h>
#include <wx/intl.h>
#include <cmath>
#include <random>
#include <map>
#include "client.h"

//---------------- SETUP ----------------//
class App : public wxApp {
public:
	bool OnInit();
};

//---------------- CONNEXION & INSCRIPTION ----------------//
class Connexion : public wxFrame {
public:
	Connexion(const wxString& title);
	Customer getClient(string prenom, string nom, string adresse) {
		/*namespace pt = boost::property_tree;
		// Create a root
		pt::ptree root;
		vector<Customer> client;
		// Load the json file in this ptree
		pt::read_json("filename.json", root);
		for (ptree::value_type& customer : root.get_child("Customers"))
		{
			auto custom = get_a_customer_from_a_ptree(customer.second);
			client.push_back(custom);
		}*/
		constexpr int MIN = 1;
		constexpr int MAX = 100;
		constexpr int RAND_NUMS_TO_GENERATE = 10;
		vector<Customer> client;
		string name;
		name = prenom + nom;
		Compte compte;
		vector<Compte> comptes;
		comptes.push_back(compte);
		int number = client.size();
		Customer c(number, std::move(name), std::move(comptes), std::move(adresse));
		client.push_back(c);
		return c;
	}
private:
	wxTextCtrl* InputPrenom = nullptr;
	wxTextCtrl* InputNom = nullptr;
	wxTextCtrl* InputAdresse = nullptr;
	wxTextCtrl* InputCodeClient = nullptr;
	wxCheckBox* checkBox = nullptr;
	void BtnValider(wxCommandEvent& event);
	void VerificationInscription(wxUpdateUIEvent& event);
	void VerificationConnexion(wxUpdateUIEvent& event);
	void BtnOuvrirUnCompte(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

//---------------- COMPTE BANCAIRE ----------------//
class CompteBancaire : public wxDialog {
public:
	CompteBancaire(wxString prenom, wxString nom, wxString adresse, wxString codeclient, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
	CompteBancaire(wxString codeclient, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
	CompteBancaire(vector<Customer> client,wxString codeclient, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
	CompteBancaire(vector<Customer> client, wxString codeclient,int numCompte, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
	CompteBancaire(vector<Customer> client, wxString codeclient, wxString Compte, wxString Montant, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
private:
	wxTextCtrl* InputCompteCreation = nullptr;
	wxTextCtrl* InputMontantCreation = nullptr;
	wxButton* BtnSuppression = nullptr;
	wxButton* BtnSuppression1 = nullptr;
	wxString prenom = "";
	wxString nom = "";
	wxString codeclient = "";
	wxString adresse = "";
	wxString CompteCreation = "";
	wxString MontantCreation = "";
	vector<Customer> client;
	wxStaticText* TextHeure = nullptr;
	wxTimer m_clockTimer;
	void BtnVirement(wxCommandEvent& evt);
	void BtnDeconnexion(wxCommandEvent& evt);
	void BtnValiderCreation(wxCommandEvent& evt);
	void BtnSuppressioncompte(wxCommandEvent& evt);
	void BtnSuppressioncompte1(wxCommandEvent& evt);
	void VerificationCreation(wxUpdateUIEvent& event);
	void OnUpdateClock(wxTimerEvent&) { UpdateClock(); }
	void UpdateClock() { TextHeure->SetLabel(wxDateTime::Now().Format("%d/%m/%Y %H:%M:%S")); }
	wxDECLARE_EVENT_TABLE();
};

//---------------- VIREMENT & DEPOT ----------------//
class Virement : public wxDialog {
public:
	Virement(vector<Customer>client, wxString codeclient, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
	Virement(vector<Customer>client, wxString codeclient, wxString CVirement, wxString Benef, wxString Montant,wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
	Virement(vector<Customer>client, wxString codeclient, wxString Montant,wxString CompteDep,wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxASCII_STR(wxDialogNameStr));
private:
	wxTextCtrl* InputBeneficiaire = nullptr;
	wxTextCtrl* InputMontantVirement = nullptr;
	wxTextCtrl* InputPourquoi = nullptr;
	wxTextCtrl* InputMontantDepot = nullptr;
	wxChoice* ChoixCompteVirement = nullptr;
	wxChoice* ChoixCompteDepot = nullptr;
	wxString prenom = "";
	wxString CompteVirement = "";
	wxString CompteDepot = "";
	wxString Beneficiaire = "";
	wxString MontantVirement = "";
	wxString MontantDepot = "";
	wxString nom = "";
	wxString codeclient = "";
	wxString adresse = "";
	vector<Customer> client;
	wxStaticText* TextHeure = nullptr;
	wxTimer m_clockTimer;
	void OnUpdateClock(wxTimerEvent&) { UpdateClock(); }
	void VerificationVirement(wxUpdateUIEvent& event);
	void VerificationDepot(wxUpdateUIEvent& event);
	void UpdateClock() { TextHeure->SetLabel(wxDateTime::Now().Format("%d/%m/%Y %H:%M:%S")); }
	void BtnValiderDepot(wxCommandEvent& evt);
	void BtnValiderVirement(wxCommandEvent& evt);
	void BtnDeconnexion(wxCommandEvent& evt);
	void BtnCompte(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};