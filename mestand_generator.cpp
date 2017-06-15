#include "mestand_generator.h"
#include "ui_mestand_generator.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

mestand_generator::mestand_generator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mestand_generator)
{
    ui->setupUi(this);
    connect(ui->generate_button,SIGNAL(clicked()),this,SLOT(mestand_generate()));
}

mestand_generator::~mestand_generator()
{
    delete ui;
}

void mestand_generator::mestand_generate(){
    QString name;
    QString code;
    QString version;
    QString date;
    QString data;
    QString base;
    QString first_line;
    first_line="standard french message file / fichier messages francais standard I";
    name="mestand";
    data="001 DATE                    :                                               	A25\n003 HEURE                   :                                               	A25\n005 NOM OPERATEUR           :                                               	A25\n007 NOM DU PROGRAMME        :                                               	A25\n009 REFERENCE DU PROGRAMME  :                                               	A25\n999 \n";
    if(ui->english_langage->isChecked())name=name+"gb.fil";
    else if(ui->french_langage->isChecked())name=name+"fr.fil";
    else { QMessageBox::critical(this,"Erreur","Veuillez rentrer langage.");
    return;//arrêt de la methode
    }
    version=ui->file_version_edit->text();
    date=ui->file_date_edit->text();
    QFile base_mestand("base_mestand.txt");
    if (base_mestand.open(QIODevice::ReadOnly |QIODevice::Text)){
        QTextStream flux(&base_mestand);
        while(!flux.atEnd()){
            base=base+base_mestand.readLine()+"\n";
        }
    }
    code=first_line+name+"\n"+"version : "+version+" date : "+date+"\n"+base;

    ui->file_apercu->document()->setPlainText(code);
    mestand_write(code,name);


}

void mestand_generator::mestand_write(QString code,QString name){
    QFile write_file_1(name);
        if(!write_file_1.open(QIODevice::WriteOnly|QIODevice::Text)){
        return;
        }
        else {
            QTextStream flux10(&write_file_1);
            flux10.setCodec("UTF-8");
            flux10<<code<<endl;
        }
    }

