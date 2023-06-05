#include "training.h"
#include "ui_training.h"

Training::Training(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Training)
{
 this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowStaysOnTopHint|Qt::ToolTip);
    ui->setupUi(this);
  this->activateWindow();
    massive=new Massive();
    QDesktopWidget desktop;
errors=new int[7];
     size=desktop.geometry();
    this->setGeometry(size.x(),size.y(),size.width(),size.height());
   int StartPositionX=(int)(size.width()-734)/3;
     int StartPositionY=(int)(size.height()-162)/2;
ui->label->setGeometry(StartPositionX,StartPositionY,291,51);
ui->lineEdit->setGeometry(StartPositionX+442,StartPositionY,151,51);

ui->label_2->setGeometry(StartPositionX,StartPositionY+102,291,51);
ui->lineEdit_2->setGeometry(StartPositionX+442,StartPositionY+102,151,51);

ui->groupBox->setGeometry(StartPositionX*2+593,StartPositionY,141,153);

label1=new QLabel(this);
label1->setGeometry(StartPositionX,StartPositionY-81,593,51);
label1->setAlignment(Qt::AlignCenter);
label1->setText("Исходные данные:");

label2=new QLabel(this);
label2->setGeometry(StartPositionX*2+593,StartPositionY-81,141,51);
label2->setAlignment(Qt::AlignCenter);
label2->setText("Вид задачи:");
label3=new QLabel(this);
label3->setAlignment(Qt::AlignCenter);
label3->hide();
help=new QLabel(this);
help->setAlignment(Qt::AlignCenter);
help->hide();
    checkMin=0;
    for(int i=0;i<7;i++)errors[i]=0;
    table=new Table();
    table->hide();
    connect(this,SIGNAL(CreateTable(int, int,int *,int,double**,double*)),table,SLOT(addInformation(int, int,int *,int,double**,double*)));
    ui->label_3->setGeometry((size.width()-401)/2,size.height()-170,401,51);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_3->hide();
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
    label1->hide();
    label2->hide();
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
    LineEdits[i]->setText( LineEdits[i]->text().replace(",","."));
    if(LineEdits[i]->text().length()==0)coeff[i]=0;
    else{
    coeff[i]=LineEdits[i]->text().toDouble();
    }
    delete LineEdits[i];
    delete Labels[i];
}
ui->pushButton->hide();
label1->hide();
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
label1->hide();
help->hide();
Show();
}

void Training::PaintTable()
{
CreateTable(cEquation,vars,errors,checkMin,coeffSystems,coeff);
table->show();
this->close();

}

void Training::KanonOne()
{
    int startX=(size.width()-80-120*vars)/2;
    label1->hide();
    help->hide();
    label2->setText("Избавление от отрицательной правой части.");
    label2->setGeometry((size.width()-600)/2,150,600,51);
    label2->show();
    help->setText("Умножьте на (-1) строки, содержащие в\nправой части отрицательное значение.");
    help->show();
    int startY=(size.height()-50-70*(cEquation+2))/2;
    button_two=new QPushButton*[cEquation];
    for(int i=0;i<cEquation;i++)
    {

        button_two[i]=new QPushButton(this);
        button_two[i]->setGeometry(startX+100+120*vars,startY+210 +i*70,200,50);
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
label2->setGeometry((size.width()-600)/2,150,600,51);
QLabel* labelsOne=new QLabel(this);
help->hide();
label2->setText("Приведение исходной системы к каноническому виду");
label2->show();
labelsOne->setText("Для приведения системы к каноническому виду,\n"
              "в строки, содержащие ограничения-неравенства\n"
              "типа «≥», «≤», добавьте дополнительные\n"
              " переменные X с нужным знаком.\n");

    for(int i=0;i<cEquation;i++)
    {
        delete button_two[i];
    }
    button=new QPushButton*[cEquation];
    button_two=new QPushButton*[cEquation];
   int startX=(size.width()-700-120*vars)/2;
    int startY=(size.height()-50-70*(cEquation+2))/2;
labelsOne->setGeometry((size.width()-80-120*vars)/2-65+120*vars,(size.height()-50-70*(cEquation+2))/2+84,530,111);
labelsOne->setAlignment(Qt::AlignCenter);
labelsOne->show();

    for(int i=0;i<cEquation;i++)
    {
        button[i]=new QPushButton(this);
        button[i]->setGeometry(startX+340+120*vars,startY+210 +i*70,150,50);
        button[i]->setText("-");
        button[i]->show();

        button_two[i]=new QPushButton(this);
        button_two[i]->setGeometry(startX+510+120*vars,startY+210 +i*70,150,50);
        button_two[i]->setText("+");
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
        if(button[position]->styleSheet()=="background-color: rgb(214,153,146);")button[position]->setStyleSheet("");
        else if(button[position]->styleSheet()!="background-color: rgb(71,250,148);"){
        button[position]->setStyleSheet("background-color: rgb(214,153,146);");
        errors[0]++;
        }
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
        if(button_two[position]->styleSheet()=="background-color: rgb(214,153,146);")button_two[position]->setStyleSheet("");
       else if(button_two[position]->styleSheet()!="background-color: rgb(71,250,148);"){
            button_two[position]->setStyleSheet("background-color: rgb(214,153,146);");
        errors[0]++;
        }
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
    if(coeffSystems[position][vars]>=0){
        if(button_two[position]->styleSheet()=="background-color: rgb(214,153,146);")button_two[position]->setStyleSheet("");
        else if(button_two[position]->styleSheet()!="background-color: rgb(71,250,148);"){
        button_two[position]->setStyleSheet("background-color: rgb(214,153,146);");
        errors[0]++;
        }
    }
    else{
        ui->label_3->hide();
        for(int i=0;i<vars+1;i++){
            coeffSystems[position][i]*=-1; 
      }
        if(sign[position]!=0)sign[position]=(sign[position]==1)?2:1;
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
        for(int i=0;i<cEquation;i++)
        {
            if(button_two[i]->styleSheet()=="background-color: rgb(214,153,146);")flag=true;
        }
       if(flag==false)KanonTwo();
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
        for(int i=0;i<cEquation;i++)
        {
            if(button_two[i]->styleSheet()=="background-color: rgb(214,153,146);")flag=true;
            if(button[i]->styleSheet()=="background-color: rgb(214,153,146);")flag=true;
        }
       if(flag==false)PaintTable();
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
    label1->setGeometry(startPositionX-30,startPositionY-132,300+130*(vars-1),102);
    label1->setText("Введите коэффициенты и знаки\nпри системе ограничений:");
    label1->show();
    help->hide();
     help->setGeometry(startPositionX-80,startPositionY+(cEquation+1)*50,400+130*(vars-1),81);
     help->show();
   // connect(ui->pushButton,SIGNAL(clicked(bool)),SLOT(Show()));
 connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));

}

void Training::ShowEquation()
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
    label1->setText("Введите коэффициенты целевой функции:");
    label1->setGeometry(startPositionX,startPositionY-81,210+(vars-1)*180+50,51);
    label1->show();
    help->setText("Вводите данные внимательно!\nВернуться к предыдущему шагу будет невозможно.");
    help->setGeometry(startPositionX-50,startPositionY+150,210+(vars-1)*180+150,81);
    help->show();
}


void Training::Show()
{
    help->setText("Проверьте введенные вами данные.\nПри обнаружении ошибки, закройте приложение и\nзапустите «Тренажер» заново.");
    Repaint();
     label1->setText("Исходная задача имеет вид:");
     label1->show();
     help->show();
    disconnect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(GetCoeffSystem()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(KanonOne()));
    ui->pushButton->show();
}

void Training::Repaint()
{
     int startX=(size.width()-700-120*vars)/2;
    int startY=(size.height()-50-70*(cEquation+2))/2;
    Zx =new QLabel("Z(X) =",this);
    Zx->setGeometry(startX,startY+94,80+120*vars,81);
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
    QString strings=(checkMin==0)?"→min":"→max";
    Zx->setText(Zx->text()+strings);
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
     label1->setGeometry(startX,startY-81,80+120*vars,51);
     help->setGeometry((size.width()-80-120*vars)/2-65+120*vars,startY+84,530,111);
    }
     label3->setGeometry(startX,startY+210+cEquation*70,80+120*vars,50);
     label3->setText("Xj ≥ 0, j = ");
     for(int i=1;i<vars+1;i++){
         if(i==vars){
             sprintf(chars, "%d.",i);
         }
         else sprintf(chars, "%d,",i);
         label3->setText(label3->text()+(QString)chars);
     }
    label3->show();

}

void Training::on_pushButton_2_clicked()
{
    this->close();
}
