#include "adddb.h"
#include "ui_adddb.h"
#include "database.h"
#include <loaddb.h>
adddb::adddb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddb)
{
    ui->setupUi(this);
}

adddb::~adddb()
{
    delete ui;
}

void adddb::on_pushButton_clicked()
{
    database db(this);
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""){
        ui->label_3->setText("<font color='red'>[+] Please insert DB name and password!</font>");
    }
    else
    {
        QString msg= db.createdb(ui->lineEdit->text(),ui->lineEdit_2->text());
        ui->label_3->setText(msg);
    }
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");

}
