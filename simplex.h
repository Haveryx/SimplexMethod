#ifndef SIMPLEX_H
#define SIMPLEX_H
#include<QVector>

class simplex
{
public:
    simplex();
    void getTetta(double** system,int vars,int cEquation);
    QVector<QVector<int>> GetMin(double ** system,int vars,int cEquation);
    void  getBasis(double** system,int vars,int cEquation,int j,int i);
    double ** getDelta(double ** system,double* mainSystem,int vars,int cEquation);

};

#endif // SIMPLEX_H
