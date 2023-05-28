#ifndef SIMPLEX_H
#define SIMPLEX_H
#include<QVector>
#define INFINITI 33554432
enum class solution
{
    Optimal,
    NotOptimal,
    SomeSolution,
    None
};
class simplex
{
public:
    simplex();
    void getTetta(double** system,int* basis,int vars,int cEquation);
    QVector<QVector<int>> GetMin(double ** system,int* basis,int vars,int cEquation);
    void  getBasis(double** system,int vars,int cEquation,int j,int i);
    void getDelta(double ** system,double* mainSystem,int vars,int cEquation);
   solution Resheno(double** system,int* basis,int vars,int cEquation,int);
   QVector<QVector<int>> GetMax(double** system,int* Basis,int vars,int cEquation,int);
   QVector<QVector<int>> SomeSolution(double** system,int* Basis,int vars,int cEquation);
   int GetMin(double** system,int j,int cEquation);
bool checkBlackList(QVector<QVector<int>> blackList,int position,int data);
};

#endif // SIMPLEX_H
