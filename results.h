#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include<QPushButton>
#include"rating.h"
namespace Ui {
class Results;
}

class Results : public QWidget
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = 0);
    ~Results();
signals:
    void ShowRaiting(int*,QString,double);
public slots:
    void AddInfo(QVector<double*>,int);
    void AddInfo(QVector<double *>, int,int*,QString,double);

private:
    Ui::Results *ui;
    void ShowResult(QVector<double*> resultat,int cEquation);
    QString CheckOstatok(double&);
    Rating* rating;
    int* error;
    QString name="";
    double variant=0;
private slots:
    void ShowRaiting();
};

#endif // RESULTS_H
