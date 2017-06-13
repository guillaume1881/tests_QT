#include "fil_generator.h"
#include "ui_fil_generator.h"

fil_generator::fil_generator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fil_generator)
{
    ui->setupUi(this);
}

fil_generator::~fil_generator()
{
    delete ui;
}
