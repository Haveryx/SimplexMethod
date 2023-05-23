#ifndef TRAINING_H
#define TRAINING_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include"massive.h"
#include"table.h"
#include"simplex.h"
#include<QDesktopWidget>
#include<QPushButton>

namespace Ui {
class Training;
}

class Training : public QWidget
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = 0);
    ~Training();
signals:
    void createTable(int, int,int error[5],int,double**,double*);
private slots:
    void on_pushButton_clicked();
    void GetCoeff();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
void GetCoeffSystem();
void PaintTable();
void Kanon();
void CheckSign();
void Unsigned();
void NextStep();
private:
void GetSystems();
void Show();
void Repaint();
void ShowEquation();
void ShowInputEquation();
    QLineEdit ** LineEdits;
Table* table;
    QLabel** Labels;
    Ui::Training *ui;
    QPushButton ** button,**button_two;
    QComboBox ** comboBox;
    int vars=0,cEquation=0;
    double* coeff,** coeffSystems,*sign;
    QLabel * Zx;
    Massive* massive;
   int checkMin;
   int errors[5];
};

#endif // TRAINING_H
