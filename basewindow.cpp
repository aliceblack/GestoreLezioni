#include "basewindow.h"

basewindow::basewindow(DataBase* DB, QWidget *parent) : QWidget(parent), windowDB(DB) {}
basewindow::~basewindow(){}

DataBase* basewindow::getDB()const{
    return windowDB;
}





