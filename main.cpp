
#include <QtWidgets/QApplication>
#include <QDialog>
#include "tol_generator.h"

int main(int argc,char *argv[]){
QApplication app(argc,argv);
tol_generator fenetre;
fenetre.show();
return app.exec();
}


