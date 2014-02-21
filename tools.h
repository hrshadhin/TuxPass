#ifndef TOOLS_H
#define TOOLS_H

#include <QDialog>

namespace Ui {
class Tools;
}

class Tools : public QDialog
{
    Q_OBJECT
    
public:
    explicit Tools(QWidget *parent = 0);
    ~Tools();
    
private slots:


    void on_btnMaster_clicked();

private:
    Ui::Tools *ui;
};

#endif // TOOLS_H
