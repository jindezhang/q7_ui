#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QEasingCurve>
#include <QPainter>
#include <Qt>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include "spinBoxdelegate.h"
#include"comboxdelegate.h"
#include"checkdelagate.h"
#include <QDebug>



//实现了下拉和spinbox的嵌入控件到tableview的功能，未实现checkbox嵌入的功能。
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();
protected:


private:
    Ui::MainWindow2 *ui;
    QSqlTableModel *tabel_model;
};

#endif // MAINWINDOW2_H
