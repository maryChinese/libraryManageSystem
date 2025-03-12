#ifndef BORROWHISTORY_H
#define BORROWHISTORY_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class BorrowHistory;
}

class BorrowHistory : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowHistory(QWidget *parent = nullptr);
    ~BorrowHistory();

    void initPage(QString strCondition);


private slots:
    void on_btn_renew_clicked();

    void on_btn_check_clicked();

private:
    Ui::BorrowHistory *ui;
    QStandardItemModel m_model;
};

#endif // BORROWHISTORY_H
