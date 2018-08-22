#include "mydialog.h"

myDialog::myDialog(QWidget *parent)
{
    setWindowTitle("my dialog");
    edit = new QLineEdit("");
    lbl = new QLabel("Name");

    btn_ok = new QPushButton("OK");
    btn_cance = new QPushButton("Cance");

    connect(btn_ok,SIGNAL(clicked(bool)),this,SLOT(ok(bool)));

    QHBoxLayout *hb1 = new QHBoxLayout();
    hb1->addWidget(lbl);
    hb1->addWidget(edit);

    QHBoxLayout  *hb2 = new QHBoxLayout();
    hb2->addWidget(btn_ok);
    hb2->addWidget(btn_cance);


    QVBoxLayout *vb = new QVBoxLayout();
    vb->addLayout(hb1);
    vb->addLayout(hb2);

    setLayout(vb);

}

void myDialog::ok(bool)
{
    edit->setText("ok");

}
