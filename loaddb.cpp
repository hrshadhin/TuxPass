#include "loaddb.h"
#include "ui_loaddb.h"
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <database.h>
QString gval="";
loaddb::loaddb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loaddb)
{
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
    //
   //call dblist
    QStringList nameFilter("*.sdb");
    QDir dir(QApplication::applicationDirPath()+"/db/");
    QStringList dbfiles = dir.entryList(nameFilter);
    foreach (QString item, dbfiles) {
        if(!(item=="main.sdb")){
            ui->listWidget->addItem(item);
        }
     }
    ui->lineEdit_2->setText("");
    ui->listWidget->clearSelection();
    gval="<font color='blue'>[+]Connected DB: None</font>";


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
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Please select one db and give passwod!</font>"));

    }
    else
    {

        database db(this);
        QString rel=db.loaddb(ui->listWidget->currentItem()->text(),ui->lineEdit_2->text());
        if(rel.compare("successfull")==0){
            gval="<font color='green'>[+]Connected DB is:"+ui->listWidget->currentItem()->text()+"</font>";
            ui->lineEdit_2->setText("");
            ui->listWidget->clearSelection();
            this->close();
        }
        else
        {
            QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>"+rel+"</font>"));
        }



    }
}
