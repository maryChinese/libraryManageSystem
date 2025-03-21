#ifndef DLG_LOGIN_H
#define DLG_LOGIN_H

#include <QDialog>

namespace Ui {
class Dlg_Login;
}

class Dlg_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Login(QWidget *parent = nullptr);
    ~Dlg_Login();


private slots:
    void on_btn_reader_clicked();
    
    void on_btn_br_clicked();
    
    void on_btn_mgr_clicked();
    
private:
    Ui::Dlg_Login *ui;
};

#endif // DLG_LOGIN_H
