#include "plateau.h"
#include "case.h"
#include "bateau.h"
#include <iostream>
using namespace std;

string Plateau::getNom() const
{
    return m_nom;
}

Plateau::Plateau(string n):m_nom(n)
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        m_plateau[i][j] = new Case(j,i);
        }
    }
m_bateaux[0] = new Bateau("Porte avion",5);
m_bateaux[1] = new Bateau("Destroyer",3);
m_bateaux[2] = new Bateau("Destroyer",3);
m_bateaux[3] = new Bateau("Destroyer",3);
m_bateaux[4] = new Bateau("Patrouilleur",2);
m_bateaux[5] = new Bateau("Patrouilleur",2);
m_bateaux[6] = new Bateau("Sous-Marin",3);
}

void Plateau::placeBateau(Bateau *bat, int x, int y,int x2, int y2)
{
    if (x==x2) {
        if(y<y2){
            for(int i = y ;i<=y2+1;i++){
                Case *caseadd = m_plateau[x][i];
                caseadd->addBateau(bat,i-y);
            }
        } else {
            for(int i = y2 ;i<=y+1;i++){
                Case *caseadd = m_plateau[x][i];
                caseadd->addBateau(bat,i-y2);
            }
        }
    } else {
        if(x<x2){
            for(int i = x ;i<=x2+1;i++){
                Case *caseadd = m_plateau[i][y];
                caseadd->addBateau(bat,i-x);
            }
        } else {
            for(int i = x2 ;i<=x+1;i++){
                Case *caseadd = m_plateau[i][y];
                caseadd->addBateau(bat,i-x2);
            }
        }
    }
}

Case *Plateau::getCase(int x, int y)
{
    return m_plateau[x][y];
}

void Plateau::tir()
{
    string strx;
    string stry;
    cout << "Moussaillon, ciblez un endroit dont vous souhaitez la disparition :" << endl;
    cout << "quelle colonne choisissez vous ? :";
    cin >> strx;
    cout << "quelle ligne choisissez vous ? :";
    cin >> stry;
    int x = stoi(strx);
    int y = stoi(stry);
    if(x>0&&x<11&&y>0&&y<11){
        string strrep;
        cout << "Voulez vous vraiment anihiler le lieu suivant :"<<endl<<"colonne : "<<x<<" ligne : "<<y<<endl;
        cout << "tapez 'oui' pour valider ou autre chose si vous changez d'avis :";
        cin >> strrep;
        if (strrep == "oui" ||strrep == "OUI" ||strrep == "Oui"){
            if (getCase(x-1,y-1)->wasHit()){
                cout << "cet endroit a deja subi votre colere, veuillez en choisir un autre"<<endl;
                tir();
                return;
            }
            if(getCase(x-1,y-1)->touche()){
                cout<<"Bravo moussaillon, un bateau se cachait ici, vous pouvez tirer une autre fois"<<endl;
                tir();
                return;
            } else {
                cout<<"Il n'y a rien ici, vous aurez plus de chance la prochaine fois"<<endl;
                return;
            }
        } else {
            cout << "choisissez bien votre tir moussaillon "<<endl;
            tir();
            return;
        }
    } else {
        cout << "Moussaillon ? avez vous bu trop de rhum ? Cette case n'existe pas, essayez d'entrer un lieu valide."<<endl;
        tir();
        return;
    }

}

string Plateau::getStrPlateau(int l)
{
    string strRet = "|";
    for(int i = 0;i< 10;i++){
        if(m_plateau[l][i]->bateau_ici()&&m_plateau[l][i]->wasHit()){
            strRet += " X |";
        } else if (m_plateau[l][i]->wasHit()){
            strRet += " ~ |";
        } else {
            strRet += "   |";
        }
    }
    return strRet;
}

bool Plateau::lost()
{
    for(int i=0;i<7;i++){
        if (m_bateaux[i]->isAlive()){
            return false;
        }
    }
    return true;
}

Bateau *Plateau::getBateau(int nb)
{
    return m_bateaux[nb];
}

void Plateau::affPlateauPlace()
{
    cout<<"voici votre plateau, placez les bateaux qui se trouvent a droite du plateau"<<endl<<endl<<endl;

    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl<<"   _______________________________________"<<endl;
    cout<<"1 "<<getStrPlateauPlace(0)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"2 "<<getStrPlateauPlace(1)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<endl;
    cout<<"3 "<<getStrPlateauPlace(2)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<< "     Porte avion : longueur 5"<<endl;
    cout<<"4 "<<getStrPlateauPlace(3)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<"      + + + + + quantite 1"<<endl;
    cout<<"5 "<<getStrPlateauPlace(4)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<"     Destroyer : longueur 3"<<endl;
    cout<<"6 "<<getStrPlateauPlace(5)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<"      + + + quantite 3"<<endl;
    cout<<"7 "<<getStrPlateauPlace(6)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<"     Patrouilleur : longueur 2"<<endl;
    cout<<"8 "<<getStrPlateauPlace(7)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<"      + + quantite 2"<<endl;
    cout<<"9 "<<getStrPlateauPlace(8)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<"     Sous-Marin : longueur 3"<<endl;
    cout<<"10"<<getStrPlateauPlace(9)<<endl<<"  |___|___|___|___|___|___|___|___|___|___|"<<"      + + + quantite 1"<<endl;
}

          string Plateau::getStrPlateauPlace(int l)
    {
          string strRet = "|";
          for(int i = 0;i< 10;i++){
              if(m_plateau[i][l]->bateau_ici()){
                  strRet += " + |";
              } else {
                  strRet += "   |";
              }
          }
          return strRet;
}
