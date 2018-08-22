#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QObject>
#include <QWidget>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>


class myDialog : public QDialog
{
    Q_OBJECT
public:
    explicit myDialog(QWidget *parent = nullptr);

signals:

public slots:
    void ok(bool);

private:
    QLabel *lbl;
    QLineEdit *edit;
    QPushButton *btn_ok;
    QPushButton *btn_cance;
};

#endif // MYDIALOG_H
