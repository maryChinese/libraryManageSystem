#ifndef DLG_FUCK_H
#define DLG_FUCK_H

#include <QDialog>
#include "book_main.h"

namespace Ui {
class Dlg_fuck;
}

class Dlg_fuck : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_fuck(QWidget *parent = nullptr);
    ~Dlg_fuck();

private slots:
    void on_btn_fuck_clicked();

private:
    Ui::Dlg_fuck *ui;


};

#endif // DLG_FUCK_H
