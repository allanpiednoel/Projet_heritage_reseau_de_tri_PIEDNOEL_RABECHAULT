#include "baston.h"
#include <QDebug>
#include <QList>


baston::baston()
{
}

bool baston::match_nul(Individu *ind1, Individu *ind2)
// pour utiliser ces deux fonctions, if(better=false && less ==false){match nul}; else beter == true: i1 gagne;
//si c'est vrai, ind1 gagne

{
   if ((ind1->m_skill-ind2->m_skill)>(-10)&&(ind1->m_skill-ind2->m_skill<10)){
       //qDebug()<<"match nul";
   return true;}
   //qDebug()<<"pas match nul";
   return false;
}

int baston::match(Individu *ind1, Individu *ind2)
{int vainqueur =0;
    if (match_nul(ind1,ind2)==false)
    {

        if(ind1->m_skill>ind2->m_skill){
            vainqueur = 1;
        }
        else if (ind1->m_skill<ind2->m_skill){
            vainqueur = 2;
        }
    }
    return vainqueur;
}

void baston::tournoi(int numfam,Individu *i1, QList <Individu *>&l)
{//faire combattre un individu d'une famille avec chaques inds de la famille adverse
    //creation des stats
    int victoire=0;
    int defaite=0;
    int ratio=0;

    //pour chaques membres de la famille, les faire se battre avec l'individu
    foreach (Individu *ind,l) {
        match(i1,ind);

        //conditions d'attribution des stats
        if (numfam==1){

            if(match(i1,ind)==1)victoire +=match(i1,ind);
            else defaite+=victoire +=match(i1,ind);}
        if (numfam==2){
            if(match(i1,ind)==2)victoire +=match(i1,ind);
            else defaite+=victoire +=match(i1,ind);}
        }
    //determination du ratio
    ratio = victoire/defaite;
    qDebug()<<"victoires : "<<victoire<<endl<<"defaites : "<<defaite<<endl<<"ratio : "<<ratio<<endl;
    }


