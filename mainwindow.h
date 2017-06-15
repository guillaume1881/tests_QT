#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mestand_generator.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionMessages_standards_triggered();

private:
    Ui::MainWindow *ui;
    mestand_generator *mestand_gen_window;
};

#endif // MAINWINDOW_H
