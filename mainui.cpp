#include "mainui.h"
#include "ui_mainui.h"
#include <database.h>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <passgenerate.h>
#include <endecrypter.h>
#include <QClipboard>
#include <QDesktopServices>
#include <QUrl>
#include <QRegExp>
QString gdbstatus="<font color='blue'>[+]No Connected DB: None</font>";
QStringList names;
QList<QStringList> List;
mainUi::mainUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUi)
{
    ui->setupUi(this);
    ui->label_status->setText(gdbstatus);
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked(QListWidgetItem*)));
    connect(ui->listWidget_update,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClickedUp(QListWidgetItem*)));
    connect(ui->listWidget_delete,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClickedDel(QListWidgetItem*)));
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
    if(ui->label_status->text().compare("<font color='blue'>[+]No Connected DB: None</font>")!=0){
        QStringList ls = ui->label_status->text().split(':');
        QStringList mls =ls[1].split('<');
        database setdb;
        setdb.setdb(mls[0]);
    }
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

         dataload();
         ui->label_status->setText(strnew);
         QStringList ls = ui->label_status->text().split(':');
         QStringList mls =ls[1].split('<');
         ui->label_dbnameDel->setText(mls[0]);

     }




}
void mainUi::dataload(){
    names.clear();
    database datab;
    datab.dbclose();
    ui->listWidget->clear();
    ui->listWidget_update->clear();
    ui->listWidget_delete->clear();
    ui->label_name1->setText("");
    ui->lineEdit_uname1->setText("");
    ui->lineEdit_pass1->setText("");
    ui->lineEdit_url1->setText("");
    ui->label_date1->setText("");
   List= datab.loaddata();
   datab.dbclose();
   int i=0;
   int entityLen = List[1].count();
   ui->listWidget->clear();
   enDecrypter endecry;
   while(i<entityLen){
       names.append(endecry.encrypt(List[1][i]));

       i++;
   }
   ui->listWidget->addItems(names);
   ui->listWidget_update->addItems(names);
   ui->listWidget_delete->addItems(names);

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
       QStringList  entyData = getIteminfo(item->text());
       ui->label_name1->setText(entyData[0]);
       ui->lineEdit_uname1->setText(entyData[1]);
       ui->lineEdit_pass1->setText(entyData[2]);
       ui->lineEdit_url1->setText(entyData[3]);
       ui->label_date1->setText(entyData[4]);

  }
void mainUi::itemClickedUp(QListWidgetItem* item){
    QStringList  entyData = getIteminfo(item->text());
    ui->lineEdit_nameUdate->setText(entyData[0]);
    ui->lineEdit_unameUpdate->setText(entyData[1]);
    ui->lineEdit_passUpdate->setText(entyData[2]);
    ui->lineEdit_urlUpdate->setText(entyData[3]);

}
void mainUi::itemClickedDel(QListWidgetItem* item){
    QStringList  entyData = getIteminfo(item->text());
    ui->label_entyNameDel->setText(entyData[0]);

}

//item click event fire funtion
QStringList mainUi::getIteminfo(QString x){
    enDecrypter endecry;
    int len=List[1].count(),j=0;
     QString nstr=endecry.encrypt(x);
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

         sdata<<endecry.encrypt(List[k][destiny]);
         k++;
     }
   return sdata;
}

void mainUi::on_pushButton_3_clicked()
{

}

void mainUi::clear(){
    database dbclose;
    dbclose.dbclose();
    ui->listWidget->clear();
    ui->listWidget_update->clear();
    ui->listWidget_delete->clear();
    ui->lineEdit_nameUdate->setText("");
    ui->lineEdit_unameUpdate->setText("");
    ui->lineEdit_passUpdate->setText("");
    ui->lineEdit_urlUpdate->setText("");
    ui->label_name1->setText("");
    ui->lineEdit_uname1->setText("");
    ui->lineEdit_pass1->setText("");
    ui->lineEdit_url1->setText("");
    ui->label_date1->setText("");
    ui->label_dbnameDel->setText("N/A");
    ui->label_entyNameDel->setText("N/A");
    ui->lineEdit_filter->setText("");
    ui->lineEdit_filter_update->setText("");
    ui->lineEdit_filter_delete->setText("");
    ui->label_status->setText(gdbstatus);
    ldbform.gval="<font color='blue'>[+]Connected DB: None</font>";
}

void mainUi::on_pushButton_12_clicked()
{


}
//password generate
void mainUi::on_pushButton_10_clicked()
{
    passgenerate genP;
    QString gnp=genP.genPass();
    ui->lineEdit_pass2->setText(gnp);
}
//data save operations
void mainUi::on_pushButton_13_clicked()
{
    if(ui->label_status->text().compare(gdbstatus)==0){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Database hasn't selected yet.\nFirst load database by 'Load DB' from control panel</font>"));

    }
    else if(ui->lineEdit_name2->text()=="" || ui->lineEdit_uname2->text()=="" || ui->lineEdit_pass2->text()=="" || ui->lineEdit_url2->text()==""){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>You left empty feilds.Fill all informations!</font>"));

    }
    else
    {
        QStringList ls = ui->label_status->text().split(':');
        QStringList mls =ls[1].split('<');


         enDecrypter endecry;
         QString name=endecry.encrypt(ui->lineEdit_name2->text());
         QString uname=endecry.encrypt(ui->lineEdit_uname2->text());
         QString pass=endecry.encrypt(ui->lineEdit_pass2->text());
         QString url=endecry.encrypt(ui->lineEdit_url2->text());
         QString datetime=endecry.encrypt(datetimenow());

         database dbinsert;
         QString res=dbinsert.insertdata(mls[0],name,uname,pass,url,datetime);

         if(res.compare(" ")==0){
             QMessageBox::information(0, QString("Info"), QString("<font color='green'>Infomations saved successfully.:)</font>"));
             ui->lineEdit_name2->setText("");
             ui->lineEdit_uname2->setText("");
             ui->lineEdit_pass2->setText("");
             ui->lineEdit_url2->setText("");

             dataload();

         }
         else
         {
             QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>"+res+"!!!</font>"));
         }


    }
}

QString mainUi::datetimenow(){
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString();
   return dateTimeString;
}

void mainUi::on_pushButton_11_clicked()
{
    QClipboard *clip;
    clip->setText(ui->lineEdit_pass2->text());
}

void mainUi::on_pushButton_8_clicked()
{
    QClipboard *clip;
    clip->setText(ui->lineEdit_pass1->text());
}

void mainUi::on_pushButton_7_clicked()
{
    QClipboard *clip;
    clip->setText(ui->lineEdit_uname1->text());
}

void mainUi::on_pushButton_9_clicked()
{

    QDesktopServices::openUrl(QUrl(ui->lineEdit_url1->text(), QUrl::TolerantMode));
}

void mainUi::on_lineEdit_filter_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1,Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->listWidget->clear();
    ui->listWidget->addItems(names.filter(regExp));
}

void mainUi::on_lineEdit_filter_update_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1,Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->listWidget_update->clear();
    ui->listWidget_update->addItems(names.filter(regExp));
}

void mainUi::on_lineEdit_filter_delete_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1,Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->listWidget_delete->clear();
    ui->listWidget_delete->addItems(names.filter(regExp));
}

void mainUi::on_btnUpdate_clicked()
{

    if(ui->label_status->text().compare(gdbstatus)==0){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Database hasn't selected yet.\nFirst load database by 'Load DB' from control panel</font>"));

    }
    else if(ui->lineEdit_nameUdate->text()=="" || ui->lineEdit_unameUpdate->text()==""|| ui->lineEdit_urlUpdate->text()==""){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'> You left empty fields!!!</font>"));

    }
    else
    {
        QStringList ls = ui->label_status->text().split(':');
        QStringList mls =ls[1].split('<');
        database dbplayer;
        enDecrypter encry;
        QString name =encry.encrypt(ui->lineEdit_nameUdate->text());
        QString uname =encry.encrypt(ui->lineEdit_unameUpdate->text());
        QString pass=encry.encrypt(ui->lineEdit_passUpdate->text());
        QString url=encry.encrypt(ui->lineEdit_urlUpdate->text());
        QString date=encry.encrypt(datetimenow());
        QString cname = encry.encrypt(ui->listWidget_update->currentItem()->text());
        dbplayer.setdb(mls[0]);
        QString result=dbplayer.updateData(cname,name,uname,pass,url,date);
        if(result.compare(" ")==0)
        {
            QMessageBox::information(0, QString("info"), QString("<font color='green'>Entity update successfully.</font>"));
            dataload();
            ui->lineEdit_nameUdate->setText("");
            ui->lineEdit_unameUpdate->setText("");
            ui->lineEdit_passUpdate->setText("");
            ui->lineEdit_urlUpdate->setText("");



        }else
        {
            QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>"+result+"</font>"));
        }




    }
}

void mainUi::on_btnGenUpdate_clicked()
{
    passgenerate genP;
    QString gnp=genP.genPass();
    ui->lineEdit_passUpdate->setText(gnp);
}

void mainUi::on_pushButton_20_clicked()
{
    if(ui->label_status->text().compare(gdbstatus)==0){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>Database hasn't selected yet.\nFirst load database by 'Load DB' from control panel</font>"));

    }
    else if(ui->label_entyNameDel->text().compare("N/A")==0){
        QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>First select a entity from listbox!!!</font>"));

    }
    else
    {
        QStringList ls = ui->label_status->text().split(':');
        QStringList mls =ls[1].split('<');
        database dbplayer;
        dbplayer.setdb(mls[0]);
        enDecrypter entry;
        QString result=dbplayer.deleteEntity(entry.encrypt(ui->label_entyNameDel->text()));
        if(result.compare(" ")==0)
        {
            QMessageBox::information(0, QString("info"), QString("<font color='green'>Entity deleted successfully.</font>"));
            dataload();
            ui->label_entyNameDel->setText("N/A");
        }else
        {
            QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>"+result+"</font>"));
        }
    }
}
