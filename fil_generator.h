#ifndef FIL_GENERATOR_H
#define FIL_GENERATOR_H
#include<Qt>
#include <QtWidgets>
#include <QMainWindow>

namespace Ui {
class fil_generator;
}

class fil_generator : public QMainWindow
{
    Q_OBJECT

public:
    explicit fil_generator(QWidget *parent = 0);
    ~fil_generator();

private:
    Ui::fil_generator *ui;
};

#endif // FIL_GENERATOR_H
