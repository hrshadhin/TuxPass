#include "login.h"
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <database.h>
#include <QMessageBox>
#include <endecrypter.h>
#include <QTextStream>
#include <QDateTime>
void createDirdb(){
    QString dbCusPath="/.tuxpass/db";
     QString dirPath=QDir::homePath()+dbCusPath;
     QDir dir(dirPath);
     if (!dir.exists()) {
         dir.mkpath(".");
         database dbplayer;
         enDecrypter encry;
         QString msg =dbplayer.createMaster();
         msg=dbplayer.addMasterUser(encry.encrypt("sys"),encry.encrypt("admin"));
         if(msg.contains("Database created") || msg.contains("true"))
            {

             qDebug()<<"Master create Successfull:)";
            }
           else{
             QMessageBox::critical(0, QString("Error!"), QString("<font color='red'>"+msg+"</font>"));

          }

     }
    else{
        qDebug()<<"DB directory Exits.";
    }
     QString filename=QDir::homePath()+"/.tuxpass/log.txt";
     QFile file( filename );
     QDateTime dateTime = QDateTime::currentDateTime();
     QString dateTimeString = dateTime.toString();
     if(file.open(QIODevice::ReadWrite) )
     {
         file.seek(file.size());
         QTextStream stream( &file );
         stream << dateTimeString << endl;
     }
     else
         qDebug()<<"log file couldn't' open!!";
     file.close();

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createDirdb();
    login w;
    w.show();
    
    return a.exec();
}


