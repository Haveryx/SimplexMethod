#include "training.h"
#include "ui_training.h"

Training::Training(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
    ui->label_3->hide();
    massive=new Massive();
    QDesktopWidget desktop;
errors=new int[5];
    QRect size=desktop.geometry();
    this->setGeometry(size.x(),size.y(),size.width(),size.height());
    checkMin=0;
    for(int i=0;i<5;i++)errors[i]=0;
    table=new Table();
    table->hide();
    connect(this,SIGNAL(CreateTable(int, int,int *,Type,int,double**,double*)),table,SLOT(addInformation(int, int,int *,Type,int,double**,double*)));
    ui->pushButton_2->setGeometry(size.width()-88,15,75,23);
    ui->pushButton->setGeometry(size.width()-251,size.height()-170,241,61);

}

Training::~Training()
{
    delete ui;
     this->close();
}


void Training::on_pushButton_clicked()
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
disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeff()));

}

void Training::GetCoeff()
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

void Training::on_radioButton_2_clicked()
{
    checkMin=1;
}

void Training::on_radioButton_clicked()
{
    checkMin=0;
}

void Training::GetCoeffSystem()
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

void Training::PaintTable()
{
CreateTable(cEquation,vars,errors,Type::training,checkMin,coeffSystems,coeff);
table->show();
this->close();

}

void Training::KanonOne()
{
    button_two=new QPushButton*[cEquation];
    for(int i=0;i<cEquation;i++)
    {

        button_two[i]=new QPushButton(this);
        button_two[i]->setGeometry(100+170*(vars+2),190 +i*50,170,50);
        button_two[i]->setText("Умножить на -1");
        button_two[i]->show();
        disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(KanonOne()));
        connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(StepOne()));
        connect(button_two[i],SIGNAL(clicked(bool)),SLOT(Unsigned()));

    }



}

void Training::KanonTwo()
{
ui->label_3->hide();
    for(int i=0;i<cEquation;i++)
    {
        delete button_two[i];
    }
    button=new QPushButton*[cEquation];
    button_two=new QPushButton*[cEquation];
    for(int i=0;i<cEquation;i++)
    {
        button[i]=new QPushButton(this);
        button[i]->setGeometry(100+170*(vars+1),190 +i*50,200,50);
        button[i]->setText("Добавить переменную со знаком -");
        button[i]->show();

        button_two[i]=new QPushButton(this);
        button_two[i]->setGeometry(300+170*(vars+1),190 +i*50,200,50);
        button_two[i]->setText("Добавить переменную со знаком +");
        button_two[i]->show();
        disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(StepOne()));
        connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(StepTwo()));
        connect(button[i],SIGNAL(clicked(bool)),SLOT(CheckMinus()));
        connect(button_two[i],SIGNAL(clicked(bool)),SLOT(CheckPlus()));

    }
}

void Training::CheckMinus()
{
    auto Button=QObject::sender();
    int position=0;
    for(int i=0;i<cEquation;i++)
    {
        if(Button==button[i]){
            position=i;
            i=cEquation;
        }
    }
    if(sign[position]!=1){
        button[position]->setStyleSheet("background-color: rgb(214,153,146);");
        errors[0]++;
    }
    else{
        ui->label_3->hide();
        massive->AddColumn(coeffSystems,vars,cEquation);
        coeffSystems[position][vars]=-1;
        massive->AddElement(coeff,vars);
        vars++;
        sign[position]=0;
        button[position]->setStyleSheet("background-color: rgb(71,250,148);");
        for(int i=0;i<cEquation;i++){
          delete Labels[i];
  }
        delete []Labels;
        delete Zx;
        Repaint();
    }

}

void Training::CheckPlus()
{
    auto Button=QObject::sender();
    int position=0;
    for(int i=0;i<cEquation;i++)
    {
        if(Button==button_two[i]){
            position=i;
            i=cEquation;
        }
    }
    if(sign[position]!=2){
        button_two[position]->setStyleSheet("background-color: rgb(214,153,146);");
        errors[0]++;
    }
    else{
        ui->label_3->hide();
        massive->AddColumn(coeffSystems,vars,cEquation);
        coeffSystems[position][vars]=1;
        massive->AddElement(coeff,vars);
        vars++;
        sign[position]=0;
        button_two[position]->setStyleSheet("background-color: rgb(71,250,148);");
        for(int i=0;i<cEquation;i++){
          delete Labels[i];
  }
        delete []Labels;
        delete Zx;
        Repaint();
    }
}

void Training::Unsigned()
{
    auto Button=QObject::sender();
    int position=0;
    for(int i=0;i<cEquation;i++)
    {
        if(Button==button_two[i]){
            position=i;
            i=cEquation;
        }
    }
    if(coeffSystems[position][vars]>0){
        button_two[position]->setStyleSheet("background-color: rgb(214,153,146);");
        errors[0]++;
    }
    else{
        ui->label_3->hide();
        for(int i=0;i<vars+1;i++){
            coeffSystems[position][i]*=-1;
      }
        for(int i=0;i<cEquation;i++){
            delete Labels[i];
        }
            delete []Labels;
            delete Zx;

        Repaint();
        button_two[position]->setStyleSheet("background-color: rgb(71,250,148);");
    }
}

void Training::StepOne()
{
    bool flag=false;
    for(int i=0;i<cEquation;i++)
    {
       // if(sign[i]!=0)flag=true;
        if(coeffSystems[i][vars]<0)flag=true;
    }
    if(flag==true){ui->label_3->show();
        errors[0]++;
    }
    else {
       KanonTwo();
    }



}

void Training::StepTwo()
{
    bool flag=false;
    for(int i=0;i<cEquation;i++)
    {
        if(sign[i]!=0)flag=true;

    }
    if(flag==true){ui->label_3->show();
        errors[0]++;
    }
    else {
       PaintTable();
    }
}

void Training::GetSystems()
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
            LineEdits[j][i].setGeometry(95 +i*110,120 + j*30,40,15);
            LineEdits[j][i].show();
            char chars[12];
            sprintf(chars, "X%d",i+1);
           Labels[j][i].setParent(this);
           Labels[j][i].setText((QString)chars);
           Labels[j][i].setGeometry(150+i*110,120 +j*30,40,15);//TODO вот тут
           Labels[j][i].show();
        }
      comboBox[j]=new QComboBox(this);
      comboBox[j]->addItem("=");
      comboBox[j]->addItem(">=");
      comboBox[j]->addItem("<=");
      comboBox[j]->setGeometry(150+vars*110 ,120 +j*30,40,15);
      comboBox[j]->show();
        LineEdits[j][vars].setParent(this);
        LineEdits[j][vars].setGeometry(150 +(vars+1)*110,120 + j*30,40,15);
        LineEdits[j][vars].show();

    }
    ui->pushButton->show();
   // connect(ui->pushButton,SIGNAL(clicked(bool)),SLOT(Show()));
 connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));

}

void Training::ShowEquation()
{
    Zx =new QLabel("Z(X)=",this);
    Zx->setGeometry(30,120,50,15);
    Zx->show();
    LineEdits =new   QLineEdit*[vars] ;
    Labels=new QLabel*[vars];
    for(int i=0;i<vars;i++)
    {
     LineEdits[i]=new QLineEdit(this);
     LineEdits[i]->setGeometry(95 +i*110,120,40,15);
     LineEdits[i]->show();
     char chars[12];
    sprintf(chars, "X%d",i+1);
    Labels[i]=new QLabel((QString)chars,this);
    Labels[i]->setGeometry(150+i*110,120,40,15);
    Labels[i]->show();
    }

}


void Training::Show()
{
    Repaint();
    disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(KanonOne()));
    ui->pushButton->show();
}

void Training::Repaint()
{
    Zx =new QLabel("Z(X)=",this);
    Zx->setGeometry(30,120,50+50*vars,50);
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
    Labels =new QLabel*[cEquation];
    for(int i=0;i<cEquation;i++){
        Labels[i]=new QLabel("",this);
        Labels[i]->setGeometry(30,190 +i*60,70+50*vars,50);
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

    }
}

void Training::on_pushButton_2_clicked()
{
    this->close();
}
