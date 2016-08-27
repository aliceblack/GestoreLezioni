#ifndef DATABASE_H
#define DATABASE_H
#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<vector>
#include"complete.h"
#include"lezione.h"
#include"motore.h"
#include"ppl.h"
#include"vds.h"
#include"gpl.h"


class DataBase{
private:
    Complete db;
    bool vuoto;
    bool corrotto;
public:
    DataBase();
    ~DataBase();
    bool getVuoto()const;
    bool getCorrotto()const;
    void load();
    void close();
    void addDB(Lezione*);
    void removeDB(int);
    void pagaDB(int);
    Complete::iterator beginDB();
    Complete::iterator endDB();
};



#endif // DATABASE_H
