#include "gpl.h"

GPL::GPL(int id, QString st, QString vel, bool ist, int m, bool pag, int nt): Lezione(id, st, vel, ist, m, pag), traini(nt){}

int GPL::getTraini()const{
    return traini;
}

double GPL::costoLezione()const{
return getMinuti()*0.38+25*getIstruttore()+traini*40;
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
