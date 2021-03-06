#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include "SrvThread.h"
#include<QPixmap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //3

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void compareData(QByteArray data);
signals:

private:
    Ui::MainWindow *ui;
    Server* server;
    int ax;
};



#endif // MAINWINDOW_H
