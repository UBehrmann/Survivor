// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Robot.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_ROBOT_H
#define SURVIVOR_ROBOT_H

#include "Coordonnee.h"
#include "Random.h"
#include <vector>

/**
 * Les déplacements relatifs autorisé de la tondeuse
 */
const std::vector<Coordonnee> DEPLACEMENTS_AUTORISE = {
        {0, -1}, // Haut
        {1, 0},  // Droite
        {0, 1},  // Bas
        {-1, 0}  // Gauche
};

class Robot {
public:
    Robot(int iD, Coordonnee coordonnee, int limiteX, int limiteY);

    //---------------------------------------------------------------------------------
    // nom         deplace
    // but         But de la fonction
    // param       Paramètre envoyer à la fonction
    // return      valeur retourné par la fonction
    // exception   n/a
    //---------------------------------------------------------------------------------
    Coordonnee deplace(Random& random);

    int getId() const;

    const Coordonnee &getCoordonnee() const;

    bool operator!=(const Robot& r) const{ return this->iD != r.getId(); }
    bool operator==(const Robot& r) const{ return this->iD == r.getId(); }
    bool operator<(const Robot& r) const{return this->coordonnee.getY() < r.getCoordonnee().getY
    (); }

private:

    int iD;
    Coordonnee coordonnee;

    int LIMITE_X;
    int LIMITE_Y;
};


#endif //SURVIVOR_ROBOT_H
