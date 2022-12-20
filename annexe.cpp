// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : annexe.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "annexe.h"
#include <iostream> // cout et cin
#include <string>	  // string
#include <limits>	  // numeric_limits<streamsize>

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max() , '\n')
using namespace std;

const string MSG_INTRO = "ce programme ...";

//LARGEUR [10..1000] : 20
//hauteur [10..1000] : 10
//nbre object [0..9] : 9
const int MIN_TAILE = 10,
          MAX_TAILE = 1000;
const int MIN_OBJ = 0,
          MAX_OBJ = 9;

int saisie(const string& MSG, const int& MIN, const int& MAX, const string&
MSG_ERROR) {
    bool erreur;
    int saisie;
    do {
		  // saisie
        cout << MSG << " [" << MIN << ".." << MAX << "]" << " :";
        cin >> saisie;

		  // vérifie que le caractère est valide
        erreur = cin.fail() or !(saisie >= MIN && saisie <= MAX);

		 // gestion du flux
        if (erreur) {
            cout << MSG_ERROR << endl;
            cin.clear();
        }
        VIDER_BUFFER; //vider buffer
    }while(erreur);
    return saisie; // retour de la valeur saisie
}

int saisie(const string& MSG_INTRO, const string& MSG, const int MIN, const int MAX, const string&
MSG_ERROR) {
    if (!MSG_INTRO.empty()) {
        cout << MSG_INTRO << endl;
    }
    bool erreur;
    int saisie;
    do {
		 // saisie
        cout << MSG << " [" << MIN << ".." << MAX << "]" << " :";
        cin >> saisie;
		 // vérifie que le caractère est valide
        erreur = cin.fail() or !(saisie >= MIN && saisie <= MAX);

		 // gestion du flux
        if (erreur) {
            cout << MSG_ERROR << endl;
            cin.clear();
        }
        VIDER_BUFFER; //vider buffer
    }while(erreur);
    return saisie; // retour de la valeur saisie
}
