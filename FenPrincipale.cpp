#include <QtWidgets>
#include "FenPrincipale.h"
#include "FenCodeGenere.h"
#include<QtWidgets/QLineEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include<QString>
#include<QtWidgets/QGroupBox>
#include<QtWidgets/QAbstractButton>
#include<QtWidgets/QGroupBox>
FenPrincipale::FenPrincipale(){



  layout_2=new QGroupBox("Options");
  layout_3=new QGroupBox("Commentaires");
  layout_4=new QGroupBox;



    Definition_de_la_classe=new QFormLayout;
    nom = new QLineEdit;
    classe_mere = new QLineEdit;
    layout_1->setLayout(Definition_de_la_classe);
    Definition_de_la_classe->addRow("nom",nom);
    Definition_de_la_classe->addRow("Classe mère",classe_mere);


    Options=new QFormLayout;
    proteger=new QCheckBox("Protéger le header contre les insertions multiples");
    proteger->setChecked(1);
    generer_constructeur=new QCheckBox("Générer un constructeur par défaut");
    generer_destructeur=new QCheckBox("Générer un destructeur");
    layout_2->setLayout(Options);
    Options->addWidget(proteger);
    Options->addWidget(generer_constructeur);
    Options->addWidget(generer_destructeur);

    QFormLayout *_com=new QFormLayout;
    auteur=new QLineEdit;
    date=new QDateEdit;
    date->setDate(QDate::currentDate());
    role_classe=new QTextEdit;
    layout_3->setCheckable(1);
    layout_3->setChecked(0);
    _com->addRow("auteur",auteur);
    _com->addRow("date",date);
    _com->addRow("Role de la classe",role_classe);
    layout_3->setLayout(_com);

    QHBoxLayout *layout_boutons=new QHBoxLayout;
    quitter=new QPushButton("quitter");
    gen_code=new QPushButton("générer code");
    layout_boutons->addWidget(gen_code);
    layout_boutons->addWidget(quitter);
    layout_boutons->setAlignment(Qt::AlignRight);
    layout_4->setLayout(layout_boutons);


     main_layout=new QVBoxLayout;
     main_layout->addWidget(layout_1);
     main_layout->addWidget(layout_2);
     main_layout->addWidget(layout_3);
     main_layout->addWidget(layout_4);
     this->setLayout(main_layout);


     //--------------Connexions------------
     QWidget::connect(quitter,SIGNAL(clicked()),qApp,SLOT(quit()));
     QWidget::connect(gen_code,SIGNAL(clicked()),this,SLOT(genererCode()));


}

void FenPrincipale::genererCode(){
    if (nom->text().isEmpty()){
        QMessageBox::critical(this,"Erreur","Veuillez rentrer un nom de classe");
        return;//arrêt de la methode
    }
    QString code;

    if (layout_3->isChecked()){
        code += "/*\nAuteur : " + auteur->text() + "\n";
        code += "Date de création : " + date->date().toString() + "\n\n";
        code += "Rôle :\n" + role_classe->toPlainText() + "\n*/\n\n\n";
    }
    if (proteger->isChecked()){
        code += code += "#ifndef HEADER_" + nom->text().toUpper() + "\n";
        code += "#define HEADER_" + nom->text().toUpper() + "\n\n\n";
    }
    code += "class "+nom->text();
    if (!classe_mere->text().isEmpty()){
        code +=" : public "+classe_mere->text();
    }
    code += "\n{\n    public:\n";
       if (generer_constructeur ->isChecked())
       {
           code += "        " + nom->text() + "();\n";
       }
       if (generer_destructeur->isChecked())
       {
           code += "        ~" + nom->text() + "();\n";
       }
       code += "\n\n    protected:\n";
       code += "\n\n    private:\n";
       code += "};\n\n";

       if (proteger->isChecked())
       {
           code += "#endif\n";
       }

    FenCodeGenere *fenetrecode=new FenCodeGenere(code,this);
    fenetrecode->exec();

}

