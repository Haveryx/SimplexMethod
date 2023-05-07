#include "massive.h"

Massive::Massive()
{

}

void Massive::AddColumn(double **x, int n, int m)
{

for(int i=0;i<m;i++)
{
    x[i][n+1]=x[i][n];
    x[i][n]=0;
}
}

void Massive::AddElement(double *x, int n)
{
    x[n]=1;



}

void Massive::Union(double** y,double **system, int vars, int cEquation)
{

    for(int j=0;j<cEquation+1;j++)
    {
        for(int i=0;i<(2*vars+2);i++)
        {
            y[j][i]=0;
        }
    }
    for(int j=0;j<cEquation;j++)
    {
        y[j][1]=system[j][vars-1];
        for(int i=0;i<vars;i++)
        {
         y[j][i+2]=system[j][i];
        }
    }

}
