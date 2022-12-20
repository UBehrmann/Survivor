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

// Constructeur
Robot::Robot(int iD, Coordonnee coordonnee, int limiteX, int limiteY) : iD(iD), coordonnee
(coordonnee), LIMITE_X(limiteX), LIMITE_Y(limiteY) {}

void Robot::deplace(Random& random) {

    Coordonnee coordonneTmp;

    // Cherche un deplacement autorisé pour le robot
    do {
        coordonneTmp = DEPLACEMENTS_AUTORISE[(size_t)random.random(0, 3)];

        coordonneTmp += coordonnee;

    } while (coordonneTmp.getX() < 0 || coordonneTmp.getX() > LIMITE_X ||
                coordonneTmp.getY() < 0 || coordonneTmp.getY() > LIMITE_Y);

    // Set la nouvelle position au robot
    coordonnee = coordonneTmp;
}

int Robot::getId() const {
    return iD;
}

const Coordonnee &Robot::getCoordonnee() const {
    return coordonnee;
}
