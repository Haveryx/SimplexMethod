#include "results.h"
#include "ui_results.h"

Results::Results(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
}

Results::~Results()
{
    delete ui;
}

QString Results::CheckOstatok(double &Data)
{
    char chars[12];
    if(Data-((int)Data)!=0){
    sprintf(chars, "%5.2f",Data);
    }
    else sprintf(chars, "%5.0f",Data);
    return (QString)chars;
}

void Results::AddInfo(QVector<double *> resultat, int cEquation)
{
ShowResult(resultat,cEquation);
}

void Results::AddInfo(QVector<double *> resultat, int cEquation, int *errors)
{
ShowResult(resultat,cEquation);
}

void Results::ShowResult(QVector<double *> resultat, int cEquation)
{

    if(!resultat.empty()){
        QLabel **label=new QLabel*[resultat.size()];

        for(int i=0;i<resultat.size();i++){
            QString string="Z=";
            string+=CheckOstatok(resultat[i][cEquation])+" при X=( ";
            label[i]=new QLabel(ui->groupBox);
            label[i]->setGeometry(0,10+i*40,30,20);//ToDo Добавить размеры
            for(int j=0;j<cEquation;j++){
                if(j==cEquation-1)string+=CheckOstatok(resultat[i][j])+")";
                else string+=CheckOstatok(resultat[i][j])+", ";
            }
            label[i]->setText(string);
            label[i]->show();
        }

    }
    else{
         QLabel *label=new QLabel(ui->groupBox);
         label->setGeometry(0,10,30,20);//ToDo Добавить размеры
         label->setText("Нет решения!!");
    }
}
