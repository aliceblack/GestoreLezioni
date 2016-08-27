#ifndef GPL_H
#define GPL_H
#include "lezione.h"

class GPL: public Lezione{
public:
    GPL(int ti, int id, QString st, QString vel, bool ist, int m, bool pag, bool acro, int nt);
    virtual ~GPL();
    virtual double costoLezione()const;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const;
};

#endif // GPL_H
