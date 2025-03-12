#include "dlg_br.h"
#include "ui_dlg_br.h"
#include "dlg_b.h"
#include "dlg_r.h"
#include "dlg_lost.h"

Dlg_BR::Dlg_BR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_BR)
{
    ui->setupUi(this);
}

Dlg_BR::~Dlg_BR()
{
    delete ui;
}

void Dlg_BR::on_btn_borrow_clicked()
{
    Dlg_B dlg;
    dlg.exec();
    this->hide();
}

void Dlg_BR::on_btn_return_clicked()
{
    Dlg_R dlg;
    dlg.exec();
    this->hide();
}

void Dlg_BR::on_btn_lost_clicked()
{
    Dlg_Lost dlg;
    dlg.exec();
    this->hide();
}
