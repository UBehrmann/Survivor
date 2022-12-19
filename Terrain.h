// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_TERRAIN_H
#define SURVIVOR_TERRAIN_H
#include <string>
#include <vector>
#include "Robot.h"

const char 	BORDURE_VERTICAL = '|',
        BORDURE_HORIZONTAL = '-',
        ESPACE = ' ';

class Terrain {
public:

    Terrain(int largeur, int longeur);

    void affiche(std::vector<Robot>& robots) const;

    int getLargeur() const;

    int getLongeur() const;

private:
    int largeur;
    int longeur;

    std::string ligneTerrain() const;
};


#endif //SURVIVOR_TERRAIN_H
