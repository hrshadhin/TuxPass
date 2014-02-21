#ifndef HELPCONTENTS_H
#define HELPCONTENTS_H

#include <QDialog>

namespace Ui {
class HelpContents;
}

class HelpContents : public QDialog
{
    Q_OBJECT
    
public:
    explicit HelpContents(QWidget *parent = 0);
    ~HelpContents();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::HelpContents *ui;
};

#endif // HELPCONTENTS_H
