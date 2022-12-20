// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Random.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Classe permettant de générer un nombre aléatoire dans l'interval
//                  [min, max]
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include "Random.h"

using namespace std;

Random::Random() {

    std::random_device rand_dev;

    default_random_engine generator(rand_dev());
    this->generator = generator;
}

int Random::random(int min, int max) {

    uniform_int_distribution<int>  distr(min, max);

    // une valeur entre min et max compris
    return distr(generator);
}