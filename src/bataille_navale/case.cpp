#include "case.h"
#include "plateau.h"

Bateau *Case::bateau() const
{
    return m_bateau;
}

int Case::partie_bateau() const
{
    return m_partie_bateau;
}

bool Case::bateau_ici() const
{
    return m_bateau_ici;
}

Case::Case(int x, int y):m_x(x),m_y(y),m_touche(false),m_bateau_ici(false)
{
}

bool Case::touche()
{
    if(m_bateau_ici){
        m_bateau->hit(m_partie_bateau);
        return true;
    } else {
        return false;
    }
    m_touche = true;
}

bool Case::wasHit()
{
    if(m_touche){
        return true;
    } else {
        return false;
    }
}

void Case::addBateau(Bateau *bateau, int partie)
{
    m_bateau = bateau;
    m_partie_bateau = partie;
    m_bateau_ici = true;
}
