#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    ilkkonum=event->pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    sonkonum=event->pos();
    cizkor.setPoints(ilkkonum,sonkonum);
    cizgiler.push_back(cizkor);
    update();
    ilkkonum=sonkonum;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter cizici(this);
    QPen kalem(Qt::black,3,Qt::SolidLine);
    cizici.setPen(kalem);
    cizici.drawLines(cizgiler);

}

