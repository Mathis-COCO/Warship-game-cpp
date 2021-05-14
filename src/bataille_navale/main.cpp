#include <iostream>
#include "bateau.h"
#include "case.h"
#include "plateau.h"
#include "moteurbataillenavale.h"

using namespace std;

void testBateau(){
    Bateau bat = Bateau("test",2);
    cout << bat.isAlive() << endl;
    bat.hit(1);
    cout << bat.isAlive() << endl;
    bat.hit(0);
    cout << bat.isAlive() << endl;
}


void testCase(){
    Case case1 = Case(1,2);
    Case case2 = Case(1,1);
    Bateau *bat = new Bateau("test",2);
    case1.addBateau(bat,1);
    case2.addBateau(bat,0);
    cout << case1.touche() << endl;
    cout << bat->isAlive() << endl;
    cout << case2.touche() << endl;
    cout << bat->isAlive() << endl;
}

void testPlateau(){
    Plateau plat1("AAAAAAAA");
    Bateau *bat1 = new Bateau("test",3);
    plat1.placeBateau(bat1,2,5,5,5);
    plat1.tir();
    plat1.tir();
    plat1.tir();
    plat1.tir();
}

void jeu(){
    MoteurBatailleNavale moteur;
    moteur.placeBateaux();
    bool victoire = false;
    while (!victoire) {
        moteur.print(moteur.getJ1(),moteur.getJ2());
        moteur.joue1Tour(moteur.getJ1());
        if (moteur.verifVictoire(moteur.getJ2())){
            cout<<"----------------------------------------------"<<endl<<endl<<endl<<"Victoire du joueur 1, Ce fut un beau combat"<<endl<<endl<<endl<<"----------------------------------------------";
            victoire = true;
        }
        moteur.print(moteur.getJ2(),moteur.getJ1());
        moteur.joue1Tour(moteur.getJ2());
        if (moteur.verifVictoire(moteur.getJ2())) {
            cout<<"----------------------------------------------"<<endl<<endl<<endl<<"Victoire du joueur 2, Ce fut un beau combat"<<endl<<endl<<endl<<"----------------------------------------------";
            victoire = true;
        }
    }
}


int main()
{
    jeu();
    return 0;
}
