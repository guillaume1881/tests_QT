#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    model=new QDirModel(this);
    model->setSorting(QDir::DirsFirst|QDir::IgnoreCase);
    ui->treeView->setModel(model);
    ui->treeView->resizeColumnToContents(0);

    dirmodel=new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot|QDir::AllDirs);
    dirmodel->setRootPath("/home/guillaume");

    ui->treeView_2->setModel(dirmodel);
    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot|QDir::Files);
    dirmodel->setRootPath("/home/guillaume");
    ui->listView->setModel(filemodel);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_treeView_2_clicked(const QModelIndex &index)
{
    QString p=dirmodel->fileInfo(index).absolutePath();
    ui->listView->setRootIndex(filemodel->setRootPath(p));
}

void Dialog::on_pushButton_clicked()
{
    QModelIndex index=ui->treeView->currentIndex();
    QString p=model->fileInfo(index).absolutePath();
    ui->treeView_2->setRootIndex(dirmodel->setRootPath(p));
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    //QString p=model->fileInfo(index).absolutePath();
    //ui->treeView_2->setRootIndex(dirmodel->setRootPath(p));
}
