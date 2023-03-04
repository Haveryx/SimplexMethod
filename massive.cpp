#include "massive.h"

Massive::Massive()
{

}

double **Massive::AddColumn(double **x, int n, int m)
{
    double ** y=new double*[m];
    for(int i=0;i<m;i++)
    {
        y[i]=new double[n+1];
    }
    for(int i=0;i<m;i++)
    {
        for(int  j=0;j<n-1;j++)
        {
            y[i][j]=x[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        y[i][n-1]=0;
        y[i][n]=x[i][n-1];
    }
    return y;
}

double *Massive::AddElement(double *x, int n)
{
    double* y=new double[n+1];
    for(int i=0;i<n;i++)
    {
        y[i]=x[i];
    }
    y[n]=0;
    return y;
}
