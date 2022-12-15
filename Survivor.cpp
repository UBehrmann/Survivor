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

using namespace std;

Survivor::Survivor(int largueur, int longueur, int nbreObject) : terrain (Terrain(largueur,
                                                                                  longueur)) {
    // reserve la place nécessaire pour nos objects robots
    robots.reserve((size_t)nbreObject);

    Coordonnee coordonnee = coordonneeAleatoir(largueur, longueur);

    // Cree les objects robots
    for (int i = 0; i < nbreObject; ++i) {

        while (estOccupe(coordonnee))
            coordonnee = coordonneeAleatoir(largueur, longueur);

        robots.push_back(Robot(i, coordonnee));
    }
}

bool Survivor::estOccupe(Coordonnee c) const {
    for (Robot r : robots)
        if(r.getCoordonnee().getX() == c.getX() && r.getCoordonnee().getY() == c.getY())
            return true;

    return false;
}

Coordonnee Survivor::coordonneeAleatoir(int largueur, int longueur) {
    return Coordonnee(random.random(0, largueur), random.random(0, longueur));
}

void Survivor::etappe() {


    Random::melangeRobots(robots);

    for(Robot r : robots)
        controlePosition(r.deplace(random), r);

    terrain.affiche(robots);

}

void Survivor::controlePosition(const Coordonnee& c, const Robot& robot) {
    for (Robot r : robots)
        if(r != robot && r.getCoordonnee().getX() == c.getX() && r.getCoordonnee().getY() == c.getY())
            robotAEteTue(r, robot);
}

void Survivor::robotAEteTue(const Robot& robotTue, const Robot& robotSurvivant) {

    // TODO: Ecrire l'historique "A killed B"
    robots.erase(find(robots.begin(), robots.end(), robotTue));
}
