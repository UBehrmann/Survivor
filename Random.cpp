// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Random.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

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