// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Random.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Classe permettant de générer un nombre aléatoire dans l'interval
//                  [min, max]
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_RANDOM_H
#define SURVIVOR_RANDOM_H

#include <random> // random_device


// Adapter de la démo : https://github.com/gmbreguet/PRG1_DEMO/blob/dccd145b3e99101c98de2d9a87ff05db386e2500/04_Fonctions/04_static_srand.cpp#L36
class Random {
public:
    Random();

    /**
     * @name random
     *
     * Fonction permettant de générer un nombre aléatoire entre un nombre minimal et un nombre maximal
     *
     * @param min valeur minimal que le nombre retourné peut avoir
     * @param max valeur maximal que le nombre retourné peut avoir
     * @return un nombre aléatoire dans l'interval [min, max]
     * @throws NIL
     */
    int random(int min, int max);

private:

    // Variables prives de la classe
    std::default_random_engine generator;

};


#endif //SURVIVOR_RANDOM_H
