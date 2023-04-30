#ifndef SIMPLEX_H
#define SIMPLEX_H
#include<QVector>

class simplex
{
public:
    simplex();
    double** getTetta(double** system,int vars,int cEquation);
    QVector<QVector<int>> GetMin(double ** system,int vars,int cEquation);
    double** getBasis(double** system,int vars,int cEquation,int j,int i);
};

#endif // SIMPLEX_H
