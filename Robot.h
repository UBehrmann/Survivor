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

class Robot {
public:
    explicit Robot(int iD, Coordonnee coordonnee);

    //---------------------------------------------------------------------------------
    // nom         deplace
    // but         But de la fonction
    // param       Paramètre envoyer à la fonction
    // return      valeur retourné par la fonction
    // exception   n/a
    //---------------------------------------------------------------------------------
    int deplace();

private:

    int iD;
    Coordonnee coordonnee;


};


#endif //SURVIVOR_ROBOT_H
