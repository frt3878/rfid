#include "mainwindow.h"
#include<QFile>
#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile file("/:Irrortater.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);

    w.show();
    return a.exec();
}
