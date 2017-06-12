#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H
#include <QWidget>
#include <QtWidgets>
#include<QtWidgets/QApplication>
#include<QtWidgets/QTextEdit>
#include<QtWidgets/QPushButton>

class FenCodeGenere:public QDialog{

public :
    FenCodeGenere(QString &code,QWidget *parent);


private :
    QTextEdit *codeGenere;
    QPushButton *quitter;
};
#endif // FENCODEGENERE_H
