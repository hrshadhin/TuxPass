#include "helpcontents.h"
#include "ui_helpcontents.h"

HelpContents::HelpContents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpContents)
{
    ui->setupUi(this);
}

HelpContents::~HelpContents()
{
    delete ui;
}

void HelpContents::on_pushButton_clicked()
{
    this->close();
}
