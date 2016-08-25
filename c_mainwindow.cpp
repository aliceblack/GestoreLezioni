#include "c_mainwindow.h"

c_mainwindow::c_mainwindow(DataBase* db, mainwindow* gr, QObject *parent) : QObject(parent), c_db(db), groundwindow(gr)  {
    connect(groundwindow,SIGNAL(aggiungi(Lezione*)),this,SLOT(aggiungiDB(Lezione*)));
    connect(groundwindow,SIGNAL(rimuovi(int)),this,SLOT(rimuoviDB(int)));
    connect(groundwindow,SIGNAL(paga(int)),this,SLOT(pagaDB(int)));
    connect(groundwindow,SIGNAL(closeProgram()),qApp,SLOT(quit()));
}

void c_mainwindow::aggiungiDB(Lezione* nuova){
    c_db->addDB(nuova);
    c_db->close();
    //view->aggiorna_vista();
}

void c_mainwindow::rimuoviDB(int id){
    c_db->removeDB(id);
    c_db->close();
    //view->aggiorna_vista();
}


void c_mainwindow::pagaDB(int id){
    c_db->pagaDB(id);
    c_db->close();
    //view->aggiorna_vista();
}
