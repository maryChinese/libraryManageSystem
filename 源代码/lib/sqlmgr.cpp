#include "sqlmgr.h"
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDateTime>
#include <QDateTime>
#include <QDebug>

SqlMgr* SqlMgr::instance = nullptr;
SqlMgr::SqlMgr()
{

}

SqlMgr::~SqlMgr()
{

}

void SqlMgr::init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(QCoreApplication::applicationDirPath()+"/db/data.db");
    qDebug()<<m_db.open();
}

QVector<QStringList> SqlMgr::getBooks(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from Book %1").arg(strCondition);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> SqlMgr::getBook(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from OneBook %1").arg(strCondition);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

void SqlMgr::AddBook(QVector<QStringList> vec)
{
    m_db.transaction();
    QSqlQuery q(m_db);
    auto ldata = vec[0];
        QString strSql = QString("insert into OneBook VALUES('%1','%2','%3','%4');")
                .arg(ldata[0])
                .arg(ldata[1])
                .arg(ldata[2])
                .arg(ldata[3]);
        bool ret = q.exec(strSql);
        if(!ret)
        {
            qDebug()<<q.lastError().text();
        }
}

void SqlMgr::DelBook(QString strId)
{
    QSqlQuery q(m_db);
    QString strSql = QString("delete from OneBook where 条形码='%1'").arg(strId);
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();
    }
}

QVector<QStringList> SqlMgr::getBorrowHistory(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from Borrow %1").arg(strCondition);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> SqlMgr::getHistory(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from History %1").arg(strCondition);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QString SqlMgr::renew(QString id)
{
    QSqlQuery q(m_db);

    QString updateSql = QString("update Borrow set 续借次数 = 续借次数 + 1 where 条形码 ='%1'")
            .arg(id);
    bool ret = q.exec(updateSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();
        return QString("借阅失败");
    }

    qint64 timestamp = QDateTime::currentSecsSinceEpoch();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp).addSecs(30 * 24 * 60 * 60);

    QString renewSql = QString("UPDATE Borrow SET 应还时间 = '%1' WHERE 条形码 = '%2'")
                            .arg(dateTime.toString(Qt::ISODate))
                            .arg(id);
    ret = q.exec(renewSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();
        return QString("借阅失败");
    }


    QString strSql = QString("select * from Borrow ");

    QVector<QStringList> vec;
    ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    auto ldata = vec[0];
    QString num = ldata[5];


    return num;
}

void SqlMgr::borrow(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from OneBook where 条形码='%1'").arg(strCondition);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols-1;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }

    qint64 timestamp = QDateTime::currentSecsSinceEpoch();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);
    QDateTime newTime = QDateTime::fromSecsSinceEpoch(timestamp).addSecs(30 * 24 * 60 * 60);
    auto ldata = vec[0];
    QString strSql1 = QString("insert into Borrow VALUES('%1','%2','%3','%4','%5','0');")
                .arg(strCondition)
                .arg(ldata[1])
                .arg(ldata[2])
                .arg(dateTime.toString(Qt::ISODate))
                .arg(newTime.toString(Qt::ISODate));
        bool temp = q.exec(strSql1);
        if(!temp)
        {
            qDebug()<<q.lastError().text();
        }

        QString strSql3 = QString("update Book set 剩余库存 = 剩余库存 - 1 where 书名='%1'")
                .arg(ldata[1]);
        bool ret2 = q.exec(strSql3);
        if(!ret2)
        {
            qDebug()<<q.lastError().text();
        }
}

QString SqlMgr::Return(QString strCondition)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from Borrow where 条形码='%1'").arg(strCondition);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols-1;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }

    qint64 timestamp = QDateTime::currentSecsSinceEpoch();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);
    auto ldata = vec[0];
    QString strSql1 = QString("insert into History VALUES('%1','%2','%3','%4','%5');")
                .arg(ldata[0])
                .arg(ldata[1])
                .arg(ldata[2])
                .arg(ldata[3])
                .arg(dateTime.toString(Qt::ISODate));
        bool temp = q.exec(strSql1);
        if(!temp)
        {
            qDebug()<<q.lastError().text();
        }
        QString time = ldata[4];

        QString strSql2 = QString("delete from Borrow where 条形码='%1'").arg(strCondition);
        bool ret1 = q.exec(strSql2);
        if(!ret1)
        {
            qDebug()<<q.lastError().text();
        }
        QString strSql4 = QString("update Book set 剩余库存 = 剩余库存 + 1 where 书名='%1'")
                .arg(ldata[1]);
        bool ret2 = q.exec(strSql4);
        if(!ret2)
        {
            qDebug()<<q.lastError().text();
        }
        return time;
}

QString SqlMgr::pro(QString name)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from Borrow where 书名='%1'").arg(name);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    auto ldata = vec[0];
    return QString(ldata[4]);
}

bool SqlMgr::check()
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from Borrow ");

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    qint64 timestamp = QDateTime::currentSecsSinceEpoch();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);
    auto ldata = vec[0];
    QString time = ldata[4];
    QDateTime timeDateTime = QDateTime::fromString(time, "yyyy-MM-dd HH:mm:ss");
    if(timeDateTime<dateTime)
    {
        return false;
    }
    else
    {
        return true;
    }
}

QString SqlMgr::money(QString name)
{
    QSqlQuery q(m_db);
    QString strSql = QString("select * from Book where 书名='%1' ").arg(name);

    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
        qDebug()<<q.lastError().text();

    }
    else
    {
        int iCols = q.record().count();
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i = 0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    auto ldata = vec[0];
    QString money = ldata[7];
    return money;
}
