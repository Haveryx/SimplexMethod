#include "solution.h"
#include "ui_solution.h"

Solution::Solution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Solution)
{
    ui->setupUi(this);
massive=new Massive();
QDesktopWidget desktop;
table=new Table();
table->hide();
QRect size=desktop.geometry();
this->setGeometry(size.x(),size.y(),size.width(),size.height());
checkMin=0;
ui->back->setGeometry(10,size.height()-170,241,61);
ui->back->hide();
ui->pushButton->setGeometry(size.width()-251,size.height()-170,241,61);
ui->pushButton_2->setGeometry(size.width()-88,15,75,23);
}

Solution::~Solution()
{
    delete ui;
    delete this;
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
     ui->label_2->hide();
    ui->label->hide();
   ui->groupBox->hide();
   ui->lineEdit->hide();
   ui->lineEdit_2->hide();
    ui->pushButton->hide();
    ui->back->show();
    //Add Equation
ShowEquation();

ui->pushButton->show();
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
    checkMin=1;
}

void Solution::on_radioButton_clicked()
{
    checkMin=0;
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

for(int i=0;i<cEquation;i++)
{
delete []LineEdits[i];
delete []Labels[i];
delete comboBox[i];
}
delete []LineEdits;
delete []Labels;
ui->pushButton->hide();
Show();
}

void Solution::PaintTable()
{

connect(this,SIGNAL(createTable(int, int,Type,int,double**,double*)),table,SLOT(addInformation(int, int,Type,int,double**,double*)));
createTable(cEquation,vars,Type::reshenie,checkMin,coeffSystems,coeff);
table->show();
this->close();

}

void Solution::Kanon()
{
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
    ShowInputEquation();

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
            LineEdits[j][i].setAlignment(Qt::AlignCenter);
            LineEdits[j][i].show();
            char chars[12];
            sprintf(chars, "X%d",i+1);
           Labels[j][i].setParent(this);
           Labels[j][i].setText((QString)chars);
           Labels[j][i].setGeometry(105+i*65,120 +j*30,20,15);
           Labels[j][i].setAlignment(Qt::AlignCenter);
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
       LineEdits[j][vars].setAlignment(Qt::AlignCenter);
       LineEdits[j][vars].show();
    }
    ui->pushButton->show();
   // connect(ui->pushButton,SIGNAL(clicked(bool)),SLOT(Show()));
 connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));

}

void Solution::ShowEquation()
{
    Zx =new QLabel("Z(X)=",this);
    Zx->setGeometry(30,120,47,15);
    Zx->setAlignment(Qt::AlignCenter);
    Zx->show();
    LineEdits =new   QLineEdit*[vars] ;
    Labels=new QLabel*[vars];
    for(int i=0;i<vars;i++)
    {
     LineEdits[i]=new QLineEdit(this);
     LineEdits[i]->setGeometry(70 +i*65,120,30,15);
     LineEdits[i]->setAlignment(Qt::AlignCenter);
     LineEdits[i]->show();
     char chars[12];
    sprintf(chars, "X%d",i+1);
    Labels[i]=new QLabel((QString)chars,this);
    Labels[i]->setGeometry(105+i*65,120,20,15);
    Labels[i]->setAlignment(Qt::AlignCenter);
    Labels[i]->show();
    }
}

void Solution::ShowInputEquation()
{
    delete Zx;
      for(int i=0;i<cEquation;i++){
        delete Labels[i];
}
      delete []Labels;
    Zx =new QLabel("Z(X)=",this);
    Zx->setGeometry(30,120,50+70*vars,15);
    Zx->setAlignment(Qt::AlignCenter);
    Zx->show();
    for(int i=0;i<vars;i++)
    {
        char chars[12];
        if(coeff[i]<0 or i==0){
            if(coeff[i]-((int)coeff[i])==0){
                sprintf(chars, "%.0f * X%d ",coeff[i],i+1);
            }
        else{
                sprintf(chars, "%.2f * X%d ",coeff[i],i+1);
            }
        }
        else {
            if(coeff[i]-((int)coeff[i])==0){
                sprintf(chars, "+ %.0f * X%d ",coeff[i],i+1);
            }
            else{
            sprintf(chars, "+ %.2f * X%d ",coeff[i],i+1);
            }
        }
        Zx->setText(Zx->text()+(QString)chars);
        Zx->setAlignment(Qt::AlignCenter);
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
             if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                 sprintf(chars, "%.0f * X%d ",coeffSystems[i][j],j+1);
             }
        else{
                 sprintf(chars, "%.2f * X%d ",coeffSystems[i][j],j+1);
             }
         }
         else {
             if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                 sprintf(chars, "+ %.0f * X%d ",coeffSystems[i][j],j+1);
             }
             else{
             sprintf(chars, "+ %.2f * X%d ",coeffSystems[i][j],j+1);
             }
         }

             Labels[i]->setText(Labels[i]->text()+(QString)chars);

     }
     if(coeffSystems[i][vars]-((int)coeffSystems[i][vars])==0){
         sprintf(chars, "= %.0f",coeffSystems[i][vars]);
     }
     else {
          sprintf(chars, "= %.2f",coeffSystems[i][vars]);
     }
     Labels[i]->setText(Labels[i]->text()+(QString)chars);
     Labels[i]->setAlignment(Qt::AlignCenter);
     Labels[i]->show();

    }
    disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(Kanon()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(PaintTable()));
    ui->pushButton->show();
}

void Solution::Show()
{
    Zx =new QLabel("Z(X)=",this);
    Zx->setGeometry(30,120,50+70*vars,15);
    Zx->show();
    for(int i=0;i<vars;i++)
    {
        char chars[12];
        if(coeff[i]<0 or i==0){
            if(coeff[i]-((int)coeff[i])==0){
                sprintf(chars, "%.0f * X%d ",coeff[i],i+1);
            }
        else{
                sprintf(chars, "%.2f * X%d ",coeff[i],i+1);
            }
        }
        else {
            if(coeff[i]-((int)coeff[i])==0){
                sprintf(chars, "+ %.0f * X%d ",coeff[i],i+1);
            }
            else{
            sprintf(chars, "+ %.2f * X%d ",coeff[i],i+1);
            }
        }
        Zx->setText(Zx->text()+(QString)chars);

    }
    Zx->setAlignment(Qt::AlignCenter);
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
             if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                 sprintf(chars, "%.0f * X%d ",coeffSystems[i][j],j+1);
             }
        else{
                 sprintf(chars, "%.2f * X%d ",coeffSystems[i][j],j+1);
             }
         }
         else {
             if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                 sprintf(chars, "+ %.0f * X%d ",coeffSystems[i][j],j+1);
             }
             else{
             sprintf(chars, "+ %.2f * X%d ",coeffSystems[i][j],j+1);
             }
         }

             Labels[i]->setText(Labels[i]->text()+(QString)chars);

     }
     if(coeffSystems[i][vars]-((int)coeffSystems[i][vars])==0){
         if(sign[i]==0){
         sprintf(chars, "= %.0f",coeffSystems[i][vars]);
         }
         else if(sign[i]==1){
              sprintf(chars, ">= %.0f",coeffSystems[i][vars]);
         }
         else{
             sprintf(chars, "<= %.0f",coeffSystems[i][vars]);
         }
     }
     else {
         if(sign[i]==0){
         sprintf(chars, "= %.2f",coeffSystems[i][vars]);
         }
         else if(sign[i]==1){
              sprintf(chars, ">= %.2f",coeffSystems[i][vars]);
         }
         else{
             sprintf(chars, "<= %.2f",coeffSystems[i][vars]);
         }

     }
     Labels[i]->setText(Labels[i]->text()+(QString)chars);
     Labels[i]->show();
     Labels[i]->setAlignment(Qt::AlignCenter);

    }
    disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(Kanon()));
    ui->pushButton->show();
}

void Solution::on_pushButton_2_clicked()
{
    this->close();
}

void Solution::on_back_clicked()
{
    delete Zx;

    for(int i=0;i<vars;i++)
    {
     delete LineEdits[i];

    delete Labels[i];

    }
    ui->label_2->show();
      ui->label->show();
     ui->groupBox->show();
     ui->lineEdit->show();
     ui->lineEdit_2->show();
      ui->pushButton->show();
   ui->back->hide();
disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeff()));
connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));

}
