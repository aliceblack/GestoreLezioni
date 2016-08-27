#include "lezione.h"

Lezione::Lezione(int ti, int id, QString st, QString vel, bool ist, int m, bool pag, bool acro, int tra):tipo(ti),id(id), studente(st), velivolo(vel), istruttore(ist), minuti(m), pagata(pag), acrobatico(acro), traini(tra){}

Lezione::~Lezione(){}

int Lezione::getTipo()const{
    return tipo;
}

bool Lezione::getAcrobatico()const{
    return acrobatico;
}

int Lezione::getTraini() const{
    return traini;
}

int Lezione::getId()const{
    return id;
}

QString Lezione::getStudente()const{
    return studente;
}

QString Lezione::getVelivolo()const{
    return velivolo;
}

bool Lezione::getIstruttore()const{
    return istruttore;
}

int Lezione::getMinuti()const{
    return minuti;
}

bool Lezione::getPagata()const{
    return pagata;
}

void Lezione::setPagata(){
    pagata=true;
}
