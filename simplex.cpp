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

void simplex::getDelta(double **system, double* z,int vars, int cEquation)
{
    for(int i=1;i<vars+2;i++)
    {
        system[cEquation][i]=0;
    }
    for(int i=0;i<cEquation;i++)
    {
        for(int j=1;j<vars+2;j++)
        {
            system[cEquation][j]+=(system[i][0]*system[i][j]);
        }
    }
    for(int i=0;i<vars;i++)
    {
        system[cEquation][i+2]-=z[i];
    }

}

solution simplex::Resheno(double **system, int *basis, int vars, int cEquation)
{
    for(int i=2;i<vars+2;i++)
    {
        if(system[cEquation][i]<0)return solution::NotOptimal;
        else if(system[cEquation][i]==0){// Смотрим базис ли это?
            for(int j=0;j<cEquation;j++)
            {
                if(i==basis[j])return solution::SomeSolution;
            }

        }
    }
    return solution::Optimal;
}

QVector<QVector<int>> simplex::GetMax(double **system, int vars, int cEquation)
{
    QVector <QVector<int>> Vector;
    QVector<int>vector;
    for(int i=0;i<cEquation;i++)
    {

        Vector.push_back(vector);
    }
    getTetta(system,vars,cEquation);
    QVector<QVector<int>> vectors=GetMin(system,vars,cEquation);
     double Max;
     int position;
    for(int i=0;i<cEquation;i++)
    {
         if(!vectors[i].empty()){
              Max=system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars];
        position=vectors[i].front();
        vectors[i].pop_front();
         }
        while(!vectors[i].empty()){
            if(Max<(system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars])){
                Max=system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars];
                position=vectors[i].front();
                  vectors[i].pop_front();
            }
            else{
                  vectors[i].pop_front();
            }
        }
        Vector[i].push_back(position);

    }
    return Vector;

}
