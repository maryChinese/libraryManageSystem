#include "dlg_r.h"
#include "ui_dlg_r.h"
#include "lib/sqlmgr.h"

#include <QDateTime>
#include <QMessageBox>

Dlg_R::Dlg_R(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_R)
{
    ui->setupUi(this);
}

Dlg_R::~Dlg_R()
{
    delete ui;
}

void Dlg_R::on_btn_return_clicked()
{
    QString strCondition = ui->le_book->text();
    QString time = SqlMgr::getInstance()->Return(strCondition);
    qint64 timestamp = QDateTime::currentSecsSinceEpoch();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);
    QDateTime timeDateTime = QDateTime::fromString(time, "yyyy-MM-dd HH:mm:ss");
    if(timeDateTime>dateTime)
    {
        QMessageBox::information(nullptr,"信息","感谢您按期归还！");
    }
    else
    {
        QMessageBox::information(nullptr,"信息","很遗憾，您超期归还，需缴纳5元罚款！");
    }
    QMessageBox::information(nullptr,"信息","归还成功！");
    this->hide();
}
