
#include <QtWidgets/QApplication>
#include <QDialog>
#include "mestand_generator.h"
#include "mainwindow.h"
int main(int argc,char *argv[]){
QApplication app(argc,argv);
MainWindow main_window;
main_window.show();
//mestand_generator fenetre;
//fenetre.show();
return app.exec();
}
