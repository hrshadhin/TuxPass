#include "login.h"
#include "ui_login.h"
#include "database.h"
#include <endecrypter.h>
#include <QDebug>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    database db(this);
    QString msg=db.connect();
    ui->label_3->setText(msg);

}

login::~login()
{
    delete ui;

}

void login::on_pushButton_clicked()
{
    database db;
    enDecrypter encry;
    QString result=db.login(encry.encrypt(ui->lineEdit->text()),encry.encrypt(ui->lineEdit_2->text()));
    if(result=="true"){

        mainF.show();

        this->hide();
    }
    else{
        ui->label_3->setText(result);
    }

}


void login::on_lineEdit_2_editingFinished()
{
    on_pushButton_clicked();
}
