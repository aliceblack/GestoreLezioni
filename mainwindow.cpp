#include "mainwindow.h"
#include <QMessageBox>
mainwindow::mainwindow(DataBase* DB) : basewindow(DB), ground() {


    QWidget * groundWindow =&ground;
    groundWindow->setWindowTitle("Gestore Lezioni");

    //PRIMA TAB

    QWidget * mainWidget=new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    tableWg = new lessonstable(getDB());
    mainLayout->addWidget(tableWg);

    QWidget * buttonsWg=new QWidget;
    QHBoxLayout * buttonsLayout=new QHBoxLayout(buttonsWg);
    QPushButton * deleteLezione = new QPushButton("Elimina Lezione");
    buttonsLayout->addWidget(deleteLezione);
    QPushButton * pagamento = new QPushButton("Pagamento");
    buttonsLayout->addWidget(pagamento);
    QPushButton * exit = new QPushButton("Esci");
    buttonsLayout->addWidget(exit);
    mainLayout->addWidget(buttonsWg);

    //SECONDA TAB

    QWidget *secondWidget=new QWidget();
    QVBoxLayout *secondLayout = new QVBoxLayout(secondWidget);
    tableSt = new studentstable(getDB());
    secondLayout->addWidget(tableSt);
    QPushButton *exit2 = new QPushButton("Esci");
    secondLayout->addWidget(exit2);

    QTabWidget *tabs = new QTabWidget(groundWindow);

    tabs->addTab(mainWidget,"LEZIONI");
    tabs->addTab(secondWidget,"STUDENTI");

    //TERZA TAB

    QWidget *verticalWidget = new QWidget;
    QVBoxLayout *verticalLayout = new QVBoxLayout(verticalWidget);

    QWidget *thirdWidget = new QWidget;//box box2 box3
    QHBoxLayout *thirdLayout = new QHBoxLayout(thirdWidget);

    verticalLayout->addWidget(thirdWidget);

    QPushButton *exit3 = new QPushButton("Esci");

    verticalLayout->addWidget(exit3);

    //AGGIUNTA LEZIONE PER LICENZA PILOTA PRIVATO

    QWidget * box = new QWidget;

    thirdLayout->addWidget(box);
    box->setMaximumWidth(350);

    QVBoxLayout *layout = new QVBoxLayout(box);

    QLabel* tipoLabel=new QLabel("NUOVA LEZIONE PILOTA PRIVATO");
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

    layout->addWidget(tipoLabel);
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

   //AGGIUNTA LEZIONE ATTESTATO VOLO DIPORTO O SPORTIVO

   QWidget* box2 = new QWidget;
   thirdLayout->addWidget(box2);
   box2->setMaximumWidth(350);
   QVBoxLayout *layout2 = new QVBoxLayout(box2);

   QLabel* tipoLabel2=new QLabel("NUOVA LEZIONE VOLO DIPORTO O SPORTIVO");
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

   layout2->addWidget(tipoLabel2);
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

   QLabel* tipoLabel3=new QLabel("NUOVA LEZIONE PILOTA ALIANTE");
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

   layout3->addWidget(tipoLabel3);
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

   tabs->addTab(verticalWidget,"AGGIUNGI LEZIONE");
   tabs->adjustSize();

   if(getDB()->getVuoto())
   {
       QMessageBox mex;
       mex.setWindowTitle("Attenzione");
       mex.setText("DataBase mancante,creato un DataBase vuoto");
       mex.setStandardButtons(QMessageBox::Ok);
       mex.exec();
   }
   if(getDB()->getCorrotto())
   {
       QMessageBox mex;
       mex.setWindowTitle("Attenzione");
       mex.setText("DataBase corrotto");
       mex.setStandardButtons(QMessageBox::Ok);
       mex.exec();
   }

   connect(aggiungiPPLButton,SIGNAL(clicked()),this,SLOT(addPPL()));
   connect(aggiungiVDSButton,SIGNAL(clicked()),this,SLOT(addVDS()));
   connect(aggiungiGPLButton,SIGNAL(clicked()),this,SLOT(addGPL()));
   connect(deleteLezione,SIGNAL(clicked()),this,SLOT(deleteMainWindow()));
   connect(pagamento,SIGNAL(clicked()),this,SLOT(pagamentoMainWindow()));
   connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
   connect(exit2,SIGNAL(clicked()),qApp,SLOT(quit()));
   connect(exit3,SIGNAL(clicked()),qApp,SLOT(quit()));

   QDesktopWidget sizes;
   groundWindow->setMinimumSize(sizes.screen()->width()*0.95,sizes.screen()->height());

   groundWindow->showMaximized();
}

void mainwindow::closeEvent(QCloseEvent*){
    emit closeProgram();
}

void mainwindow::addPPL(){
    int id; Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {id=(*it)->getId()+1;}
    if(getDB()->getVuoto()){id=1;}

    QString cod = studenteEdit->text();
    QString vel = velivoloEdit->text();
    int min = minutiEdit->text().toInt();

    bool istr = istruttoreComboBox->currentIndex();
    bool paga = pagataComboBox->currentIndex();
    bool acro = acrobComboBox->currentIndex();

    PPL* nuova=new PPL(1,id,cod,vel,istr,min,paga,acro,0);
    if(cod!="" && vel!="" && min!=0)
    {
        emit aggiungi(nuova);
        updateView();
        studenteEdit->clear();
        velivoloEdit->clear();
        minutiEdit->clear();
        QMessageBox mex;
        mex.setWindowTitle("Lezione Aggiunta");
        mex.setText("La lezione e' stata aggiunta correttamente");
        mex.setStandardButtons(QMessageBox::Ok);
        mex.exec();
    }
    else
    {
        QMessageBox mex;
        mex.setWindowTitle("Attenzione");
        if(min==0){mex.setText("Completare tutti i campi. Attenzione: la lezione non puo' durare 0 minuti");}
        else{mex.setText("Completare tutti i campi");}
        mex.setStandardButtons(QMessageBox::Ok);
        mex.exec();
    }
}

void mainwindow::addVDS(){
    int id; Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {id=(*it)->getId()+1;}
    if(getDB()->getVuoto()){id=1;}

    QString cod = studenteEdit2->text();
    QString vel = velivoloEdit2->text();
    int min = minutiEdit2->text().toInt();

    bool istr = istruttoreComboBox2->currentIndex();
    bool paga = pagataComboBox2->currentIndex();

    VDS* nuova=new VDS(2,id,cod,vel,istr,min,paga);
    if(cod!="" && vel!="" && min!=0)
    {
        emit aggiungi(nuova);
        updateView();
        studenteEdit2->clear();
        velivoloEdit2->clear();
        minutiEdit2->clear();
        QMessageBox mex;
        mex.setWindowTitle("Lezione Aggiunta");
        mex.setText("La lezione e' stata aggiunta correttamente");
        mex.setStandardButtons(QMessageBox::Ok);
        mex.exec();
    }
    else
    {
        QMessageBox mex;
        mex.setWindowTitle("Attenzione");
        if(min==0){mex.setText("Completare tutti i campi. Attenzione: la lezione non puo' durare 0 minuti");}
        else{mex.setText("Completare tutti i campi");}
        mex.setStandardButtons(QMessageBox::Ok);
        mex.exec();
    }
}

void mainwindow::addGPL(){
    int id; Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {id=(*it)->getId()+1;}
    if(getDB()->getVuoto()){id=1;}

    QString cod = studenteEdit3->text();
    QString vel = velivoloEdit3->text();
    int min = minutiEdit3->text().toInt();
    int traini = trainiEdit3->text().toInt();

    bool istr = istruttoreComboBox3->currentIndex();
    bool paga = pagataComboBox3->currentIndex();

    GPL* nuova=new GPL(3,id,cod,vel,istr,min,paga,0,traini);
    if(cod!="" && vel!="" && min!=0 && traini!=0)
    {
        emit aggiungi(nuova);
        updateView();
        studenteEdit3->clear();
        velivoloEdit3->clear();
        minutiEdit3->clear();
        trainiEdit3->clear();
        QMessageBox mex;
        mex.setWindowTitle("Lezione Aggiunta");
        mex.setText("La lezione e' stata aggiunta correttamente");
        mex.setStandardButtons(QMessageBox::Ok);
        mex.exec();
    }
    else
    {
        QMessageBox mex;
        mex.setWindowTitle("Attenzione");
        if(min==0){mex.setText("Completare tutti i campi. Attenzione: la lezione non puo' durare 0 minuti");}
        else if(traini==0){mex.setText("Completare tutti i campi. Attenzione: minimo 1 traino");}
        else{mex.setText("Completare tutti i campi");}
        mex.setStandardButtons(QMessageBox::Ok);
        mex.exec();
    }
}

void mainwindow::deleteMainWindow(){
    bool inserito;
    QInputDialog *inputDialog = new QInputDialog();
    QString idLezione = inputDialog->getText(0, "Elimina Lezione", "Insere ID della lezione da eliminare:", QLineEdit::Normal,"", &inserito);
    if(inserito){
        emit rimuovi(idLezione.toInt());
        updateView();
    }
}

void mainwindow::pagamentoMainWindow(){
    bool inserito;
    QInputDialog *inputDialog = new QInputDialog();
    QString idLezione = inputDialog->getText(0, "Pagamento Lezione", "Inserire ID della lezione da pagare", QLineEdit::Normal,"", &inserito);
    if(inserito)
    {
        emit paga(idLezione.toInt());
        updateView();
    }
}

void mainwindow::updateView(){
    tableWg->updateView();
    tableSt->updateView();
}

mainwindow::~mainwindow(){
    delete  tableWg;
    delete tableSt;

    delete studenteEdit;
    delete velivoloEdit;
    delete istruttoreComboBox;
    delete minutiEdit;
    delete pagataComboBox;
    delete acrobComboBox;

    delete studenteEdit2;
    delete velivoloEdit2;
    delete istruttoreComboBox2;
    delete minutiEdit2;
    delete pagataComboBox2;

    delete studenteEdit3;
    delete velivoloEdit3;
    delete istruttoreComboBox3;
    delete minutiEdit3;
    delete pagataComboBox3;
    delete trainiEdit3;
}
