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
#include <array>
#include "Terrain.h"
#include "Coordonnee.h"
#include "Random.h"
#include "Robot.h"

using Robots = std::vector<Robot>;
using ListeTuee = std::array<std::array<int,2>, 10>;

class Survivor {
public:
    Survivor(int largueur, int longueur, int nbreObject);

    void etappe();

    bool fin();

private:
    Robots robots;

    Terrain terrain;

    Random random;

    std::string deathList;

    ListeTuee aTuee;

    const size_t NRE_OBJECT_DEBUT;

    bool estOccupe(Coordonnee coordonnee) const;

    Coordonnee coordonneeAleatoir(int largueur, int longueur);

    void controlePosition(const Coordonnee& coordonnee, const Robot& robot);

    void robotAEteTue(const Robot& robotTue, const Robot& robotSurvivant);

    void afficheTableauScore();
};

#endif //SURVIVOR_SURVIVOR_H
