#ifndef BOOK_H
#define BOOK_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class Book;
}

class Book : public QWidget
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = nullptr);
    ~Book();

    void initPage(QString strCondition);


private slots:


    void on_btn_my_clicked();

    void on_btn_pro_clicked();

    void on_btn_search_clicked();

private:
    Ui::Book *ui;
    QStandardItemModel m_model;
};

#endif // BOOK_H
