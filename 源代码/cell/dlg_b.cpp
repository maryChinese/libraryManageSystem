#include "dlg_b.h"
#include "ui_dlg_b.h"
#include "lib/sqlmgr.h"

#include <QMessageBox>

Dlg_B::Dlg_B(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_B)
{
    ui->setupUi(this);
}

Dlg_B::~Dlg_B()
{
    delete ui;
}


void Dlg_B::on_btn_borrow_clicked()
{
    QString strCondition = ui->le_book->text();
    SqlMgr::getInstance()->borrow(strCondition);
    QMessageBox::information(nullptr,"信息","借阅成功！");
    this->hide();
}
