#ifndef DLG_B_H
#define DLG_B_H

#include <QDialog>

namespace Ui {
class Dlg_B;
}

class Dlg_B : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_B(QWidget *parent = nullptr);
    ~Dlg_B();

private slots:


    void on_btn_borrow_clicked();

private:
    Ui::Dlg_B *ui;
};

#endif // DLG_B_H
