#ifndef TRAINING_H
#define TRAINING_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include"massive.h"
#include"table.h"
#include"simplex.h"
#include<QDesktopWidget>
#include<QPushButton>
#define INFINITI 33554432
/*
 * Список ошибок
 * 0) Канонический вид
 * 1)Подсчет тетт
 * 2)Выбор минимальных Тетт/базиса
 * 3)не правильно высчитывается базис методом гаусса
 * 4)кол-во использований пособия
 * 5)Дельты
 * 6)Не правильная оценка дельты
 */
namespace Ui {
class Training;
}

class Training : public QWidget
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = 0);
    ~Training();
signals:
    void CreateTable(int, int,int*,int,double**,double*,QString,double);
private slots:
    void on_pushButton_clicked();
    void GetCoeff();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
void GetCoeffSystem();
void PaintTable();
void KanonOne();
void KanonTwo();
void CheckPlus();
void CheckMinus();

void Unsigned();
void StepOne();
void StepTwo();
void on_pushButton_2_clicked();
public slots:
void GetName(QString name,double variant);
private:
void GetSystems();
void Show();
void Repaint();
void RepaintButton();
void ShowEquation();
void ShowInputEquation();
QRect size; //Размеры монитора
    QLineEdit ** LineEdits; //Куда вводим данные
Table* table; //Форма с таблицей
    QLabel** Labels; //Вывод введенных данный
    Ui::Training *ui; //Указатель на текущую форму
    QPushButton ** button,**button_two; //Кнопки
    QComboBox ** comboBox; //<=,=,>=
    int vars=0,cEquation=0;//Количество уравнений и переменных
    double* coeff,** coeffSystems,*sign,variant=0; //Коэфициенты системы, целевой функции, а так же знаки (>=,=,<=)
    QLabel * Zx; //Вывод целевой функции
    QLabel* label1,*label2,*label3,*help;
    Massive* massive; //Класс с методами для работы с массивами
   int checkMin; //тип задачи (Минимум, максимум)
   int *errors;//ошибки
   QLabel* labelsOne;//Информация о том как добавлять переменные
   QString name="";
};

#endif // TRAINING_H
