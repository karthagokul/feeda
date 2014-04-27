#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

using namespace Core;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mEngine=new FeedaEngine(this);
    mEngine->start();

    if(!mEngine->registerRssFeed(QString(RSS2SAMPLE_XML)))
    {
        qDebug()<<"Already Registered";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
