#include "simplex.h"

simplex::simplex()
{

}

void simplex::getTetta(double **system,int* basis, int vars, int cEquation)
{

    for(int j=0;j<cEquation;j++)
    {
        for(int i=2+vars;i<2*vars+2;i++)
        {
            if((system[j][1]!=0) && (system[j][1]!=INFINITY)){
            system[j][i]=(system[j][1]/system[j][i-vars]>=0 )?system[j][1]/system[j][i-vars]:INFINITY;
            }
            else system[j][i]=INFINITY;
        }
    }
for(int j=0;j<cEquation;j++)
{
    if(basis[j]!=-1000){
        for(int i=0;i<cEquation;i++){
            system[i][basis[j]+vars+1]=INFINITY;
        }

    }
}
}

QVector<QVector<int>>simplex::GetMin(double **system,int* basis, int vars,int cEquation)
{
    QVector <QVector<int>> vectors;
    QVector<int>vector;
    for(int i=0;i<cEquation;i++)
    {

        vectors.push_back(vector);
    }
    int string,column;
    bool flag=false;
    double Min;
    for(int j=vars+2;j<2*vars+2;j++)
    {
        Min=system[0][j];
        string=0;
        column=j;
        flag=false;
    for(int i=1;i<cEquation;i++)
    {
        if(Min>system[i][j] ){
            Min=system[i][j];
            string=i;
            column=j;

        }

    }

    for(int i=0;i<cEquation;i++){
        if(basis[i]==(column)-vars-1)flag=true;
    }

    if(flag==false && Min!=INFINITY){
        vectors[string].push_back(column);
        for(int I=0;I<cEquation;I++){
            if((Min==system[I][column]) &&I!=string)vectors[I].push_back(column);
        }


    }
    }

    return vectors;
}

void simplex::getBasis(double **system, int vars, int cEquation, int j, int i)
{

    double basis=system[j][i];
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
    for(int j=1;j<vars+2;j++)
    {
         for(int i=0;i<cEquation;i++)
        {
            system[cEquation][j]+=(system[i][0]*system[i][j]);
        }
    }
    for(int i=0;i<vars;i++)
    {
        system[cEquation][i+2]-=z[i];
    }

}

solution simplex::Resheno(double **system, int *basis, int vars, int cEquation,int checkMin)
{
    bool flag=false;
    bool optimal=true;
    if(checkMin==1){
    for(int i=2;i<vars+2;i++)
    {
        if(system[cEquation][i]<0){
            return solution::NotOptimal;
        }
        if(system[cEquation][i]==0){// Смотрим базис ли это?
           flag=true;
           for(int j=0;j<cEquation;j++)
           {
               if(i-1==(basis[j])){
                   flag=false;
               }
           }
           if(flag==true)optimal=false;
    }
    }

    if(optimal==false)return solution::SomeSolution;
    else return solution::Optimal;
    }
    else{
        for(int i=2;i<vars+2;i++)
        {
            if(system[cEquation][i]>0){
                return solution::NotOptimal;
            }
            if(system[cEquation][i]==0){// Смотрим базис ли это?
               flag=true;
               for(int j=0;j<cEquation;j++)
               {
                   if(i-1==(basis[j])){
                       flag=false;
                   }
               }
               if(flag==true)optimal=false;
        }
        }
        if(optimal==false)return solution::SomeSolution;
        else return solution::Optimal;

    }
}


QVector<QVector<int>> simplex::GetMax(double **system,int* Basis, int vars, int cEquation,int checkMin)
{
    QVector <QVector<int>> Vector;
    QVector<int>vector;
    for(int i=0;i<cEquation;i++)
    {

        Vector.push_back(vector);
    }

    QVector<QVector<int>> vectors=GetMin(system,Basis,vars,cEquation);
     double Max;
     bool flag=false;
     int position;
     int I=0;
     if(checkMin==1)//Ищем максимальное значение
     {
    for(int i=0;i<cEquation;i++)
    {
         if(!vectors[i].empty() && flag==false){
              Max=-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars];
        position=vectors[i].front();
        vectors[i].pop_front();
        I=i;
        flag=true;
         }
        while(!vectors[i].empty()){
            if((Max<(-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars]))&&(system[cEquation][vectors[i].front()-vars]<0)){
                Max=-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars];
                position=vectors[i].front();  
                I=i;
            }
            else if(Max==(-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars]))
            {
                Vector[i].push_back(vectors[i].front());
            }

                  vectors[i].pop_front();

        }
    }
    Vector[I].push_back(position);
    for(int i=0;i<cEquation;i++){
 for(auto j=Vector[i].begin();j<Vector[i].end();j++){
     if(((-1*system[i][*j]*system[cEquation][(*j)-vars])>Max) ||(system[cEquation][(*j)-vars]>=0))Vector[i].erase(j);
 }
    }
    return Vector;
     }
     else{ //Ищем минимальное значение
         for(int i=0;i<cEquation;i++)
         {
              if(!vectors[i].empty() && flag==false){
                   Max=-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars];
             position=vectors[i].front();
             vectors[i].pop_front();
             I=i;
             flag=true;
              }
             while(!vectors[i].empty()){
                 if((Max>(-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars]))&&(system[cEquation][vectors[i].front()-vars]>0)){
                     Max=-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars];
                     position=vectors[i].front();
                     I=i;
                 }
                 else if(Max==(-1*system[i][vectors[i].front()]*system[cEquation][vectors[i].front()-vars]))
                 {
                     Vector[i].push_back(vectors[i].front());
                 }

                       vectors[i].pop_front();

             }
         }
         Vector[I].push_back(position);
         for(int i=0;i<cEquation;i++){
      for(auto j=Vector[i].begin();j<Vector[i].end();j++){
          if(((-1*system[i][*j]*system[cEquation][(*j)-vars])>Max) ||(system[cEquation][(*j)-vars]<=0))Vector[i].erase(j);
      }
         }
         return Vector;
          }
     }



QVector<QVector<int> > simplex::SomeSolution(double **system, int *Basis, int vars, int cEquation)
{
    QVector <QVector<int>> Vector;
    QVector<int>vector;
    bool flag=false;
    for(int i=0;i<cEquation;i++)
    {

        Vector.push_back(vector);
    }
    for(int i=2;i<vars+2;i++)
    {
        flag=false;
        if(system[cEquation][i]==0){
            for(int j=0;j<cEquation;j++){
                if(Basis[j]==i-1)flag=true;
            }
            if(flag==false){
                Vector[GetMin(system,i+vars,cEquation)].push_back(i+vars);
            }
        }
    }
    return Vector;


}

int simplex::GetMin(double **system, int j, int cEquation)
{
    double Min=system[0][j];
    int position=0;
    for(int i=1;i<cEquation;i++)
    {
        if(Min>system[i][j]){
            position=i;
            Min=system[i][j];
        }
    }
    return position;
}

bool simplex::checkBlackList(QVector<QVector<int> > blackList, int position, int data)
{
  for(int i=0;i<blackList[position].size();i++)
    {
      if(blackList[position][i]==data)return true;

    }
    return false;
}
