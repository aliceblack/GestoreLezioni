#ifndef PPL_H
#define PPL_H
#include "lezione.h"
#include "motore.h"

using namespace std;

class PPL: public Motore{
private:
    bool acrobatico;
public:
    PPL(int id, QString st, QString vel, bool ist, int m, bool pag, bool acro);
    bool getAcrobatico()const;
    virtual double costoBenzina()const;
    virtual double costoLezione()const;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const;
};

#endif // PPL_H
