#ifndef SOLUTION_H
#define SOLUTION_H

#include <QWidget>

namespace Ui {
class Solution;
}

class Solution : public QWidget
{
    Q_OBJECT

public:
    explicit Solution(QWidget *parent = 0);
    ~Solution();

private:
    Ui::Solution *ui;
};

#endif // SOLUTION_H
