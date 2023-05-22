#include "solution.h"
#include "ui_solution.h"

Solution::Solution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Solution)
{
    ui->setupUi(this);
massive=new Massive();

}

Solution::~Solution()
{
    delete ui;
}

void Solution::on_pushButton_clicked()
{
    //Read Consts
    if(ui->lineEdit_2->text().length()==0)cEquation=0;
    else{
    cEquation=ui->lineEdit_2->text().toInt();
    }
     if(ui->lineEdit->text().length()==0)vars=0;
     else{
    vars=ui->lineEdit->text().toInt();
     }
    //hide all
    delete ui->label_2;
   delete ui->label;
   delete ui->groupBox;
   delete ui->lineEdit;
   delete ui->lineEdit_2;
    ui->pushButton->hide();
    //Add Equation
ShowEquation();

ui->pushButton->show();
ui->pushButton->setGeometry(40+(vars*65)/2 ,150,60,25);
disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeff()));

}

void Solution::GetCoeff()
{
coeff=new double[vars+cEquation];//процедура увеличения памяти достаточно затратная,поэтому выделим её сразу с запасом
for(int i=0;i<vars;i++)
{
    if(LineEdits[i]->text().length()==0)coeff[i]=0;
    else{
    coeff[i]=LineEdits[i]->text().toDouble();
    }
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

void Solution::GetCoeffSystem()
{
coeffSystems=new double*[cEquation];
sign=new double[cEquation];
for(int i=0;i<cEquation;i++)
{
    coeffSystems[i]=new double[vars+1+cEquation];
}
for(int j=0;j<cEquation;j++)
{

    for(int i=0;i<=vars;i++)
    {
        if(LineEdits[j][i].text().length()==0) coeffSystems[j][i]=0;
        else{
    coeffSystems[j][i]= LineEdits[j][i].text().toDouble();
        }

    }

sign[j]=comboBox[j]->currentIndex();

}
for(int j=0;j<cEquation;j++)
{
if(sign[j]!=0){ //add New vars (if in equation have <= or >=
   massive->AddColumn(coeffSystems,vars,cEquation);
   coeffSystems[j][vars]=sign[j]==2?1:-1;
   massive->AddElement(coeff,vars);
   vars++;
}
if(coeffSystems[j][vars]<0){//if <0
    for(int i=0;i<vars+1;i++){
        coeffSystems[j][i]*=-1;
    }
}
}
for(int i=0;i<cEquation;i++)
{
delete []LineEdits[i];
delete []Labels[i];
delete comboBox[i];
}
delete []LineEdits;
delete []Labels;
ui->pushButton->hide();
ShowInputEquation();
}

void Solution::PaintTable()
{

table=new Table();
connect(this,SIGNAL(createTable(int, int,Type,double**,double*)),table,SLOT(addInformation(int, int,Type,double**,double*)));
createTable(cEquation,vars,Type::reshenie,coeffSystems,coeff);
table->show();
this->close();

}

void Solution::GetSystems()
{
    Labels =new QLabel*[cEquation];
   LineEdits =new QLineEdit*[cEquation];
   comboBox=new QComboBox*[cEquation];
   for(int i=0;i<cEquation;i++)
   {
       LineEdits[i]=new QLineEdit[vars+1];
       Labels[i]=new QLabel[vars];
   }
int i;
    for(int j=0;j<cEquation;j++)
    {
        for( i=0;i<vars;i++)
        {
LineEdits[j][i].setParent(this);
            LineEdits[j][i].setGeometry(70 +i*65,120 + j*30,30,15);
            LineEdits[j][i].show();
            char chars[12];
            sprintf(chars, "X%d",i+1);
           Labels[j][i].setParent(this);
           Labels[j][i].setText((QString)chars);
           Labels[j][i].setGeometry(105+i*65,120 +j*30,20,15);
           Labels[j][i].show();
        }
      comboBox[j]=new QComboBox(this);
      comboBox[j]->addItem("=");
      comboBox[j]->addItem(">=");
      comboBox[j]->addItem("<=");
      comboBox[j]->setGeometry(105+i*65 ,120 +j*30,40,15);
      comboBox[j]->show();
        LineEdits[j][vars].setParent(this);
        LineEdits[j][vars].setGeometry(170 +i*65,120 + j*30,30,15);
        LineEdits[j][vars].show();

    }
    ui->pushButton->setGeometry((vars+1)/2 + 70,150+cEquation*30,60,25);
    ui->pushButton->show();
    connect(ui->pushButton,SIGNAL(clicked(bool)),SLOT(GetCoeffSystem()));


}

void Solution::ShowEquation()
{
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
}

void Solution::ShowInputEquation()
{
    Zx =new QLabel("Z(X)=",this);
    Zx->setGeometry(30,120,50+70*vars,15);
    Zx->show();
    for(int i=0;i<vars;i++)
    {
        char chars[12];
        if(coeff[i]<0 or i==0){
        sprintf(chars, "%.2f * X%d ",coeff[i],i+1);
        }
        else  sprintf(chars, "+ %.2f * X%d ",coeff[i],i+1);
        Zx->setText(Zx->text()+(QString)chars);
    }
    Labels =new QLabel*[cEquation];
    for(int i=0;i<cEquation;i++){
        Labels[i]=new QLabel("",this);
        Labels[i]->setGeometry(30,190 +i*30,70+70*vars,15);
    }
    char chars[22];
    for(int i=0;i<cEquation;i++){
     for(int j=0;j<vars;j++)
     {
         if(coeffSystems[i][j]<0 or j==0){
         sprintf(chars, "%.2f * X%d ",coeffSystems[i][j],j+1);
         }
         else  sprintf(chars, "+ %.2f * X%d ",coeffSystems[i][j],j+1);

             Labels[i]->setText(Labels[i]->text()+(QString)chars);

     }
     sprintf(chars, "= %.2f",coeffSystems[i][vars]);
     Labels[i]->setText(Labels[i]->text()+(QString)chars);
     Labels[i]->show();

    }
    disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(PaintTable()));
    ui->pushButton->setGeometry((70+70*vars)/2-30,190 +(cEquation+1)*30,60,25);
    ui->pushButton->show();
}
