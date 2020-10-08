#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , floor(new factoryfloor(this))
{
    ui->setupUi(this);
    //QLabel* label = new QLabel("testQT");
    ui->floorLayout->addWidget(floor);
    //ui->floorLayout->addWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    floor->startSim();
}


