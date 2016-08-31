#include "vds.h"

VDS::VDS(int id, QString st, QString vel, bool ist, int m, bool pag):Motore(id, st, vel, ist, m, pag){}

VDS::~VDS(){}

int VDS::getTipo()const{
    return 2;
}

double VDS::costoBenzina()const{
    return getMinuti()*stimaConsumo;
}

double VDS::costoLezione()const{
    return getMinuti()*0.38+costoBenzina()+25*getIstruttore();
}

void VDS::saveLezione(QXmlStreamWriter& xmlWriter)const{
    QString codiceDB = QString::number(getId());
    QString istruttoreDB = getIstruttore() ? "1" : "0";
    QString minutiDB = QString::number(getMinuti());
    QString pagataDB = getPagata() ? "1" : "0";

    xmlWriter.writeTextElement("id", codiceDB);
    xmlWriter.writeTextElement("tipo", "2");                     //<tipo>...</tipo>
    xmlWriter.writeTextElement("studente", getStudente());       //<studente>...</studente>
    xmlWriter.writeTextElement("velivolo", getVelivolo());
    xmlWriter.writeTextElement("istruttore", istruttoreDB);      //<istruttore>...</istruttore>
    xmlWriter.writeTextElement("minuti", minutiDB);              //<minuti>...</minuti>
    xmlWriter.writeTextElement("pagata", pagataDB);
}
