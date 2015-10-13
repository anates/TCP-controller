#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Debug
    ui->ip->setText("127.0.0.1");
    ui->port->setText("50000");

}

MainWindow::~MainWindow()
{
/*    if(myServer != NULL)
        myServer->close();
    else
        myClient->disconnectFromServer();
  */  delete ui;
}

void MainWindow::on_Server_clicked()
{
    ui->label_3->setText("Server selected");
    ui->client->setDisabled(true);
    qDebug() << "Server selected!";
    if(!ui->ip->text().isEmpty() && !ui->port->text().isEmpty())
        myServer = new Server(ui->ip->text(), ui->port->text().toInt());
    ui->Server->setDisabled(true);
}

void MainWindow::on_client_clicked()
{
    ui->label_3->setText("Client selected");
    ui->Server->setDisabled(true);
    if(!ui->ip->text().isEmpty() && !ui->port->text().isEmpty())
        myClient = new Client();
    else
        return;
    myClient->connectToServer(ui->ip->text(), ui->port->text().toInt());
    connect(myClient, SIGNAL(gotData(QVariant)), this, SLOT(dataReceived(QVariant)));
    ui->client->setDisabled(true);

}

void MainWindow::dataReceived(QVariant data)
{
    //data.replace('\0', "");  // get rid of 0 characters
    //dbg.replace('"', "\\\"");  // more special characters as you like

    //QString data_string(data);
    ui->lineEdit->setText(data.toString());
}

void MainWindow::on_pushButton_2_clicked()
{
    QVariant data = "Hello World";
//    if(myServer != NULL)
//        myServer->sendData(data);
//    else
        ui->lineEdit_6->setText("Not a server");
}
