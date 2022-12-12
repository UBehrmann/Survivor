// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Survivor.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_SURVIVOR_H
#define SURVIVOR_SURVIVOR_H

#include <vector>
#include "Robot.h"
#include "Terrain.h"
#include "Coordonnee.h"

class Survivor {
public:
    Survivor(int largueur, int longueur, int nbreObject);

private:
    std::vector<Robot> robots;

    Terrain terrain;

};


#endif //SURVIVOR_SURVIVOR_H
