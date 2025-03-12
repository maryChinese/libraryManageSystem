#include "dlg_in.h"
#include "ui_dlg_in.h"
#include "book_main.h"

Dlg_in::Dlg_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_in)
  ,book(nullptr)
{
    ui->setupUi(this);
}

Dlg_in::~Dlg_in()
{
    delete ui;
}


void Dlg_in::on_btn_in_clicked()
{
    if (!book)
        {
            book = new Book_Main(this); // 使用 `Dlg_in` 作为父对象，确保在 `Dlg_in` 关闭时销毁 `Book_Main` 对象
            book->show();
        }
        else
        {
            book->show(); // 如果已经创建了对象，则直接调用 show() 函数显示
        }

}
