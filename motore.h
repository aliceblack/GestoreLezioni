#ifndef MOTORE_H
#define MOTORE_H
#include "lezione.h"

class Motore: public Lezione{
public:
    Motore(int id, QString st, QString vel, bool ist, int m, bool pag);
    virtual double costoBenzina()const=0;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const=0;
};

#endif // MOTORE_H
