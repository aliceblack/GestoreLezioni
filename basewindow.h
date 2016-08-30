#ifndef BASEWINDOW_H
#define BASEWINDOW_H
#include "database.h"
#include <QWidget>
#include <QDesktopWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class basewindow : public QWidget{
    Q_OBJECT
private:
    DataBase* windowDB;
public:
    basewindow(DataBase* DB,QWidget *parent = 0);
    virtual  ~basewindow();
    virtual void updateView()=0;
    DataBase* getDB()const;
};

#endif // BASEWINDOW_H



