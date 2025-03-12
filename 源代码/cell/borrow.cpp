#include "borrow.h"
#include "ui_borrow.h"

Borrow::Borrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Borrow)
{
    ui->setupUi(this);
}

Borrow::~Borrow()
{
    delete ui;
}
