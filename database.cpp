#include"database.h"
#include<fstream>
#include<iostream>
#include<QTextStream>

Complete::iterator DataBase::beginDB(){ return db.begin(); }
Complete::iterator DataBase::endDB(){ return db.end(); }

DataBase::DataBase(){load();}
DataBase::~DataBase(){}

void DataBase::load(){
    Lezione* lez=0;
    QString studente, velivolo; int tipo=0, id, minuti=0,  traini=0;
    vuoto=0; corrotto=0;
    bool istruttore, pagata, acrobatico;

    QFile file("../GestoreLezioni/DataBase.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QString filename="../GestoreLezioni/DataBase.xml";
        QFile file(filename);
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            stream<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
            stream<<"<database>"<<endl;
            stream<<"</database>"<<endl;
        }
        vuoto=1;
    }
    QXmlStreamReader xmlReader(&file);
    xmlReader.readNext();
    bool t_id=0, t_stud=0, t_vel=0, t_ist=0, t_min=0, t_pag=0, t_acro=0, t_traini=0;
    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name()=="database"|| xmlReader.name()=="lezione")
            {
                xmlReader.readNext();
                t_id=0, t_stud=0, t_vel=0, t_ist=0, t_min=0, t_pag=0, t_acro=0, t_traini=0;
            }
            if(xmlReader.name()=="id")
            {
                id=xmlReader.readElementText().toInt();
                xmlReader.readNext();
                t_id=1;
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
                t_stud=1;
            }
            if(xmlReader.name()=="velivolo")
            {
                velivolo=xmlReader.readElementText();
                xmlReader.readNext();
                t_vel=1;
            }
            if(xmlReader.name()=="istruttore")
            {
                istruttore=xmlReader.readElementText().toInt();
                xmlReader.readNext();
                t_ist=1;
            }
            if(xmlReader.name()=="minuti")
            {
                minuti=xmlReader.readElementText().toInt();
                xmlReader.readNext();
                t_min=1;
            }
            if(xmlReader.name()=="pagata")
            {
                pagata=xmlReader.readElementText().toInt();
                xmlReader.readNext();
                t_pag=1;
            }

            if(tipo==1)
            {
                if(xmlReader.name()=="acrobatico")
                {
                    acrobatico=xmlReader.readElementText().toInt();
                    xmlReader.readNext();
                    t_acro=1;
                }
            }
            if(tipo==3)
            {
                if(xmlReader.name()=="traini")
                {
                    traini=xmlReader.readElementText().toInt();
                    xmlReader.readNext();
                    t_traini=1;
                 }
            }

        }
        else  //tag closure
        {

             if(xmlReader.isEndElement() && xmlReader.name()=="lezione")    //</lezione>
             {
                if(t_id && t_stud && t_vel && t_ist && t_min && t_pag)
                {
                     if(tipo==1 && t_acro)
                     {
                         lez= new PPL(1,id,studente,velivolo,istruttore,minuti,pagata,acrobatico,0);
                         db.add(lez);
                     }
                     if(tipo==2)
                     {
                        lez=new VDS(2,id,studente,velivolo,istruttore,minuti,pagata);
                        db.add(lez);
                     }
                     if(tipo==3 && t_traini)
                     {
                        lez=new GPL(3,id,studente,velivolo,istruttore,minuti,pagata,0,traini);
                        db.add(lez);
                     }
                }
                else{corrotto=1;}
                if(tipo==1&&t_acro==0){corrotto=1;}
                if(tipo==3&&t_traini==0){corrotto=1;}
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

bool DataBase::getVuoto()const{
    return vuoto;
}
bool DataBase::getCorrotto()const{
    return corrotto;
}
