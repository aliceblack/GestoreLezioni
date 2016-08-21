#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basewindow.h"
#include "lessonstable.h"
#include "studentstable.h"

class mainwindow : public basewindow{
    Q_OBJECT
public:
    explicit mainwindow(DataBase* DB);
    //~mainwindow();
    QWidget ground;
};

#endif // MAINWINDOW_H


