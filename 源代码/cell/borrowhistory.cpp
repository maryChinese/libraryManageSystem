#include "borrowhistory.h"
#include "ui_borrowhistory.h"
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QMessageBox>
#include "lib/sqlmgr.h"

BorrowHistory::BorrowHistory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowHistory)
{
    ui->setupUi(this);
    initPage("");
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

BorrowHistory::~BorrowHistory()
{
    delete ui;
}

void BorrowHistory::initPage(QString strCondition)
{

    auto l = SqlMgr::getInstance()->getBorrowHistory(strCondition);
    m_model.clear();
     m_model.setHorizontalHeaderLabels(QStringList{"条形码","书名","作者","借阅时间","应还时间","续借次数"});
    for(int i = 0;i<l.size();i++)
    {
        QList<QStandardItem*> items;
        for(int j = 0;j<l[i].size();j++)
        {
            items.append(new QStandardItem(l[i][j]));
        }
        m_model.appendRow(items);
    }
}

void BorrowHistory::on_btn_renew_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0)
    {
        QMessageBox::information(nullptr,"信息","没有选中图书！");
    }
    else
    {
        auto id = m_model.item(r,0)->text();
        QString num = SqlMgr::getInstance()->renew(id);
        if("2"==num)
        {
            QMessageBox::information(nullptr,"信息","已达最大借阅次数！");
        }
        initPage("");
    }
}

void BorrowHistory::on_btn_check_clicked()
{
    bool ret = SqlMgr::getInstance()->check();
    if(!ret)
    {
        QMessageBox::information(nullptr,"信息","存在超期未归还图书，请立即归还！");
    }

}
