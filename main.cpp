// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Nous souhaitons simuler des robots autonomes dans un espaces
//                  donné.
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include <iostream>
#include "Survivor.h"
#include <limits>               // Utilisation de numeric limits
#include "annexe.h"

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {

    int longeur = saisie("Longeur", 10, 1000, "La valeur n'est pas dans les limites indiquees!");
    int largeur = saisie("Largeur", 10, 1000, "La valeur n'est pas dans les limites indiquees!");
    int nbreObjects = saisie("Nbre objects", 10, 1000, "La valeur n'est pas dans les limites indiquees!");


    Survivor survivor(longeur, largeur, nbreObjects);

    do{

        survivor.etappe();

    }while ( survivor.fin() );


    cout << "Pressez ENTER pour quitter";
    VIDER_BUFFER;

    return EXIT_SUCCESS;
}
