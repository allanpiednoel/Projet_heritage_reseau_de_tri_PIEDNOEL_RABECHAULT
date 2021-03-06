#include "individu.h"
#include <QTextStream>
#include "parametres.h"
#include "gene.h"
#include <QDebug>


int Individu::agilite() const
{
    return genome[AGILITE];
}

int Individu::force() const
{
    return genome[FORCE];
}

int Individu::precision() const
{
    return genome[PRECISION];
}

int Individu::intelligence() const
{
    return genome[INTELLIGENCE];
}

int Individu::resistance() const
{
    return genome[RESISTANCE];
}



void Individu::mutate()
{

    int index = (Parameters::randomGenerator->get(1000))%TAILLE_GENOME;
 qDebug() << "index : " << index;

 int val= Parameters::randomGenerator->get(100);
 if (val<genome[index])val=genome[index];
 genome[index]= val;



 /*int mutationPossibility = Parameters::randomGenerator->get(Parameters::population.size());
 qDebug() << "mutationPossibility : " << mutationPossibility;
 if (mutationPossibility<5){
 (Parameters::population.at(aleaInd)->genome[mutationPossibility])+=1;
 qDebug() << "genome[mutationPossibility] : " << genome[mutationPossibility];
 }*/

}

Individu::Individu(int a, int f, int p, int i, int r)
{ //m_agilite(a), m_force(f), m_precision(p), m_intelligence(i), m_resistance(r)
    genome[AGILITE]=a;
    genome[FORCE]=f;
    genome[PRECISION]=p;
    genome[INTELLIGENCE]=i;
    genome[RESISTANCE]=r;
    m_skill=-1;

}

Individu::Individu(Individu *papa)
    // on prends les caractéristiques du père
 /*   m_agilite(papa->m_agilite), m_force(papa->m_force),
    m_precision(papa->m_precision), m_intelligence(papa->m_intelligence),
    m_resistance(papa->m_resistance)*/
{
    for (int i=0; i<5; i++){
        genome[i]=papa->genome[i];
    }
    mutate();
}

void Individu::evaluate()
{
    m_skill=0;
    for (int i=0; i<5; i++){
        m_skill+=genome[i];
    }

}

bool Individu::lessSkillThan(Individu *i1, Individu *i2)
{
    return i1->m_skill < i2->m_skill;
}

bool Individu::betterSkillThan(Individu *i1, Individu *i2)
{
    return i1->m_skill > i2->m_skill;
}

QString Individu::toString() {
    QString res;
    QTextStream buf(&res);
    buf<<m_skill<<" : [ag="<<genome[AGILITE]<<" ; fo="<<genome[FORCE]<<" ; pre="<<genome[PRECISION]<<" ; int="<<genome[INTELLIGENCE]<<" ; res="<<genome[RESISTANCE]<<"]";
    return res;
}
