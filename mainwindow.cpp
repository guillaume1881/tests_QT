#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_mestand_generator.h"
#include "mestand_generator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionMessages_standards_triggered()
{
    mestand_gen_window=new mestand_generator(this);
    mestand_gen_window->show();
}
