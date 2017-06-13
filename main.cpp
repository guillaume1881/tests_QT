#include <QtWidgets/QApplication>
#include <QDialog>
#include "fil_generator.h"

int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    fil_generator fenetre;
    fenetre.show();
    return app.exec();

}

