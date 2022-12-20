// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Survivor
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Classe "Game master" qui contient tous les objets du jeu et
//                  manage le deroulement du jeu.
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

    melangeRobots();

    // Bouge chaque robot et controle, s'il arrive sur une coordonnee deja occupee par un autre
    // robot.
    for(Robot& robot : robots) {

        robot.deplace(random);

        controlePosition(robot);
    }

    trieRobots();

    // affiche le terrain
    terrain.affiche(robots);

    // Affiche le tableau des robots tuees
    afficheTableauScore();

    // Attend Xms
    this_thread::sleep_for(dureeTick);
}

void Survivor::controlePosition(const Robot& robot) {
    // Verifie si un robot autre que celui qui vient de se deplacer se situe a la position ou le robot vient de se mettre
    // Si oui alors celui-ci est tuee.
    for (Robot r : robots)
        if(r != robot && r.getCoordonnee().getX() == robot.getCoordonnee().getX() &&
        r.getCoordonnee().getY() == robot.getCoordonnee().getY()) {
            robotAEteTue(r, robot);
            return;
        }
}

void Survivor::robotAEteTue(const Robot& robotTue, const Robot& robotSurvivant) {
    int compteur = 0;

    // trouve l'indice du robot tuee dans le vecteur de robot
    for(Robot r : robots){
        if (r == robotTue)
            break;
        compteur++;
    }

    // Ajoute l'id du robot qui a tue et celui qui a ete tue au tableau de score
    aTuee[NRE_OBJECT_DEBUT - robots.size()] = { robotSurvivant.getId(), robotTue.getId()};

    // Supprime le robot tuee du vecteur de robot
    robots.erase(robots.begin() + compteur);//find(robots.begin(), robots.end(), robotTue) );
}

void Survivor::afficheTableauScore() {

    for (size_t i = 0; i < NRE_OBJECT_DEBUT; ++i) {
        if(NRE_OBJECT_DEBUT ==  robots.size() || i > NRE_OBJECT_DEBUT - robots.size() - 1)
            return;
        cout << aTuee[i][0] << " a tue " << aTuee[i][1] << endl;
    }

}

void Survivor::melangeRobots() {
    // Prise de https://cplusplus.com/reference/algorithm/shuffle/

    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(robots.begin(), robots.end(), default_random_engine(seed));
}


void Survivor::trieRobots() {
    // Remet en ordre les robots d'apres l'axe des Y
    sort(robots.begin(), robots.end());
}