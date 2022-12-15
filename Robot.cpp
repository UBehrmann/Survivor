// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Robot.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "Robot.h"

Robot::Robot(int iD, Coordonnee coordonnee) : iD(iD), coordonnee(coordonnee){}

Coordonnee Robot::deplace(Random& random) {

    Coordonnee c = DEPLACEMENTS_AUTORISE[(size_t)random.random(0,3)];

    coordonnee += c;

    return c;
}

int Robot::getId() const {
    return iD;
}

void Robot::setId(int iD) {
    Robot::iD = iD;
}

const Coordonnee &Robot::getCoordonnee() const {
    return coordonnee;
}

void Robot::setCoordonnee(const Coordonnee &coordonnee) {
    Robot::coordonnee = coordonnee;
}
