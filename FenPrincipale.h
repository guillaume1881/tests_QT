#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H
#include <QWidget>
#include<QtWidgets/QApplication>
#include<QtWidgets/QPushButton>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QVBoxLayout>
#include<QtWidgets/QFormLayout>
#include<QtWidgets/QRadioButton>
#include<QtWidgets/QCheckBox>
#include<QtWidgets/QGroupBox>
#include<QtWidgets/QDateEdit>
#include<QtWidgets/QTextEdit>
#include <QtGui/qwindowdefs.h>

class FenPrincipale: public QWidget{
    Q_OBJECT
public :
    FenPrincipale();
    ~FenPrincipale(){}

private slots:
    void genererCode();
signals :

private :

    QGroupBox *layout_1;//=new QGroupBox("Definition de la classe");
    QGroupBox *layout_2;//=new QGroupBox("Options");
    QGroupBox *layout_3;//=new QGroupBox("Commentaires");
    QGroupBox *layout_4;//=new QGroupBox;

    //Definition Classe
    QLineEdit   *nom;
    QLineEdit   *classe_mere;
    QFormLayout *Definition_de_la_classe;
    //------------------
    //Options
    QCheckBox *proteger;
    QCheckBox *generer_constructeur;
    QCheckBox *generer_destructeur;
    QFormLayout  *Options;
    //-----------------
    //ajouter commentaires
    QLineEdit *auteur;
    QDateEdit *date;
    QTextEdit *role_classe;
    QGroupBox *commentaires;
    QCheckBox *ajouter_commentaires;
    //-----------------
    //boutons
    QPushButton *gen_code;
    QPushButton *quitter;

    QVBoxLayout *main_layout;


};




#endif // FENPRINCIPALE_H
