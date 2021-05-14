#include "moteurbataillenavale.h"
#include "plateau.h"
#include "bateau.h"
#include <iostream>
using namespace std;

Plateau MoteurBatailleNavale::getJ1() const
{
    return j1;
}

Plateau MoteurBatailleNavale::getJ2() const
{
    return j2;
}

MoteurBatailleNavale::MoteurBatailleNavale()
{

}

bool MoteurBatailleNavale::verifVictoire(Plateau joueurennemi)
{
    if (joueurennemi.lost()){
        return false;
    } else {
        return true;
    }
}

void MoteurBatailleNavale::placeBateaux()
{
    cout<<"Les joueurs vont chacun leur tour placer leurs bateaux, pour eviter toute triche on ne les remontrera pas"<<endl;
    cout<<"c'est au tour du joueur 1"<<endl;
    for(int i =0;i<7;i++){
        j1.affPlateauPlace();
        Bateau *bat =j1.getBateau(i);
        string strx;
        string stry;
        cout<<endl<<"bateau n° "<<i<<", "<<bat->nom()<<" longueur :"<<bat->longueur();
        cout<<endl<<" sur quelle colonne souhaitez vous placer le debut du bateau ? :";
        cin>>strx;
        cout<<endl<<" sur quelle ligne voulez vous placer le debut du bateau ? :";
        cin>>stry;
        int x = stoi(strx);
        int y = stoi(stry);
        cout<<endl<<" longueur :"<<bat->longueur();
        cout<<endl<<" sur quelle colonne souhaitez vous placer la fin du bateau ? :";
        cin>>strx;
        cout<<endl<<" sur quelle ligne voulez vous placer la fin du bateau ? :";
        cin>>stry;
        int x2 = stoi(strx);
        int y2 = stoi(stry);
        if (x==x2&& abs(y-y2)==bat->longueur()-1 &&x>0&&11>x&&x2>0&&11>x2&&y>0&&11>y&&y2>0&&11>y2){
            j1.placeBateau(bat,x,y,x2,y2);
        } else if (y==y2&& abs(x-x2)==bat->longueur()-1 &&x>0&&11>x&&x2>0&&11>x2&&y>0&&11>y&&y2>0&&11>y2){
            j1.placeBateau(bat,x,y,x2,y2);
        } else {
            cout<<endl<<"Moussaillon, tu places tes bateaux n'importe comment, recommence"<<endl;
            i--;
        }
    }
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"c'est au tour du joueur 2, nous avons sauté quelques lignes pour éviter la triche"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    for(int i =0;i<7;i++){
        j2.affPlateauPlace();
        Bateau *bat =j2.getBateau(i);
        string strx;
        string stry;
        cout<<endl<<"bateau n° "<<i<<", "<<bat->nom()<<" longueur :"<<bat->longueur();
        cout<<endl<<" sur quelle colonne souhaitez vous placer le debut du bateau ? :";
        cin>>strx;
        cout<<endl<<" sur quelle ligne voulez vous placer le debut du bateau ? :";
        cin>>stry;
        int x = stoi(strx);
        int y = stoi(stry);
        cout<<endl<<" longueur :"<<bat->longueur();
        cout<<endl<<" sur quelle colonne souhaitez vous placer la fin du bateau ? :";
        cin>>strx;
        cout<<endl<<" sur quelle ligne voulez vous placer la fin du bateau ? :";
        cin>>stry;
        int x2 = stoi(strx);
        int y2 = stoi(stry);
        if (x==x2&& abs(y-y2)==bat->longueur()-1 &&x>0&&11>x&&x2>0&&11>x2&&y>0&&11>y&&y2>0&&11>y2){
            j2.placeBateau(bat,x,y,x2,y2);
        } else if (y==y2&& abs(x-x2)==bat->longueur()-1 &&x>0&&11>x&&x2>0&&11>x2&&y>0&&11>y&&y2>0&&11>y2){
            j2.placeBateau(bat,x,y,x2,y2);
        } else {
            cout<<endl<<"Moussaillon, tu places tes bateaux n'importe comment, recommence"<<endl;
            i--;
        }
    }


}

void MoteurBatailleNavale::joue1Tour(Plateau joueur)
{
   cout<<"joueur "<<joueur.getNom()<<" c'est a toi"<<endl;
   cout<<" voici le plateau : "<<endl;
   joueur.tir();
}

void MoteurBatailleNavale::print(Plateau jactif, Plateau jafk)
{
    cout<<"               Votre Plateau              "<<"    |    "<<"               Plateau ennemi             "<<endl;
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<"    |    "<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    cout<<"  _______________________________________ "<<"    |    "<<"  _______________________________________ "<<endl;
    cout<<"1 "<<jactif.getStrPlateau(0)<<"    |    "<<"1 "<<jafk.getStrPlateau(0)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"2 "<<jactif.getStrPlateau(1)<<"    |    "<<"2 "<<jafk.getStrPlateau(1)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"3 "<<jactif.getStrPlateau(2)<<"    |    "<<"3 "<<jafk.getStrPlateau(2)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"4 "<<jactif.getStrPlateau(3)<<"    |    "<<"4 "<<jafk.getStrPlateau(3)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"5 "<<jactif.getStrPlateau(4)<<"    |    "<<"5 "<<jafk.getStrPlateau(4)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"6 "<<jactif.getStrPlateau(5)<<"    |    "<<"6 "<<jafk.getStrPlateau(5)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"7 "<<jactif.getStrPlateau(6)<<"    |    "<<"7 "<<jafk.getStrPlateau(6)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"8 "<<jactif.getStrPlateau(7)<<"    |    "<<"8 "<<jafk.getStrPlateau(7)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"9 "<<jactif.getStrPlateau(8)<<"    |    "<<"9 "<<jafk.getStrPlateau(8)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"10"<<jactif.getStrPlateau(9)<<"    |    "<<"10"<<jafk.getStrPlateau(9)<<endl;
    cout<<"  |___|___|___|___|___|___|___|___|___|___|"<<"    |    "<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;

}
