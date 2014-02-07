#include "database.h"
#include <QDebug>
#include<QSqlDatabase>
#include <QDir>
#include <QApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
database::database(QWidget *parent) :
    QWidget(parent)
{
}

QString database::connect(){
        QDir dir(QApplication::applicationDirPath()+"/db/");
         db.setDatabaseName(dir.filePath("main.sdb"));

         if(db.open() )
          {

              return "<font color='green'>[+]Connected</font>";

          }
          else{

              return "<font color='red'>[+] DB Not found!</font>";

        }



}
void database::dbclose(){
    db.close();
}

QString database::login(QString user,QString pass){
    QSqlQuery qry;
    QString suck="false";
    if(qry.exec("select * from user where username='"+user+"' and password='"+pass+"'") )
    {
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            suck="true";
        }
        else if(count<1){
            suck="<font color='red'>[+] User/password wrong!</font>";
        }

    }

    return suck;


}

QString database::createdb(QString dbname,QString pass){
    QString success = "false";
    dbname=dbname+".sdb";
    QDir dir(QApplication::applicationDirPath()+"/db/");
    QString dbpath =dir.filePath(dbname);
    if(QFile::exists(dbpath) )
    {
         success="<font color='red'>[+] Database Exits!</font>";
    }
    else
    {
        db.setDatabaseName(dbpath);

           if (db.open()) {
               //create password table
               const QString createTb = "CREATE TABLE IF NOT EXISTS password ('pass VARCHAR not null');";
                       QSqlQuery queryt1(db);
                       if (queryt1.exec(createTb)) {
                           success="<font color='green'>[+] Database created.</font>";
                       } else {
                           const QSqlError error = queryt1.lastError();
                           success="<font color='red'>[+] "+error.text()+"/font>";
                       }

                //crete data table
                 const QString createTbdata = "CREATE TABLE IF NOT EXISTS data ("
                         "name varchar not null unique,"
                         "username varchar not null,"
                         "password varchar not null,"
                         "url varchar not null,"
                         "dateTime DATETIME not null"
                         ");";
                    QSqlQuery queryt2(db);
                     if (queryt2.exec(createTbdata)) {
                               success="<font color='green'>[+] Database created.</font>";
                    } else {
                          const QSqlError error = queryt2.lastError();
                           success="<font color='red'>[+] "+error.text()+"/font>";
                   }
                  //insert value in passwrod table
                     const QString passQ = "insert into password values('"+pass+"');";
                     QSqlQuery qinsert(db);
                     if(qinsert.exec(passQ)){
                              success="<font color='green'>[+] Database created.</font>";
                     } else {
                            const QSqlError error = qinsert.lastError();
                             success="<font color='red'>[+] "+error.text()+"/font>";
                    }





              }
           else {
                  const QSqlError error = db.lastError();
                  success="<font color='red'>[+] "+error.text()+"/font>";
              }
        db.close();
    }
     return success;
}
