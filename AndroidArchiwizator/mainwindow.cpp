#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new Server();//skasowac stad przy przycisku: nasluchuje niech bedzie
    connect( server, SIGNAL( sendingToGUI(QByteArray)), this, SLOT(compareData(QByteArray) ) ) ;
    server->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    connect( server, SIGNAL( sendingToGUI(QByteArray)), this, SLOT(compareData(QByteArray) ) ) ;
    server->run();
}

void MainWindow::compareData(QByteArray data)
{

    ui->textEdit->setText(data);
}

