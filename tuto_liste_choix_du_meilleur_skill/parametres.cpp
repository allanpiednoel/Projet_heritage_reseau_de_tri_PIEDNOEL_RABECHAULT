#include "parametres.h"
#include "qstd.h"
using namespace qstd;
QList <Individu *> Parameters::population_1;
QList <Individu *> Parameters::population_2;
int Parameters::individualsNb =22;
int Parameters::generationsMaxNb = 50;
int Parameters::initialGenesNb = 0;
int Parameters::minFitness = 0;
int Parameters::mutationNB = 0;

double Parameters::mutationRate = 0.1;
double Parameters::mutationAddRate = 0.2;
double Parameters::mutationDeleteRate = 0.1;
double Parameters::crossoverRate = 0.6;

int Parameters::indiv_fam_1;
int Parameters::indiv_fam_2;
// ******************************************************
// TODO : modifier la graine :
// - 0 : non aléatoire pour debug
// - rien : aléatoire
// ******************************************************
MyRandom *Parameters::randomGenerator=new MyRandom(30);

int Parameters::debug = 1;

void Parameters::affichage()
{
    foreach (Individu *ind, Parameters::population_1) {
            ind->evaluate();
        }

        // affichage *1
        cout<<endl;
        foreach (Individu *ind, Parameters::population_1) {
            cout<<ind->toString()<<endl;
        }
        // calcul des puissances *2
        foreach (Individu *ind, Parameters::population_2) {
            ind->evaluate();
        }

        // affichage *2
        cout<<endl;
        foreach (Individu *ind, Parameters::population_2) {
            cout<<ind->toString()<<endl;
        }
}

void Parameters::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt<<endl;
}
