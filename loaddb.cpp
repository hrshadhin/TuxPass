#include "loaddb.h"
#include "ui_loaddb.h"
#include <QDir>
#include <QDebug>
#include <QMessageBox>
loaddb::loaddb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loaddb)
{
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
   //call dblist
    QStringList nameFilter("*.sdb");
    QDir dir(QApplication::applicationDirPath()+"/db/");
    QStringList dbfiles = dir.entryList(nameFilter);
    foreach (QString item, dbfiles) {
        if(!(item=="main.sdb")){
            ui->listWidget->addItem(item);
        }
     }



}

loaddb::~loaddb()
{
    delete ui;
}

void loaddb::on_pushButton_clicked()
{
    if(ui->listWidget->currentItem()->text()=="" || ui->lineEdit_2->text()=="")
    {
        qDebug()<<"Please seltect one db and give passwod";
    }
    else
    {
        qDebug()<<ui->listWidget->currentItem()->text()+ui->lineEdit_2->text();
    }
}
