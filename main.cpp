#include "mainwindow.h"
#include <QApplication>
#include <QXmlStreamReader>
#include <QString>
#include "ppl.h"
#include "gpl.h"
#include "vds.h"
#include "complete.h"
#include "studente.h"
#include "database.h"
#include "basewindow.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataBase primodb;
    mainwindow m(&primodb);
    //m.show();


        /*cout<<endl<<"ore master ppl "<<primodb.db.oreMasterPPL();
        cout<<endl<<"ore solo ppl "<<primodb.db.oreSoloPPL();
        cout<<endl<<"ore acrobatico ppl "<<primodb.db.oreAcrobaticoPPL();
        cout<<endl<<"ore master vds "<<primodb.db.oreMasterVDS();
        cout<<endl<<"ore solo vds "<<primodb.db.oreSoloVDS();
        cout<<endl<<"ore master gpl "<<primodb.db.oreMasterGPL();
        cout<<endl<<"ore solo gpl "<<primodb.db.oreSoloGPL();

        Complete lezioniJack;
        PPL JAK(4,"001","N444",1,75,1,0);
        PPL* puntJAK=&JAK;
        lezioniJack.add(puntJAK);
        cout<<endl<<endl<<"Jack ha completato "<<lezioniJack.oreMasterPPL()<<" ore ppl master";

        primodb.addDB(puntJAK);*/
        primodb.close();

        cout<<endl<<endl;

    return a.exec();
}
