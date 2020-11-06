#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <QString>
#include <QList>
#include "gene.h"
#define TAILLE_GENOME 5
class Individu
{
private:
   // int m_skill;

public:
    int m_skill;
    void mutate();
    Individu(int a, int f, int p, int i, int r);
    Individu(Individu *papa);
    void evaluate();
    static bool lessSkillThan(Individu *i1, Individu *i2);
    static bool betterSkillThan(Individu *i1, Individu *i2);
    QString toString();
    int genome[TAILLE_GENOME];

    enum GENE_type {AGILITE,FORCE,PRECISION,INTELLIGENCE,RESISTANCE};
    int agilite() const;
    int force() const;
    int precision() const;
    int intelligence() const;
    int resistance() const;

    void setGenome(const QList<Gene *> &value);

};

#endif // INDIVIDU_H
