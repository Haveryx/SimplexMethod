#ifndef SOLUTION_H
#define SOLUTION_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
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

private:
    Ui::Solution *ui;
    QLineEdit ** LineEdits;
    QLabel** Labels;
    int vars=0,cEquation=0;
    double* coeff;
    bool type=false;
    QLabel * Zx;
};

#endif // SOLUTION_H
