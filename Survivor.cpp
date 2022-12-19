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
                                                                                  longueur)) {
    // reserve la place nécessaire pour nos objects robots
    robots.reserve((size_t)nbreObject);

    Coordonnee coordonnee;

    // Cree les objects robots
    for (int i = 0; i < nbreObject; ++i) {

        do {
            coordonnee = coordonneeAleatoir(largueur, longueur);
        }while (estOccupe(coordonnee));

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

    // obtain a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(robots.begin(), robots.end(), default_random_engine(seed));


    for(Robot& r : robots) {

        controlePosition(r.deplace(random), r);

        terrain.affiche2(robots);
        cout << endl << deahtList << endl << "Robots restants: " << robots.size() << endl;

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
    const char START = '0';

//    if(robotTue.getCoordonnee().getX() == robotSurvivant.getCoordonnee().getX() && robotTue.getCoordonnee().getY
//    () == robotSurvivant.getCoordonnee().getY())
//        cin.ignore();

//    cout << "Robot tue " << robotTue.getId() << " : " << robotTue.getCoordonnee().getX() << ""
//    " : " << robotTue.getCoordonnee() .getY() << endl;
//
//    cout << "Robot surivant " << robotSurvivant.getId() << " : " << robotSurvivant.getCoordonnee()
//    .getX()
//    << " : "
//                                                                                             "" <<
//    robotSurvivant
//    .getCoordonnee().getY() << endl;
//
//    cin.ignore();


    for(Robot r : robots){
        if (r == robotTue)
            break;
        compteur++;
    }

    deahtList += START + robotSurvivant.getId();
    deahtList += " a tue ";
    deahtList += START + robotTue.getId();
    deahtList += "\n";

    robots.erase(robots.begin() + compteur);//find(robots.begin(), robots.end(), robotTue) );
}

bool Survivor::fin() {
    return robots.size() > 1;
}
