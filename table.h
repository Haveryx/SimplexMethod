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
#include<QMap>
enum class Type{
    reshenie,
    helper
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
    addInformation(int,int,Type,double**,double*);

private:
    Ui::Table *ui;
    int cEquation=3,vars=3;
    QPainter* painter;
    const int sizeX=80,sizeY=40;
    Type type=Type::reshenie;
   QLabel** text;
   QLineEdit ** input;
   int sizeLine=2;
   int Position=0;
   QString* basis;
   QColor color=QColor::fromRgb(0,0,0);
   double** system,*z;
   simplex* SimpleGod;
QVector<QLabel*> actual;
QMap<QLabel*,int> map;
 QVector<QVector<int>> vectors;
void ColorColumn(int j);
void NotColor();
void NextStep();
protected:
    void paintEvent(QPaintEvent*) override;

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // TABLE_H
