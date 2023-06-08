#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowStaysOnTopHint|Qt::ToolTip);
    ui->setupUi(this);
  this->activateWindow();
    QDesktopWidget desktop;

    QRect size=desktop.geometry();
    this->setGeometry(size.x(),size.y(),size.width(),size.height());
    int PositionX=(int)(size.width()-241)/2;
    int PositionY=(int)(size.height()-91)/2;
    ui->pushButton->setGeometry(PositionX,PositionY,241,61);
     ui->pushButton_2->setGeometry(PositionX,PositionY+101,241,61);
     ui->pushButton_3->setGeometry(size.width()-88,15,75,41);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Name* name=new Name();
    this->hide();
    name->show();

}

void MainWindow::on_pushButton_2_clicked()
{
   Solution* solution=new Solution();
   this->hide();
   solution->show();


}



void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
