#include "gpl.h"

GPL::GPL(int ti, int id, QString st, QString vel, bool ist, int m, bool pag, bool acro, int nt): Lezione(ti,id, st, vel, ist, m, pag, acro, nt){}

GPL::~GPL(){}

double GPL::costoLezione()const{
return getMinuti()*0.38+25*getIstruttore()+getTraini()*40;
}

void GPL::saveLezione(QXmlStreamWriter& xmlWriter)const{
    QString codiceDB = QString::number(getId());
    QString istruttoreDB = getIstruttore() ? "1" : "0";
    QString minutiDB = QString::number(getMinuti());
    QString trainiDB = QString::number(getTraini());
    QString pagataDB = getPagata() ? "1" : "0";

    xmlWriter.writeTextElement("id", codiceDB); //<id> </id>
    xmlWriter.writeTextElement("tipo", "3");
    xmlWriter.writeTextElement("studente", getStudente());
    xmlWriter.writeTextElement("velivolo", getVelivolo());
    xmlWriter.writeTextElement("istruttore", istruttoreDB);
    xmlWriter.writeTextElement("minuti", minutiDB);
    xmlWriter.writeTextElement("pagata", pagataDB);
    xmlWriter.writeTextElement("traini", trainiDB);
}
