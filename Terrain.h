// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.h
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Classe qui represente le terrain de jeu et qui peut afficher
//                  celui-ci dans la console.
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_TERRAIN_H
#define SURVIVOR_TERRAIN_H

#include <string>
#include <vector>
#include "Robot.h"

const char 	BORDURE_VERTICAL = '|',
            BORDURE_HORIZONTAL = '-',
            ESPACE = ' ';

class Terrain {
public:

    /**
     * @name Terrain
     *
     * Constructeur de la classe Terrain.
     *
     * @param largeur   : Largeur du terrain
     * @param longeur   : Longeur du terrain
     * @return          : void
     * @throws          : NIL
     */
    Terrain(int largeur, int longeur);

    /**
     * @name affiche
     *
     * Affiche le terrain de jeu.
     *
     * @param robots    : Vecteur des robots sur le terrain
     * @return          : void
     * @throws          : NIL
     */
    void affiche(std::vector<Robot>& robots) const;

    /**
     * @name estOccupe
     *
     * Retour la largeur du terrain.
     *
     * @return              : La largeur du terrain
     * @throws              : NIL
     */
    int getLargeur() const;

    /**
     * @name getLongeur
     *
     * Retour la longeur du terrain.
     *
     * @return              : La longeur du terrain
     * @throws              : NIL
     */
    int getLongeur() const;

private:

    // Variables prives de la classe
    const int LARGEUR;
    const int LONGEUR;


    // Fonction privee de la classer

    /**
     * @name ligneTerrainVide
     *
     * Cree une ligne du terrain vide.
     *
     * @return              : Un string qui represente une ligne de terrain.
     * @throws              : NIL
     */
    std::string ligneTerrainVide() const;
};


#endif //SURVIVOR_TERRAIN_H
