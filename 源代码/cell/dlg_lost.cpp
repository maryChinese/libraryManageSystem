#include "dlg_lost.h"
#include "ui_dlg_lost.h"
#include "lib/sqlmgr.h"

#include <QMessageBox>

Dlg_Lost::Dlg_Lost(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Lost)
{
    ui->setupUi(this);
}

Dlg_Lost::~Dlg_Lost()
{
    delete ui;
}

void Dlg_Lost::on_btn_ok_clicked()
{
    QString name = ui->le_name->text();
    QString money = SqlMgr::getInstance()->money(name);
    QMessageBox::information(nullptr,"信息","赔款为"+money);
}
