#include "book.h"
#include "ui_book.h"
#include "dlg_in.h"
#include <QFileDialog>
#include <QMessageBox>
#include "lib/sqlmgr.h"

Book::Book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Book)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Book::~Book()
{
    delete ui;
}

void Book::initPage(QString strCondition)
{
    auto l = SqlMgr::getInstance()->getBooks(strCondition);
    m_model.clear();
     m_model.setHorizontalHeaderLabels(QStringList{"索书名","丛书号","书名","作者","出版社","总库存","剩余库存","价格"});
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







void Book::on_btn_my_clicked()
{
    Dlg_in f;
    f.exec();
}

void Book::on_btn_pro_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0)
    {
        QMessageBox::information(nullptr,"信息","没有选中图书！");
    }
    else
    {
        auto name = m_model.item(r,2)->text();
        QString time = SqlMgr::getInstance()->pro(name);
        QMessageBox::information(nullptr,"信息","请于该时间后来图书馆取书！" + time);
    }
}

void Book::on_btn_search_clicked()
{
    QString searchType = ui->cbox_slc->currentText();
    QString searchWord = ui->le_search->text();
    QString strCond = QString("where %1 like '%%2%'")
            .arg(searchType)
            .arg(searchWord);
    initPage(strCond);
}
