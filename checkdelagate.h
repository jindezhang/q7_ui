#ifndef CHECKDELAGATE_H
#define CHECKDELAGATE_H

#include <QCheckBox>
#include<QAbstractItemDelegate>
#include<QTableView>
#include<QPen>
#include<QMouseEvent>
#include<QEvent>
#include <QKeyEvent>
#include<QStyledItemDelegate>
#include<QStyleOptionButton>
#include<QRect>
#include <QApplication>
#include<QPainter>

class checkDelagate:public QStyledItemDelegate
{
    Q_OBJECT
public:
    checkDelagate(QTableView * tableView);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    QPen pen;
    QTableView* view;
};

#endif // CHECKDELAGATE_H
