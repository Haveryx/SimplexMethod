#ifndef NAME_H
#define NAME_H

#include <QWidget>
#include<QDesktopWidget>
#include"training.h"
namespace Ui {
class Name;
}

class Name : public QWidget
{
    Q_OBJECT

public:
    explicit Name(QWidget *parent = 0);
    ~Name();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Name *ui;
    QString name;
    double variant;
public:
signals:
    void PushName(QString,double);
};

#endif // NAME_H
