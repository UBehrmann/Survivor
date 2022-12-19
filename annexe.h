// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : annexe.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            :
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_ANNEXE_H
#define SURVIVOR_ANNEXE_H
#include <string>

int saisie(const std::string& MSG, const int MIN, const int MAX, const std::string& MSG_ERROR);
int saisie(const std::string& MSG_INTRO, const std::string& MSG, const int MIN, const int MAX,
           const std::string&
MSG_ERROR);

#endif //SURVIVOR_ANNEXE_H
