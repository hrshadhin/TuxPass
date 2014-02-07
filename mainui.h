#ifndef MAINUI_H
#define MAINUI_H
#include <QWidget>
#include <adddb.h>
#include <loaddb.h>
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

private:
    Ui::mainUi *ui;
    adddb adbfrom;
    loaddb ldbform;
};

#endif // MAINUI_H
