#include "login.h"
#include "ui_login.h"
#include <database.h>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->label_3->setText("K");

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    mainF.show();
    this->hide();
}
