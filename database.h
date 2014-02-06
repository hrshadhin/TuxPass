#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>
#include <QString>
class database : public QWidget
{
    Q_OBJECT
public:
    explicit database(QWidget *parent = 0);
    
signals:
    
public slots:
    QString hello();
    
};

#endif // DATABASE_H
