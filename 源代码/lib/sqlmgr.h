#ifndef SQLMGR_H
#define SQLMGR_H

#include <QDebug>
#include <QtSql/QSqlDatabase>

class SqlMgr
{
public:
    SqlMgr();
    ~SqlMgr();

    static SqlMgr* instance;

    static SqlMgr* getInstance()
    {
        if(nullptr == instance)
        {
            instance = new SqlMgr();
        }
        return instance;
    }

    void init();

    //获取所有书籍
    QVector<QStringList> getBooks(QString strCondition = "");

    //获取所有单个书籍
    QVector<QStringList> getBook(QString strCondition = "");

    //增加书籍
    void AddBook(QVector<QStringList> vec);

    //删除书籍
    void DelBook(QString strId);

    //获取所有借阅记录
    QVector<QStringList> getBorrowHistory(QString strCondition = "");

    //获取所有历史记录
    QVector<QStringList> getHistory(QString strCondition = "");

    //续借书籍
    QString renew(QString id);

    //借阅书籍
    void borrow(QString strCondition = "");

    //归还书籍
    QString Return(QString strCondition = "");

    //预约书籍
    QString pro(QString name);

    //检查书籍超期
    bool check();

    //获取书籍价格
    QString money(QString name);



private:
    QSqlDatabase m_db;

};

#endif // SQLMGR_H
