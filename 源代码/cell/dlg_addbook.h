#ifndef DLG_ADDBOOK_H
#define DLG_ADDBOOK_H

#include <QDialog>

namespace Ui {
class Dlg_AddBook;
}

class Dlg_AddBook : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_AddBook(QWidget *parent = nullptr);
    ~Dlg_AddBook();

private slots:
    void on_btn_add_clicked();

private:
    Ui::Dlg_AddBook *ui;
};

#endif // DLG_ADDBOOK_H
