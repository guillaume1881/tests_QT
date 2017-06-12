#include <QtWidgets/QApplication>
#include "FenCodeGenere.h"
#include "FenPrincipale.h"
#include <QDialog>

int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    FenPrincipale fenetre;
    fenetre.show();
    return app.exec();

}
