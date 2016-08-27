#include "ppl.h"

PPL::PPL(int ti, int id, QString st,  QString vel, bool ist, int m, bool pag, bool acro, int tra): Motore(ti, id, st, vel, ist, m, pag, acro, tra){}

PPL::~PPL(){}


double PPL::costoBenzina()const{
    return getMinuti()*stimaConsumo+5*getAcrobatico();
}

double PPL::costoLezione()const{
    return getMinuti()*1.56+costoBenzina()+25*getIstruttore()+10*getAcrobatico();
}

void PPL::saveLezione(QXmlStreamWriter& xmlWriter)const{
    QString codiceDB = QString::number(getId());
    QString istruttoreDB = getIstruttore() ? "1" : "0";
    QString minutiDB = QString::number(getMinuti());
    QString acrobaticoDB = getAcrobatico() ? "1" : "0";
    QString pagataDB = getPagata() ? "1" : "0";


    xmlWriter.writeTextElement("id", codiceDB);     //<id>...</id>
    xmlWriter.writeTextElement("tipo", "1");
    xmlWriter.writeTextElement("studente", getStudente());
    xmlWriter.writeTextElement("velivolo", getVelivolo());
    xmlWriter.writeTextElement("istruttore", istruttoreDB);
    xmlWriter.writeTextElement("minuti", minutiDB);
    xmlWriter.writeTextElement("pagata", pagataDB);
    xmlWriter.writeTextElement("acrobatico", acrobaticoDB);
}
