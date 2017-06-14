#ifndef MESTAND_GENERATOR_H
#define MESTAND_GENERATOR_H

#include <QMainWindow>

namespace Ui {
class mestand_generator;
}

class mestand_generator : public QMainWindow
{
    Q_OBJECT

public:
    explicit mestand_generator(QWidget *parent = 0);
    ~mestand_generator();

private:
    Ui::mestand_generator *ui;
};

#endif // MESTAND_GENERATOR_H
