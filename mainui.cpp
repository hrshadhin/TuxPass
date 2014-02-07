#include "mainui.h"
#include "ui_mainui.h"

mainUi::mainUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUi)
{
    ui->setupUi(this);
}

mainUi::~mainUi()
{
    delete ui;
}

void mainUi::on_pushButton_clicked()
{
    adddb adform(this);
    adform.setModal(true);
    adform.exec();
}

void mainUi::on_pushButton_4_clicked()
{
    this->close();
}

void mainUi::on_pushButton_5_clicked()
{

    ldbform.setModal(true);
    ldbform.show();
}
