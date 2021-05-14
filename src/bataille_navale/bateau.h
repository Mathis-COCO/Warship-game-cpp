#ifndef BATEAU_H
#define BATEAU_H
#include <string>
using namespace std;
#include <list>

class Bateau
{
private:
    string m_nom;
    int m_longueur;
    bool m_etat;
    list<bool> m_etat_parties;
public:
    Bateau(string n, int l);
    void destroy();
    void hit(int p);
    bool isAlive();
    int longueur() const;
    string nom() const;
};

#endif // BATEAU_H
