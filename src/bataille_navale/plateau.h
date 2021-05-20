#ifndef PLATEAU_H
#define PLATEAU_H
#include "case.h"
#include "bateau.h"
#include <string>
using namespace std;

class Plateau
{
private:
    string m_nom;
    Case *m_plateau[10][10];
    Bateau *m_bateaux[7];
public:
    Plateau(string n);
    bool placeBateau(Bateau *bat,int x, int y,int x2, int y2);
    Case *getCase(int x, int y);
    void tir();
    string getStrPlateau(int l);
    bool lost();
    Bateau *getBateau(int nb);
    void affPlateauPlace();
    string getStrPlateauPlace(int l);
    string getNom() const;
};

#endif // PLATEAU_H
