#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{

    //this->setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
  //  this->activateWindow();
   results=new Results();
   results->hide();
   connect(this,SIGNAL(PushInfo(QVector<double*>,int)),results,SLOT(AddInfo(QVector<double*>,int)));
   connect(this,SIGNAL(PushInfo(QVector<double*>,int,int*)),results,SLOT(AddInfo(QVector<double*>,int,int*)));
    QDesktopWidget desktop;
    QRect size=desktop.geometry();

    this->setGeometry(size.x(),size.y(),size.width(),size.height());

    SimpleGod=new simplex();

    label=new QLabel("Решение найдено!",this);

   label->setGeometry(0,5,150,20);
    label2=new QLabel("Однако есть ещё одно решение!",this);
     label2->setGeometry(0,30,150,20);
     label->hide();
     label2->hide();

     ui->pushButton_2->setGeometry(size.width()-88,15,75,23);
 auto StartPosition=(size.width()-429)/6;
 ui->Optimal->setGeometry(StartPosition,15,80,21);
 ui->Optimal->hide();

 ui->NotOptimal->setGeometry(StartPosition*2+80,15,120,21);
 ui->NotOptimal->hide();

 ui->SomeSolution->setGeometry(StartPosition*3+200,15,141,21);
 ui->SomeSolution->hide();

     next=new QPushButton(this);
     next->setText("Далее");
     next->setGeometry(size.width()-251,size.height()-170,241,61);
     next->hide();

errors=new int[7];
}


Table::~Table()
{
    delete ui;
    delete SimpleGod;
     this->close();
}

void Table::addInformation(int cEquation, int vars,int minimum,double** System,double* Z)
{
    system=new double*[cEquation+1];
     count=new bool[cEquation];
      for(int i=0;i<cEquation;i++)count[i]=false;
QVector<int> p;
    for(int i=0;i<cEquation+1;i++)
    {
        system[i]=new double[vars*2+2];
        blackList.push_back(p);
    }
    basis=new QString[cEquation];
    Basis=new int[cEquation];
    for(int i=0;i<cEquation;i++)
    {
        basis[i]="";
        Basis[i]=-1000;
    }


     z=new double[vars+1];
     this->Z=new QLabel*[vars];
     this->Z[0]=new QLabel(this);
     this->Z[0]->setText("Z(X)");
      this->Z[0]->hide();
      char chars[12];
      for(int i=1;i<vars+1;i++){

          if(Z[i-1]-((int)Z[i-1])!=0){

          sprintf(chars, "%5.2f",Z[i-1]);

          }
          else sprintf(chars, "%5.0f",Z[i-1]);
          this->Z[i]=new QLabel(this);
          this->Z[i]->setText((QString)chars);
           this->Z[i]->hide();
      }
    this->cEquation=cEquation;
    this->vars=vars;
    this->type=Type::reshenie;
     checkMin=minimum;
    Massive massive;
    z=Z;
   massive.Union(system,System,vars,cEquation);

       text=new QLabel*[cEquation+2];
       for(int i=0;i<cEquation+2;i++)
       {
           text[i]=new QLabel[vars*2+3];
       }
       for(int j=0;j<cEquation+2;j++)
       {
           for(int i=0;i<vars*2+3;i++)
           {
                text[j][i].setParent(this);
           }
       }
SimpleGod->getTetta(system,Basis,vars,cEquation);
     vectors=SimpleGod->GetMin(system,Basis,vars,cEquation);
     for(int i=0;i<cEquation;i++)
     {
     while(!vectors[i].empty()){
         text[1+i][vectors[i].front()+1].setStyleSheet("background-color: rgb(71,250,148);");
         text[1+i][vectors[i].front()+1].installEventFilter(this);
         actual.push_back(&text[1+i][vectors[i].front()+1]);
         map[&text[1+i][vectors[i].front()+1]]=vectors[i].front();
         vectors[i].pop_front();
     }
}

   repaint();
}

void Table::addInformation(int cEquation, int vars,int *errors,int minimum,double** System,double* Z)
{
    next->show();

    count=new bool[cEquation];
    for(int i=0;i<cEquation;i++)count[i]=false;

    system=new double*[cEquation+1];
QVector<int> p;
connect(next,SIGNAL(clicked(bool)),SLOT(CheckTetta()));
    for(int i=0;i<cEquation+1;i++)
    {
        system[i]=new double[vars*2+2];
        blackList.push_back(p);
    }
    basis=new QString[cEquation];
    Basis=new int[cEquation];
    for(int i=0;i<cEquation;i++)
    {
        basis[i]="";
        Basis[i]=-1000;
    }
     z=new double[vars];
    this->Z=new QLabel*[vars+1];
     char chars[12];
     this->Z[0]=new QLabel(this);
     this->Z[0]->setText("Z(X)");
     this->Z[0]->hide();

     for(int i=1;i<vars+1;i++){

         if(Z[i-1]-((int)Z[i-1])!=0){

         sprintf(chars, "%5.2f",Z[i-1]);

         }
         else sprintf(chars, "%5.0f",Z[i-1]);
         this->Z[i]=new QLabel(this);
         this->Z[i]->setText((QString)chars);
         this->Z[i]->hide();
     }
    this->cEquation=cEquation;
    this->vars=vars;
    this->type=Type::training;
     for(int i=0;i<7;i++){
         this->errors[i]=errors[i];
     }
     checkMin=minimum;
    Massive massive;
    z=Z;
   massive.Union(system,System,vars,cEquation);
       text=new QLabel*[vars*2+4];
       input=new QLineEdit*[cEquation+1];
       for(int i=0;i<cEquation+1;i++)
       {
          input[i]=new QLineEdit[vars*2+3];
       }
       for(int i=0;i<cEquation+1;i++)
       {
           for(int j=0;j<vars*2+3;j++){
               input[i][j].setParent(this);
               input[i][j].hide();
               input[i][j].setAlignment(Qt::AlignCenter);
           }
       }

       for(int i=0;i<vars*2+4;i++)
       {
           text[i]=new QLabel(this);
           text[i]->setAlignment(Qt::AlignCenter);

       }

       for(int j=0;j<cEquation;j++)//Циферки выводим
       {

           for(int i=1;i<vars+2;i++)
           {
               if(system[j][i]-((int)system[j][i])!=0){
               sprintf(chars, "%5.2f",system[j][i]);
               }
               else sprintf(chars, "%5.0f",system[j][i]);
               input[j][i+1].setText(chars);

           }
       }



SetReadOnly();
SetWrite(0,cEquation,3+vars,2*vars+3);
}

void Table::AllNotColor()
{
    for(int i=0;i<(cEquation+2);i++)
    {
        for(int j=0;j<(vars*2+3);j++)
        {
            text[i][j].setStyleSheet("background-color: rgb(255,255,255);");
        }

    }
}

void Table::SetColorBasis()
{
    for(int i=0;i<cEquation+1;i++)
    {
       text[i][0].setStyleSheet("background-color: rgb(71,250,148);");
    }
}

void Table::NotColorBasis(int * basis)
{
    for(int j=0;j<cEquation;j++)
    {
 for(int i=0;i<cEquation+1;i++)
 {
    if(basis[j]!=-1000)text[i][basis[j]+2].setStyleSheet("background-color: rgb(255,255,255);");
 }
    }
}

void Table::SetColorBasis(int *basis)
{
       for(int j=0;j<cEquation;j++)
       {
    for(int i=0;i<cEquation+1;i++)
    {
        if(basis[j]!=-1000)text[i][basis[j]+2].setStyleSheet("background-color: rgb(71,250,148);");
    }
       }
}

void Table::ColorColumn(int j)
{
    for(int i=0;i<cEquation+2;i++)
    {
        text[i][j].setStyleSheet("background-color: rgb(71,250,148);");
    }
}

void Table::NotColor()
{
    for(int i=0;i<actual.size();i++)
    {
        actual[i]->setStyleSheet("background-color: rgb(255,255,255);");
    }
}

void Table::PushResult()
{
    double* resultat=new double[vars+1];
    for(int i=0;i<vars;i++)
    {
        resultat[i]=0;
    }
    for(int i=0;i<cEquation;i++)
    {
        resultat[Basis[i]-1]=system[i][1];
    }
    resultat[vars]=system[cEquation][1];
    result.push_back(resultat);
}

void Table::NextStep()
{
    int Reshenie=0;
    bool flags=false;
    for(int i=0;i<cEquation;i++){
        if(count[i]==false){
            flags=true;
        }
    }
    if(flags==true){
        SimpleGod->getTetta(system,Basis,vars,cEquation);
             vectors=SimpleGod->GetMin(system,Basis,vars,cEquation);
             for(int i=0;i<cEquation;i++){
             while(!vectors[i].empty()){
                 if(SimpleGod->checkBlackList(blackList,i,vectors[i].front())==false){
                 text[1+i][vectors[i].front()+1].setStyleSheet("background-color: rgb(71,250,148);");
                 text[1+i][vectors[i].front()+1].installEventFilter(this);
                 actual.push_back(&text[1+i][vectors[i].front()+1]);
                 map[&text[1+i][vectors[i].front()+1]]=vectors[i].front();
                 vectors[i].pop_front();
                 Reshenie++;
                 }
                 else{
                      vectors[i].pop_front();
                 }
             }

             }
             if(Reshenie==0){
                 label->setText("Нет решения");
                  label->show();
                  AllNotColor();
             }
    }
    else{
        SimpleGod->getDelta(system,z,vars,cEquation);
        solution j=SimpleGod->Resheno(system,Basis,vars,cEquation,checkMin);
        switch (j) {
        case solution::Optimal:
     label2->hide();
           label->show();
            AllNotColor();
            SetColorBasis();
            for(int i=3;i<vars+3;i++)
            {
                  text[cEquation+1][i].setStyleSheet("background-color: rgb(71,250,148);");
            }
            PushResult();
            PushInfo(result,vars);
            results->show();
             this->close();
            break;

        case solution::NotOptimal:
            AllNotColor();
             SetColorBasis(Basis);
              SimpleGod->getTetta(system,Basis,vars,cEquation);
            vectors=SimpleGod->GetMax(system,Basis,vars,cEquation,checkMin);
            for(int i=0;i<cEquation;i++)
            {
                while(!vectors[i].empty()){
if(SimpleGod->checkBlackList(blackList,i,vectors[i].front())==false){
                    text[1+i][vectors[i].front()+1].setStyleSheet("background-color: rgb(71,250,148);");
                    text[1+i][vectors[i].front()+1].installEventFilter(this);
                    actual.push_back(&text[1+i][vectors[i].front()+1]);
                    map[&text[1+i][vectors[i].front()+1]]=vectors[i].front();
                    vectors[i].pop_front();
                    Reshenie++;
}
else{
    vectors[i].pop_front();
}

                }
            }
if(Reshenie==0){
    label->setText("Нет решения");
     label->show();
     AllNotColor();
     PushInfo(result,vars);
     results->show();
      this->close();
}
            break;
        case solution::SomeSolution:

            AllNotColor();
            SetColorBasis();
            PushResult();
            for(int i=3;i<vars+3;i++)
            {
                  text[cEquation+1][i].setStyleSheet("background-color: rgb(71,250,148);");
            }

              label->show();
              label2->show();
              SimpleGod->getTetta(system,Basis,vars,cEquation);
              vectors=SimpleGod->SomeSolution(system,Basis,vars,cEquation);
                 AllNotColor();
              for(int i=0;i<cEquation;i++)
              {
                  while(!vectors[i].empty()){
if(SimpleGod->checkBlackList(blackList,i,vectors[i].front())==false)
{
                      text[1+i][vectors[i].front()+1].setStyleSheet("background-color: rgb(71,250,148);");
                      text[1+i][vectors[i].front()+1].installEventFilter(this);
                      actual.push_back(&text[1+i][vectors[i].front()+1]);
                      map[&text[1+i][vectors[i].front()+1]]=vectors[i].front();
                      vectors[i].pop_front();
                      Reshenie++;
}
else{
    vectors[i].pop_front();

                  }
              }
}
              if(Reshenie==0)
              {
                  label2->hide();
                  label->show();
                  AllNotColor();
                  SetColorBasis();
                  PushInfo(result,vars);
                  results->show();
                  this->close();
                  for(int i=3;i<vars+3;i++)
                  {
                        text[cEquation+1][i].setStyleSheet("background-color: rgb(71,250,148);");
                  }
              }

            break;

        default:
            break;
        }


    }
}

int Table::CheckPosition(QLabel *labelOne, QLabel **LabelTwo)
{
    for(int i=1;i<cEquation+1;i++)
    {
        for(int j=vars+3;j<vars*2+3;j++)
        {
            if(labelOne==&LabelTwo[i][j])return i;
        }
    }
    return -1;
}

int Table::CheckPosition(QLineEdit *lineOne, QLineEdit **lineTwo)
{
    for(int i=0;i<cEquation;i++)
    {
        for(int j=vars+3;j<vars*2+3;j++)
        {
          if(lineOne==&lineTwo[i][j])return i;
        }
    }
    return -1;
}

int Table::CheckString(QLineEdit *lineOne, QLineEdit **lineTwo)
{
    for(int i=0;i<cEquation;i++)
    {
        for(int j=vars+3;j<vars*2+3;j++)
        {
          if(lineOne==&lineTwo[i][j])return j;
        }
    }
    return -1;
}

void Table::GetInputTetta()
{
      next->setStyleSheet("background-color: rgb(255,255,255);");
    bool flag=true;
    double ** CheckInput=new double*[cEquation+1];
    for(int i=0;i<cEquation+1;i++)
    {
        CheckInput[i]=new double[2*vars+2];
    }
    for(int i=0;i<cEquation;i++)
    {
        for(int j=2+vars;j<2*vars+2;j++){

           input[i][j+1].setText(input[i][j+1].text().replace(",","."));
            CheckInput[i][j]=(input[i][j+1].text()=="-")? INFINITY:input[i][j+1].text().toDouble();
            input[i][j+1].setStyleSheet("background-color: rgb(255,255,255);");
            if(std::abs(CheckInput[i][j]-system[i][j])>0.05){
                flag=false;
                errors[1]++;
                input[i][j+1].setStyleSheet("background-color: rgb(214,153,146);");
          }

        }

    }
    if(flag==true){
        next->setText("Выбираем минимальные тетты");

            for(int i=0;i<cEquation;i++)
            {
                for(int j=2+vars;j<2*vars+2;j++){
             system[i][j]=CheckInput[i][j];
                }

        }
        disconnect(next,SIGNAL(clicked(bool)),this,SLOT(CheckTetta()));
  CheckMinTetta();

    }
  for(int i=0;i<cEquation+1;i++)
    {
        delete []CheckInput[i];
    }
    delete []CheckInput;

}

void Table::paintEvent(QPaintEvent *)
{
    painter=new QPainter(this);
     painter->setPen(QPen(color,sizeLine,Qt::SolidLine));
   auto geometry= this->geometry();
    label->setGeometry((geometry.width()-250)/2,5,250,20);
      label2->setGeometry((geometry.width()-250)/2,30,250,20);
    if(geometry.width()<((vars*2 +3)*sizeX +2*sizeLine))resize(((vars*2 +3)*sizeX) +2*sizeLine,geometry.height());
   x=(int)(geometry.width()-((vars*2 +3)*sizeX))/2;
  if(geometry.height()<((cEquation+2)*sizeY + 2*sizeLine+50))resize(geometry.width(),((cEquation+2)*sizeY +2*sizeLine+50));
    y=(int)(geometry.height()-(cEquation+2)*sizeY)/2;
        painter->drawLine(QPointF(x,y),QPointF(x+(vars*2 +3)*sizeX,y));//Верхняя линия
        painter->drawLine(QPointF(x,y),QPointF(x,y+(cEquation+2)*sizeY));//Левая вертикальная
        painter->drawLine(QPointF(x,y+(cEquation+2)*sizeY),QPointF(x+(vars*2 +3)*sizeX,y+(cEquation+2)*sizeY));//Нижняя линия
  painter->drawLine(QPointF(x+(vars*2 +3)*sizeX,y+(cEquation+2)*sizeY),QPointF(x+(vars*2 +3)*sizeX,y));//Правая линия
  //Строим горизонтальные
for(int i=x+sizeX;i<x+(vars*2 +3)*sizeX;i+=sizeX){
    painter->drawLine(QPointF(i,y),QPointF(i,y+(cEquation+1)*sizeY));
}
//Вертикальные
for(int i=y+sizeY;i<y+(cEquation+2)*sizeY;i+=sizeY){
   painter->drawLine(QPointF(x,i),QPointF(x+(vars*2 +3)*sizeX,i));//Верхняя линия

}
//Нижняя строка с оптимальностью
painter->drawLine(QPointF(x+sizeX*2,y+(cEquation+1)*sizeY),QPointF(x+sizeX*2,y+(cEquation+2)*sizeY));
for(int i=x+sizeX*3;i<=(x+sizeX*(3+vars));i+=sizeX)
{
painter->drawLine(QPointF(i,y+(cEquation+1)*sizeY),QPointF(i,y+(cEquation+2)*sizeY));
}
//Добавляем всё остальное в таблицу
switch (type) {
case Type::reshenie:
    //text[0][0].setFont();Todo Добавить шрифт
    text[0][0].setGeometry(x+sizeLine,y+sizeLine,sizeX-2*sizeLine,sizeY-2*sizeLine);
    text[0][0].setText("B");
    text[0][0].setAlignment(Qt::AlignCenter);
    text[0][0].show();

    text[0][1].setGeometry(x+sizeX+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
    text[0][1].setText("C");
    text[0][1].setAlignment(Qt::AlignCenter);
    text[0][1].show();
//Выводим цифры из Z
    for(int i=0;i<vars+1;i++)
    {
        Z[i]->setGeometry(x+sizeX*(i+2)+sizeLine,y-sizeLine-sizeY,sizeX-sizeLine*2,sizeY-sizeLine*2);
          Z[i]->setAlignment(Qt::AlignCenter);
           Z[i]->show();
    }
    for(int i=2;i<vars+3;i++)//Заголовок
    {
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i].setGeometry(x+(sizeX*i)+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
        char chars[12];

        sprintf(chars, "A%d",i-2);
        text[0][i].setText((QString)chars);
        text[0][i].setAlignment(Qt::AlignCenter);
        text[0][i].show();

        //Добавляем Тетты
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i+vars].setGeometry(x+(sizeX*(i+vars))+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);

       sprintf(chars, "O%d",i-2);//ToDo Добавить Тетту
        text[0][i+vars].setText((QString)chars);
        text[0][i+vars].setAlignment(Qt::AlignCenter);
        text[0][i+vars].show();
    }
//Delta
    //text[0][0].setFont();Todo Добавить шрифт
    text[cEquation+1][0].setGeometry(x+sizeLine,y+(cEquation+1)*sizeY+sizeLine,2*(sizeX-sizeLine),sizeY-2*sizeLine);
   text[cEquation+1][0].setText("Delta");
    text[cEquation+1][0].setAlignment(Qt::AlignCenter);
    text[cEquation+1][0].show();

    char chars[12];

for(int j=0;j<cEquation;j++)//Циферки выводим
{
    //text[0][0].setFont();Todo Добавить шрифт
  text[j+1][0].setGeometry(x+sizeLine,y+sizeY*(j+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
  text[j+1][0].setText(basis[j]);
 text[j+1][0].setAlignment(Qt::AlignCenter);
  text[j+1][0].show();

    for(int i=0;i<(2*vars+2);i++)
    {
        //text[0][0].setFont();Todo Добавить шрифт
      text[j+1][i+1].setGeometry(x+(sizeX*(i+1))+sizeLine,y+sizeY*(j+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
      if((i>vars+1) &&(system[j][i]==INFINITY))
      {
           text[j+1][i+1].setText("-");
      }
      else{
          if(system[j][i]-((int)system[j][i])!=0){
          sprintf(chars, "%5.2f",system[j][i]);
          }
          else sprintf(chars, "%5.0f",system[j][i]);
    text[j+1][i+1].setText((QString)chars);
     }
       text[j+1][i+1].setAlignment(Qt::AlignCenter);
        text[j+1][i+1].show();
    }
}
//Выводим delta
for(int i=1;i<vars+2;i++)
{
    //text[0][0].setFont();Todo Добавить шрифт
 text[1+cEquation][i+1].setGeometry(x+(sizeX*(i+1))+sizeLine,y+sizeY*(cEquation+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
 if(system[cEquation][i]-((int)system[cEquation][i])!=0){
 sprintf(chars, "%5.2f",system[cEquation][i]);
 }
 else sprintf(chars, "%5.0f",system[cEquation][i]);
text[1+cEquation][i+1].setText((QString)chars);
 text[1+cEquation][i+1].setAlignment(Qt::AlignCenter);
    text[1+cEquation][i+1].show();
}
    break;
case Type::training:

    //text[0][0].setFont();Todo Добавить шрифт
    text[0]->setGeometry(x+sizeLine,y+sizeLine,sizeX-2*sizeLine,sizeY-2*sizeLine);
    text[0]->setText("B");
    text[0]->show();

    text[1]->setGeometry(x+sizeX+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
    text[1]->setText("C");
    text[1]->show();
    //Выводим цифры из Z
        for(int i=0;i<vars+1;i++)
        {
            Z[i]->setGeometry(x+sizeX*(i+2)+sizeLine,y-sizeLine-sizeY,sizeX-sizeLine*2,sizeY-sizeLine*2);
              Z[i]->setAlignment(Qt::AlignCenter);
              Z[i]->show();
        }
    for(int i=2;i<vars+3;i++)//Заголовок
    {

        //text[0][0].setFont();Todo Добавить шрифт
        text[i]->setGeometry(x+(sizeX*i)+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
        char chars[12];
       sprintf(chars, "A%d",i-2);
        text[i]->setText((QString)chars);
        text[i]->show();
        //Добавляем Тетты
        //text[0][0].setFont();Todo Добавить шрифт
        text[i+vars]->setGeometry(x+(sizeX*(i+vars))+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);

       sprintf(chars, "O%d",i-2);//ToDo Добавить Тетту
        text[i+vars]->setText((QString)chars);
        text[i+vars]->show();
    }
//Delta
    //text[0][0].setFont();Todo Добавить шрифт
    text[vars*2+3]->setGeometry(x+sizeLine,y+(cEquation+1)*sizeY+sizeLine,2*(sizeX-sizeLine),sizeY-2*sizeLine);
   text[vars*2+3]->setText("Delta");
    text[vars*2+3]->show();
    for(int j=0;j<cEquation;j++)//Циферки выводим
    {

        //text[0][0].setFont();Todo Добавить шрифт
      input[j][0].setGeometry(x+sizeLine,y+sizeY*(j+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
     input[j][0].show();

        for(int i=0;i<(2*vars+2);i++)
        {

            //text[0][0].setFont();Todo Добавить шрифт
          input[j][i+1].setGeometry(x+(sizeX*(i+1))+sizeLine,y+sizeY*(j+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
            input[j][i+1].show();
        }
    }
    //Выводим delta
    for(int i=1;i<vars+2;i++)
    {
        //text[0][0].setFont();Todo Добавить шрифт
    input[cEquation][i+1].setGeometry(x+(sizeX*(i+1))+sizeLine,y+sizeY*(cEquation+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
        input[cEquation][i+1].show();
    }
    break;
default:
    break;
}
delete painter;

}

bool Table::eventFilter(QObject *watched, QEvent *event)
{
    if(type==Type::reshenie){
   for(int i=0;i<actual.size();i++)
    {
    if(watched==actual[i])
       {
           if(event->type() == QEvent::MouseButtonPress)
           {

auto position=(CheckPosition(actual[i],text) -1);
if(position!=-2){
    NotColorBasis(Basis);
SimpleGod->getBasis(system,vars,cEquation,position,map[actual[i]]-vars);
NotColor();
ColorColumn(map[actual[i]]+1-vars);

char chars[12];
sprintf(chars, "A%d",map[actual[i]]-1-vars);
blackList[position].push_back(map[actual[i]]);
Basis[position]=map[actual[i]]-1-vars;
SetColorBasis(Basis);
basis[position]=(QString)chars;
system[position][0]=z[map[actual[i]]-2-vars];
actual.clear();//ToDo добавить продолжение
count[position]=true;
Position++;

NextStep();
return true;
           }

       }
}

   }
   return false;
    }
    else{
        bool flag=true;
        if(checked) //Чтобы лишних ошибок не было
        {
     for( int i=0;i<actualInput.size();i++)
         {
         if(watched==actualInput[i])
            {
                if(event->type() == QEvent::MouseButtonPress)
                {
if(countMinTetta==-2000){//Если -2000 то клик означает выбор базиса
    flag=false;
    checked=false;
    char chars[12];
     string=CheckString(actualInput[i],input);
    sprintf(chars, "A%d",string-vars-2);
  Position=CheckPosition(actualInput[i],input);
  blackList[Position].push_back(string-1);
  Basis[Position]=string-vars-2;
  count[Position]=true;
    if(Position!=-1){
    input[Position][0].setText((QString)chars);
    actualInput.clear();
    }

    SetWrite(0,cEquation,2,vars+3);
    AllInputNotColor();
    SimpleGod->getBasis(system,vars,cEquation,Position,string-vars-1);
next->setText("Проверить приведение базису");
    connect(next,SIGNAL(clicked(bool)),this,SLOT(CheckBasis()));
    return true;
}
else{
               actualInput[i]->setStyleSheet("background-color: rgb(71,250,148);");
                flag=false;
countMinTetta++;
return true;
}
                }
    }
}
                if(flag==true) //Проверка может клик вообще не в тему
                {


                    for(int i=0;i<cEquation;i++)
                    {
                        for(int j=vars+3;j<vars*2+3;j++)
                        {
                            if(watched==&input[i][j])
                            {
                                if(event->type() == QEvent::MouseButtonPress)
                                {
                flag=false;

                                }
                }

                }
                }
                    if(flag==false){
                        errors[2]++;
QLineEdit* line=(QLineEdit*)watched;
line->setStyleSheet("background-color: rgb(214,153,146);");
return true;

                    }
                }
                }
}
    return false;
                }

void Table::on_pushButton_2_clicked()
{
    this->close();
}

void Table::CheckTetta()
{
SimpleGod->getTetta(system,Basis,vars,cEquation);
GetInputTetta();

}

void Table::CheckBasis()
{
      next->setStyleSheet("background-color: rgb(255,255,255);");
    bool flag=true;
    double ** CheckInput=new double*[cEquation];
       for(int i=0;i<cEquation;i++)
    {
        CheckInput[i]=new double[2*vars+2];
    }
    for(int i=0;i<cEquation;i++)
    {
        for(int j=1;j<vars+2;j++){
            input[i][j+1].setText(input[i][j+1].text().replace(",","."));
            CheckInput[i][j]=(input[i][j+1].text()=="-")? INFINITY:input[i][j+1].text().toDouble();
            input[i][j+1].setStyleSheet("background-color: rgb(255,255,255);");
            if(std::abs(CheckInput[i][j]-system[i][j])>0.05){
                flag=false;
                errors[3]++;
                input[i][j+1].setStyleSheet("background-color: rgb(214,153,146);");
          }

        }
    }
    if(flag==true){
        for(int i=0;i<cEquation;i++)
        {
            for(int j=1;j<vars+2;j++){
         system[i][j]=CheckInput[i][j];
            }
        }
        next->setText("Проверить C");
        SetWrite(Position,Position+1,1,2);
            disconnect(next,SIGNAL(clicked(bool)),this,SLOT(CheckBasis()));
            connect(next,SIGNAL(clicked(bool)),this,SLOT(CheckC()));
    }


}
void Table::CheckAllMin()
{
   next->setStyleSheet("background-color: rgb(255,255,255);");
    if(actualInput.size()==countMinTetta){
     setStyleSheet("background-color: rgb(255,255,255);");
     next->setText("Выбираем базис");
        disconnect(next,SIGNAL(clicked(bool)),this,SLOT(CheckAllMin()));
       countMinTetta=-2000;
    }
    else{
      next->setStyleSheet("background-color: rgb(214,153,146);");
      errors[2]++;
    }
}

void Table::CheckC()
{
    next->setStyleSheet("background-color: rgb(255,255,255);");
     input[Position][1].setText(input[Position][1].text().replace(",","."));
    double C=(input[Position][1].text()=="-")? INFINITY:input[Position][1].text().toDouble();
    input[Position][1].setStyleSheet("background-color: rgb(255,255,255);");
    if(std::abs(C-z[string-vars-3])>0.05){
        errors[4]++;
         input[Position][1].setStyleSheet("background-color: rgb(214,153,146);");
    }
    else{
        system[Position][0]=C;
        //Проверяем заполнин ли базис
        bool flags=false;
        for(int i=0;i<cEquation;i++){
            if(count[i]==false){
                flags=true;
            }
        }
        if(flags){//Если не заполнен базис начинаем с начала
            next->setText("Проверить тетты");
            countMinTetta=0;

            SetReadOnly();
            SetWrite(0,cEquation,vars+3,2*vars+3);
            disconnect(next,SIGNAL(clicked(bool)),this,SLOT(CheckC()));
            connect(next,SIGNAL(clicked(bool)),SLOT(CheckTetta()));

        }
        else{
            next->setText("Проверить дельту");
            countMinTetta=0;

            SetReadOnly();
            SetWrite(cEquation,cEquation+1,2,vars+3);
            disconnect(next,SIGNAL(clicked(bool)),this,SLOT(CheckC()));
            connect(next,SIGNAL(clicked(bool)),SLOT(CheckDelta()));
        }

    }
}

void Table::CheckDelta()
{
    SimpleGod->getDelta(system,z,vars,cEquation);
    next->setStyleSheet("background-color: rgb(255,255,255);");
  bool flag=true;
  double ** CheckInput=new double*[cEquation+1];
  for(int i=0;i<cEquation+1;i++)
  {
      CheckInput[i]=new double[2*vars+2];
  }


  for(int j=1;j<vars+2;j++){

         input[cEquation][j+1].setText(input[cEquation][j+1].text().replace(",","."));
         CheckInput[cEquation][j]=(input[cEquation][j+1].text()=="-")? INFINITY:input[cEquation][j+1].text().toDouble();
         input[cEquation][j+1].setStyleSheet("background-color: rgb(255,255,255);");
         if(std::abs(CheckInput[cEquation][j]-system[cEquation][j])>0.05){
             flag=false;
             errors[1]++;
             input[cEquation][j+1].setStyleSheet("background-color: rgb(214,153,146);");


     }
  }
  if(flag==true){
     Solution= SimpleGod->Resheno(system,Basis,vars,cEquation,checkMin);
next->hide();
ui->SomeSolution->show();
ui->NotOptimal->show();
ui->Optimal->show();
  }
}

void Table::CheckMinTetta()
{
    int reshenie=0;
       next->setStyleSheet("background-color: rgb(255,255,255);");
    checked=true;
    switch (Solution) {
    case solution::NotOptimal:
        vectors=SimpleGod->GetMax(system,Basis,vars,cEquation,checkMin);
        break;
    case solution::SomeSolution:
        vectors=SimpleGod->SomeSolution(system,Basis,vars,cEquation);
        break;
    default:
        vectors=SimpleGod->GetMin(system,Basis,vars,cEquation);
        break;
    }

   SetReadOnly();



   //Проверяем есть ли вообще решения или уже все?
    for(int i=0;i<cEquation;i++)
    {
    while(!vectors[i].empty()){
if(SimpleGod->checkBlackList(blackList,i,vectors[i].front())==false){
    actualInput.push_back(&input[i][vectors[i].front()+1]);
        reshenie++;
    }
vectors[i].pop_front();
    }

    }
    if(reshenie!=0){
        for(int i=0;i<cEquation;i++)
        {
            for(int j=vars+3;j<vars*2+3;j++)
            {

         input[i][j].installEventFilter(this);

            }
        }

    connect(next,SIGNAL(clicked(bool)),SLOT(CheckAllMin()));

    }
    else{

        if(Solution==solution::NotOptimal){
        label->setText("Нет решения");
      label->show();
            for(int i=3;i<vars+3;i++)
            {
                  input[cEquation][i].setStyleSheet("background-color: rgb(214,153,146);");
            }
         next->hide();
         PushInfo(result,vars,errors);
         results->show();
         this->close();
    }
    else if(Solution==solution::SomeSolution){
        for(int i=3;i<vars+3;i++)
        {
              input[cEquation][i].setStyleSheet("background-color: rgb(71,250,148);");
        }
        next->hide();
        PushInfo(result,vars,errors);
        results->show();
       this->close();
    }

}
}

void Table::AllInputNotColor()
{
    for(int i=0;i<cEquation+1;i++)
    {
        for(int j=0;j<3+2*vars;j++)
        {
            input[i][j].setStyleSheet("background-color: rgb(255,255,255);");
        }
    }
}

void Table::SetReadOnly()
{
    for(int i=0;i<cEquation+1;i++)
    {
        for(int j=0;j<2*vars+3;j++)
        {
            input[i][j].setReadOnly(true);
        }
    }
}

void Table::SetWrite(int StringOne,int StringTwo,int ColumnOne,int ColumnTwo)
{
    for(int i=StringOne;i<StringTwo;i++)
    {
        for(int j=ColumnOne;j<ColumnTwo;j++)
        {
            input[i][j].setReadOnly(false);
        }
    }
}

void Table::on_Optimal_clicked()
{
    if(Solution==solution::Optimal)
    {
        for(int i=3;i<vars+3;i++)
        {
              input[cEquation][i].setStyleSheet("background-color: rgb(71,250,148);");
        }
        ui->SomeSolution->hide();
        ui->NotOptimal->hide();
        ui->Optimal->hide();
        PushResult();
        PushInfo(result,vars,errors);
        results->show();
        this->close();
    }
    else{
        ui->Optimal->setStyleSheet("background-color: rgb(214,153,146);");
         errors[6]++;
    }
}

void Table::on_NotOptimal_clicked()
{
    if(Solution==solution::NotOptimal)
    {

        ui->SomeSolution->hide();
        ui->NotOptimal->hide();
        ui->Optimal->hide();
        next->setText("Проверить тетты");
        next->show();
        disconnect(next,SIGNAL(clicked(bool)),this,SLOT(CheckDelta()));
        countMinTetta=0;
        SetReadOnly();
        SetWrite(0,cEquation,vars+3,2*vars+3);
       connect(next,SIGNAL(clicked(bool)),this,SLOT(CheckTetta()));
    }
    else{
        ui->NotOptimal->setStyleSheet("background-color: rgb(214,153,146);");
         errors[6]++;
    }
}


void Table::on_SomeSolution_clicked()
{
    if(Solution==solution::SomeSolution)
    {
        for(int i=3;i<vars+3;i++)
        {
              input[cEquation][i].setStyleSheet("background-color: rgb(71,250,148);");
        }
        ui->SomeSolution->hide();
        ui->NotOptimal->hide();
        ui->Optimal->hide();
        PushResult();
        next->setText("Проверить тетты");
        next->show();
        disconnect(next,SIGNAL(clicked(bool)),this,SLOT(CheckDelta()));
        countMinTetta=0;
        SetReadOnly();
        SetWrite(0,cEquation,vars+3,2*vars+3);
       connect(next,SIGNAL(clicked(bool)),this,SLOT(CheckTetta()));
    }
    else{
         ui->SomeSolution->setStyleSheet("background-color: rgb(214,153,146);");
         errors[6]++;
    }
}
