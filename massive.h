#ifndef MASSIVE_H
#define MASSIVE_H


class Massive
{
public:
    Massive();
  void AddColumn(double ** x,int n,int m);
    void AddElement(double*x,int n);
    void Union(double** y,double** system,int vars,int cEquation);
};

#endif // MASSIVE_H
