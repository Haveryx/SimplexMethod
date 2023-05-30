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

void Results::ShowRaiting()
{
    rating=new Rating();
    connect(this,SIGNAL(ShowRaiting(int*)),rating,SLOT(addError(int*)));
    ShowRaiting(error);
    rating->show();
    this->close();

}

void Results::AddInfo(QVector<double *> resultat, int vars)
{
ShowResult(resultat,vars);
}

void Results::AddInfo(QVector<double *> resultat, int vars, int *errors)
{
ShowResult(resultat,vars);
QPushButton* button=new QPushButton(this);
error=new int[6];
for(int i=0;i<6;i++)error[i]=errors[i];
button->setGeometry(861,591,50,50);
button->setText("Далее");
connect(button,SIGNAL(clicked(bool)),this,SLOT(ShowRaiting()));
button->show();
}

void Results::ShowResult(QVector<double *> resultat, int vars)
{

    if(!resultat.empty()){
        QLabel **label=new QLabel*[resultat.size()];

        for(int i=0;i<resultat.size();i++){
            QString string="Z=";
            string+=CheckOstatok(resultat[i][vars])+" при X=(";
            label[i]=new QLabel(ui->groupBox);
            label[i]->setGeometry(0,40+i*80,521,40);//ToDo Добавить размеры
            for(int j=0;j<vars;j++){
                if(j==vars-1)string+=CheckOstatok(resultat[i][j])+")";
                else string+=CheckOstatok(resultat[i][j])+", ";
            }
            label[i]->setText(string);
            label[i]->setAlignment(Qt::AlignCenter);
            label[i]->show();
        }

    }
    else{
         QLabel *label=new QLabel(ui->groupBox);
         label->setGeometry(0,10,521,40);//ToDo Добавить размеры
         label->setAlignment(Qt::AlignCenter);
         label->setText("Нет решения!!");
    }
}
