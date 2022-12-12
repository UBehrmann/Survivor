// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Survivor
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "Survivor.h"
#include "Coordonnee.h"

bool estOccupe(Robot robot, Coordonnee coordonnee){

}

Survivor::Survivor(int largueur, int longueur, int nbreObject) : terrain (Terrain(largueur,
                                                                                  longueur)) {
    // reserve la place nécessaire pour nos objects robots
    robots.reserve((size_t)nbreObject);

    Coordonnee coordonnee(1,1);

    // Cree les objects robots
    for (int i = 0; i < nbreObject; ++i) {
        while ()
        for (Robot robot : robots) {
            if(robot.coordonnee.getX() == coordonnee.getX())
        }
        robots.push_back(Robot(i));
    }
}
