#ifndef DLG_LOST_H
#define DLG_LOST_H

#include <QDialog>

namespace Ui {
class Dlg_Lost;
}

class Dlg_Lost : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Lost(QWidget *parent = nullptr);
    ~Dlg_Lost();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::Dlg_Lost *ui;
};

#endif // DLG_LOST_H
