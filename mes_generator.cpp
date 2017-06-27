#include "mes_generator.h"
#include "ui_mes_generator.h"

mes_generator::mes_generator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mes_generator)
{
    ui->setupUi(this);
}

mes_generator::~mes_generator()
{
    delete ui;
}

void mes_generator::on_add_entete_button_clicked()
{
    QString name_fr;
    QString name_gb;
    QString version;
    QString date;
    QString base;
    QString first_line;
    first_line="standard french message file / fichier messages francais standard I";
    QString name="mespe";
    name_fr=name+"fr.fil";
    name_gb=name+"gb.fil";

    version=ui->file_version_edit->text();
    date=ui->file_date_edit->text();
    code_fr=first_line+name_fr+"\n"+"version : "+version+" date : "+date+"\n"+base;
    code_gb=first_line+name_gb+"\n"+"version : "+version+" date : "+date+"\n"+base;

    ui->mespefr_apercu->document()->setPlainText(code_fr);
    ui->mespegb_apercu->document()->setPlainText(code_gb);

    //mespe_head_write(code_fr,code_gb,name_fr,name_gb);
}

void mes_generator::on_texte_generate_button_clicked()
{

    /*QString index;
    QString line_fr,line_gb;
    QString spaces_fr,spaces_gb;
    int line_length_fr,line_length_gb;
    QString _length_fr,_length_gb;
    //on rajoute des 0 sur l'index si cest inférieur à 10 ou 100-----------
    if(ui->index_edit->value()<10)index="00"+ui->index_edit->text();
    else if(ui->index_edit->value()<100)index="0"+ui->index_edit->text();
    else index=ui->index_edit->text();
    //---------------------------------------------------------------------
   //on rajoute l'index à la liste


    _index=ui->index_edit->value();
    line_fr=ui->text_edit_fr->text();
    line_length_fr=line_fr.length();
    if(!ui->text_gb->isChecked())line_gb=line_fr;
    else line_gb=ui->text_edit_gb->text();
    line_length_gb=line_gb.length();
    //si on veut modifier la longueur par défaut---------------------------
    if(ui->modif_length->isChecked()){
        _length_fr="A"+ui->length_edit->text();
        ui->length_edit->setMinimum(line_length_fr);
    }
    else _length_fr="A72";
    _length_gb=_length_fr;
    //---------------------------------------------------------------------
    //on rajoute les espaces pour que la ligne ait la bonne longueur-------
    for(int i=0;i<20-line_length_fr;i++){
        spaces_fr+=" ";
    }
    for(int i=0;i<20-line_length_gb;i++){
        spaces_gb+=" ";
    }
    //---------------------------------------------------------------------
    //ajoute de ligne à l'appui sur le bouton------------------------------

            if(!indexlist.contains(index)){
               indexlist.append(index);
            if (line_length_fr>15){
                QMessageBox::critical(this,"Erreur","La ligne est trop longue.");
                return;
            }
            if(ui->index_edit->value()>=_index)
            code_fr+=index+" "+line_fr+spaces_fr+" "+_length_fr+"\n";
            _index++;


            if (line_length_gb>15){
                QMessageBox::critical(this,"Erreur","La ligne est trop longue.");
                return;
            }
            //if(ui->index_edit->value()>=_index)
            code_gb+=index+" "+line_gb+spaces_gb+" "+_length_gb+"\n";
            _index++;
        }

    //---------------------------------------------------------------------
    //if (indexlist.contains("1"));


    ui->mespefr_apercu->document()->setPlainText(code_fr);
    ui->mespegb_apercu->document()->setPlainText(code_gb);
*/

    int index=ui->index_edit->value();
    QString tmp;
    QString ind=tmp.number(index);
    QString code=ui->text_edit_fr->text();
    int length=ui->default_length_edit->value();
    line *current_line=new line(index,code,length);
    addLine(current_line);
    if(!indexlist.contains(ind)){
       indexlist.append(ind);
    //if (a->getLineLengthInt()>15){
       // QMessageBox::critical(this,"Erreur","La ligne est trop longue.");
     //   return;
    //}


        code_fr+=current_line->displayLine();
        delete(current_line);

    }
    ui->mespefr_apercu->document()->setPlainText(code_fr);

}


void mes_generator::on_index_edit_valueChanged(int arg1)
{
    /*QTextDocument *doc = ui->mespefr_apercu->document();
    tb = doc->findBlockByLineNumber(arg1+2); // The second line.
    QString s = tb.text(); // returns 'is'
    code_fr+=s;
    ui->text_edit_fr->setText(code_fr);*/
}

void mes_generator::addLine(line *a){lines.push_back(a);}
