#ifndef STUDENTSTABLE_H
#define STUDENTSTABLE_H
#include "basewindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QHeaderView>



class studentstable : public basewindow{
    Q_OBJECT
public:
    explicit studentstable(DataBase* DB);
    ~studentstable();
    QTableWidget* tableWidget;
};

#endif // STUDENTSTABLE_H
