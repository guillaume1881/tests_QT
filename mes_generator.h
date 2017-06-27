#ifndef MES_GENERATOR_H
#define MES_GENERATOR_H

#include <QDialog>
#include <QMessageBox>
#include <QTextBlock>
#include "line.h"

namespace Ui {
class mes_generator;
}

class mes_generator : public QDialog
{
    Q_OBJECT

public:
    explicit mes_generator(QWidget *parent = 0);
    ~mes_generator();
    void addLine(line *a);

private slots:
    void on_add_entete_button_clicked();

    void on_texte_generate_button_clicked();

    void on_index_edit_valueChanged(int arg1);

private:
    Ui::mes_generator *ui;
    QString             code_mes;
    QString code_fr;
    QString code_gb;
    int _index;
    int _max_length;
    QStringList indexlist;
    QTextBlock tb;
    std::vector<line*> lines;
};

#endif // MES_GENERATOR_H
