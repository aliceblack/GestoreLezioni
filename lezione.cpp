#include "lezione.h"

Lezione::Lezione(){}

Lezione::Lezione(int id, QString st, QString vel, bool ist, int m, bool pag):id(id), studente(st), velivolo(vel), istruttore(ist), minuti(m), pagata(pag){} //costruzione?

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

void Lezione::setPagata(){//resetPagata() per modifiche
    pagata=true;
}
