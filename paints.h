#ifndef PAINTS_H
#define PAINTS_H

#include <QObject>

class Paints
{
public:
    Paints();
      Paints(QObject*);
      void CreateTable(int,int);
private:
      QObject* parent;
};

#endif // PAINTS_H
