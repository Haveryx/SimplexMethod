#include "solution.h"
#include "ui_solution.h"

Solution::Solution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Solution)
{
this->setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
  this->activateWindow();
massive=new Massive();
QDesktopWidget desktop;
table=new Table();
table->hide();
size=desktop.geometry();
this->setGeometry(size.x(),size.y(),size.width(),size.height());
int StartPositionX=(int)(size.width()-734)/3;
int StartPositionY=(int)(size.height()-162)/2;
ui->label->setGeometry(StartPositionX,StartPositionY,291,51);
ui->lineEdit->setGeometry(StartPositionX+442,StartPositionY,151,51);

ui->label_2->setGeometry(StartPositionX,StartPositionY+102,291,51);
ui->lineEdit_2->setGeometry(StartPositionX+442,StartPositionY+102,151,51);

ui->groupBox->setGeometry(StartPositionX*2+593,StartPositionY,141,153);

checkMin=0;
ui->back->setGeometry(10,size.height()-170,241,61);
ui->back->hide();
ui->pushButton_2->setGeometry(size.width()-88,15,75,23);
ui->pushButton->setGeometry(size.width()-251,size.height()-170,241,61);
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
   LineEdits[i]->setText(LineEdits[i]->text().replace(",","."));
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
         LineEdits[j][i].setText(LineEdits[j][i].text().replace(",","."));
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

connect(this,SIGNAL(createTable(int, int,int,double**,double*)),table,SLOT(addInformation(int, int,int,double**,double*)));
createTable(cEquation,vars,checkMin,coeffSystems,coeff);
table->show();
this->close();

}

void Solution::Kanon()
{
    for(int j=0;j<cEquation;j++)
    {
    if(sign[j]!=0){ //add New vars (if in equation have <= or >=
       massive->AddColumn(coeffSystems,vars,cEquation);
       coeffSystems[j][vars]=(sign[j]==2)?1:-1;
       massive->AddElement(coeff,vars);
       sign[j]=0;
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
int startPositionX=(size.width()-190-130*(vars-1))/2;
int startPositionY=(size.height()-25*cEquation*2-1)/2;
    for(int j=0;j<cEquation;j++)
    {
        for( i=0;i<vars;i++)
        {
LineEdits[j][i].setParent(this);
            LineEdits[j][i].setGeometry(startPositionX+i*130,startPositionY+ j*50,50,25);
            LineEdits[j][i].setAlignment(Qt::AlignCenter);
            LineEdits[j][i].show();
            char chars[12];
            sprintf(chars, "X%d",i+1);
           Labels[j][i].setParent(this);
           Labels[j][i].setText((QString)chars);
           Labels[j][i].setGeometry(startPositionX+70+i*130,startPositionY+ j*50,40,25);//TODO вот тут
           Labels[j][i].show();
        }
      comboBox[j]=new QComboBox(this);
      comboBox[j]->addItem("=");
      comboBox[j]->addItem("≥");
      comboBox[j]->addItem("≤");
      comboBox[j]->setGeometry(startPositionX+130+130*(vars-1),startPositionY+ j*50,40,25);
      comboBox[j]->show();
        LineEdits[j][vars].setParent(this);
        LineEdits[j][vars].setGeometry(startPositionX+190+130*(vars-1),startPositionY+ j*50,50,25);
        LineEdits[j][vars].setAlignment(Qt::AlignCenter);
        LineEdits[j][vars].show();

    }
    ui->pushButton->show();

 connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));

}

void Solution::ShowEquation()
{
    Zx =new QLabel("Z(X) =",this);
    int startPositionX=(size.width()-260-(vars-1)*180)/2;
    int startPositionY=(size.height()-30)/2;
    Zx->setGeometry(startPositionX,startPositionY,80,30);
    Zx->show();
    LineEdits =new   QLineEdit*[vars] ;
    Labels=new QLabel*[vars];
    for(int i=0;i<vars;i++)
    {
     LineEdits[i]=new QLineEdit(this);
     LineEdits[i]->setGeometry(startPositionX+105+i*180,startPositionY,80,30);
     LineEdits[i]->setAlignment(Qt::AlignCenter);
     LineEdits[i]->show();
     char chars[12];
    sprintf(chars, "X%d",i+1);
    Labels[i]=new QLabel((QString)chars,this);
    Labels[i]->setGeometry(startPositionX+210+i*180,startPositionY,50,30);
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
      int startX=(size.width()-80-120*vars)/2;
      int startY=(size.height()-50-70*(cEquation+2))/2;
      Zx =new QLabel("Z(X)=",this);
      Zx->setGeometry(startX,startY,80+120*vars,70);
      Zx->setAlignment(Qt::AlignCenter);
      Zx->show();
      for(int i=0;i<vars;i++)
      {
          char chars[12];
          if(coeff[i]<0 or i==0){
              if(coeff[i]-((int)coeff[i])==0){
                  sprintf(chars, "%2.0f * X%d ",coeff[i],i+1);
              }
          else{
                  sprintf(chars, "%2.2f * X%d ",coeff[i],i+1);
              }
          }
          else {
              if(coeff[i]-((int)coeff[i])==0){
                  sprintf(chars, "+ %2.0f * X%d ",coeff[i],i+1);
              }
              else{
              sprintf(chars, "+ %2.2f * X%d ",coeff[i],i+1);
              }
          }
          Zx->setText(Zx->text()+(QString)chars);
      }
      Labels =new QLabel*[cEquation];
      for(int i=0;i<cEquation;i++){
          Labels[i]=new QLabel("",this);
          Labels[i]->setGeometry(startX,startY+210+i*70,80+120*vars,50);
          Labels[i]->setAlignment(Qt::AlignCenter);
      }
      char chars[22];
      for(int i=0;i<cEquation;i++){
       for(int j=0;j<vars;j++)
       {
           if(coeffSystems[i][j]<0 or j==0){
               if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                   sprintf(chars, "%2.0f * X%d ",coeffSystems[i][j],j+1);
               }
          else{
                   sprintf(chars, "%2.2f * X%d ",coeffSystems[i][j],j+1);
               }
           }
           else {
               if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                   sprintf(chars, "+ %2.0f * X%d ",coeffSystems[i][j],j+1);
               }
               else{
               sprintf(chars, "+ %2.2f * X%d ",coeffSystems[i][j],j+1);
               }
           }

               Labels[i]->setText(Labels[i]->text()+(QString)chars);

       }
       if(coeffSystems[i][vars]-((int)coeffSystems[i][vars])==0){
           if(sign[i]==0){
           sprintf(chars, "= %2.0f",coeffSystems[i][vars]);
           }
           else if(sign[i]==1){
                sprintf(chars, "≥ %2.0f",coeffSystems[i][vars]);
           }
           else{
               sprintf(chars, "≤ %2.0f",coeffSystems[i][vars]);
           }
       }
       else {
           if(sign[i]==0){
           sprintf(chars, "= %2.2f",coeffSystems[i][vars]);
           }
           else if(sign[i]==1){
                sprintf(chars, "≥ %2.2f",coeffSystems[i][vars]);
           }
           else{
               sprintf(chars, "≤ %2.2f",coeffSystems[i][vars]);
           }

       }
       Labels[i]->setText(Labels[i]->text()+(QString)chars);
       Labels[i]->show();

      }
    disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(Kanon()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(PaintTable()));
    ui->pushButton->show();
}

void Solution::Show()
{
    int startX=(size.width()-80-120*vars)/2;
    int startY=(size.height()-50-70*(cEquation+2))/2;
    Zx =new QLabel("Z(X)=",this);
    Zx->setGeometry(startX,startY,80+120*vars,70);
    Zx->setAlignment(Qt::AlignCenter);
    Zx->show();
    for(int i=0;i<vars;i++)
    {
        char chars[12];
        if(coeff[i]<0 or i==0){
            if(coeff[i]-((int)coeff[i])==0){
                sprintf(chars, "%2.0f * X%d ",coeff[i],i+1);
            }
        else{
                sprintf(chars, "%2.2f * X%d ",coeff[i],i+1);
            }
        }
        else {
            if(coeff[i]-((int)coeff[i])==0){
                sprintf(chars, "+ %2.0f * X%d ",coeff[i],i+1);
            }
            else{
            sprintf(chars, "+ %2.2f * X%d ",coeff[i],i+1);
            }
        }
        Zx->setText(Zx->text()+(QString)chars);
    }
    Labels =new QLabel*[cEquation];
    for(int i=0;i<cEquation;i++){
        Labels[i]=new QLabel("",this);
        Labels[i]->setGeometry(startX,startY+210+i*70,80+120*vars,50);
        Labels[i]->setAlignment(Qt::AlignCenter);
    }
    char chars[22];
    for(int i=0;i<cEquation;i++){
     for(int j=0;j<vars;j++)
     {
         if(coeffSystems[i][j]<0 or j==0){
             if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                 sprintf(chars, "%2.0f * X%d ",coeffSystems[i][j],j+1);
             }
        else{
                 sprintf(chars, "%2.2f * X%d ",coeffSystems[i][j],j+1);
             }
         }
         else {
             if(coeffSystems[i][j]-((int)coeffSystems[i][j])==0){
                 sprintf(chars, "+ %2.0f * X%d ",coeffSystems[i][j],j+1);
             }
             else{
             sprintf(chars, "+ %2.2f * X%d ",coeffSystems[i][j],j+1);
             }
         }

             Labels[i]->setText(Labels[i]->text()+(QString)chars);

     }
     if(coeffSystems[i][vars]-((int)coeffSystems[i][vars])==0){
         if(sign[i]==0){
         sprintf(chars, "= %2.0f",coeffSystems[i][vars]);
         }
         else if(sign[i]==1){
              sprintf(chars, "≥ %2.0f",coeffSystems[i][vars]);
         }
         else{
             sprintf(chars, "≤ %2.0f",coeffSystems[i][vars]);
         }
     }
     else {
         if(sign[i]==0){
         sprintf(chars, "= %2.2f",coeffSystems[i][vars]);
         }
         else if(sign[i]==1){
              sprintf(chars, "≥ %2.2f",coeffSystems[i][vars]);
         }
         else{
             sprintf(chars, "≤ %2.2f",coeffSystems[i][vars]);
         }

     }
     Labels[i]->setText(Labels[i]->text()+(QString)chars);
     Labels[i]->show();

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
