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

    // Saisie des parametres du jeu
    int longeur = saisie("ce programme...", "Longeur", 10, 1000, "La valeur n'est pas dans les limites indiquees!");
    int largeur = saisie("Largeur", 10, 1000, "La valeur n'est pas dans les limites indiquees!");
    int nbreObjects = saisie("Nbre objects", 1, 10, "La valeur n'est pas dans les limites indiquees!");

    // Initialisation du "Game master"
    Survivor survivor(longeur, largeur, nbreObjects);

    // boucle de jeu
    do{

        survivor.etappe();

    }while ( survivor.fin() );


    // Fin du programme
    cout << endl << "Pressez ENTER pour quitter";
    VIDER_BUFFER;

    return EXIT_SUCCESS;
}
