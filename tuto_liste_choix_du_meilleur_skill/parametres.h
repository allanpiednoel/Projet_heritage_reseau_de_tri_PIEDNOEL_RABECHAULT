#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "individu.h"
#include "myrandom.h"
#include <QString>
#include <QMap>

class Parameters {
public:
    static int individualsNb;
    static int generationsMaxNb;
    static int initialGenesNb;
    static int minFitness;
    static int mutationNB ;
    static int indiv_fam_1;
    static int indiv_fam_2;
    static QList<Individu *> population_1;
    static QList<Individu *> population_2;
    static double mutationRate;
    static double mutationAddRate;
    static double mutationDeleteRate;
    static double crossoverRate;
    Parameters *ptr;
    static MyRandom *randomGenerator;
    static void affichage();
    static int debug;
    static void print(QString txt, int d);};



#endif // PARAMETERS_H
