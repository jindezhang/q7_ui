#ifndef WIGET_LABEL_H
#define WIGET_LABEL_H

#include <QWidget>

namespace Ui {
class wiget_label;
}

class wiget_label : public QWidget
{
    Q_OBJECT

public:
    explicit wiget_label(QWidget *parent = 0);
    ~wiget_label();

private:
    Ui::wiget_label *ui;
};

#endif // WIGET_LABEL_H
