// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "Terrain.h"
#include "Robot.h"
#include <iostream>
#include <string>


using namespace std;

Terrain::Terrain(int largeur, int longeur) : largeur(largeur + 1), longeur(longeur + 1) {}

void Terrain::affiche(std::vector<Robot>& robots) const{

    string ligne = string((size_t)largeur + 2, BORDURE_HORIZONTAL);
    const char START = '0';

    vector<Robot>::iterator itRobot = robots.begin();

    // Efface le terminal pour Windows et Linux / Mac
    if (system("cls"))
        system("clear");

    // Bordure superieure
    cout << ligne << endl;

    // Affiche une ligne du terrain
    for (int i = 0; i <= longeur; ++i){

        ligne = ligneTerrain();

        // Place les robots qui sont sur cette ligne
        while (itRobot->getCoordonnee().getY() == i - 1 && robots.end() != itRobot){
            ligne.at((size_t)itRobot->getCoordonnee().getX() + 1) = START + (char)
                    itRobot->getId();
            ++itRobot;
        }

        cout << ligne << endl;
    }

    // Bordure inferieure
    ligne = string((size_t)largeur + 2, BORDURE_HORIZONTAL);
    cout << ligne << endl;
}

string Terrain::ligneTerrain() const{

    string ligne;
    ligne += BORDURE_VERTICAL;
    ligne += string((size_t)largeur, ESPACE);
    ligne += BORDURE_VERTICAL;

    return ligne;
}

int Terrain::getLargeur() const {
    return largeur-1;
}

int Terrain::getLongeur() const {
    return longeur-1;
}
