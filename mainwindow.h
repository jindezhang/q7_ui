#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "comboxdelegate.h"

#include <QMainWindow>
#include<QMouseEvent>
#include "mylineedit.h"
#include <QStandardItem>
#include"mydialog.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QDebug>
#include<QSqlTableModel>
#include<QTableWidgetItem>
#include<QTreeWidgetItem>
#include<QPushButton>
#include<QItemDelegate>
#include<spinBoxdelegate.h>

#pragma execution_character_set("utf-8")

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //鼠标点击事件
    void mousePressEvent(QMouseEvent* event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);

private slots:
    void chang_value(int v);
    void chang_font(QFont qf);
    void trigerMenuBar(QAction * act);
    void toolbar_tri(bool b, int i = 20);
    void tw_changeValue(QTableWidgetItem *curr );
    void tw_changeValue1(QTableWidgetItem* curr,QTableWidgetItem* prv);
    void tv_changValue(QModelIndex index);

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *tabel_model;
};

#endif // MAINWINDOW_H
