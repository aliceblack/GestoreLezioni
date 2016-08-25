#include "mainwindow.h"
#include <QMessageBox>
mainwindow::mainwindow(DataBase* DB) : basewindow(DB), ground() {

    QWidget * groundWindow =&ground;

    //PRIMA TAB

    QWidget * mainWidget=new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    lessonstable * tableWg = new lessonstable(getDB());
    mainLayout->addWidget(tableWg);

    QPushButton *deleteLezione = new QPushButton("Elimina Lezione");
    mainLayout->addWidget(deleteLezione);
    QPushButton *pagamento = new QPushButton("Pagamento");
    mainLayout->addWidget(pagamento);
    QPushButton *exit = new QPushButton("Esci");
    mainLayout->addWidget(exit);

    //SECONDA TAB

    QWidget * secondWidget=new QWidget();
    QVBoxLayout *secondLayout = new QVBoxLayout(secondWidget);
    studentstable * tableSt = new studentstable(getDB());
    secondLayout->addWidget(tableSt);
    QPushButton *exit2 = new QPushButton("Esci");
    secondLayout->addWidget(exit2);

    QTabWidget *tabs = new QTabWidget(groundWindow);

    tabs->addTab(mainWidget,"TAB 1");
    tabs->addTab(secondWidget,"TAB 2");

    //TERZA TAB
    QWidget * thirdWidget = new QWidget;
    QHBoxLayout *thirdLayout= new QHBoxLayout(thirdWidget);

    //AGGIUNTA LEZIONE PER LICENZA PILOTA PRIVATO

    QWidget * box = new QWidget;
    thirdLayout->addWidget(box);
    box->setMaximumWidth(350);

    QVBoxLayout *layout = new QVBoxLayout(box);

    QLabel* studenteLabel=new QLabel("Codice Studente:");
    QLabel* velivoloLabel=new QLabel("Velivolo:");
    QLabel* minutiLabel=new QLabel("Minuti:");

    studenteEdit = new QLineEdit ( box );
    velivoloEdit = new QLineEdit ( box );
    minutiEdit = new QLineEdit ( box );

    QLabel *istruttoreLabel = new QLabel(tr("Istruttore:"));
    istruttoreComboBox = new QComboBox;
    istruttoreComboBox->addItem(tr("No"));
    istruttoreComboBox->addItem(tr("Si"));

    QLabel *pagataLabel = new QLabel(tr("Pagata:"));
    pagataComboBox = new QComboBox;
    pagataComboBox->addItem(tr("No"));
    pagataComboBox->addItem(tr("Si"));

    QLabel *acrobLabel = new QLabel(tr("Acrobatica:"));
    acrobComboBox = new QComboBox;
    acrobComboBox->addItem(tr("No"));
    acrobComboBox->addItem(tr("Si"));


    layout->addWidget(studenteLabel);
    layout->addWidget(studenteEdit);
    layout->addWidget(velivoloLabel);
    layout->addWidget(velivoloEdit);

    layout->addWidget(istruttoreLabel);
    layout->addWidget(istruttoreComboBox);

    layout->addWidget(minutiLabel);
    layout->addWidget(minutiEdit);

    layout->addWidget(pagataLabel);
    layout->addWidget(pagataComboBox);

    layout->addWidget(acrobLabel);
    layout->addWidget(acrobComboBox);



    QPushButton *aggiungiPPLButton = new QPushButton("Aggiungi");
    layout->addWidget(aggiungiPPLButton);

    QPushButton *exit3 = new QPushButton("Esci");
   layout->addWidget(exit3);

   //AGGIUNTA LEZIONE ATTESTATO VOLO DIPORTO O SPORTIVO

   QWidget* box2 = new QWidget;
   thirdLayout->addWidget(box2);
   box2->setMaximumWidth(350);
   QVBoxLayout *layout2 = new QVBoxLayout(box2);

   QLabel* studenteLabel2=new QLabel("Codice Studente:");
   QLabel* velivoloLabel2=new QLabel("Velivolo:");
   QLabel* minutiLabel2=new QLabel("Minuti:");

   studenteEdit2 = new QLineEdit ( box2 );
   velivoloEdit2 = new QLineEdit ( box2 );
   minutiEdit2 = new QLineEdit ( box2 );

   QLabel* istruttoreLabel2 = new QLabel(tr("Istruttore:"));
   istruttoreComboBox2 = new QComboBox;
   istruttoreComboBox2->addItem(tr("No"));
   istruttoreComboBox2->addItem(tr("Si"));

   QLabel* pagataLabel2 = new QLabel(tr("Pagata:"));
   pagataComboBox2 = new QComboBox;
   pagataComboBox2->addItem(tr("No"));
   pagataComboBox2->addItem(tr("Si"));

   layout2->addWidget(studenteLabel2);
   layout2->addWidget(studenteEdit2);
   layout2->addWidget(velivoloLabel2);
   layout2->addWidget(velivoloEdit2);

   layout2->addWidget(istruttoreLabel2);
   layout2->addWidget(istruttoreComboBox2);

   layout2->addWidget(minutiLabel2);
   layout2->addWidget(minutiEdit2);

   layout2->addWidget(pagataLabel2);
   layout2->addWidget(pagataComboBox2);

   QPushButton *aggiungiVDSButton = new QPushButton("Aggiungi");
   layout2->addWidget(aggiungiVDSButton);

   //AGGIUNTA LEZIONE PER LICENZA PILOTA DI ALIANTE

   QWidget * box3 = new QWidget;
   thirdLayout->addWidget(box3);
   box3->setMaximumWidth(350);
   QVBoxLayout *layout3 = new QVBoxLayout(box3);

   QLabel* studenteLabel3=new QLabel("Codice Studente:");
   QLabel* velivoloLabel3=new QLabel("Velivolo:");
   QLabel* minutiLabel3=new QLabel("Minuti:");
   QLabel* trainiLabel3=new QLabel("Traini:");

   studenteEdit3 = new QLineEdit ( box3 );
   velivoloEdit3 = new QLineEdit ( box3 );
   minutiEdit3 = new QLineEdit ( box3 );
   trainiEdit3 = new QLineEdit ( box3 );

   QLabel* istruttoreLabel3 = new QLabel(tr("Istruttore:"));
   istruttoreComboBox3 = new QComboBox;
   istruttoreComboBox3->addItem(tr("No"));
   istruttoreComboBox3->addItem(tr("Si"));

   QLabel* pagataLabel3 = new QLabel(tr("Pagata:"));
   pagataComboBox3 = new QComboBox;
   pagataComboBox3->addItem(tr("No"));
   pagataComboBox3->addItem(tr("Si"));

   layout3->addWidget(studenteLabel3);
   layout3->addWidget(studenteEdit3);
   layout3->addWidget(velivoloLabel3);
   layout3->addWidget(velivoloEdit3);

   layout3->addWidget(istruttoreLabel3);
   layout3->addWidget(istruttoreComboBox3);

   layout3->addWidget(minutiLabel3);
   layout3->addWidget(minutiEdit3);

   layout3->addWidget(pagataLabel3);
   layout3->addWidget(pagataComboBox3);

   layout3->addWidget(trainiLabel3);
   layout3->addWidget(trainiEdit3);

   QPushButton *aggiungiGPLButton = new QPushButton("Aggiungi");
   layout3->addWidget(aggiungiGPLButton);

   //CONNECT BUTTONS, DIMENSIONI

    tabs->addTab(thirdWidget,"TAB 3");
    //tabs->setFixedSize(400, 400);
    //tabs->adjustSize();

    //connect(addLezione,SIGNAL(clicked()),this,SLOT(addSignal()));
    connect(aggiungiPPLButton,SIGNAL(clicked()),this,SLOT(addPPL()));
    connect(aggiungiVDSButton,SIGNAL(clicked()),this,SLOT(addVDS()));
    connect(aggiungiGPLButton,SIGNAL(clicked()),this,SLOT(addGPL()));
    connect(deleteLezione,SIGNAL(clicked()),this,SLOT(deleteSignal()));
    connect(pagamento,SIGNAL(clicked()),this,SLOT(pagamentoSignal()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(exit2,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(exit3,SIGNAL(clicked()),qApp,SLOT(quit()));

    groundWindow->showMaximized();
}

void mainwindow::closeEvent(QCloseEvent*){
    emit closeProgram();
}

void mainwindow::addPPL(){
    int id; Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {id=(*it)->getId()+1;}

    QString cod = studenteEdit->text();
    QString vel = velivoloEdit->text();
    int min = minutiEdit->text().toInt();

    bool istr = istruttoreComboBox->currentIndex();
    bool paga = pagataComboBox->currentIndex();
    bool acro = acrobComboBox->currentIndex();

    PPL* nuova=new PPL(id,cod,vel,istr,min,paga,acro);
    emit aggiungi(nuova);
}

void mainwindow::addVDS(){
    int id; Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {id=(*it)->getId()+1;}

    QString cod = studenteEdit2->text();
    QString vel = velivoloEdit2->text();
    int min = minutiEdit2->text().toInt();

    bool istr = istruttoreComboBox2->currentIndex();
    bool paga = pagataComboBox2->currentIndex();

    VDS* nuova=new VDS(id,cod,vel,istr,min,paga);
    emit aggiungi(nuova);
}

void mainwindow::addGPL(){
    int id; Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {id=(*it)->getId()+1;}

    QString cod = studenteEdit3->text();
    QString vel = velivoloEdit3->text();
    int min = minutiEdit3->text().toInt();
    int traini = trainiEdit3->text().toInt();

    bool istr = istruttoreComboBox3->currentIndex();
    bool paga = pagataComboBox3->currentIndex();

    GPL* nuova=new GPL(id,cod,vel,istr,min,paga,traini);
    emit aggiungi(nuova);
}

/*
void mainwindow::addSignal(){
    PPL* nuova=new PPL(79,"stude","m-899",1,40,0,0);
    emit aggiungi(nuova);
    bool inserito;
    QStringList items;
    items << tr("Licenza Pilota Privato") << tr("Attestato Volo Diporto e Sportivo") << tr("Licenza Pilota Aliante");
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),tr("Tipo:"), items, 0, false, &inserito);

    int id; Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {id=(*it)->getId()+1;}

    if(item=="Licenza Pilota Privato")
    {
        //PPL* nuova=new PPL(id,"770","m-899",1,40,0,0);
        //aggiungiPPL formPPL;
        //aggiungiPPL boh(getDB());
        //QString stude=boh.studente;
        //PPL* nuova=new PPL(69,stude,"m-899",1,40,0,0);
        //emit aggiungi(nuova);
        //aggiungiPPL formPPL;
        //aggiungiPPL boh(getDB());
        //c_aggiungiPPL controller(getDB(),&boh);
        //boh.show();

    }
    if(item=="Attestato Volo Diporto e Sportivo")
    {
        VDS* nuova=new VDS(id,"770","m-899",1,40,0);
        emit aggiungi(nuova);
    }
    if(item=="Licenza Pilota Aliante")
    {
        GPL* nuova=new GPL(id,"770","m-899",1,40,0,3);
        emit aggiungi(nuova);
    }
}*/

void mainwindow::deleteSignal(){
    bool inserito;
    QInputDialog *inputDialog = new QInputDialog();
    QString idLezione = inputDialog->getText(0, "Pagamento Lezione", "ID Lezione", QLineEdit::Normal,"", &inserito);
    if(inserito){emit rimuovi(idLezione.toInt());}
}

void mainwindow::pagamentoSignal(){
    bool inserito;
    QInputDialog *inputDialog = new QInputDialog();
    QString idLezione = inputDialog->getText(0, "Pagamento Lezione", "ID Lezione", QLineEdit::Normal,"", &inserito);     /*parent titolo label echomode text boolok*/
    if(inserito){emit paga(idLezione.toInt());}
}
