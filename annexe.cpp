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
#include <iostream>
#include <string>
#include <limits>

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max() , '\n')
using namespace std;

const string MSG_INTRO = "ce programme ...";
const string MSG_ERROR = "";
//LARGEUR [10..1000] : 20
//hauteur [10..1000] : 10
//nbre object [0..9] : 9
const int MIN_TAILE = 10,
          MAX_TAILE = 1000;
const int MIN_OBJ = 0,
          MAX_OBJ = 9;

int saisie(const string& MSG, const int MIN, const int MAX, const string& MSG_ERROR) {
    bool erreur;
    int saisie;
    do {
        cout << MSG << " [" << MIN << ".." << "]" << " :";
        cin >> saisie;
        erreur = cin.fail() or !(saisie >= MIN && saisie <= MAX);

        if (erreur) {
            cout << MSG_ERROR << endl;
            cin.clear();
        }
        VIDER_BUFFER;
    }while(erreur);
    return saisie;
}

int saisie(const string& MSG_INTRO, const string& MSG, const int MIN, const int MAX, const string&
MSG_ERROR) {
    if (!MSG_INTRO.empty()) {
        cout << MSG_INTRO << endl;
    }
    bool erreur;
    int saisie;
    do {
        cout << MSG << " [" << MIN << ".." << "]" << " :";
        cin >> saisie;
        erreur = cin.fail() or !(saisie >= MIN && saisie <= MAX);

        if (erreur) {
            cout << MSG_ERROR << endl;
            cin.clear();
        }
        VIDER_BUFFER;
    }while(erreur);
    return saisie;
}
