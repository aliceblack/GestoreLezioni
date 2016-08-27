#include "lessonstable.h"


lessonstable::lessonstable(DataBase* DB) : basewindow(DB) {

    tableWidget=new QTableWidget(0, 10);
    QStringList tabHeader;
    tabHeader<<"ID Lezione"<<"Cod. Studente"<<"Velivolo"<<"Istruttore"<<"Minuti"<<"Pagamento"<<"Acrobatica"<<"N. Traini"<<"Costo"<<"Tipo";
    tableWidget->setHorizontalHeaderLabels(tabHeader);

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVBoxLayout* tableLayout=new QVBoxLayout();
    tableLayout->addWidget(tableWidget);

    QDesktopWidget sizes;
    tableWidget->setFixedSize(sizes.screen()->width()*0.90,sizes.screen()->height()*0.75);

    updateView();

    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setLayout(tableLayout);
}

void lessonstable::updateView(){
    tableWidget->setRowCount(0);
    int n=0;
    Complete::iterator it;
    for(it=(getDB())->beginDB(); it!=(getDB())->endDB(); ++it)
    {
        int id=(*it)->getId();
        QString studente = (*it)->getStudente();
        QString velivolo = (*it)->getVelivolo();
        int minuti = (*it)->getMinuti();
        double costo=(*it)->costoLezione();

        PPL* lezionePPL=dynamic_cast<PPL*>(*it);
        GPL* lezioneGPL=dynamic_cast<GPL*>(*it);

        tableWidget->insertRow( tableWidget->rowCount() );

        QString codiceDB = QString::number(id);
        QString minutiDB = QString::number(minuti);
        QString costoDB = QString::number(costo);

        QString istruttoreDB = (*it)->getIstruttore() ? "Si" : "No";
        QString pagamentoDB = (*it)->getPagata() ? "Si" : "No";

        QTableWidgetItem *idItem = new QTableWidgetItem(codiceDB);
        QTableWidgetItem *studenteItem = new QTableWidgetItem(studente);
        QTableWidgetItem *velivoloItem = new QTableWidgetItem(velivolo);
        QTableWidgetItem *istruttoreItem = new QTableWidgetItem(istruttoreDB);
        QTableWidgetItem *minutiItem = new QTableWidgetItem(minutiDB);
        QTableWidgetItem *pagamentoItem = new QTableWidgetItem(pagamentoDB);
        QTableWidgetItem *costoItem = new QTableWidgetItem(costoDB);

        if(lezionePPL)
        {
            QString acrobatico = (*lezionePPL).getAcrobatico() ? "Si" : "No";
            QTableWidgetItem *acrobaticoItem = new QTableWidgetItem(acrobatico);
            tableWidget->setItem(n,6,acrobaticoItem);

            QTableWidgetItem *trainiGray = new QTableWidgetItem("0");
            tableWidget->setItem(n,7,trainiGray);
            tableWidget->item(n,7)->setFlags(!Qt::ItemIsEditable);

            QTableWidgetItem *tipoPPL = new QTableWidgetItem("PPL");
            tableWidget->setItem(n,9,tipoPPL);
        }
        else if(lezioneGPL)
        {
            int traini = (*lezioneGPL).getTraini();
            QString trainiDB = QString::number(traini);
            QTableWidgetItem *trainiItem = new QTableWidgetItem(trainiDB);
            tableWidget->setItem(n,7,trainiItem);

            QTableWidgetItem *acrobaticoGray = new QTableWidgetItem("No");
            tableWidget->setItem(n,6,acrobaticoGray);
            tableWidget->item(n,6)->setFlags(!Qt::ItemIsEditable);

            QTableWidgetItem *tipoGPL = new QTableWidgetItem("GPL");
            tableWidget->setItem(n,9,tipoGPL);
        }
        else
        {
            QTableWidgetItem *acrobaticoGray = new QTableWidgetItem("No");
            tableWidget->setItem(n,6,acrobaticoGray);
            tableWidget->item(n,6)->setFlags(!Qt::ItemIsEditable);

            QTableWidgetItem *trainiGray = new QTableWidgetItem("0");
            tableWidget->setItem(n,7,trainiGray);
            tableWidget->item(n,7)->setFlags(!Qt::ItemIsEditable);

            QTableWidgetItem *tipoVDS = new QTableWidgetItem("VDS");
            tableWidget->setItem(n,9,tipoVDS);
        }

        tableWidget->setItem(n,0,idItem);
        tableWidget->setItem(n,1,studenteItem);
        tableWidget->setItem(n,2,velivoloItem);
        tableWidget->setItem(n,3,istruttoreItem);
        tableWidget->setItem(n,4,minutiItem);
        tableWidget->setItem(n,5,pagamentoItem);
        tableWidget->setItem(n,8,costoItem);

        ++n;
    }

}

lessonstable::~lessonstable(){
    delete tableWidget;
}
