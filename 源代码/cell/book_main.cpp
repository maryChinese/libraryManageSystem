#include "book_main.h"
#include "ui_book_main.h"

Book_Main::Book_Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Book_Main)
    ,m_borrowPage(nullptr)
    ,m_historyPage(nullptr)
{
    ui->setupUi(this);
    initPage();
}

Book_Main::~Book_Main()
{
    delete ui;
}

void Book_Main::initPage()
{

    m_borrowPage = new BorrowHistory(this);
    m_historyPage = new History(this);

    ui->stackedWidget->addWidget(m_borrowPage);
    ui->stackedWidget->addWidget(m_historyPage);

    ui->stackedWidget->setCurrentIndex(0);

    auto l = ui->tool->children();
    for(auto it : l)
    {
        if(it->objectName().contains("btn"))
        {
            connect(static_cast<QPushButton*>(it), &QPushButton::clicked,this,&Book_Main::dealMenu);
        }
    }





}

void Book_Main::dealMenu()
{
    auto str = sender()->objectName();
    do
    {

        if("btn_borrow" == str)
        {
            ui->stackedWidget->setCurrentIndex(0);
            break;
        }
        if("btn_record" == str)
        {
            ui->stackedWidget->setCurrentIndex(1);
            break;
        }
    }while(false);
}

