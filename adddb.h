#ifndef ADDDB_H
#define ADDDB_H

#include <QDialog>

namespace Ui {
class adddb;
}

class adddb : public QDialog
{
    Q_OBJECT
    
public:
    explicit adddb(QWidget *parent = 0);
    ~adddb();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::adddb *ui;
};

#endif // ADDDB_H
