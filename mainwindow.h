#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "basewindow.h"
#include "lessonstable.h"
#include "studentstable.h"
#include <QLabel>
#include <QApplication>
#include <QInputDialog>
#include <QFormLayout>
#include <QComboBox>

class mainwindow : public basewindow{
    Q_OBJECT
public:
    explicit mainwindow(DataBase* DB);
    virtual ~mainwindow();
    void closeEvent(QCloseEvent*);
    virtual void updateView();
private:
    QWidget ground;
    lessonstable*  tableWg;
    studentstable* tableSt;

    QLineEdit* studenteEdit;
    QLineEdit* velivoloEdit;
    QComboBox* istruttoreComboBox;
    QLineEdit* minutiEdit;
    QComboBox* pagataComboBox;
    QComboBox* acrobComboBox;

    QLineEdit* studenteEdit2;
    QLineEdit* velivoloEdit2;
    QComboBox* istruttoreComboBox2;
    QLineEdit* minutiEdit2;
    QComboBox* pagataComboBox2;

    QLineEdit* studenteEdit3;
    QLineEdit* velivoloEdit3;
    QComboBox* istruttoreComboBox3;
    QLineEdit* minutiEdit3;
    QComboBox* pagataComboBox3;
    QLineEdit* trainiEdit3;
signals:
    void aggiungi(Lezione*);
    void rimuovi(int);
    void paga(int);
    void closeProgram();
private slots:
    void addPPL();
    void addVDS();
    void addGPL();
    void deleteMainWindow();
    void pagamentoMainWindow();
};

#endif // MAINWINDOW_H


