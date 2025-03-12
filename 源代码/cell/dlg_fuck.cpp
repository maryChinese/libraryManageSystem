#include "dlg_fuck.h"
#include "ui_dlg_fuck.h"
#include "book_main.h"


Dlg_fuck::Dlg_fuck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_fuck)

{
    ui->setupUi(this);
}

Dlg_fuck::~Dlg_fuck()
{
    delete ui;
}

void Dlg_fuck::on_btn_fuck_clicked()
{
    Book_Main w;
    w.show();

}
