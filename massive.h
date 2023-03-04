#ifndef MASSIVE_H
#define MASSIVE_H


class Massive
{
public:
    Massive();
    double** AddColumn(double ** x,int n,int m);
    double* AddElement(double*x,int n);
};

#endif // MASSIVE_H
