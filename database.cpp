#include"database.h"

Complete::iterator DataBase::beginDB(){ return db.begin(); }
Complete::iterator DataBase::endDB(){ return db.end(); }

DataBase::DataBase(){load();}
DataBase::~DataBase(){}

void DataBase::load(){
    Lezione* lez=0;
    QString studente, velivolo; int tipo=0, id, minuti=0,  traini=0;
    bool istruttore, pagata, acrobatico;

    QFile file("../GestoreLezioni/DataBase.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text))  std::cout << "Errore: Impossibile leggere il file"<< std::endl;
    QXmlStreamReader xmlReader(&file);
    xmlReader.readNext();

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name()=="database"|| xmlReader.name()=="lezione")
            {
                xmlReader.readNext();
            }
            if(xmlReader.name()=="id")
            {
                id=xmlReader.readElementText().toInt();
                xmlReader.readNext();
            }
            if(xmlReader.name()=="tipo")
            {
                tipo=xmlReader.readElementText().toInt();
                xmlReader.readNext();
            }
            if(xmlReader.name()=="studente")
            {
                studente=xmlReader.readElementText();
                xmlReader.readNext();
            }
            if(xmlReader.name()=="velivolo")
            {
                velivolo=xmlReader.readElementText();
                xmlReader.readNext();
            }
            if(xmlReader.name()=="istruttore")
            {
                istruttore=xmlReader.readElementText().toInt();
                xmlReader.readNext();
            }
            if(xmlReader.name()=="minuti")
            {
                minuti=xmlReader.readElementText().toInt();
                xmlReader.readNext();
            }
            if(xmlReader.name()=="pagata")
            {
                pagata=xmlReader.readElementText().toInt();
                xmlReader.readNext();
            }

            if(tipo==1)
            {
                if(xmlReader.name()=="acrobatico")
                {
                    acrobatico=xmlReader.readElementText().toInt();
                    xmlReader.readNext();
                }
            }
            if(tipo==3)
            {
                if(xmlReader.name()=="traini")
                {
                    traini=xmlReader.readElementText().toInt();
                    xmlReader.readNext();
                 }
            }

        }
        else  //tag closure
        {

             if(xmlReader.isEndElement() && xmlReader.name()=="lezione")    //</lezione>
             {
                 if(tipo==1)
                 {
                     lez= new PPL(id,studente,velivolo,istruttore,minuti,pagata,acrobatico);
                     db.add(lez);
                 }
                 if(tipo==2)
                 {
                    lez=new VDS(id,studente,velivolo,istruttore,minuti,pagata);
                    db.add(lez);
                 }
                 if(tipo==3)
                 {
                    lez=new GPL(id,studente,velivolo,istruttore,minuti,pagata,traini);
                    db.add(lez);
                 }
                 xmlReader.readNext();
             }
             else xmlReader.readNext();
        }
    }
    file.close();
}

void DataBase::close(){
    QFile file("../GestoreLezioni/DataBase.xml");
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("database");    //<database>
    Complete::iterator it;
    for(it=db.begin(); it!=db.end(); ++it)
    {
        xmlWriter.writeStartElement("lezione");
        db[it]->saveLezione(xmlWriter);
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndDocument();               //</database>
    file.close();
}

void DataBase::addDB(Lezione* lez){
    db.add(lez);
}

void DataBase::removeDB(int id){
    db.remove(id);
}

void DataBase::pagaDB(int id){
    db.paga(id);
}
