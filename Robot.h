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
 * Les déplacements relatifs autorisé d'un robot
 */
const std::vector<Coordonnee> DEPLACEMENTS_AUTORISE = {
        {0, -1}, // Haut
        {1, 0},  // Droite
        {0, 1},  // Bas
        {-1, 0}  // Gauche
};

class Robot {
public:
    /**
     * @name Robot
     *
     * Constructeur de l'objet robot
     *
     * @param iD            : ID du robot
     * @param coordonnee    : Coordonnee de creation du robot
     * @param limiteX       : Limite x du terrain
     * @param limiteY       : Limite y du terrain
     * @return              : void
     * @throws              : NIL
     */
    Robot(int iD, Coordonnee coordonnee, int limiteX, int limiteY);

    /**
     * @name deplace
     *
     * Deplace le robot dans une direction aleatoir.
     *
     * @param random    : Class generateur de chiffre aleatoire crée par la classe Survivor
     * @return          : void
     * @throws          : NIL
     */
    void deplace(Random& random);

    /**
     * @name getId
     *
     * Retour l'ID du robot
     *
     * @return   : L'ID du robot
     * @throws   : NIL
     */
    int getId() const;

    /**
     * @name getCoordonnee
     *
     * Retour les Coordonnee du robot
     *
     * @return   : Un objet Coordonnee qui est la position du robot sur le terrain
     * @throws   : NIL
     */
    const Coordonnee &getCoordonnee() const;

    bool operator!=(const Robot& r) const{ return this->iD != r.getId(); }
    bool operator==(const Robot& r) const{ return this->iD == r.getId(); }
    bool operator<(const Robot& r) const{return this->coordonnee.getY() < r.getCoordonnee().getY(); }

private:

    // Variables prives de la classe
    int iD;
    Coordonnee coordonnee;

    int LIMITE_X;
    int LIMITE_Y;
};


#endif //SURVIVOR_ROBOT_H
