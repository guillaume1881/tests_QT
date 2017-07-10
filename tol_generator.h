#ifndef TOL_GENERATOR_H
#define TOL_GENERATOR_H

#include <QDialog>
#include <QHash>
#include "tol_line.h"

namespace Ui {
class tol_generator;
}

class tol_generator : public QDialog
{
    Q_OBJECT

public:
    explicit tol_generator(QWidget *parent = 0);
    ~tol_generator();
    void addTolLine(int i,tol_line *l);
    void addEssaiLine(int i, int h,tol_line* a);
    tol_line * getTolLine(int i);

private:
    Ui::tol_generator *ui;
    QHash<int,tol_line*> tol_lines;
    QHash<int,QHash<int,tol_line*> >essai;

    void display();
};

#endif // TOL_GENERATOR_H
