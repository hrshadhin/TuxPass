#ifndef LOADDB_H
#define LOADDB_H
#include <QDialog>
namespace Ui {
class loaddb;
}

class loaddb : public QDialog
{
    Q_OBJECT
    
public:
    explicit loaddb(QWidget *parent = 0);
    ~loaddb();
    QString myVal();
    QString gval;


    
private slots:
    void on_pushButton_clicked();

private:
    Ui::loaddb *ui;

};

#endif // LOADDB_H
