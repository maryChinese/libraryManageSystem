#include "dlg_addbook.h"
#include "ui_dlg_addbook.h"
#include "lib/sqlmgr.h"


Dlg_AddBook::Dlg_AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddBook)
{
    ui->setupUi(this);
}

Dlg_AddBook::~Dlg_AddBook()
{
    delete ui;
}

void Dlg_AddBook::on_btn_add_clicked()
{
    QStringList l;
    l<<ui->le_id->text();
    l<<ui->le_name->text();
    l<<ui->le_author->text();
    l<<ui->le_publish->text();

    QVector<QStringList> vec;
    vec.push_back(l);
    SqlMgr::getInstance()->AddBook(vec);
    this->hide();
}
