// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Random.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include <chrono>
#include "Random.h"

using namespace std;

Random::Random() {
    default_random_engine generator(rand_dev());
    this->generator = generator;
}

int Random::random(int min, int max) {
    uniform_int_distribution<int>  distr(min, max);

    // une valeur entre min et max compris
    return distr(generator);
}

void Random::melangeRobots(Robots& robots) {

    // obtain a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(robots.begin(), robots.end(), default_random_engine(seed));

}
