#include "mestand_gen.h"
#include "ui_mestand_gen.h"

mestand_gen::mestand_gen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mestand_gen)
{
    ui->setupUi(this);
    connect(ui->generate_button,SIGNAL(clicked()),this,SLOT(mestand_generate()));
}

mestand_gen::~mestand_gen()
{
    delete ui;
}

void mestand_gen::mestand_generate(){
    QString name;
    QString code;
    QString version;
    QString date;
    QString data;
    name="mestand";
    data="001 DATE                    :                                               	A25\n003 HEURE                   :                                               	A25\n005 NOM OPERATEUR           :                                               	A25\n007 NOM DU PROGRAMME        :                                               	A25\n009 REFERENCE DU PROGRAMME  :                                               	A25\n999 \n";
    if(ui->english_langage->isChecked())name=name+"gb.fil";
    else if(ui->french_language->isChecked())name=name+"fr.fil";
    else { QMessageBox::critical(this,"Erreur","Veuillez rentrer langage.");
    return;//arrêt de la methode
    }
    version=ui->file_version_edit->text();
    date=ui->file_date_edit->text();
    code="fichier français/patati \n"+name+"\n"+"version : "+version+" date : "+date+"\n"+data;

    ui->textEdit->setText(code);
    mestand_write(code,name);


}

void mestand_gen::mestand_write(QString code,QString name){
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

