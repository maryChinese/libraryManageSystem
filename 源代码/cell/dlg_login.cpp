#include "dlg_login.h"
#include "ui_dlg_login.h"

Dlg_Login::Dlg_Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Login)
{
    ui->setupUi(this);
}

Dlg_Login::~Dlg_Login()
{
    delete ui;
}



void Dlg_Login::on_btn_reader_clicked()
{
    setResult(1);
    hide();
}

void Dlg_Login::on_btn_br_clicked()
{
    setResult(2);
    hide();
}

void Dlg_Login::on_btn_mgr_clicked()
{
    setResult(3);
    hide();
}
