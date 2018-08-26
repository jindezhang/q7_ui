#ifndef QPUSHBUTTONDELEGATE_H
#define QPUSHBUTTONDELEGATE_H

#include <QItemDelegate>
#include <QSpinBox>

class spinBoxdelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit spinBoxdelegate(QObject *parent = nullptr);
    /*创建控件*/

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    /*设置控件数据*/
    void setEditorData(QWidget *editor,  const  QModelIndex &index)  const;
    /*更新模型上的数据*/
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    /*控件位置更新*/
    void updateEditorGeometry(QWidget *editor, const  QStyleOptionViewItem &option,  const  QModelIndex &index) const ;

signals:

public slots:
};

#endif // QPUSHBUTTONDELEGATE_H
