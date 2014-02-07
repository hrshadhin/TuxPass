#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <adddb.h>
namespace Ui {
class mainwindow;
}

class mainwindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();
    
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
