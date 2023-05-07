#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
   Solution* solution=new Solution();
   this->hide();
   solution->show();
  /*  Table* table=new Table();
    this->hide();
    table->addInformation(3,3,Type::reshenie,0,0);
    table->show();
    */

}
