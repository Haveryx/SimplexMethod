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

void Solution::on_pushButton_clicked()
{
    //Read Consts
    cEquation=ui->lineEdit_2->text().toInt();
    vars=ui->lineEdit->text().toInt();
    //hide all
    delete ui->label_2;
   delete ui->label;
   delete ui->groupBox;
   delete ui->lineEdit;
   delete ui->lineEdit_2;
    ui->pushButton->hide();
    //Add Equation
Zx =new QLabel("Z(X)=",this);
Zx->setGeometry(30,120,47,15);
Zx->show();
LineEdits =new   QLineEdit*[vars] ;
Labels=new QLabel*[vars];
for(int i=0;i<vars;i++)
{
 LineEdits[i]=new QLineEdit(this);
 LineEdits[i]->setGeometry(70 +i*65,120,30,15);
 LineEdits[i]->show();
 char chars[12];
 sprintf(chars, "X%d",i+1);
Labels[i]=new QLabel((QString)chars,this);
Labels[i]->setGeometry(105+i*65,120,20,15);
Labels[i]->show();
}
ui->pushButton->show();
ui->pushButton->setGeometry(40+(vars*65)/2 ,150,60,25);
disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeff()));

}

void Solution::GetCoeff()
{
coeff=new double[vars];
for(int i=0;i<vars;i++)
{
    coeff[i]=LineEdits[i]->text().toDouble();
    delete LineEdits[i];
    delete Labels[i];
}
ui->pushButton->hide();
disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeff()));
GetSystems();


delete Zx;

}

void Solution::on_radioButton_2_clicked()
{
    type=true;
}

void Solution::on_radioButton_clicked()
{
    type=false;
}

void Solution::PaintTable()
{


}

void Solution::GetSystems()
{
    Labels =new QLabel*[vars+1];
   LineEdits =new QLineEdit*[vars+1];
   int i;
    for(int j=0;j<cEquation;j++)
    {


        for(i=0;i<vars;i++)
        {
            LineEdits[i]=new QLineEdit(this);
            LineEdits[i]->setGeometry(70 +i*65,120 + j*30,30,15);
            LineEdits[i]->show();
            char chars[12];
            sprintf(chars, "X%d",i+1);
           Labels[i]=new QLabel((QString)chars,this);
           Labels[i]->setGeometry(105+i*65,120 +j*30,20,15);
           Labels[i]->show();
        }
        Labels[i+1]=new QLabel("=",this);
        Labels[i+1]->setGeometry(135+i*65,120 +j*30,20,15);
        Labels[i+1]->show();
        LineEdits[i+1]=new QLineEdit(this);
        LineEdits[i+1]->setGeometry(170 +i*65,120 + j*30,30,15);
        LineEdits[i+1]->show();
        vectors.push_back(LineEdits);
    }


}
