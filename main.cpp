
#include <QtWidgets/QApplication>
#include <QDialog>
#include "mes_generator.h"

int main(int argc,char *argv[]){
QApplication app(argc,argv);
mes_generator fenetre;
fenetre.show();
return app.exec();
}

