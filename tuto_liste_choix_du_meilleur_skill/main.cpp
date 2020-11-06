#include "../shared/qstd.h"
using namespace qstd;
#include "individu.h"
#include "parametres.h"
#include "gene.h"
#include <QList>
#include <QDebug>
#include "baston.h"
//

int main()
{
    for (int i=0; i<5;i++)
   {
    //attribution aléatoire des genes ( entre 0 et 100 )
    int agilite = Parameters::randomGenerator->get(100);
    int force = Parameters::randomGenerator->get(100);
    int precision = Parameters::randomGenerator->get(100);
    int intelligence = Parameters::randomGenerator->get(100);
    int resistance =Parameters::randomGenerator->get(100) ;
    // remplissage
    Parameters::population_1.append(new Individu(agilite,force,precision,intelligence,resistance));
    }

    for (int i=0; i<5;i++)
   {
    //attribution aléatoire des genes ( entre 0 et 100 )
    int agilite = Parameters::randomGenerator->get(100);
    int force = Parameters::randomGenerator->get(100);
    int precision = Parameters::randomGenerator->get(100);
    int intelligence = Parameters::randomGenerator->get(100);
    int resistance =Parameters::randomGenerator->get(100) ;
    // remplissage
    Parameters::population_2.append(new Individu(agilite,force,precision,intelligence,resistance));
    }
    Parameters::affichage();

    // recherche du meilleur
    std::sort(Parameters::population_1.begin(), Parameters::population_1.end(), Individu::betterSkillThan);
    std::sort(Parameters::population_2.begin(), Parameters::population_2.end(), Individu::betterSkillThan);
     Parameters::affichage();
     cout<<endl<<"tournoi : "<<endl<<"individu famille 1 contre la famille 2 : "<<Parameters::population_1.at(0)->toString()<<endl;
     baston::tournoi(1,Parameters::population_1.at(0), Parameters::population_2);
    /*cout<<endl<<"element *1: "<<Parameters::population_1.at(4)->toString()<<endl;
    cout<<"element *2: "<<Parameters::population_2.at(1)->toString()<<endl<<endl;
    cout<<"test combat : "<<endl;
    cout<<"vainqueur : famille "<<baston::match(Parameters::population_1.at(4),Parameters::population_2.at(1))<<endl;*/
    /*cout<<endl<<"test mutation : "<<endl;

    foreach (Individu *ind, Parameters::population_1) {
        qDebug()<<"avant mutation";
        cout<<ind->toString()<<endl;
        ind->mutate();
        ind->evaluate();
        qDebug()<<"apres mutation";
        cout<<ind->toString()<<endl;}
   // cout<<endl<<Individu::ptr;*/
}
