#include "simplex.h"

simplex::simplex()
{

}

double **simplex::getTetta(double **system, int vars, int cEquation)
{
    double** systems=new double*[cEquation];
    for(int i=0;i<cEquation;i++)
    {
        systems[i]=new double[vars*2+1];
    }
    for(int j=0;j<cEquation;j++)
    {
        for(int i=0;i<vars+1;i++)
        {
            systems[j][i]=system[j][i];
        }
    }
    for(int j=0;j<cEquation;j++)
    {
        for(int i=vars;i<2*vars+1;i++)
        {
            systems[j][i]=(systems[j][i-vars]/systems[j][i-vars+1]>0)?systems[j][i-vars]/systems[j][i-vars+1]:INFINITY;
        }
    }
    return systems;

}

QVector<QVector<int>>simplex::GetMin(double **system, int vars,int cEquation)
{
    QVector <QVector<int>> vectors;
    QVector<int>vector;
    for(int i=0;i<cEquation;i++)
    {
        vector.push_back(INFINITY);
        vectors.push_back(vector);
    }
    int string=0,column=0;
    int** min=new int*[cEquation];
    for(int i=0;i<cEquation;i++)
    {
        min[i]=new int[vars];
    }
    double Min=system[0][vars+1];
    for(int j=vars+1;j<2*vars+1;j++)
    {
    for(int i=0;i<cEquation;i++)
    {
        if(Min>system[j][i] ){
            Min=system[j][i];
            string=i;
            column=j;

        }
        vectors[i].push_back(0);
    }
    vectors[string].pop_back();
    vectors[string].push_back(column);


    }
    for(int i=0;i<cEquation;i++)
    {
       vectors[i].pop_front();
    }

    return vectors;
}

double **simplex::getBasis(double **system, int vars, int cEquation, int j, int i)
{
    int basis=system[j][i];
    for(int I=0;I<vars;I++)
    {
system[j][I]/=basis;

    }
    int I;
    for(int J=0;J<j;j++)
    {
        double coefficient=system[J][I]/basis;
        for(I=0;I<vars;I++){
system[J][I]-=(coefficient*system[j][I]);
        }
    }
    for(int J=j+1;J<cEquation;j++)
    {
        double coefficient=system[J][I]/basis;
        for(I=0;I<vars;I++){
system[J][I]-=(coefficient*system[j][I]);
        }
    }
return system;
}
