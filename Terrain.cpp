// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Classe qui represente le terrain de jeu et qui peut afficher
//                  celui-ci dans la console.
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "Terrain.h"
#include "Robot.h"
#include <iostream>
#include <string>


using namespace std;

Terrain::Terrain(int largeur, int longeur) : LARGEUR(largeur + 1), LONGEUR(longeur + 1) {}

void Terrain::affiche(std::vector<Robot>& robots) const{

    string ligne = string((size_t)LARGEUR + 2, BORDURE_HORIZONTAL);
    const char START = '0';

    vector<Robot>::iterator itRobot = robots.begin();

    // Efface le terminal pour Windows et Linux / Mac
    #if defined(_WIN32) && defined(_WIN64)
		 system("cls");
	 #else //defined(__linux__)
		 system("clear");
	 #endif




    // Bordure superieure
    cout << ligne << endl;

    // Affiche une ligne du terrain
    for (int i = 0; i <= LONGEUR; ++i){

        ligne = ligneTerrainVide();

        // Place les robots qui sont sur cette ligne
        while (itRobot->getCoordonnee().getY() == i - 1 && robots.end() != itRobot){
            ligne.at((size_t)itRobot->getCoordonnee().getX() + 1) = START + (char)
                    itRobot->getId();
            ++itRobot;
        }

        cout << ligne << endl;
    }

    // Bordure inferieure
    ligne = string((size_t)LARGEUR + 2, BORDURE_HORIZONTAL);
    cout << ligne << endl;
}

string Terrain::ligneTerrainVide() const{

    string ligne;
    ligne += BORDURE_VERTICAL;
    ligne += string((size_t)LARGEUR, ESPACE);
    ligne += BORDURE_VERTICAL;

    return ligne;
}

int Terrain::getLargeur() const {
    return LARGEUR - 1;
}

int Terrain::getLongeur() const {
    return LONGEUR - 1;
}
