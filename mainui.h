#ifndef MAINUI_H
#define MAINUI_H
#include <QWidget>
#include <adddb.h>
#include <loaddb.h>
#include <QListWidgetItem>

namespace Ui {
class mainUi;
}

class mainUi : public QWidget
{
    Q_OBJECT
    
public:
    explicit mainUi(QWidget *parent = 0);
    ~mainUi();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void itemClicked(QListWidgetItem* item);

    void clear();
    void on_pushButton_3_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void dataload();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::mainUi *ui;
    adddb adbfrom;
    loaddb ldbform;

};

#endif // MAINUI_H
