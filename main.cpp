#include <QApplication>
#include <QXmlStreamReader>
#include <QString>
#include "ppl.h"
#include "gpl.h"
#include "vds.h"
#include "complete.h"
#include "database.h"
#include "mainwindow.h"
#include "basewindow.h"
#include "c_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataBase primodb;
    mainwindow m(&primodb);

    c_mainwindow controller(&primodb,&m);


    return a.exec();
}
