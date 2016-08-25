#include "studentstable.h"


studentstable::studentstable(DataBase* DB) : basewindow(DB) {

    tableWidget=new QTableWidget(0, 14);
    QStringList tabHeader;
    tabHeader<<"Studente"<<"Pagamento"<<"Debito"<<"Master PPL"<<"Solo PPL"<<"Minimo PPL"<<"Master VDS"<<"Solo VDS"<<"Minimo VDS"<<"Master GPL"<<"Solo GPL"<<"Minimo GPL"<<"PPL Acrob"<<"PLL Acrob";

    tableWidget->setHorizontalHeaderLabels(tabHeader);

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVBoxLayout* tableLayout=new QVBoxLayout();
    tableLayout->addWidget(tableWidget);


    //tableWidget->setFixedSize(1200,500);

    Complete::iterator it;
    QVector<QString> studenti;
    QVector<QString>::iterator sit;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {

        bool trovato=false;
        for(sit=studenti.begin(); sit!=studenti.end(); ++sit)
        {

            if( (*it)->getStudente()==*sit)
                trovato=true;
        }
        if(!trovato)
        {
            studenti.push_back( (*it)->getStudente() );
        }
    }
    double totPagato=0; double totDebito=0; int n=0;
    for(sit=studenti.begin(); sit!=studenti.end(); ++sit)
    {
        totPagato=0; totDebito=0;
        for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
        {
            if((*it)->getStudente()==*sit)
            {
                if( (*it)->getPagata() )
                {
                    totPagato+=(*it)->costoLezione();
                }
                else
                {
                    totDebito+=(*it)->costoLezione();
                }
            }

        }
        tableWidget->insertRow( tableWidget->rowCount() );
        QTableWidgetItem *studenteItem = new QTableWidgetItem(*sit);
        tableWidget->setItem(n,0,studenteItem);

        QString pagatoVal = QString::number(totPagato);
        QTableWidgetItem *pagatoItem = new QTableWidgetItem(pagatoVal);
        tableWidget->setItem(n,1,pagatoItem);

        QString debitoVal = QString::number(totDebito);
        QTableWidgetItem *debitoItem = new QTableWidgetItem(debitoVal);
        tableWidget->setItem(n,2,debitoItem);


        Complete lezioniStudente;
        for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
        {
            if((*it)->getStudente()==*sit)
            {
                lezioniStudente.add(*it);
            }
        }

        QString masterPPL = QString::number(lezioniStudente.oreMasterPPL());
        QTableWidgetItem *masterPPLItem = new QTableWidgetItem(masterPPL);
        tableWidget->setItem(n,3,masterPPLItem);

        QString soloPPL = QString::number(lezioniStudente.oreSoloPPL());
        QTableWidgetItem *soloPPLItem = new QTableWidgetItem(soloPPL);
        tableWidget->setItem(n,4,soloPPLItem);

        QString minimoPPL = lezioniStudente.orePPL() ? "Si" : "No";
        QTableWidgetItem *minPPLItem = new QTableWidgetItem(minimoPPL);
        tableWidget->setItem(n,5,minPPLItem);

        QString masterVDS = QString::number(lezioniStudente.oreMasterVDS());
        QTableWidgetItem *masterVDSItem = new QTableWidgetItem(masterVDS);
        tableWidget->setItem(n,6,masterVDSItem);

        QString soloVDS = QString::number(lezioniStudente.oreSoloVDS());
        QTableWidgetItem *soloVDSItem = new QTableWidgetItem(soloVDS);
        tableWidget->setItem(n,7,soloVDSItem);

        QString minimoVDS = lezioniStudente.oreVDS() ? "Si" : "No";
        QTableWidgetItem *minVDSItem = new QTableWidgetItem(minimoVDS);
        tableWidget->setItem(n,8,minVDSItem);

        QString masterGPL = QString::number(lezioniStudente.oreMasterGPL());
        QTableWidgetItem *masterGPLItem = new QTableWidgetItem(masterGPL);
        tableWidget->setItem(n,9,masterGPLItem);

        QString soloGPL = QString::number(lezioniStudente.oreSoloGPL());
        QTableWidgetItem *soloGPLItem = new QTableWidgetItem(soloGPL);
        tableWidget->setItem(n,10,soloGPLItem);

        QString minimoGPL = lezioniStudente.oreGPL() ? "Si" : "No";
        QTableWidgetItem *minGPLItem = new QTableWidgetItem(minimoGPL);
        tableWidget->setItem(n,11,minGPLItem);

        QString acrobPPL = QString::number(lezioniStudente.minAcrobPPL());
        QTableWidgetItem *acrobPPLItem = new QTableWidgetItem(acrobPPL);
        tableWidget->setItem(n,12,acrobPPLItem);

        QString minimoAcrobPPL = lezioniStudente.minAcrobPPL() ? "Si" : "No";
        QTableWidgetItem *minAcrobPPLItem = new QTableWidgetItem(minimoAcrobPPL);
        tableWidget->setItem(n,13,minAcrobPPLItem);

        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        n++;
    }
    setLayout(tableLayout);

}

studentstable::~studentstable(){}
