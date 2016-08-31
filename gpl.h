#ifndef GPL_H
#define GPL_H
#include "lezione.h"

class GPL: public Lezione{
public:
    GPL(int id, QString st, QString vel, bool ist, int m, bool pag, bool acro, int nt);
    virtual ~GPL();
    int getTipo()const;
    virtual double costoLezione()const;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const;
};

#endif // GPL_H
