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
