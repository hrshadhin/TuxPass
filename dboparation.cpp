#include "dboparation.h"
#include "ui_dboparation.h"
#include <QMessageBox>
#include "QDebug"
#include <endecrypter.h>
#include <QDir>
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
    database db;
    enDecrypter encry;
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""){
        ui->label_4->setText("<font color='red'>[+] Please insert DB name and password!</font>");
    }
    else
    {
        if(ui->lineEdit_2->text().length()<26){
            QString msg= db.createdb(ui->lineEdit->text(),encry.encrypt(ui->lineEdit_2->text()));
            ui->label_4->setText(msg);
            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
        }
        else
           {
               QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Password must be less than 25 characters!</font>"));

           }
    }
}

void DbOparation::on_tabWidget_currentChanged(int index)
{
    if(!index==0){
        loadList();
    }
}

void DbOparation::loadList(){
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
        if(ui->lineEdit_loaddbPass->text().length()<26)
        {
            database db;
            enDecrypter encry;
            QString rel=db.loaddb(ui->listWidget_load->currentItem()->text(),encry.encrypt(ui->lineEdit_loaddbPass->text()));
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
     else
        {
            QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Password must be less than 25 characters!</font>"));

        }


    }
}

void DbOparation::on_pushButton_3_clicked()
{
     QString msg;
     QStringList ls =gval.split(':');
     QStringList mls =ls[1].split('<');
     qDebug()<<ui->listWidget_delete->currentItem()->text();
     qDebug()<<mls[0];
    if(ui->listWidget_delete->selectedItems().count()!=1 || ui->lineEdit_deletePass->text()=="")
    {
              msg="<font color='red'>Please select one db and give passwod!</font>";

    }
    else if(ui->listWidget_delete->currentItem()->text().compare(mls[0])==0)
     {
         msg="<font color='red'> Your Selected DB is now connected.For delete first detouch it.</font>";

    }
    else if(ui->lineEdit_deletePass->text().length()<26)
    {
                  database db;
                  enDecrypter encry;
                  QString rel=db.checkPass(ui->listWidget_delete->currentItem()->text(),encry.encrypt(ui->lineEdit_deletePass->text()));
                  if(rel.compare("true")==0){

                      QString dbpathf = QDir::homePath()+"/.TuxPass/db/"+ui->listWidget_delete->currentItem()->text();

                      if(QFile::remove(dbpathf))
                      {
                         msg="<font color='green'> DB deleted sucsessfully.</font>";
                         ui->lineEdit_deletePass->setText("");
                         loadList();
                      }
                      else
                      {
                          msg="<font color='red'> File cannot delete!!</font>";
                      }



                  }
                  else
                  {
                      msg="<font color='red'>"+rel+"</font>";
                  }
   }
   else
    {

        msg="<font color='red'>Password must be less than 25 characters!</font>";
    }



    QMessageBox::information(0, QString("Error!"), QString(msg));

}
