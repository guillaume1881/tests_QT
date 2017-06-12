#include "FenCodeGenere.h"

#include <QtWidgets>
#include <QVBoxLayout>
#include <QString>
FenCodeGenere::FenCodeGenere(QString &code,QWidget *parent=0):QDialog(parent){
    codeGenere=new QTextEdit();
    codeGenere->setPlainText(code);
    codeGenere->setReadOnly(1);
    codeGenere->setFont(QFont("Courier"));
    codeGenere->setLineWrapMode(QTextEdit::NoWrap);

    quitter=new QPushButton("quitter");

    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(codeGenere);
    layout->addWidget(quitter);
    resize(350,450);

    setLayout(layout);

    connect(quitter,SIGNAL(clicked()),this,SLOT(accept()));

}
