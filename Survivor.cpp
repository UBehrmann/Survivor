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
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

Survivor::Survivor(int largueur, int longueur, int nbreObject) : terrain (Terrain(largueur,
                  longueur)), NRE_OBJECT_DEBUT(nbreObject) {

    // reserve la place nécessaire pour nos objects robots
    robots.reserve((size_t)nbreObject);

    Coordonnee coordonnee;

    // Cree les objects robots
    for (int i = 0; i < nbreObject; ++i) {

        // Cherche une coordonnee qui n'est pas occupee par un autre robot
        do {
            coordonnee = coordonneeAleatoir(largueur, longueur);
        }while (estOccupe(coordonnee));

        // Ajoute le robot au vecteur
        robots.push_back(Robot(i, coordonnee, terrain.getLargeur(), terrain.getLongeur()));
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

    // Melange les robots
    shuffle(robots.begin(), robots.end(), default_random_engine((unsigned)random.random(0, 1000)));

    // Bouge chaque robot et controle, si il arrive sur une coordonnee deja occupee par un autre
    // robot.
    for(Robot& r : robots) {

        controlePosition(r.deplace(random), r);

        // Remet en ordre les robots d'apres l'axe des Y
        sort(robots.begin(), robots.end());

        // affiche le terrain
        terrain.affiche(robots);

        // Affiche le tableau des robots tuees
        afficheTableauScore();

        // Attend Xms
        this_thread::sleep_for(25ms);
    }
}

void Survivor::controlePosition(const Coordonnee& c, const Robot& robot) {
    for (Robot r : robots)
        if(r != robot && r.getCoordonnee().getX() == c.getX() && r.getCoordonnee().getY() == c
        .getY()) {
            robotAEteTue(r, robot);
            return;
        }
}

void Survivor::robotAEteTue(const Robot& robotTue, const Robot& robotSurvivant) {
    int compteur = 0;

    for(Robot r : robots){
        if (r == robotTue)
            break;
        compteur++;
    }

    aTuee[NRE_OBJECT_DEBUT - robots.size()] = { robotSurvivant.getId(), robotTue.getId()};

    robots.erase(robots.begin() + compteur);//find(robots.begin(), robots.end(), robotTue) );
}

bool Survivor::fin() {
    return robots.size() > 1;
}

void Survivor::afficheTableauScore() {

    for (size_t i = 0; i < NRE_OBJECT_DEBUT; ++i) {
        if(NRE_OBJECT_DEBUT ==  robots.size() || i > NRE_OBJECT_DEBUT - robots.size() - 1)
            return;
        cout << aTuee[i][0] << " a tue " << aTuee[i][1] << endl;
    }

}
