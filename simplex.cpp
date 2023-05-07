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
            system[j][i]=(system[j][1]/system[j][i-vars]>=0)?system[j][1]/system[j][i-vars]:INFINITY;
        }
    }

}

QVector<QVector<int>>simplex::GetMin(double **system, int vars,int cEquation)
{
    QVector <QVector<int>> vectors;
    QVector<int>vector;
    for(int i=0;i<cEquation;i++)
    {

        vectors.push_back(vector);
    }
    int string,column;
    double Min;
    for(int j=vars+2;j<2*vars+2;j++)
    {
        Min=system[0][j];
        string=0;
        column=j;
    for(int i=0;i<cEquation;i++)
    {
        if(Min>system[i][j] ){
            Min=system[i][j];
            string=i;
            column=j;

        }

    }
    vectors[string].push_back(column);

    }

    return vectors;
}

void simplex::getBasis(double **system, int vars, int cEquation, int j, int i)
{

    int basis=system[j][i];
 for(int I=1;I<vars+2;I++)
    {
system[j][I]/=basis;

    }

    for(int J=0;J<j;J++)
    {
        double coefficient=system[J][i];
        for(int I=1;I<vars+2;I++){
system[J][I]-=(coefficient*system[j][I]);
        }
    }
    for(int J=j+1;J<cEquation;J++)
    {
        double coefficient=system[J][i];
        for(int I=1;I<vars+2;I++){
system[J][I]-=(coefficient*system[j][I]);
        }
    }

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
