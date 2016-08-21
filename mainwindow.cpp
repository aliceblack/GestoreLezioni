#include "mainwindow.h"

mainwindow::mainwindow(DataBase* DB) : basewindow(DB), ground() {

    QWidget * groundWindow =&ground;
    QWidget * mainWidget=new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    lessonstable * tableWg = new lessonstable(getDB());
    QWidget * secondWidget=new QWidget();
    QVBoxLayout *secondLayout = new QVBoxLayout(secondWidget);
    studentstable * tableSt = new studentstable(getDB());
    secondLayout->addWidget(tableSt);
    secondWidget->setLayout(secondLayout);

    mainLayout->addWidget(tableWg);
    QPushButton *btn1 = new QPushButton("button1");
    mainLayout->addWidget(btn1);
    QPushButton *btn2 = new QPushButton("button2");
    mainLayout->addWidget(btn2);
    QPushButton *btn3 = new QPushButton("button3");
    mainLayout->addWidget(btn3);
    QPushButton *btn4 = new QPushButton("button4");
    mainLayout->addWidget(btn4);
    QPushButton *btn5 = new QPushButton("button5");
    mainLayout->addWidget(btn5);
    mainWidget->setLayout(mainLayout);

    QTabWidget *tabs = new QTabWidget(groundWindow);//fra parentesi il parent

    tabs->addTab(mainWidget,"TAB 1");
    tabs->addTab(secondWidget,"TAB 2");
    //tabs->setFixedSize(400, 400);
    tabs->adjustSize();

    groundWindow->showMaximized();





    /*
    //QWidget * groundWindow = new QWidget(this);
    QWidget * groundWindow =&ground;
    QWidget * mainWidget=new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    QTableWidget* tableWidget = new QTableWidget(10, 8);

    tableWidget->setFixedSize(1000,400);     //ATTENZIONE
    tableWidget->resizeRowsToContents();

    QStringList tabHeader;
    tabHeader<<"ID Lezione"<<"ID Cliente"<<"Velivolo"<<"Istruttore"<<"Minuti"<<"Pagamento"<<"Acrobatica"<<"N. Traini";
    tableWidget->setHorizontalHeaderLabels(tabHeader);

    mainLayout->addWidget(tableWidget);
    QPushButton *btn1 = new QPushButton("button1");
    mainLayout->addWidget(btn1);
    QPushButton *btn2 = new QPushButton("button2");
    mainLayout->addWidget(btn2);
    QPushButton *btn3 = new QPushButton("button3");
    mainLayout->addWidget(btn3);
    QPushButton *btn4 = new QPushButton("button4");
    mainLayout->addWidget(btn4);
    QPushButton *btn5 = new QPushButton("button5");
    mainLayout->addWidget(btn5);
    mainWidget->setLayout(mainLayout);

    QTabWidget *tabs = new QTabWidget(groundWindow);//fra parentesi il parent

    tabs->addTab(mainWidget,"TAB 1");
    tabs->addTab(new QWidget(),"TAB 2");
    //tabs->setFixedSize(400, 400);
    tabs->adjustSize();

    groundWindow->showMaximized();
    */
}
