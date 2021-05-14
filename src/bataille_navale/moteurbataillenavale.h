#ifndef MOTEURBATAILLENAVALE_H
#define MOTEURBATAILLENAVALE_H
#include "plateau.h"

class MoteurBatailleNavale
{
private:
    Plateau j1 = Plateau("1");
    Plateau j2 = Plateau("2");
public:
    MoteurBatailleNavale();
    bool verifVictoire(Plateau joueurennemi);
    void placeBateaux();
    void joue1Tour(Plateau joueur);
    void print(Plateau jactif, Plateau jafk);
    Plateau getJ1() const;
    Plateau getJ2() const;
};

#endif // MOTEURBATAILLENAVALE_H
