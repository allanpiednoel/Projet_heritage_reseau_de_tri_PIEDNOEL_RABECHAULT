#ifndef BASTON_H
#define BASTON_H
#include "parametres.h"
#include <QList>

class baston
{
public:
    baston();
    static bool match_nul(Individu * ind1 , Individu * ind2);
    static int match (Individu * ind1,Individu * ind2);
    static void tournoi (int numfam, Individu *i1, QList<Individu *>&l);
};

#endif // BASTON_H
