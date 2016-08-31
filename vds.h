#ifndef VDS_H
#define VDS_H
#include "lezione.h"
#include "motore.h"


class VDS: public Motore{
public:
    VDS(int id, QString st,  QString vel, bool ist, int m, bool pag);
    virtual ~VDS();
    int getTipo()const;
    virtual double costoBenzina()const;
    virtual double costoLezione()const;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const;
};

#endif // VDS_H
