#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include "client.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Server_clicked();

    void on_client_clicked();

    void dataReceived(QVariant data);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Server *myServer = NULL;
    Client *myClient = NULL;
};

#endif // MAINWINDOW_H
