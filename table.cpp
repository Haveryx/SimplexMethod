#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
}


Table::~Table()
{
    delete ui;
}

Table::addInformation(int cEquation, int vars,Type type)
{
    this->cEquation=cEquation;
    this->vars=vars;
    this->type=type;
    if(type==Type::reshenie){
        text=new QLabel*[cEquation+1];
        for(int i=0;i<cEquation+1;i++)
        {
            text[i]=new QLabel[vars*2+1];
        }

    }
    else{
        text=new QLabel*[vars*2+1];
        input=new QLineEdit*[cEquation];
        for(int i=0;i<cEquation;i++)
        {
           input[i]=new QLineEdit[vars*2+1];
        }
    }

}

void Table::paintEvent(QPaintEvent *)
{
    painter=new QPainter(this);
   auto geometry= this->geometry();
    painter->setPen(QPen(color,sizeLine,Qt::SolidLine));
   int x=(int)(geometry.width()-((vars*2 +1)*sizeX))/2;
    if(x<0)x=0;
     double y=(int)(geometry.height()-(cEquation+1)*sizeY)/2;
        if(y<0)x=0;
        painter->drawLine(QPointF(x,y),QPointF(x+(vars*2 +1)*sizeX,y));//Верхняя линия
        painter->drawLine(QPointF(x,y),QPointF(x,y+(cEquation+1)*sizeY));//Левая вертикальная
        painter->drawLine(QPointF(x,y+(cEquation+1)*sizeY),QPointF(x+(vars*2 +1)*sizeX,y+(cEquation+1)*sizeY));//Нижняя линия
  painter->drawLine(QPointF(x+(vars*2 +1)*sizeX,y+(cEquation+1)*sizeY),QPointF(x+(vars*2 +1)*sizeX,y));//Правая линия
  //Строим горизонтальные
for(int i=x+sizeX;i<x+(vars*2 +1)*sizeX;i+=sizeX){
    painter->drawLine(QPointF(i,y),QPointF(i,y+(cEquation+1)*sizeY));
}
//Вертикальные
for(int i=y+sizeY;i<y+(cEquation+2)*sizeY;i+=sizeY){
   painter->drawLine(QPointF(x,i),QPointF(x+(vars*2 +1)*sizeX,i));//Верхняя линия

}
//Добавляем всё остальное в таблицу
switch (type) {
case Type::reshenie:
    text[0][0].setParent(this);
    //text[0][0].setFont();Todo Добавить шрифт
    text[0][0].setGeometry(x+sizeLine,y+sizeLine,sizeX-2*sizeLine,sizeY-2*sizeLine);
    text[0][0].setText("b");
    text[0][0].show();
    for(int i=1;i<vars+1;i++)
    {
        text[0][i].setParent(this);
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i].setGeometry(x+(sizeX*i)+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);
        char chars[12];
       sprintf(chars, "X%d",i);
        text[0][i].setText((QString)chars);
        text[0][i].show();
        //Добавляем Тетты
        text[0][i+vars].setParent(this);
        //text[0][0].setFont();Todo Добавить шрифт
        text[0][i+vars].setGeometry(x+(sizeX*(i+vars))+sizeLine,y+sizeLine,sizeX-sizeLine*2,sizeY-sizeLine*2);

       sprintf(chars, "T%d",i);//ToDo Добавить Тетту
        text[0][i+vars].setText((QString)chars);
        text[0][i+vars].show();
    }

    break;
case Type::helper:

    break;
default:
    break;
}

}
