#include "history.h"
#include "ui_history.h"
#include <QFileDialog>
#include <QMessageBox>
#include "lib/sqlmgr.h"


History::History(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    initPage("");
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

History::~History()
{
    delete ui;
}

void History::initPage(QString strCondition)
{
    auto l = SqlMgr::getInstance()->getHistory(strCondition);
    m_model.clear();
     m_model.setHorizontalHeaderLabels(QStringList{"条形码","书名","作者","借阅时间","归还时间"});
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
