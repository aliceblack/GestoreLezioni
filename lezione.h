#ifndef LEZIONE_H
#define LEZIONE_H
#include <iostream>
#include <QString>
#include <QXmlStreamWriter>
using namespace std;

class Lezione{
private:
    int id;
    QString studente;
    QString velivolo; //immatricolazione enac
    bool istruttore;
    int minuti;
    bool pagata;
public:
    Lezione();
    Lezione(int id, QString st, QString vel, bool ist, int m, bool pag); //argomenti default
    int getId()const;
    QString getStudente()const;
    QString getVelivolo()const;
    bool getIstruttore()const;
    int getMinuti()const;
    bool getPagata()const;
    void setPagata();      //resetPagata()
    virtual double costoLezione()const=0;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const=0;
    //distruttore
};

#endif // LEZIONE_H
