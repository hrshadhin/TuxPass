#ifndef DBOPARATION_H
#define DBOPARATION_H

#include <QDialog>
#include <database.h>
namespace Ui {
class DbOparation;
}

class DbOparation : public QDialog
{
    Q_OBJECT
    
public:
    explicit DbOparation(QWidget *parent = 0);
    ~DbOparation();
    QString gval;
    QString myVal();
    
private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_destroyed();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();
    void loadList();

private:
    Ui::DbOparation *ui;
};

#endif // DBOPARATION_H
