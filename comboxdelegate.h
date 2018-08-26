#ifndef COMBOXDELEGATE_H
#define COMBOXDELEGATE_H

#include<QComboBox>
#include<QItemDelegate>

class comBoxdelegate : public QItemDelegate
{
public:
    comBoxdelegate();
    /*创建控件*/

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    /*设置控件数据*/
    void setEditorData(QWidget *editor,  const  QModelIndex &index)  const;
    /*更新模型上的数据*/
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    /*控件位置更新*/
    void updateEditorGeometry(QWidget *editor, const  QStyleOptionViewItem &option,  const  QModelIndex &index) const ;

};

#endif // COMBOXDELEGATE_H
