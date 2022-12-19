// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Robot.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include <iostream>
#include "Robot.h"

using namespace std;


Robot::Robot(int iD, Coordonnee coordonnee, int limiteX, int limiteY) : iD(iD), coordonnee
(coordonnee), LIMITE_X(limiteX), LIMITE_Y(limiteY) {}

Coordonnee Robot::deplace(Random& random) {

    Coordonnee c;

    do {
        c = DEPLACEMENTS_AUTORISE[(size_t)random.random(0,3)];

        c += coordonnee;

    } while (c.getX() < 0 || c.getX() > LIMITE_X || c.getY() < 0 || c.getY() > LIMITE_Y);

    coordonnee = c;

    return c;
}

int Robot::getId() const {
    return iD;
}

const Coordonnee &Robot::getCoordonnee() const {
    return coordonnee;
}
