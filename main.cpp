// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Nous souhaitons simuler des robots autonomes dans un espaces
//                  donné.
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#include <iostream>
#include "Survivor.h"
#include <limits>               // Utilisation de numeric limits
#include <thread>

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {
    Survivor survivor(20, 20, 5);

    while (true){

        survivor.etappe();

        this_thread::sleep_for(100ms);
    }

    return 0;
}
