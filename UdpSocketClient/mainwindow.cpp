#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onPressed()));
//    ui->pushButton
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow ::onPressed()
{
    QJsonObject object;
    QString string;
    qus = new QUdpSocket();
    string = (QString)ui->lineEdit_Type->text();
    qDebug()<<"lineEdit_type->text():"<<string;
    object.insert("type",string);

    string =  (QString)ui->lineEdit_Ticket->text();
    qDebug()<<"lineEdit_ticket->text():"<<string;
    object.insert("ticket",string);

    QJsonDocument rectJsonDoc;
    rectJsonDoc.setObject(object);
    msg = rectJsonDoc.toJson(QJsonDocument::Compact);
    qDebug()<<"==============socketSend:"<<msg.data();
    qus->writeDatagram(msg.data(), QHostAddress::LocalHost, 12342);
    update();
}
