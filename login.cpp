#include "login.h"
#include "ui_login.h"
#include "database.h"
#include <QString>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    database db(this);
    QString d=db.hello();
    ui->label_3->setText(d);






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
