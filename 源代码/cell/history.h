#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class History;
}

class History : public QWidget
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

    void initPage(QString strCondition);

private:
    Ui::History *ui;
    QStandardItemModel m_model;
};

#endif // HISTORY_H
