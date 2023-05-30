#include "rating.h"
#include "ui_rating.h"

Rating::Rating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rating)
{
    ui->setupUi(this);
}

Rating::~Rating()
{
    delete ui;
}

void Rating::addError(int *error)
{
    char chars[12];
    int sum=0;
    sprintf(chars, "%d",error[0]);
    ui->label_5->setText((QString)chars);

    sprintf(chars, "%d",error[1]);
    ui->label_7->setText((QString)chars);

    sprintf(chars, "%d",error[2]);
    ui->label_9->setText((QString)chars);

    sprintf(chars, "%d",error[3]);
    ui->label_11->setText((QString)chars);

    sprintf(chars, "%d",error[4]);
    ui->label_13->setText((QString)chars);

    for(int i=0;i<5;i++)
    {
        sum+=error[i];
    }
    sprintf(chars, "%d",sum);
    ui->label_3->setText((QString)chars);

}
