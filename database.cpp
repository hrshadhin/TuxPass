#include "database.h"
#include <QDebug>
#include <QString>
database::database(QWidget *parent) :
    QWidget(parent)
{
}

QString database::hello(){
    return " Hello from db";
}
