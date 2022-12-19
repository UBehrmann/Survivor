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

void Terrain::initializerTerrain(vector<Robot>& robots){
    //return le terrain

//    for (int ligne; ligne <= largeur; ++ligne){
//        if (ligne == 0 or ligne == largeur) {
//            terrain[ligne] = string(largeur + 2, BORDURE_HORIZONTAL); //setw 2
//        } else {
//            terrain[ligne] = textFormat(string(largeur, ESPACE));
//
//        }
//    }
    positionRobot(terrain, robots);


}

void Terrain::affiche(std::vector<Robot>& robots) {
    system("cls");
    for (int ligne = 0; ligne <= longeur; ++ligne) {
        // ligne
        //cout << terrain << endl;
    }
}

string Terrain::textFormat(const string& strIn) {
    return string(BORDURE_VERTICAL + strIn + BORDURE_VERTICAL + '\n');
}

void Terrain::positionRobot(string& terrain_ligne, vector<Robot>& robots) {
    for (const Robot& r : robots){
//        terrain_ligne[(r.getCoordonnee().getX())].replace((r.getCoordonnee().getY()), r.getId());
    }
}

Terrain::Terrain(int largeur, int longeur) : largeur(largeur + 1), longeur(longeur + 1) {}

void Terrain::affiche2(std::vector<Robot>& robots){
    string ligne2 = string((size_t)largeur + 2, BORDURE_HORIZONTAL);
    const char START = '0';

    system("cls");

    cout << ligne2 << endl;

    for (int ligne = 0; ligne <= longeur; ++ligne){
        ligne2.clear();
        ligne2 += BORDURE_VERTICAL;
        ligne2 += string((size_t)largeur, ESPACE);
        ligne2 += BORDURE_VERTICAL;

        for (Robot r : robots) {
            if (r.getCoordonnee().getY() == ligne - 1)
                ligne2.at(r.getCoordonnee().getX() +1 ) = START + r.getId();
        }

        cout << ligne2 << endl;

    }

    ligne2 = string((size_t)largeur + 2, BORDURE_HORIZONTAL);

    cout << ligne2 << endl;
}

int Terrain::getLargeur() const {
    return largeur-1;
}

int Terrain::getLongeur() const {
    return longeur-1;
}
