#include "database.h"
#include <QDebug>
#include<QSqlDatabase>
#include <QDir>
#include <QApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QSqlRecord>
QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
database::database(QWidget *parent) :
    QWidget(parent)
{
}
void database::setdb(QString dbname){
    QDir dir(QDir::homePath()+"/.TuxPass/db/");
     db.setDatabaseName(dir.filePath(dbname));
}

QStringList database::dblist(){
    QStringList nameFilter("*.sdb");
    QDir dir(QDir::homePath()+"/.TuxPass/db/");
    QStringList dbfiles = dir.entryList(nameFilter);
    return dbfiles;
}

QString database::connect(){
        setdb("main.sdb");

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
    if(qry.exec("select * from users where username='"+user+"' and password='"+pass+"'") )
    {

        if(qry.next()){
            suck="true";
        }
        else{
            suck="<font color='red'>[+] User/password wrong!</font>";
        }

    }
    else
        suck=qry.lastError().text();

    return suck;


}

QString database::createdb(QString dbname,QString pass){
    QString success = "false";
    dbname=dbname+".sdb";
    QDir dir(QDir::homePath()+"/.TuxPass/db/");
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
               const QString createTb = "CREATE TABLE IF NOT EXISTS password (pass varchar not null);";
                       QSqlQuery queryt1(db);
                       if (queryt1.exec(createTb)) {
                           success="<font color='green'>[+] Database created.</font>";
                       } else {
                           const QSqlError error = queryt1.lastError();
                           success="<font color='red'>[+] "+error.text()+"</font>";
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
QString database::loaddb(QString dbname,QString pass){

     setdb(dbname);
     QString rel="false";
     if(db.open() )
      {


          QSqlQuery qry(db);
          if(qry.exec("select pass from password where pass='"+pass+"';"))
          {
              int count=0;
              while(qry.next()){
                  count++;
              }
              if(count==1){
                  rel="successfull";
              }
              else if(count<1){
                  rel="<font color='red'>Password wrong!</font>";
              }

          }
          else{
              rel=qry.lastError().text();
          }




      }
      else{

         rel= "<font color='red'>[+]DB couldn't open!</font>";

    }
     \
     return rel;
}

QList<QStringList> database::loaddata(){
      QList<QStringList> list;
      QStringList fieldNames;

     db.open();
      QSqlQuery q( "Select * from data;" );
      QSqlRecord rec = q.record();

      // Put field names in string list
      for( int i=0; i<rec.count(); ++i )
          fieldNames << rec.fieldName( i );

      // Store names to list
      list << fieldNames;
      // Print data based on fields
          foreach( QString str, fieldNames ){
              QStringList dbData;
              while( q.next() ){
                  dbData << q.value(rec.indexOf( str )).toString();
              }
              q.seek(-1);
              list << dbData;
              // since next at end - start at top again for next pass
          }
          // Store dbData in List when complete

          return list;

}

QString database::insertdata(QString dbname,QString name,QString uname,QString pass,QString url,QString date){
    setdb(dbname);
     QString rel="false";
     if(db.open() )
      {
         QSqlQuery qry(db);
         QString q="insert into data values('"+name+"','"+uname+"','"+pass+"','"+url+"','"+date+"');";
         qry.exec(q);
         rel=qry.lastError().text();




     }
     else{

        rel= "<font color='red'>[+]DB couldn't open!</font>";

   }
   db.close();
     return rel;

}

QString database::updateData(QString cname,QString name,QString uname,QString pass,QString url,QString date){
    QString rel="false";
    if(db.open() )
     {
        QSqlQuery qry(db);
         qry.prepare("UPDATE data SET  name=?,username=?,password=?,url=?,dateTime=? WHERE name=?");
         qry.addBindValue(name);
         qry.addBindValue(uname);
         qry.addBindValue(pass);
         qry.addBindValue(url);
         qry.addBindValue(date);
         qry.addBindValue(cname);
         qry.exec();
        rel=qry.lastError().text();

    }
    else{

       rel= "<font color='red'>[+]DB couldn't open!</font>";
    }
  db.close();
  return rel;
}

QString database::deleteEntity(QString entyName){
    QString rel="false";
    if(db.open() )
     {
        QSqlQuery qry(db);
         qry.prepare("delete from data WHERE name=?");
         qry.addBindValue(entyName);
         qry.exec();
         rel=qry.lastError().text();

    }
    else{

       rel= "<font color='red'>[+]DB couldn't open!</font>";
    }
  db.close();
  return rel;
}
//password test
QString database::checkPass(QString dbname,QString pass){
    setdb(dbname);
    QString rel="false";
    if(db.open() )
     {
        QSqlQuery qry(db);
         qry.prepare("select * from password WHERE pass=?");
         qry.addBindValue(pass);
         if(qry.exec()){
             if(qry.next()){
                 rel="true";
             }
             else{
                 rel="Wrong password!";
             }
         }
         else
             rel=qry.lastError().text();

    }
    else{

       rel= "<font color='red'>[+]DB couldn't open!</font>";
    }
  db.close();
  return rel;
}
QString database::changePass(QString dbname,QString olPass,QString nePass){
    setdb(dbname);
    QString rel="false";
    if(db.open() )
     {
        QSqlQuery qry(db),qry2(db);
         qry.prepare("select * from password WHERE pass=?");
         qry.addBindValue(olPass);
         if(qry.exec()){
             if(qry.next()){
                 qry2.prepare("update password set pass=? where pass=?");
                 qry2.addBindValue(nePass);
                 qry2.addBindValue(olPass);
                 if(qry2.exec())
                 {
                      rel="true";
                 }
                 else
                     rel=qry2.lastError().text();
             }
             else{
                 rel="Wrong password! Cant't Change to new password.";
             }
         }
         else
             rel=qry.lastError().text();

    }
    else{

       rel= "<font color='red'>[+]DB couldn't open!</font>";
    }
  db.close();
  return rel;
}
//change master pass
QString database::changeMasterPass(QString name,QString olPass,QString nePass){
    setdb("main.sdb");
    QString rel="false";
    if(db.open() )
     {
        QSqlQuery qry(db),qry2(db);
         qry.prepare("select * from users where username=? and password=?");
         qry.addBindValue(name);
         qry.addBindValue(olPass);
         if(qry.exec()){
             if(qry.next()){
                 qry2.prepare("update users set password=? where password=?");
                 qry2.addBindValue(nePass);
                 qry2.addBindValue(olPass);
                 if(qry2.exec())
                 {
                      rel="true";
                 }
                 else
                     rel=qry2.lastError().text();
             }
             else{
                 rel="Wrong password! Cant't Change to new password.";
             }
         }
         else
             rel=qry.lastError().text();

    }
    else{

       rel= "<font color='red'>[+]DB couldn't open!</font>";
    }
  db.close();
  return rel;
}
//add user to main db
QString database::addMasterUser(QString uname,QString pass){
    setdb("main.sdb");
    QString rel="false";
    if(db.open() )
     {
        QSqlQuery qry(db);
        qry.prepare("insert into users (username,password) values(?,?)");
         qry.addBindValue(uname);
         qry.addBindValue(pass);
         if(qry.exec()){
            rel="true";
         }
         else
             rel=qry.lastError().text();

    }
    else{

       rel= "<font color='red'>[+]DB couldn't open!</font>";
    }
  db.close();
  return rel;
}
