#include "tol_generator.h"
#include "ui_tol_generator.h"

tol_generator::tol_generator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tol_generator)
{
    ui->setupUi(this);
    tol_line *line=new tol_line(0,0,"Mot MPE","MPE word","bin","00000000","        ");
    ui->plainTextEdit->document()->setPlainText(line->displayTolLine());
}

tol_generator::~tol_generator()
{
    delete ui;
}
