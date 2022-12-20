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

    const int MIN_TERRAIN = 10;
    const int MAX_TERRAIN = 1000;
    const int MIN_NBRE_OBJECTS = 1;
    const int MAX_NBRE_OBJECTS = 10;

    // Saisie des parametres du jeu
    int longeur = saisieIntro("ce programme...", "Longeur", MIN_TERRAIN, MAX_TERRAIN);
    int largeur = saisie("Largeur", MIN_TERRAIN, MAX_TERRAIN);
    int nbreObjects = saisie("Nbre objects", MIN_NBRE_OBJECTS, MAX_NBRE_OBJECTS);

    // Initialisation du "Game master"
    Survivor survivor(longeur, largeur, nbreObjects);

    // boucle de jeu, tant que >1 robots sont en vie
    do{

        survivor.etappe();

    }while ( survivor() );


    // Fin du programme
    cout << endl << "Pressez ENTER pour quitter";
    VIDER_BUFFER;

    return EXIT_SUCCESS;
}
