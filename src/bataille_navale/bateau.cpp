#include "bateau.h"
#include <list>

int Bateau::longueur() const
{
    return m_longueur;
}

string Bateau::nom() const
{
    return m_nom;
}

Bateau::Bateau(string n, int l):m_nom(n),m_longueur(l),m_etat(true)
{
   list<bool> init;
   for(int i=0;i<l;i++){
       init.push_back(true);
   }
   m_etat_parties = init;
}

void Bateau::destroy()
{
    m_etat = false;
}

void Bateau::hit(int p)
{
    int i = 0;
    list<bool> etat_parties;
    list<bool>::iterator itEtat;
    for(itEtat=m_etat_parties.begin();itEtat!=m_etat_parties.end();itEtat++){
        if(i==p){
            etat_parties.push_back(false);
        } else {
            etat_parties.push_back(*itEtat);
        }
        i++;
    }
    m_etat_parties = etat_parties;
}

bool Bateau::isAlive()
{
    if(m_etat == false){
        return false;
    } else {
        list<bool>::iterator itEtat;
        for(itEtat=m_etat_parties.begin();itEtat!=m_etat_parties.end();itEtat++){
            bool etat=*itEtat;
            if(etat){
                return true;
            }
        }
        destroy();
        return false;
    }
}
