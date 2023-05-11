#ifndef SIMPLEX_H
#define SIMPLEX_H
#include<QVector>

enum class solution
{
    Optimal,
    NotOptimal,
    SomeSolution
};

class simplex
{
public:
    simplex();
    void getTetta(double** system,int vars,int cEquation);
    QVector<QVector<int>> GetMin(double ** system,int vars,int cEquation);
    void  getBasis(double** system,int vars,int cEquation,int j,int i);
    void getDelta(double ** system,double* mainSystem,int vars,int cEquation);
   solution Resheno(double** system,int* basis,int vars,int cEquation);
   QVector<QVector<int>> GetMax(double** system,int vars,int cEquation);

};

#endif // SIMPLEX_H
