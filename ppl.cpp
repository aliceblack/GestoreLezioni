#include "ppl.h"

PPL::PPL(int id, QString st,  QString vel, bool ist, int m, bool pag, bool ac): Motore(id, st, vel, ist, m, pag), acrobatico(ac){}

PPL::~PPL(){}

bool PPL::getAcrobatico()const{
    return acrobatico;
}

double PPL::costoBenzina()const{
    return getMinuti()*stimaConsumo+5*acrobatico;
}

double PPL::costoLezione()const{
    return getMinuti()*1.56+costoBenzina()+25*getIstruttore()+10*acrobatico;
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
