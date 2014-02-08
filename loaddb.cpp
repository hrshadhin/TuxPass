#include "loaddb.h"
#include "ui_loaddb.h"
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <database.h>
QString gval="<font color='blue'>[+]Connected DB: None</font>";
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
QString loaddb::myVal(){
    return gval;
}
loaddb::~loaddb()
{
    delete ui;
}

void loaddb::on_pushButton_clicked()
{
    if(ui->listWidget->selectedItems().count()!=1 || ui->lineEdit_2->text()=="")
    {
        qDebug()<<"Please seltect one db and give passwod";
    }
    else
    {
        database db(this);
        QString rel=db.loaddb(ui->listWidget->currentItem()->text(),ui->lineEdit_2->text());
        gval=rel;
        ui->lineEdit_2->setText("");
        ui->listWidget->clearSelection();
        this->close();

    }
}
