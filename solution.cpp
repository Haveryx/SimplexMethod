#include "solution.h"
#include "ui_solution.h"

Solution::Solution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Solution)
{
    ui->setupUi(this);
}

Solution::~Solution()
{
    delete ui;
}
