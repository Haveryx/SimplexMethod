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

void Rating::addError(int *error,QString name,double variant)
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
    ui->label_16->setText((QString)chars);

    sprintf(chars, "%d",error[4]);
    ui->label_11->setText((QString)chars);

    sprintf(chars, "%d",error[5]);
    ui->label_13->setText((QString)chars);

    sprintf(chars, "%d",error[6]);
    ui->label_15->setText((QString)chars);

    for(int i=0;i<7;i++)
    {
        sum+=error[i];
    }
    sum-=error[4];
    sprintf(chars, "%d",sum);
    ui->label_3->setText((QString)chars);
    ui->label_19->setText(name);
    sprintf(chars, " %5.2f",variant);
    ui->label_20->setText(ui->label_20->text()+(QString)chars);

}

void Rating::paintEvent(QPaintEvent *)
{
    auto geometry= this->geometry();
    int x=(geometry.width()-571)/2;
    if(x<0){this->setGeometry(geometry.x(),geometry.y(),1011,geometry.height());
      x=(geometry.width()-571)/2;
    }
    int y=(geometry.height()-691)/2;
    if(y<0){this->setGeometry(geometry.x(),geometry.y(),geometry.width(),711);
        y=10;
    }
    ui->groupBox->setGeometry(x,y,571,691);
    ui->label_20->setGeometry(x+600,y,181,41);
}
