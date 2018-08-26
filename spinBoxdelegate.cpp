#include "spinBoxdelegate.h"


spinBoxdelegate::spinBoxdelegate(QObject *parent)
{

}

QWidget *spinBoxdelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);//b必须添加parent，不然会导致控件不再窗体内

//         editor->setMinimum(0);

//         editor->setMaximum(100);

         return editor;
}

void spinBoxdelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::DisplayRole).toInt();

         QSpinBox *spinBox = static_cast<QSpinBox*>(editor);

         spinBox->setValue(value);
}

void spinBoxdelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);

         spinBox->interpretText();

         int value = spinBox->value();

         model->setData(index, value);

}

void spinBoxdelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
