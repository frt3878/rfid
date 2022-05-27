#include "mainwindow.h"
#include<QFile>
#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("QTDark.stylesheet");
     file.open(QFile::ReadOnly);
     QString styleSheet = QLatin1String(file.readAll());

     qApp->setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}
