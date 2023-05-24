#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    //this->setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
  //  this->activateWindow();
    QDesktopWidget desktop;
    QRect size=desktop.geometry();
    this->setGeometry(size.x(),size.y(),size.width(),size.height());
    SimpleGod=new simplex();
    label=new QLabel("Решение найдено!",this);
   auto geo=this->geometry();
   label->setGeometry(0,5,150,20);
    label2=new QLabel("Однако есть ещё одно решение!",this);
     label2->setGeometry(0,30,150,20);
     label->hide();
     label2->hide();
     ui->pushButton_2->setGeometry(size.width()-88,15,75,23);
errors=new int[5];
}


Table::~Table()
{
    delete ui;
    delete SimpleGod;
     this->close();
}

Table::addInformation(int cEquation, int vars,int minimum,double** System,double* Z)
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
     z=new double[vars];
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

Table::addInformation(int cEquation, int vars,int *errors,int minimum,double** System,double* Z)
{
    count=new bool[cEquation];
    for(int i=0;i<cEquation;i++)count[i]=false;

    system=new double*[cEquation+1];
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
     z=new double[vars];
    this->cEquation=cEquation;
    this->vars=vars;
    this->type=Type::training;
     for(int i=0;i<5;i++){
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
       char chars[12];
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



   repaint();
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

void Table::SetColorBasis(int *basis)
{
       for(int j=0;j<cEquation;j++)
       {
    for(int i=0;i<cEquation+1;i++)
    {
        text[i][basis[j]+2].setStyleSheet("background-color: rgb(71,250,148);");
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

           label->show();
            AllNotColor();
            SetColorBasis();
            for(int i=3;i<vars+3;i++)
            {
                  text[cEquation+1][i].setStyleSheet("background-color: rgb(71,250,148);");
            }
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
}
            break;
        case solution::SomeSolution:

            AllNotColor();
            SetColorBasis();
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
}

void Table::paintEvent(QPaintEvent *)
{
    painter=new QPainter(this);
   auto geometry= this->geometry();
    label->setGeometry((geometry.width()-250)/2,5,250,20);
      label2->setGeometry((geometry.width()-250)/2,30,250,20);
    painter->setPen(QPen(color,sizeLine,Qt::SolidLine));
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
    text[0][0].setParent(this);
    //text[0][0].setFont();Todo Добавить шрифт
    text[0][0].setGeometry(x+sizeLine,y+sizeLine,sizeX-2*sizeLine,sizeY-2*sizeLine);
    text[0][0].setText("B");
    text[0][0].setAlignment(Qt::AlignCenter);
    text[0][0].show();

    text[0][1].setParent(this);
    text[0][1].setGeometry(x+sizeX+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
    text[0][1].setText("C");
    text[0][1].setAlignment(Qt::AlignCenter);
    text[0][1].show();

    for(int i=2;i<vars+3;i++)//Заголовок
    {
        text[0][i].setParent(this);
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i].setGeometry(x+(sizeX*i)+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
        char chars[12];

        sprintf(chars, "A%d",i-2);
        text[0][i].setText((QString)chars);
        text[0][i].setAlignment(Qt::AlignCenter);
        text[0][i].show();

        //Добавляем Тетты
        text[0][i+vars].setParent(this);
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i+vars].setGeometry(x+(sizeX*(i+vars))+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);

       sprintf(chars, "O%d",i-2);//ToDo Добавить Тетту
        text[0][i+vars].setText((QString)chars);
        text[0][i+vars].setAlignment(Qt::AlignCenter);
        text[0][i+vars].show();
    }
//Delta
    text[cEquation+1][0].setParent(this);
    //text[0][0].setFont();Todo Добавить шрифт
    text[cEquation+1][0].setGeometry(x+sizeLine,y+(cEquation+1)*sizeY+sizeLine,2*(sizeX-sizeLine),sizeY-2*sizeLine);
   text[cEquation+1][0].setText("Delta");
    text[cEquation+1][0].setAlignment(Qt::AlignCenter);
    text[cEquation+1][0].show();

    char chars[12];

for(int j=0;j<cEquation;j++)//Циферки выводим
{
    text[j+1][0].setParent(this);
    //text[0][0].setFont();Todo Добавить шрифт
  text[j+1][0].setGeometry(x+sizeLine,y+sizeY*(j+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
  text[j+1][0].setText(basis[j]);
 text[j+1][0].setAlignment(Qt::AlignCenter);
  text[j+1][0].show();

    for(int i=0;i<(2*vars+2);i++)
    {
        text[j+1][i+1].setParent(this);
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
    text[1+cEquation][i+1].setParent(this);
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

}

bool Table::eventFilter(QObject *watched, QEvent *event)
{
   for(int i=0;i<actual.size();i++)
    {
    if(watched==actual[i])
       {
           if(event->type() == QEvent::MouseButtonPress)
           {

auto position=(CheckPosition(actual[i],text) -1);
SimpleGod->getBasis(system,vars,cEquation,position,map[actual[i]]-vars);
NotColor();
ColorColumn(map[actual[i]]+1-vars);

char chars[12];
sprintf(chars, "A%d",map[actual[i]]-1-vars);
blackList[position].push_back(map[actual[i]]-1);
Basis[position]=map[actual[i]]-1-vars;
basis[position]=(QString)chars;
system[position][0]=z[map[actual[i]]-2-vars];
actual.clear();//ToDo добавить продолжение
count[position]=true;
Position++;

NextStep();
           }
       }
}
    return false;
}

void Table::on_pushButton_2_clicked()
{
    this->close();
}
