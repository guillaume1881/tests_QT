#ifndef TOL_GENERATOR_H
#define TOL_GENERATOR_H

#include <QDialog>
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

private:
    Ui::tol_generator *ui;
};

#endif // TOL_GENERATOR_H
