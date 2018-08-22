#include "myLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{

}

MyLineEdit::~MyLineEdit()
{

}

void MyLineEdit::focusInEvent(QFocusEvent *e)
{
       QPalette p=QPalette();
       p.setColor(QPalette::Base,Qt::green);    //QPalette::Base 对可编辑输入框有效，还有其他类型，具体的查看文档
       setPalette(p);
}

void MyLineEdit::focusOutEvent(QFocusEvent *e)
{
       QPalette p1=QPalette();
       p1.setColor(QPalette::Base,Qt::white);
       setPalette(p1);
}
