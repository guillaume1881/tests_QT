#include <QtWidgets/QApplication>
#include <QDialog>
#include "mestand_gen.h"
int main(int argc,char *argv[]){
QApplication app(argc,argv);
mestand_gen fenetre;
fenetre.show();
return app.exec();
}
