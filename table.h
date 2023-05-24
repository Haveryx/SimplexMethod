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
   public slots:
    addInformation(int,int,Type,int,double**,double*);
 addInformation(int,int,int*,Type,int,double**,double*);
private:
    Ui::Table *ui;
    int cEquation=3,vars=3;
    int* errors;
    QPainter* painter;
    const int sizeX=80,sizeY=40;
    Type type=Type::none;
   QLabel** text;
   QLineEdit ** input;
   int sizeLine=2;
   int y,x;
   int checkMin;
   int Position=0;
   void AllNotColor();
   void SetColorBasis();
   void SetColorBasis(int* basis);
   QString* basis;
   int  * Basis;
   QColor color=QColor::fromRgb(0,0,0);
   double** system,*z;
   simplex* SimpleGod;
QVector<QLabel*> actual;
QLabel* label,*label2;
QMap<QLabel*,int> map;
 QVector<QVector<int>> vectors,blackList;
void ColorColumn(int j);
void NotColor();
void NextStep();
int CheckPosition(QLabel* labelOne,QLabel** LabelTwo);
protected:
    void paintEvent(QPaintEvent*) override;

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // TABLE_H
