#ifndef C_MAINWINDOW_H
#define C_MAINWINDOW_H
#include "database.h"
#include "mainwindow.h"
#include <QWidget>
#include <QApplication>


class c_mainwindow : public QObject{
    Q_OBJECT
public:
    explicit c_mainwindow(DataBase* , mainwindow * , QObject *parent=0);
    ~c_mainwindow();
private slots:
    void aggiungiDB(Lezione*);
    void rimuoviDB(int);
    void pagaDB(int);
private:
    DataBase* c_db;
    mainwindow* groundwindow;
};

#endif // C_MAINWINDOW_H
