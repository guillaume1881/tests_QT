#include "mespe_generator.h"
#include "ui_mespe_generator.h"

mespe_generator::mespe_generator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mespe_generator)
{
    ui->setupUi(this);
}

mespe_generator::~mespe_generator()
{
    delete ui;
}
