#ifndef DLG_BR_H
#define DLG_BR_H

#include <QDialog>

namespace Ui {
class Dlg_BR;
}

class Dlg_BR : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_BR(QWidget *parent = nullptr);
    ~Dlg_BR();

private slots:
    void on_btn_borrow_clicked();

    void on_btn_return_clicked();

    void on_btn_lost_clicked();

private:
    Ui::Dlg_BR *ui;
};

#endif // DLG_BR_H
