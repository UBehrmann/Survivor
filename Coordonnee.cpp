//
// Created by ursbe on 12.12.2022.
//

#include "Coordonnee.h"

int Coordonnee::getX() const {
    return x;
}

void Coordonnee::setX(int x) {
    Coordonnee::x = x;
}

int Coordonnee::getY() const {
    return y;
}

void Coordonnee::setY(int y) {
    Coordonnee::y = y;
}

Coordonnee::Coordonnee(int x, int y) : x(x), y(y) {}
