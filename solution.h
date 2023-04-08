#ifndef SOLUTION_H
#define SOLUTION_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include"paints.h"
#include"massive.h"
namespace Ui {
class Solution;
}

class Solution : public QWidget
{
    Q_OBJECT

public:
    explicit Solution(QWidget *parent = 0);
    ~Solution();

private slots:
    void on_pushButton_clicked();
    void GetCoeff();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
void GetCoeffSystem();
void PaintTable();
private:
    Ui::Solution *ui;
    QLineEdit ** LineEdits;
    Paints * paints;
    void GetSystems();
    void ShowEquation();
    void ShowInputEquation();
    QLabel** Labels;
    QComboBox ** comboBox;
    int vars=0,cEquation=0;
    double* coeff,** coeffSystems,*sign;
    bool type=false;
    QLabel * Zx;
    Massive* massive;
};

#endif // SOLUTION_H
