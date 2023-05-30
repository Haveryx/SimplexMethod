#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>

namespace Ui {
class Results;
}

class Results : public QWidget
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = 0);
    ~Results();
public slots:
    void AddInfo(QVector<double*>,int);
    void AddInfo(QVector<double *>, int,int*);

private:
    Ui::Results *ui;
    void ShowResult(QVector<double*> resultat,int cEquation);
    QString CheckOstatok(double&);
};

#endif // RESULTS_H
