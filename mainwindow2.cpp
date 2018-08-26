#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("test.db");
//        database.setUserName("XingYeZhiXia");
//        database.setPassword("123456");
    }

    //MVC------------------------>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //tableview
        tabel_model = new QSqlTableModel();
          tabel_model->setTable("student");
          tabel_model->setEditStrategy(QSqlTableModel::OnManualSubmit);


          tabel_model->select();
//          tabel_model->setHeaderData(3, Qt::Horizontal, "姓");
//          tabel_model->setHeaderData(2, Qt::Horizontal, "名");
//          tabel_model->setHeaderData(3, Qt::Horizontal, "入职时间");
        tabel_model->insertColumn(3);//插入失败时候。必须在select() 之后才会插入。
        tabel_model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("删除"));
        ui->tableView->setModel(tabel_model);
//        ui->tableView->hideColumn(0);
//        connect(ui->tableView,SIGNAL(tri))

        //connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(tv_changValue(QModelIndex)));//获取选中值。
//        ui->tableView->setEnabled(false);
//        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
        //在tableview上添加控件/Delegate类
//        QPushButton *btn = new QPushButton("click");
        spinBoxdelegate *delegate = new spinBoxdelegate();
        comBoxdelegate *delegate_cb = new comBoxdelegate();
        checkDelagate *delegate_ccb = new checkDelagate(ui->tableView);

//        ui->t
        ui->tableView->setItemDelegate(delegate);
        ui->tableView->setItemDelegateForColumn(2,delegate_ccb);
        ui->tableView->setItemDelegateForColumn(1   ,delegate_cb);


}

MainWindow2::~MainWindow2()
{
    delete ui;

    //qe_line = new QEasingCurve((QEasingCurve::Type) 0);


}

