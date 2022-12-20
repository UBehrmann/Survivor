// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Survivor.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Classe "Game master" qui contient tous les objets du jeu et
//                  manage le deroulement du jeu.
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_SURVIVOR_H
#define SURVIVOR_SURVIVOR_H

#include <vector>
#include <array>
#include "Terrain.h"
#include "Coordonnee.h"
#include "Random.h"
#include "Robot.h"

using Robots = std::vector<Robot>;
using ListeTuee = std::array<std::array<int,2>, 10>;

#define dureeTick 250ms

class Survivor {
public:

    /**
     * @name Survivor
     *
     * Constructeur de la classe Survivor
     *
     * @param largueur      : LARGEUR du terrain du jeu
     * @param longueur      : longueur du terrain du jeu
     * @param nbreObject    : nombre de robot qui font être initialise dans le terrain
     * @return              : void
     * @throws              : NIL
     */
    Survivor(int largueur, int longueur, int nbreObject);

    /**
     * @name etappe
     *
     * Une etappe du jeu ou tous les robots sont bouges, les robots tues supprimes et le terrain affiche.
     *
     * @return              : void
     * @throws              : NIL
     */
    void etappe();

    /**
     * @name operator()
     *
     * Fonction qui retour faux pour signifier la fin du jeu, lorsque plus qu'un robot est sur le terrain
     *
     * @return              : Faux, s'il n'y a plus qu'un robot, sinon vrai.
     * @throws              : NIL
     */
     bool operator() (){ return robots.size() > 1; };

private:

    // Variables prives de la classe

    Robots robots;
    Terrain terrain;
    Random random;
    ListeTuee aTuee;
    const size_t NRE_OBJECT_DEBUT;

    // Fonction privee

    /**
     * @name estOccupe
     *
     * Verifie si la coordonnee est occupee ou non par un robot.
     *
     * @param coordonnee    : Coordonnee teste
     * @return              : Vrai, si la coordonne est occupe, sinon faux
     * @throws              : NIL
     */
    bool estOccupe(Coordonnee coordonnee) const;

    /**
     * @name coordonneeAleatoir
     *
     * Genere une coordonnee aleatoir d'apres les parametres de taille du terrain.
     *
     * @param largueur  : Largueur du terrain
     * @param longueur  : Longeur du terrain
     * @return          : Une coordonne aleatoir du terrain specifie
     * @throws   : NIL
     */
    Coordonnee coordonneeAleatoir(int largueur, int longueur);

    /**
     * @name controlePosition
     *
     * Controle laa coordonnee sur laquelle le robot a ete deplace, si il y a un autre robot.
     *
     * @param robot         : robot qui a bouge
     * @return              : void
     * @throws              : NIL
     */
    void controlePosition(const Robot& robot);

    /**
     * @name robotAEteTue
     *
     * Additionne les positions x et y de deux coordonnées.
     *
     * @param robotTue          : Première coordonnée
     * @param robotSurvivant    : Deuxième coordonnée
     * @return                  : void
     * @throws                  : NIL
     */
    void robotAEteTue(const Robot& robotTue, const Robot& robotSurvivant);

    /**
     * @name afficheTableauScore
     *
     * Affiche quelle robot a ete tue par quelle robot.
     *
     * @return   : void
     * @throws   : NIL
     */
    void afficheTableauScore();

    /**
     * @name melangeRobots
     *
     * Melange le vecteur de robot robots
     *
     * @return   : void
     * @throws   : NIL
     */
    void melangeRobots();

    /**
     * @name trieRobots
     *
     * Trie le vecteur de robot robots.
     *
     * @return   : void
     * @throws   : NIL
     */
    void trieRobots();
};

#endif //SURVIVOR_SURVIVOR_H
