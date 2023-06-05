#ifndef RATING_H
#define RATING_H

#include <QWidget>

namespace Ui {
class Rating;
}

class Rating : public QWidget
{
    Q_OBJECT

public:
    explicit Rating(QWidget *parent = 0);
    ~Rating();
public slots:
    void addError(int*);
private:
    Ui::Rating *ui;
};

#endif // RATING_H