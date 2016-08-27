#ifndef LESSONSTABLE_H
#define LESSONSTABLE_H
#include "basewindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>


class lessonstable : public basewindow{
    Q_OBJECT
public:
    explicit lessonstable(DataBase* DB);
    virtual ~lessonstable();
    virtual void updateView();
private:
    QTableWidget* tableWidget;
};

#endif // LESSONSTABLE_H
