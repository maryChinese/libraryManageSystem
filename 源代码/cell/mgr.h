#ifndef MGR_H
#define MGR_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class Mgr;
}

class Mgr : public QWidget
{
    Q_OBJECT

public:
    explicit Mgr(QWidget *parent = nullptr);
    ~Mgr();

     void initPage(QString strCondition);

private slots:
     void on_btn_add_clicked();

     void on_btn_del_clicked();

private:
    Ui::Mgr *ui;

    QStandardItemModel m_model;
};

#endif // MGR_H
