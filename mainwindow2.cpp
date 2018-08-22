#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;

    //qe_line = new QEasingCurve((QEasingCurve::Type) 0);


}

void MainWindow2::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint;
   // paint.begin(ui->widget);

//    QPen
    //paint.setPen(Qt::blue);
//    paint.drawLine(10,10,100,40);
//    paint.drawRect(120,10,80,80);



//    paint.end();

}

void MainWindow2::on_pushButton_clicked()
{
    update();
}
