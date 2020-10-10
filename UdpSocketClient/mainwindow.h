#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonDocument>
#include <QHostAddress>
#include <QByteArray>
#include <QUdpSocket>
#include <QDebug>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QUdpSocket *qus = nullptr;
    QByteArray msg;

protected slots:
    void onPressed();
};
#endif // MAINWINDOW_H
