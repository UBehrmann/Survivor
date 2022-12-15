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
#include "random.h"

class Survivor {
public:
    Survivor(int largueur, int longueur, int nbreObject);

    void etappe();

private:
    std::vector<Robot> robots;

    Terrain terrain;

    Random random;

    bool estOccupe(Coordonnee coordonnee) const;

    Coordonnee coordonneeAleatoir(int largueur, int longueur);

    void controlePosition(const Coordonnee& coordonnee, const Robot& robot);

    void robotAEteTue(const Robot& robotTue, const Robot& robotSurvivant);
};


#endif //SURVIVOR_SURVIVOR_H
