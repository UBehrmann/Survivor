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

class Terrain {
public:
    const char 	BORDURE_VERTICAL = '|',
            BORDURE_HORIZONTAL = '-',
            ESPACE = ' ';

    Terrain(int largeur, int longeur);
    void affiche(std::vector<Robot>& robots);
    void initializerTerrain(std::vector<Robot>& robots);

    void affiche2(std::vector<Robot> &robots);

    int getLargeur() const;

    int getLongeur() const;

private:
    int largeur;
    int longeur;
    void positionRobot(std::string& terrain_ligne, std::vector<Robot>& robots);
    std::string textFormat(const std::string& strIn);
    std::string terrain;


};


#endif //SURVIVOR_TERRAIN_H
