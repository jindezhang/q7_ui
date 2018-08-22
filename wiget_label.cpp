#include "wiget_label.h"
#include "ui_wiget_label.h"

wiget_label::wiget_label(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wiget_label)
{
    ui->setupUi(this);
}

wiget_label::~wiget_label()
{
    delete ui;
}
