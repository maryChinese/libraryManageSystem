#include "book_main.h"
#include "dlg_login.h"
#include "dlg_br.h"
#include "book.h"
#include "mgr.h"
#include "lib/sqlmgr.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SqlMgr::getInstance()->init();

    Dlg_Login l;
    int ret = l.exec();
    if(1==ret)
    {
        Book w;
        w.show();
        return a.exec();
    }
    if(2==ret)
    {
        Dlg_BR dlg;
        dlg.exec();
    }
    if(3==ret)
    {
        Mgr w;
        w.show();
        w.initPage("");
        return a.exec();
    }
    return 0;

    
}
