#include "dboparation.h"
#include "ui_dboparation.h"
#include <QMessageBox>
#include "QDebug"

DbOparation::DbOparation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DbOparation)
{

    ui->setupUi(this);
    gval="<font color='blue'>[+]Connected DB: None</font>";
    ui->tab_1->setFocus();
}

DbOparation::~DbOparation()
{
    delete ui;
}

QString DbOparation::myVal(){
    return gval;
}
void DbOparation::on_pushButton_clicked()
{
    database db(this);
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""){
        ui->label_4->setText("<font color='red'>[+] Please insert DB name and password!</font>");
    }
    else
    {
        QString msg= db.createdb(ui->lineEdit->text(),ui->lineEdit_2->text());
        ui->label_4->setText(msg);
    }
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}

void DbOparation::on_tabWidget_currentChanged(int index)
{
    if(!index==0){
        database dbPlayer;
        QStringList dbfiles = dbPlayer.dblist();
        ui->listWidget_load->clear();
        ui->listWidget_delete->clear();
        ui->listWidget_change->clear();
         foreach (QString item, dbfiles) {
             if(!(item=="main.sdb")){
                 ui->listWidget_load->addItem(item);
                 ui->listWidget_delete->addItem(item);
                 ui->listWidget_change->addItem(item);
             }
          }
    }
}

void DbOparation::on_tabWidget_destroyed()
{

}

void DbOparation::on_pushButton_5_clicked()
{
    if(ui->listWidget_load->selectedItems().count()!=1 || ui->lineEdit_loaddbPass->text()=="")
    {
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Please select one db and give passwod!</font>"));

    }
    else
    {

        database db(this);
        QString rel=db.loaddb(ui->listWidget_load->currentItem()->text(),ui->lineEdit_loaddbPass->text());
        if(rel.compare("successfull")==0){
            gval="<font color='green'>[+]Connected DB is:"+ui->listWidget_load->currentItem()->text()+"</font>";
            ui->lineEdit_loaddbPass->setText("");
            ui->listWidget_load->clearSelection();
            this->close();
        }
        else
        {
            QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>"+rel+"</font>"));
        }



    }
}
