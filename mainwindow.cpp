#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
    this->activateWindow();
    QDesktopWidget desktop;

    QRect size=desktop.geometry();
    this->setGeometry(size.x(),size.y(),size.width(),size.height());
    int PositionX=(int)(size.width()-241)/2;
    int PositionY=(int)(size.height()-91)/2;
    ui->pushButton->setGeometry(PositionX,PositionY,241,61);
     ui->pushButton_2->setGeometry(PositionX,PositionY+101,241,61);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Training* training=new Training();
    this->hide();
    training->show();
}

void MainWindow::on_pushButton_2_clicked()
{
   Solution* solution=new Solution();
   this->hide();
   solution->show();


}


