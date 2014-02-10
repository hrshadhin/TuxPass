#include "mainui.h"
#include "ui_mainui.h"
#include <database.h>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <passgenerate.h>
QString gdbstatus="<font color='blue'>[+]No Connected DB: None</font>";

QList<QStringList> List;
mainUi::mainUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUi)
{
    ui->setupUi(this);
    ui->label_status->setText(gdbstatus);
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked(QListWidgetItem*)));
    //list items need tob be sorts........
}

mainUi::~mainUi()
{
    delete ui;
}

void mainUi::on_pushButton_clicked()
{
    adddb adform(this);
    adform.setModal(true);
    adform.exec();
}

void mainUi::on_pushButton_4_clicked()
{
    this->close();
}

void mainUi::on_pushButton_5_clicked()
{


    //above code need to be functionalize

    ldbform.setModal(true);


    ldbform.exec();
     QString strnew = ldbform.myVal();

     if(strnew.contains("DB is:")){

        database datab;
        datab.dbclose();
        ui->listWidget->clear();
        ui->label_name1->setText("");
        ui->lineEdit_uname1->setText("");
        ui->lineEdit_pass1->setText("");
        ui->lineEdit_url1->setText("");
        ui->label_date1->setText("");
       List= datab.loaddata();
       int i=0;
       int entityLen = List[1].count();
       ui->listWidget->clear();
       while(i<entityLen){
           ui->listWidget->addItem(List[1][i]);
           i++;
       }
        ui->label_status->setText(strnew);

     }




}

void mainUi::on_pushButton_6_clicked()
{

    if(ui->label_status->text().compare(gdbstatus)==0){

        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Database hasn't selected yet.\nFirst load database by 'Load DB' from control panel</font>"));

    }
    else{
        clear();
    }


}

void mainUi::itemClicked(QListWidgetItem* item)
    {

    int len=List[1].count(),j=0;
     QString nstr=item->text();
     int destiny;
     while(j<len){
         if(List[1][j].compare(nstr)==0){
             destiny=j;
         }
         j++;
     }


     int lenList = List.count();

    int k=1;
    QStringList sdata;
     while(k<lenList){

         sdata<<List[k][destiny];
         k++;
     }
     ui->label_name1->setText(sdata[0]);
     ui->lineEdit_uname1->setText(sdata[1]);
     ui->lineEdit_pass1->setText(sdata[2]);
     ui->lineEdit_url1->setText(sdata[3]);
     ui->label_date1->setText(sdata[4]);

  }

void mainUi::on_pushButton_3_clicked()
{

}

void mainUi::clear(){
    database dbclose;
    dbclose.dbclose();
    ui->listWidget->clear();
    ui->label_status->setText(gdbstatus);
    ui->label_name1->setText("");
    ui->lineEdit_uname1->setText("");
    ui->lineEdit_pass1->setText("");
    ui->lineEdit_url1->setText("");
    ui->label_date1->setText("");
    ldbform.gval="<font color='blue'>[+]Connected DB: None</font>";
}

void mainUi::on_pushButton_12_clicked()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString();
    ui->lineEdit_date2->setText(dateTimeString);

}
//password generate
void mainUi::on_pushButton_10_clicked()
{
    passgenerate genP;
    ui->lineEdit_pass2->setText(genP.genPass());
}

void mainUi::on_pushButton_13_clicked()
{
    if(ui->label_status->text().compare(gdbstatus)==0){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Database hasn't selected yet.\nFirst load database by 'Load DB' from control panel</font>"));

    }
    else if(ui->lineEdit_name2->text()=="" || ui->lineEdit_uname2->text()=="" || ui->lineEdit_pass2->text()=="" || ui->lineEdit_url2->text()=="" || ui->lineEdit_date2->text()==""){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>You left empty feilds.Fill all informations!</font>"));

    }
    else
    {
        QStringList ls = ui->label_status->text().split(':');
        QStringList mls =ls[1].split('<');

         database dbinsert;
         QString res=dbinsert.insertdata(mls[0],ui->lineEdit_name2->text(),ui->lineEdit_uname2->text(),ui->lineEdit_pass2->text(),ui->lineEdit_url2->text(),ui->lineEdit_date2->text());
         qDebug() << res;
    }
}
