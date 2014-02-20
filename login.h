#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <mainui.h>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    ~login();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    mainUi mainF;



};

#endif // LOGIN_H
