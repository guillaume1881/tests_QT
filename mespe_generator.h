#ifndef MESPE_GENERATOR_H
#define MESPE_GENERATOR_H

#include <QDialog>

namespace Ui {
class mespe_generator;
}

class mespe_generator : public QDialog
{
    Q_OBJECT

public:
    explicit mespe_generator(QWidget *parent = 0);
    ~mespe_generator();

private:
    Ui::mespe_generator *ui;
};

#endif // MESPE_GENERATOR_H
