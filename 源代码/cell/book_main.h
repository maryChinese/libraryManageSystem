#ifndef BOOK_MAIN_H
#define BOOK_MAIN_H

#include <QMainWindow>
#include "book.h"
#include "borrowhistory.h"
#include "history.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Book_Main; }
QT_END_NAMESPACE

class Book_Main : public QMainWindow
{
    Q_OBJECT

public:
    Book_Main(QWidget *parent = nullptr);
    ~Book_Main();

    void initPage();
    void dealMenu();


private:
    Ui::Book_Main *ui;

    BorrowHistory *m_borrowPage;
    History *m_historyPage;
};
#endif // BOOK_MAIN_H
