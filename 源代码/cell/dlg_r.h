#ifndef DLG_R_H
#define DLG_R_H

#include <QDialog>

namespace Ui {
class Dlg_R;
}

class Dlg_R : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_R(QWidget *parent = nullptr);
    ~Dlg_R();

private slots:
    void on_btn_return_clicked();

private:
    Ui::Dlg_R *ui;
};

#endif // DLG_R_H
