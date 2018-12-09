#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("HackMe");
    ui->scoreLabel->setText(QString::number(score));

    timer = new QTimer();
    timer->start(5000);

    connect(timer, &QTimer::timeout, this, &MainWindow::increase);
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::increase()
{
    score += 100;
    ui->scoreLabel->setText(QString::number(score));
}
