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
#include <iostream>
using namespace std;

Terrain::Terrain(int largeur, int longeur) {
    for (int ligne = 0; ligne <= largeur; ++ligne) {
        // TODO: affiche robot
        for (int colonne = 0; colonne <= longeur; ++colonne) {
            if (ligne == 0 && ligne == largeur) {//premier ligne et dernier ligne
                cout << '-';
            } else {
                if(colonne == 0 && colonne == longeur) {
                    cout << '|';
                } else { //affiche robot position robot dans
                    // ligne
                    cout << (Robot(ligne,colonne)) ? Robot.id : ' ';
                }


            }
        }
    }
}

Terrain::Terrain(int largeur, int longeur) : largeur(largeur), longeur(longeur) {}
