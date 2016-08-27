#ifndef MOTORE_H
#define MOTORE_H
#include "lezione.h"

class Motore: public Lezione{
public:
    Motore(int ti,int id, QString st, QString vel, bool ist, int m, bool pag, bool acro=0, int tra=0);
    virtual ~Motore();
    virtual double costoBenzina()const=0;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const=0;
    static const double stimaConsumo;
};

#endif // MOTORE_H
