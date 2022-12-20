// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : annexe.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Fonction generique pour la saisie de valeur
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include <iostream> // cout et cin
#include <string>	  // string
#include <limits>	  // numeric_limits<streamsize>

#include "annexe.h"

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max() , '\n')

using namespace std;

int saisie(const string& msg, int min, int max, const string& msg_erreur) {
    bool erreur;
    int saisie;
    do {
        // saisie
        cout << msg << " [" << min << ".." << max << "]" << " :";
        cin >> saisie;

        // vérifie que le caractère est valide
        erreur = cin.fail() or !(saisie >= min && saisie <= max);

        // gestion du flux
        if (erreur) {
            cout << msg_erreur << endl;
            cin.clear();
        }
        VIDER_BUFFER; //vider buffer
    }while(erreur);
    return saisie; // retour de la valeur saisie
}

int saisieIntro(const string& msg_intro, const string& msg, int min, int max,
                const string& msg_erreur) {

    if (!msg_intro.empty()) {
        cout << msg_intro << endl;
    }

    return saisie(msg, min, max, msg_erreur); // retour de la valeur saisie
}
