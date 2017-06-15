#ifndef MESTAND_GENERATOR_H
#define MESTAND_GENERATOR_H

#include <QDialog>

namespace Ui {
class mestand_generator;
}

class mestand_generator : public QDialog
{
    Q_OBJECT

public:
    explicit mestand_generator(QWidget *parent = 0);
    ~mestand_generator();

private:
    Ui::mestand_generator *ui;
    void mestand_write(QString code,QString name);

    private slots :
        void mestand_generate();
};

#endif // MESTAND_GENERATOR_H
