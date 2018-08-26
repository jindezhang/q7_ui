#include "checkdelagate.h"


static QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options)
{
    QStyleOptionButton check_box_style_option;
    QRect check_box_rect = QApplication::style()->subElementRect(
        QStyle::SE_CheckBoxIndicator,
        &check_box_style_option);

    QPoint check_box_point(view_item_style_options.rect.x() +
                           view_item_style_options.rect.width() / 2 -
                           check_box_rect.width() / 2,
                           view_item_style_options.rect.y() +
                           view_item_style_options.rect.height() / 2 -
                           check_box_rect.height() / 2);
    return QRect(check_box_point, check_box_rect.size());
}


checkDelagate::checkDelagate(QTableView *tableView)
{
    int gridHint = tableView->style()->styleHint(QStyle::SH_Table_GridLineColor, new QStyleOptionViewItemV4());
        QColor gridColor = static_cast<QRgb>(gridHint);
        pen = QPen(gridColor,0,tableView->gridStyle());
        view = tableView;
}

void checkDelagate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    bool checked = index.model()->data(index, Qt::DisplayRole).toBool();

        if(index.column() == 0)
        {
            QStyleOptionButton check_box_style_option;
            check_box_style_option.state |= QStyle::State_Enabled;
            if(checked)
            {
                check_box_style_option.state |= QStyle::State_On;
            }
            else
            {
                check_box_style_option.state |= QStyle::State_Off;
            }
            check_box_style_option.rect = CheckBoxRect(option);
            QApplication::style()->drawControl(QStyle::CE_CheckBox,&check_box_style_option,painter);
        }

        QStyledItemDelegate::paint(painter,option,index);
        QStyleOptionViewItem itemOption(option);
        if(itemOption.state & QStyle::State_HasFocus)
            itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
        QStyledItemDelegate::paint(painter,itemOption,index);
        QPen oldPen = painter->pen();
        painter->setPen(pen);
        painter->drawLine(option.rect.topRight(),option.rect.bottomRight());
        painter->drawLine(itemOption.rect.bottomLeft(),itemOption.rect.bottomRight());
        painter->setPen(oldPen);

}

bool checkDelagate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if((event->type() == QEvent::MouseButtonRelease) ||
            (event->type() == QEvent::MouseButtonDblClick))
        {
             QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
            if(mouse_event->button() != Qt::LeftButton ||
               !CheckBoxRect(option).contains(mouse_event->pos()))
            {
                return false;
            }

            if(event->type() == QEvent::MouseButtonDblClick)
            {
                return true;
            }
        }
        else if(event->type() == QEvent::KeyPress)
        {
            if(static_cast<QKeyEvent*>(event)->key() != Qt::Key_Space &&
               static_cast<QKeyEvent*>(event)->key() != Qt::Key_Select)
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
        return model->setData(index, !checked, Qt::EditRole);
}
