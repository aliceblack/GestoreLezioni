#ifndef LEZIONE_H
#define LEZIONE_H
#include <QString>
#include <QXmlStreamWriter>

class Lezione{
private:
    int id;
    QString studente;
    QString velivolo; //immatricolazione enac (o estero)
    bool istruttore;
    int minuti;
    bool pagata;
public:
    Lezione(int id, QString st, QString vel, bool ist, int m, bool pag);
    virtual ~Lezione();
    int getId()const;
    QString getStudente()const;
    QString getVelivolo()const;
    bool getIstruttore()const;
    int getMinuti()const;
    bool getPagata()const;
    void setPagata();
    virtual double costoLezione()const=0;
    virtual void saveLezione(QXmlStreamWriter& xmlWriter)const=0;
};

#endif // LEZIONE_H
