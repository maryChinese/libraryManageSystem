#ifndef DLG_IN_H
#define DLG_IN_H

#include <QDialog>
#include "book_main.h"

namespace Ui {
class Dlg_in;
}

class Dlg_in : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_in(QWidget *parent = nullptr);
    ~Dlg_in();

private slots:

    void on_btn_in_clicked();

private:
    Ui::Dlg_in *ui;
    Book_Main *book;
};

#endif // DLG_IN_H
