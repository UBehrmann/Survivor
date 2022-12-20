// PRG1_E
//---------------------------------------------------------------------------------
// Fichier        : Terrain.cpp
// Auteur(s)      : Sirak Mussie et Urs Behrmann
// But            : Classe pour faciliter le stockage et l'utilisation de coordonnee
//                  ( x ; y )
// Modifications  :
// Remarque(s)    : NILL
// Compilateur    : MinGW w64 9.0 / C++20
//---------------------------------------------------------------------------------

#ifndef SURVIVOR_COORDONNEE_H
#define SURVIVOR_COORDONNEE_H


class Coordonnee {
public:

    /**
     * @name Coordonnee
     *
     * Constructeur generique de la classe Coordonnee.
     *
     * @return          : void
     * @throws          : NIL
     */
    Coordonnee() : x(0), y(0) {};

    /**
     * @name Terrain
     *
     * Constructeur de la classe Coordonnee.
     *
     * @param x   : position x
     * @param y   : position y
     * @return    : void
     * @throws    : NIL
     */
    Coordonnee(int x, int y) : x(x), y(y) {};

    /**
     * @name getX
     *
     * Retour la valeur x.
     *
     * @return          : valeur de x
     * @throws          : NIL
     */
    int getX() const{ return x; };

    /**
     * @name getY
     *
     * Retour la valeur y.
     *
     * @return          : valeur de y
     * @throws          : NIL
     */
    int getY() const { return y; };

    /**
     * @name operator+=
     *
     * Operateur += pour la classe Coordonne pour pouvoir addition 2 Coordonnees.
     *
     * @param c   : coordoonnee a ajouter a cette coordonnee
     * @return          : void
     * @throws          : NIL
     */
    void operator+=(const Coordonnee c){ x += c.x; y += c.y; };

private:

    // Variables prives de la classe
    int x;
    int y;
};

#endif //SURVIVOR_COORDONNEE_H
