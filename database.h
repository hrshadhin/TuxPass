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
    
};

#endif // DATABASE_H
