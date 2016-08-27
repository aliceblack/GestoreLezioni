#ifndef PPL_H
#define PPL_H
#include "lezione.h"
#include "motore.h"


class PPL: public Motore{
public:
    PPL(int ti, int id, QString st, QString vel, bool ist, int m, bool pag, bool acro, int tra);
    virtual ~PPL();
    virtual double costoBenzina()const;
    virtual double costoLezione()const;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const;
};

#endif // PPL_H
