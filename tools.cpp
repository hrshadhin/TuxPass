#include "tools.h"
#include "ui_tools.h"
#include <database.h>
#include <endecrypter.h>
#include <QMessageBox>
#include <QDebug>
Tools::Tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tools)
{
    ui->setupUi(this);
}

Tools::~Tools()
{
    delete ui;
}


void Tools::on_btnMaster_clicked()
{
    QString msg;
    if(ui->lineEditMasterOlP->text()=="" || ui->lineEditMasterNewP->text()=="" || ui->lineEditMasterConP->text()==""){
        msg="<font color='red'>Please fill all feilds first!!!</font>";
    }
    else if(ui->lineEditMasterNewP->text().compare(ui->lineEditMasterConP->text())!=0){
        msg="<font color='red'>New two passwords didn't match!!</font>";
    }
    else if(ui->lineEditMasterOlP->text().length()<26 && ui->lineEditMasterNewP->text().length()<26 && ui->lineEditMasterConP->text().length()<26)
       {
                     database db;
                     enDecrypter encry;

                     QString rel=db.changeMasterPass(encry.encrypt("sys"),encry.encrypt(ui->lineEditMasterOlP->text()),encry.encrypt(ui->lineEditMasterNewP->text()));

                     if(rel.compare("true")==0){

                         msg="<font color='green'>Master Password Change successfully :)</font>";
                                 ui->lineEditMasterOlP->setText("");
                                 ui->lineEditMasterNewP->setText("");
                                 ui->lineEditMasterConP->setText("");
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



       QMessageBox::information(0, QString("Info"), QString(msg));
}
