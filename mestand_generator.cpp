#include "mestand_generator.h"
#include "ui_mestand_generator.h"

mestand_generator::mestand_generator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mestand_generator)
{
    ui->setupUi(this);
}

mestand_generator::~mestand_generator()
{
    delete ui;
}
