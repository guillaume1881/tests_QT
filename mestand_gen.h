#ifndef MESTAND_GEN_H
#define MESTAND_GEN_H
#include<Qt>
#include <QtWidgets>
#include <QMainWindow>

namespace Ui {
class mestand_gen;
}

class mestand_gen : public QMainWindow
{
    Q_OBJECT

public:
    explicit mestand_gen(QWidget *parent = 0);
    ~mestand_gen();

private:
    Ui::mestand_gen *ui;
    void mestand_write(QString code,QString name);

private slots :
    void mestand_generate();
};

#endif // MESTAND_GEN_H
