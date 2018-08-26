#include "comboxdelegate.h"

comBoxdelegate::comBoxdelegate()
{

}

QWidget *comBoxdelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *cb = new QComboBox(parent);//

    return cb;
}

void comBoxdelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
        QStringList value = index.model()->data(index,Qt::DisplayRole).toStringList();
        QComboBox *cb = static_cast<QComboBox *>(editor);
        cb->addItems(value);
}

void comBoxdelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}

void comBoxdelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
