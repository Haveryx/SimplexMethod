#ifndef SOLUTION_H
#define SOLUTION_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
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
private:
    Ui::Solution *ui;
    QLineEdit ** LineEdits;
    void PaintTable();
    void GetSystems();
    QLabel** Labels;
    QComboBox ** comboBox;
    int vars=0,cEquation=0;
    double* coeff,** coeffSystems;
    bool type=false;
    QLabel * Zx;
};

#endif // SOLUTION_H
