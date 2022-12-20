// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : annexe.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Fonction generique pour la saisie de valeur
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_ANNEXE_H
#define SURVIVOR_ANNEXE_H

#include <string>

#define MSG_ERREUR "La valeur n'est pas dans les limites indiquees!"

/**
 * @name saisie
 *
 * Fonction de saisie d'une valeur entre "min" et "max"
 *
 * @param msg           : Message d'indication pour la saisie
 * @param min           : Valeur minimal que le nombre retourné peut avoir
 * @param max           : Valeur maximal que le nombre retourné peut avoir
 * @param msg_erreur    : Message si la valeur saisie est en dehors des limits
 * @return              : Saisie de l'utilisateur entre min et max
 * @throws NIL
 */
int saisie(const std::string& msg, int min, int max, const std::string& msg_erreur = MSG_ERREUR);

/**
 * @name saisieIntro
 *
 * Fonction de saisie d'une valeur entre "min" et "max"
 *
 * @param msg_intro     : Message d'introduction
 * @param msg           : Message d'indication pour la saisie
 * @param min           : Valeur minimal que le nombre retourné peut avoir
 * @param max           : Valeur maximal que le nombre retourné peut avoir
 * @param msg_erreur    : Message si la valeur saisie est en dehors des limits
 * @return              : Saisie de l'utilisateur entre min et max
 * @throws NIL
 */
int saisieIntro(const std::string& msg_intro, const std::string& msg, int min, int max,
                const std::string& msg_erreur = MSG_ERREUR);

#endif //SURVIVOR_ANNEXE_H
