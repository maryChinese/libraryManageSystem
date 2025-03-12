#include "dlg_addbook.h"
#include "mgr.h"
#include "ui_mgr.h"
#include <QFileDialog>
#include <QMessageBox>
#include "lib/sqlmgr.h"

Mgr::Mgr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mgr)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Mgr::~Mgr()
{
    delete ui;
}

void Mgr::initPage(QString strCondition)
{
    auto l = SqlMgr::getInstance()->getBook(strCondition);
    m_model.clear();
     m_model.setHorizontalHeaderLabels(QStringList{"条形码","书名","作者","出版社"});
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

void Mgr::on_btn_add_clicked()
{
    Dlg_AddBook dlg;
    dlg.exec();
    initPage("");
}

void Mgr::on_btn_del_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0)
    {
        QMessageBox::information(nullptr,"信息","没有选中图书！");
    }
    else
    {
        auto id = m_model.item(r,0)->text();
        SqlMgr::getInstance()->DelBook(id);
        initPage("");
    }
}
