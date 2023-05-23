#ifndef SOLUTION_H
#define SOLUTION_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include"massive.h"
#include"table.h"
#include"simplex.h"
#include<QDesktopWidget>
namespace Ui {
class Solution;
}

class Solution : public QWidget
{
    Q_OBJECT

public:
    explicit Solution(QWidget *parent = 0);
    ~Solution();
signals:
    void createTable(int, int,int,double**,double*);
private slots:
    void on_pushButton_clicked();
    void GetCoeff();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
void GetCoeffSystem();
void PaintTable();
void Kanon();
private:
void GetSystems();
void Show();
void ShowEquation();
void ShowInputEquation();

    Ui::Solution *ui;
    QLineEdit ** LineEdits;
Table* table;
    QLabel** Labels;
    QComboBox ** comboBox;
    int vars=0,cEquation=0;
    double* coeff,** coeffSystems,*sign;
    QLabel * Zx;
    Massive* massive;
   int checkMin;

};

#endif // SOLUTION_H
