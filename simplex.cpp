#include "simplex.h"

simplex::simplex()
{

}

void simplex::getTetta(double **system, int vars, int cEquation)
{

    for(int j=0;j<cEquation;j++)
    {
        for(int i=2+vars;i<2*vars+2;i++)
        {
            system[j][i]=(system[j][1]/system[j][i-vars]>0)?system[j][1]/system[j][i-vars]:INFINITY;
        }
    }

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

    }
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

double **simplex::getDelta(double **system, double* mainSystem,int vars, int cEquation)
{
    for(int i=0;i<vars+3;i++)
    {
        system[cEquation][i]=0;
    }
    for(int i=0;i<cEquation;i++)
    {
        for(int j=2;j<vars+3;j++)
        {
            system[cEquation][j]+=(system[i][1]*system[i][j]);
        }
    }
    for(int i=3;i<vars+3;i++)
    {
        system[cEquation][i]-=mainSystem[i];
    }
    return system;
}
