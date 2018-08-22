#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QFont>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_2_clicked()));
    timer->start(1000);
//    ui->dateEdit->setEnabled(false);
    QFont font( "Microsoft YaHei", 10, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）

    ui->dateEdit->setFont(QFont( "Microsoft YaHei", 10, 75));
    ui->dateEdit->setDate(QDate::currentDate());

    setWindowTitle("myQt program");//修改程序名


    ui->dial->setNotchesVisible(true);
    connect(ui->dial,SIGNAL(valueChanged(int)),this, SLOT(chang_value(int)));

    //DoubleSpinBox
    ui->doubleSpinBox->setPrefix("$ ");
    ui->doubleSpinBox->setSuffix(" dollar");
    ui->doubleSpinBox->setFont(QFont("Microsoft YaHei",10,25));
    ui->doubleSpinBox->setMaximum(50.00);

    //QFontcomboBox
    ui->fontComboBox->setFontFilters(QFontComboBox::AllFonts);//显示所有字体
    connect(ui->fontComboBox,SIGNAL(currentFontChanged(QFont)), this,SLOT(chang_font(QFont)));

    //label
//    QPixmap pix = QPixmap(QImage().load("pirate.png"));
//    QImage img;


//    //QString::fromLocal8Bit()解决中文乱码；
//    if(! ( img.load("D:/qt_test/build-q7_ui-Desktop_Qt_5_9_1_MSVC2015_64bit-Debug/debug/pirate.png") ) ) //加载图像
//    {
//        QMessageBox::information(this,QString::fromLocal8Bit("失败！"),"eorro");


//    }

//    按比例缩放：
//    QPixmap scaledPixmap = pixmap.scaled(picSize, Qt::KeepAspectRatio);

    QPixmap pix = QPixmap("C:/Users/rd330.ZY-IVD/Pictures/pirate.png");
    QSize picSize(100,100);
    ui->label_3->setSizeIncrement(picSize);
    ui->label_3->setPixmap(pix.scaled(picSize,Qt::KeepAspectRatio));


    //QMenu QMenuBar
    connect(ui->menuBar,SIGNAL(triggered(QAction*)),this, SLOT(trigerMenuBar(QAction *)));

    //QProgressBar
    ui->progressBar->setValue( 0);

    //----------------------------------------------------------------------------------------------------------------------
    //QToolBar
    QList<QAction *> qap;
    for(int i = 0; i< 4;i++){
        qap<<new QAction(QIcon("C:/Users/rd330.ZY-IVD/Pictures/pirate.png"), "pirate",this);
        connect(qap[i],SIGNAL(triggered(bool)),this,SLOT(toolbar_tri(bool)));
    }
    ui->mainToolBar->addActions(qap);

    //----------------------------------------------------------------------------------------------------------------------
    //mouse Event
    //ui->l_mouse->mouseMoveEvent();

    //----------------------------------------------------------------------------------------------------------------------
    //diy linedit
    QLineEdit *line = new MyLineEdit(this);
    line->setGeometry(50,50,200,40);

    //----------------------------------------------------------------------------------------------------------------------
    //column view
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *name = new QStandardItem("name");
    QStandardItem *firstname = new QStandardItem("firstname");
    QStandardItem *lastname = new QStandardItem("lastname");

    name->appendRow(firstname);
    name->appendRow(lastname);
    model->appendRow(name);

    QStandardItem *name1 = new QStandardItem("name1");
    QStandardItem *firstname1 = new QStandardItem("firstname1");
    QStandardItem *lastname1 = new QStandardItem("lastname1");

    name1->appendRow(firstname1);
    name1->appendRow(lastname1);
    model->appendRow(name1);

    ui->columnView->setModel(model);


    //----------------------------------------------------------------------------------------------------------------------
    //sqlite3
    //eorro：找不到table，因为创建的数据库是在程序的运行目录下，所以需要去程序的运行目录下才能找到该数据库和创建表格。

    /*
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

    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        // do something
        QString select_sql = "select distinct name,age from student ";
        QSqlQuery sql_query;

        if(!sql_query.exec(select_sql))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"$$";
            while(sql_query.next())
            {
                qDebug()<<"**";
                QString name = sql_query.value(0).toString();
                QString age = sql_query.value(1).toString();
                qDebug()<<QString("id:%1    name:%2").arg(age).arg(name);
                line->setText(QString("id:%1    name:%2").arg(age).arg(name));
            }
        }
    }


    database.close();


*/
    //----------------------------------------------------------------------------------------------------------------------
    //mysql
    //eorro：
    //[1] QSqlDatabase: QMYSQL driver not loaded
    //    QSqlDatabase: available drivers: QSQLITE QMYSQL QMYSQL3 QODBC QODBC3 QPSQL QPSQL7

    //[2] QSqlError("1045", "QMYSQL: Unable to connect", "Access denied for user 'root'@'localhost' (using password: YES)")


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");   						//127.0.0.1也是一样的,属于本地地址
        db.setUserName("root");       							//登陆MYSQL的用户名
        db.setPassword("zhang#330");    							//你自己登陆的密码
        db.setDatabaseName("sakila");  						//登陆数据库的名称
        if(!db.open()){                     								//打开数据库连接
            qDebug()<<"open mysql failed!"<<db.lastError();
        }

        QString select_sql = "select distinct first_name,last_name from actor where first_name = 'ED' ";
        QSqlQuery sql_query;

        if(!sql_query.exec(select_sql))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            //qDebug()<<"$$";
            while(sql_query.next())
            {
                qDebug()<<"**";
                QString first_name = sql_query.value(0).toString();
                QString last_name = sql_query.value(1).toString();
                qDebug()<<QString("first_name:%1    last_name:%2").arg(first_name).arg(last_name);
//                line->setText(QString("id:%1    name:%2").arg(age).arg(name));
            }
        }

    //MVC------------------------>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //tableview
        QSqlTableModel *tabel_model = new QSqlTableModel();
          tabel_model->setTable("actor");
          tabel_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

          tabel_model->select();
          tabel_model->setHeaderData(1, Qt::Horizontal, "姓");
          tabel_model->setHeaderData(2, Qt::Horizontal, "名");
          tabel_model->setHeaderData(3, Qt::Horizontal, "入职时间");
        ui->tableView->setModel(tabel_model);
        ui->tableView->hideColumn(0);
//        connect(ui->tableView,SIGNAL(tri))

        //tablewidget
        QSqlQuery query;
        int i = 0, j = 0, nColumn, nRow;
        query.prepare("select * from actor");
        query.exec();
        query.last();//为了计算出数据项
        nRow = query.at() + 1;
        ui->tableWidget->setRowCount(nRow);
        ui->tableWidget->setColumnCount(4);
        nColumn = ui->tableWidget->columnCount();
//        nColumn = 4;
        //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
        ui->tableWidget->hideColumn(0);


        //设置bi'abiao'ta表头
        QStringList tw_list;
        tw_list<<"0"<<"first name"<<"last name"<<"time";
        ui->tableWidget->setHorizontalHeaderLabels(tw_list);
        query.first();



        while(j<nRow)
        {
        for (i = 0; i<nColumn; i++){
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(query.value(i).toString()));

        }

        j++;
        query.next();
        }
        //行列自适应,★★★先装载数据，再自适应。
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
        //充满窗体
        //表列随着表格变化而自适应变化
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //表行随着表格变化而自适应变化
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        //当值发生变化时候
        //错误：connect(ui->tableWidget,SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)),this,SLOT(tw_changeValue(QTableWidgetItem*,QTableWidgetItem*)));
//        connect(ui->tableWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(getItem(QTreeWidgetItem*,int)));
        //获取点击时候的值
        connect(ui->tableWidget,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(tw_changeValue(QTableWidgetItem*)));
        connect(ui->tableWidget,SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)),this,SLOT(tw_changeValue1(QTableWidgetItem*,QTableWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    setMouseTracking(true);
    if(event->buttons()&Qt::LeftButton)
    {
        ui->l_mouse->setText(tr("pushLeftButtonAndMove!"));
    }else if(event->buttons()&Qt::RightButton)
    {
        ui->l_mouse->setText(tr("pushRightButtonAndMove!"));
    }else if(event->buttons()&Qt::MidButton)
    {
        ui->l_mouse->setText(tr("pushMidButtonAndMove!"));
    }



}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void MainWindow::leaveEvent(QEvent *event)
{
    //if(event->MouseMove&Qt::mou)

}

void MainWindow::chang_value(int v)
{
    ui->doubleSpinBox->setValue(v);
}

void MainWindow::chang_font(QFont qf)
{
    ui->label->setFont(qf);
}

void MainWindow::trigerMenuBar(QAction *act)
{
    ui->label->setText(act->text());
}

void MainWindow::toolbar_tri(bool b, int i)
{
    if(b)
        qDebug("hh");
    else
        qDebug("oo");
    ui->label->setText(QString("%1").arg(i));
}

void MainWindow::tw_changeValue(QTableWidgetItem *curr)
{

   // ui->label->setText(prev->text());
    ui->label_2->setText(curr->text());
}

void MainWindow::tw_changeValue1(QTableWidgetItem *curr, QTableWidgetItem *prv)
{
     ui->label->setText(prv->text());
     ui->label_3->setText(curr->text());
}

void MainWindow::on_pushButton_2_clicked()
{

    static int i = 0;
    ui->dateEdit->setTime(QTime::currentTime());

    //LCDNumber
    ui->lcdNumber->setFont(QFont("Microsoft YaHei",10,75));
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);//设置外观。
    ui->lcdNumber->setDigitCount(25);//设置显示位数。
    ui->lcdNumber->display(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz"));//时间转换成string类型。

    ui->dial->setValue(i%100);

    //QProgressBar
    ui->progressBar->setValue(i%100);

    //sider srcoll
    ui->horizontalScrollBar->setValue(i%100);
    ui->verticalSlider->setValue(i%100);
    i++;




}

void MainWindow::on_pushButton_6_clicked()
{
    myDialog *my = new myDialog();
    //my.exec();
    my->show();
}

void MainWindow::on_pushButton_8_clicked()
{

}
