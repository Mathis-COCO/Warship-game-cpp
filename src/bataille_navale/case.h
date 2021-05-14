#ifndef CASE_H
#define CASE_H
#include "string"
using namespace std;
#include "bateau.h"


class Case
{
private:
    Bateau *m_bateau;
    bool m_bateau_ici;
    int m_partie_bateau;
    bool m_touche;
    int m_x;
    int m_y;
public:
    Case(int x, int y);
    bool touche();
    bool wasHit();
    void addBateau(Bateau *bateau,int partie);
    Bateau *bateau() const;
    int partie_bateau() const;
    bool bateau_ici() const;
};

#endif // CASE_H
