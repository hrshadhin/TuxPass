#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>

class database : public QWidget
{
    Q_OBJECT
public:
    explicit database(QWidget *parent = 0);
    
signals:
    
public slots:
    QString connect();
    void dbclose();
    QString login(QString user,QString pass);
    QString createdb(QString dbname,QString pass);
    QString loaddb(QString dbname,QString pass);
    QList<QStringList> loaddata();
    QString insertdata(QString dbname,QString name,QString uname,QString pass,QString url,QString date);
    void setdb(QString dbname);
    QStringList dblist();
    QString updateData(QString cname,QString name,QString uname,QString pass,QString url,QString date);
    QString deleteEntity(QString entyName);
    QString checkPass(QString dbname,QString pass);
    QString changePass(QString dbname,QString olPass,QString nePass);

    
};

#endif // DATABASE_H
