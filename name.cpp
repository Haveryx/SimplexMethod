#include "name.h"
#include "ui_name.h"

Name::Name(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Name)
{
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowStaysOnTopHint|Qt::ToolTip);
        ui->setupUi(this);
      this->activateWindow();
        QDesktopWidget desktop;

        QRect size=desktop.geometry();
        this->setGeometry(size.x(),size.y(),size.width(),size.height());
        int x=(size.width()-801)/2;
        int y=(size.height()-391)/2;
        ui->groupBox->setGeometry(x,y,801,391);
        ui->pushButton->setGeometry(size.width()-88,15,75,23);
        ui->pushButton_2->setGeometry(size.width()-251,size.height()-170,241,61);
}

Name::~Name()
{
    delete ui;
}

void Name::on_pushButton_clicked()
{
    this->close();
    delete ui;
}

void Name::on_pushButton_2_clicked()
{
Training* training=new Training();
connect(this,SIGNAL(PushName(QString,double)),training,SLOT(GetName(QString,double)));
name=ui->lineEdit->text();
ui->lineEdit_2->setText(ui->lineEdit_2->text().replace(",","."));
variant=ui->lineEdit_2->text().toDouble();
PushName(name,variant);
training->show();
this->hide();
}
