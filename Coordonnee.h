//
// Created by ursbe on 12.12.2022.
//

#ifndef SURVIVOR_COORDONNEE_H
#define SURVIVOR_COORDONNEE_H


class Coordonnee {
public:

    Coordonnee(int x, int y);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    Coordonnee operator+=(const Coordonnee c) const;

private:
    int x;
    int y;
};


#endif //SURVIVOR_COORDONNEE_H
