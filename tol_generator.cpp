#include "tol_generator.h"
#include "ui_tol_generator.h"

tol_generator::tol_generator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tol_generator)
{
    ui->setupUi(this);
    for(int i=0;i<10;i++){

    tol_line *line=new tol_line(i,0,"Mot MPE","MPE word","bin","00000000","        ");
    QString a,b;
    a="00"+a.number(0);
    b="00"+b.number(0);
    QString index=a+" "+b;
    addTolLine(i,line);

    }
    QString aa;
    for(int i=0;i<5;i++){
    tol_line *line2=new tol_line(i,0,"Mot MPE","MPE word","bin","00000000","        ");
    addEssaiLine(i,0,line2);;
        }
    for(int i=0;i<10;i++){
        tol_line*a=new tol_line(0,i,"Mot MPE","MPE word","bin","00000000","1111111");
    addEssaiLine(0,i,a);
    }
    display();

}

tol_generator::~tol_generator()
{
    delete ui;
}


void tol_generator::addTolLine(int i, tol_line *l){
    tol_lines.insert(i,l);
}

void tol_generator::addEssaiLine(int i, int h,tol_line* a){
    tol_lines.insert(h,a);
    essai.insert(i,tol_lines);
}

void tol_generator::display(){
    QString tmp;
    for(int i=0;i<100;i++){
       if(tol_lines.contains(i)&getTolLine(i)->TLA_index_i==0)tmp+=getTolLine(i)->displayTolLine();
    }
   // ui->plainTextEdit->document()->setPlainText(tmp);
    QString ttmp;
    for(int tbf=0;tbf<50;tbf++){
        if(essai.contains(tbf))ttmp+=essai.value(tbf).value(0)->displayTolLine();
        }
    for(int tbf=0;tbf<2;tbf++){
        for(int tla=0;tla<2;tla++){
            if(essai.value(tbf).contains(tla)&essai.contains(tla) ){

                ttmp+=essai.value(tbf).value(tla)->displayTolLine();
            }
        }
    }


    ui->plainTextEdit->document()->setPlainText(ttmp);

}


tol_line * tol_generator::getTolLine(int i){
    if(tol_lines.contains(i))return tol_lines.value(i);

}
