#ifndef BORROW_H
#define BORROW_H

#include <QWidget>

namespace Ui {
class Borrow;
}

class Borrow : public QWidget
{
    Q_OBJECT

public:
    explicit Borrow(QWidget *parent = nullptr);
    ~Borrow();

private:
    Ui::Borrow *ui;
};

#endif // BORROW_H
