//
// Created by ursbe on 12.12.2022.
//

#ifndef SURVIVOR_COORDONNEE_H
#define SURVIVOR_COORDONNEE_H


class Coordonnee {
public:

    Coordonnee() : x(0), y(0) {};

    Coordonnee(int x, int y);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    void operator+=(const Coordonnee c);

private:
    int x;
    int y;
};


#endif //SURVIVOR_COORDONNEE_H
