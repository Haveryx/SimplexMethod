#ifndef TABLE_H
#define TABLE_H
#include <QWidget>
#include<QPainter>
#include<QLineEdit>
#include<QLabel>
#include<QColor>
#include"simplex.h"
#include"massive.h"
#include<Qvector>
#include<QDesktopWidget>
#include<QMap>
#include<QPushButton>
#include"results.h"
#define INFINITI 33554432

enum Minimal
{
    min,
    max
};
enum class Type{
    reshenie,
    training,
    none
};

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
    ~Table();
signals:
    void PushInfo(QVector<double*>,int);
    void PushInfo(QVector<double *>, int,int*);
   public slots:
    void addInformation(int,int,int,double**,double*);
 void addInformation(int,int,int*,int,double**,double*);
private:
    Ui::Table *ui;
    int cEquation=3,vars=3;
    int* errors;
    int countMinTetta=0;
    bool* count,checked=false;
    const int sizeX=80,sizeY=40;
    Type type=Type::none;
    solution Solution=solution::None;
   QLabel** text,** Z;
   QLabel * label1;
   QLineEdit ** input;
   QPushButton* next;
   QPainter* painter;
   Results* results;
   int sizeLine=2;
   int y,x;
   int checkMin;
   int Position=0,string=0;
   void AllNotColor();
   void SetColorBasis();
   void NotColorBasis(int*basis);
   void SetColorBasis(int* basis);
   QString* basis;
   int  * Basis;
   QColor color=QColor::fromRgb(0,0,0);
   double** system,*z;
   simplex* SimpleGod;
QVector<QLabel*> actual;
QVector<double*> result;
QVector<QLineEdit*>actualInput;
QLabel* label,*label2;
QMap<QLabel*,int> map;
 QVector<QVector<int>> vectors,blackList;
void ColorColumn(int j);
void NotColor();
void PushResult();
void NextStep();
int CheckPosition(QLabel* labelOne,QLabel** LabelTwo);
int CheckPosition(QLineEdit* lineOne,QLineEdit** lineTwo);
int CheckString(QLineEdit* lineOne,QLineEdit** lineTwo);
void GetInputTetta();
 void SetReadOnly();
 void SetWrite(int StringOne,int StringTwo,int ColumnOne,int ColumnTwo);
 void CheckMinTetta();
 void AllInputNotColor();
 void ErrorNotColor();
protected:
    void paintEvent(QPaintEvent*) override;

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void on_pushButton_2_clicked();
    void CheckTetta();
    void CheckBasis();
void CheckAllMin();
void CheckC();
void CheckDelta();


void on_Optimal_clicked();
void on_NotOptimal_clicked();
void on_SomeSolution_clicked();
};

#endif // TABLE_H
