#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    SimpleGod=new simplex();
}


Table::~Table()
{
    delete ui;
    delete SimpleGod;
}

Table::addInformation(int cEquation, int vars,Type type,double** System,double* Z)
{
    system=new double*[cEquation+1];

    for(int i=0;i<cEquation+1;i++)
    {
        system[i]=new double[vars*2+2];
    }
    basis=new QString[cEquation];
    for(int i=0;i<cEquation;i++)
    {
        basis[i]="";
    }
     z=new double[vars];
    this->cEquation=cEquation;
    this->vars=vars;
    this->type=type;
    Massive massive;
    z=Z;
   massive.Union(system,System,vars,cEquation);
   switch (type) {
   case Type::reshenie:
       text=new QLabel*[cEquation+2];
       for(int i=0;i<cEquation+2;i++)
       {
           text[i]=new QLabel[vars*2+3];
       }
SimpleGod->getTetta(system,vars,cEquation);
     vectors=SimpleGod->GetMin(system,vars,cEquation);
     while(!vectors[0].empty()){
text[1][vectors[0].front()+1].setStyleSheet("background-color: rgb(71,250,148);");
text[1][vectors[0].front()+1].installEventFilter(this);
actual.push_back(&text[1][vectors[0].front()+1]);
map[&text[1][vectors[0].front()+1]]=vectors[0].front();
vectors[0].pop_front();
     }

       break;
   case Type::helper:
       text=new QLabel*[vars*2+1];
       input=new QLineEdit*[cEquation];
       for(int i=0;i<cEquation;i++)
       {
          input[i]=new QLineEdit[vars*2+1];
       }
       break;
   default:
       break;
   }
   repaint();
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
    if(Position<cEquation){
        SimpleGod->getTetta(system,vars,cEquation);
             vectors=SimpleGod->GetMin(system,vars,cEquation);
             while(!vectors[Position].empty()){
        text[1+Position][vectors[Position].front()+1].setStyleSheet("background-color: rgb(71,250,148);");
        text[1+Position][vectors[Position].front()+1].installEventFilter(this);
        actual.push_back(&text[1+Position][vectors[Position].front()+1]);
        map[&text[1+Position][vectors[Position].front()+1]]=vectors[Position].front();
        vectors[Position].pop_front();
             }
    }
    else{
        SimpleGod->getDelta(system,z,vars,cEquation);
    }
}

void Table::paintEvent(QPaintEvent *)
{
    painter=new QPainter(this);
   auto geometry= this->geometry();
    painter->setPen(QPen(color,sizeLine,Qt::SolidLine));
    if(geometry.width()<((vars*2 +3)*sizeX +2*sizeLine))resize(((vars*2 +3)*sizeX) +2*sizeLine,geometry.height());
  int x=(int)(geometry.width()-((vars*2 +3)*sizeX))/2;
  if(geometry.height()<((cEquation+2)*sizeY + 2*sizeLine))resize(geometry.width(),((cEquation+2)*sizeY +2*sizeLine));
   int y=(int)(geometry.height()-(cEquation+2)*sizeY)/2;
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
    text[0][0].show();

    text[0][1].setParent(this);
    text[0][1].setGeometry(x+sizeX+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
    text[0][1].setText("C");
    text[0][1].show();

    for(int i=2;i<vars+3;i++)//Заголовок
    {
        text[0][i].setParent(this);
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i].setGeometry(x+(sizeX*i)+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
        char chars[12];
       sprintf(chars, "A%d",i-2);
        text[0][i].setText((QString)chars);
        text[0][i].show();
        //Добавляем Тетты
        text[0][i+vars].setParent(this);
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i+vars].setGeometry(x+(sizeX*(i+vars))+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);

       sprintf(chars, "O%d",i-2);//ToDo Добавить Тетту
        text[0][i+vars].setText((QString)chars);
        text[0][i+vars].show();
    }
//Delta
    text[cEquation+1][0].setParent(this);
    //text[0][0].setFont();Todo Добавить шрифт
    text[cEquation+1][0].setGeometry(x+sizeLine,y+(cEquation+1)*sizeY+sizeLine,2*(sizeX-sizeLine),sizeY-2*sizeLine);
   text[cEquation+1][0].setText("Delta");
    text[cEquation+1][0].show();
    char chars[12];

for(int j=0;j<cEquation;j++)//Циферки выводим
{
    text[j+1][0].setParent(this);
    //text[0][0].setFont();Todo Добавить шрифт
  text[j+1][0].setGeometry(x+sizeLine,y+sizeY*(j+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
  text[j+1][0].setText(basis[j]);
  text[j+1][0].show();

    for(int i=0;i<(2*vars+2);i++)
    {
        text[j+1][i+1].setParent(this);
        //text[0][0].setFont();Todo Добавить шрифт
      text[j+1][i+1].setGeometry(x+(sizeX*(i+1))+sizeLine,y+sizeY*(j+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
   sprintf(chars, "%5.2f",system[j][i]);
    text[j+1][i+1].setText((QString)chars);
        text[j+1][i+1].show();
    }
}
//Выводим тетту
for(int i=1;i<vars+2;i++)
{
    text[1+cEquation][i+1].setParent(this);
    //text[0][0].setFont();Todo Добавить шрифт
 text[1+cEquation][i+1].setGeometry(x+(sizeX*(i+1))+sizeLine,y+sizeY*(cEquation+1) +sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
sprintf(chars, "%5.2f",system[cEquation][i]);
text[1+cEquation][i+1].setText((QString)chars);
    text[1+cEquation][i+1].show();
}
    break;
case Type::helper:

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

SimpleGod->getBasis(system,vars,cEquation,Position,map[actual[i]]-vars);
ColorColumn(map[actual[i]]+1-vars);
NotColor();
char chars[12];
sprintf(chars, "A%d",map[actual[i]]-1-vars);
basis[Position]=(QString)chars;
system[Position][0]=z[map[actual[i]]-2-vars];
actual.clear();//ToDo добавить продолжение
Position++;
NextStep();
           }
       }
}
    return false;
}
