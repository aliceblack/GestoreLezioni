#ifndef STUDENTE_H
#define STUDENTE_H
#include "complete.h"
using namespace std;

class Studente{
    QString codice;
    Complete allComp;
public:
    Studente();
    Studente(QString cod, Complete lez);
};

#endif // STUDENTE_H
