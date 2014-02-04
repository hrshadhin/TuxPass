#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QtSql"
mainwindow::mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_pushButton_4_clicked()
{
    this->close();
}
