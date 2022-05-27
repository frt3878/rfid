#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
 QList<QSerialPortInfo> list;
 QSerialPort *serial1 = new QSerialPort;
 bool serialDeviceIsConnected = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(serial1, &QSerialPort::readyRead,
            this, &MainWindow::serialReadyRead);



}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_update_clicked()
{
    list = QSerialPortInfo::availablePorts();
    ui->comPortBox->clear();
    if(list.length() >= 1){
        foreach (const QSerialPortInfo &Port, QSerialPortInfo::availablePorts() )
        {
            ui->comPortBox->addItem(Port.portName());
            qDebug("Foreach");

        }
    }
    else{
        qDebug("PORT YOK");
        ui->comPortBox->setDisabled(1);
        ui->comPortBox->addItem("PORT YOK");
    }


    qDebug("çalışıyor");


}


int i = 0;
void MainWindow::Read_Data()
{

    QByteArray buf;

    i=i+1;
    qDebug("%d",i);
    serial1->write("%h",0x55);


}



void MainWindow::on_add_clicked()
{

}


void MainWindow::on_remove_clicked()
{

}


void MainWindow::on_allremove_clicked()
{

}





void MainWindow::on_connect_clicked()
{
    QString port_name;
    port_name = ui->comPortBox->currentText();

    //Set serial port name
    serial1->setPortName(port_name);
    if (serial1->open(QIODevice:: ReadWrite))
    {
        qDebug("TRUE") ;
        serialDeviceIsConnected = true;
        serial1->setBaudRate(QSerialPort::Baud115200);
        serial1->setDataBits(QSerialPort::Data8);
        serial1->setParity(QSerialPort::NoParity);
        serial1->setStopBits(QSerialPort::OneStop);
        serial1->setFlowControl(QSerialPort::NoFlowControl);
        ui->label->setText("Connection Succes!");

    }

    else
    {
        qDebug("FALSE") ;
        ui->label->setText("Connection Failed!");
    }

}




void MainWindow::on_disconnect_clicked()
{

    if(serialDeviceIsConnected == true)
        {
            serial1->close();
            serialDeviceIsConnected = false;
            ui->label->setText("Disconnected");

        }
        else
        {
           qDebug ("Can't disconnect, no device is connected") ;
           ui->label->setText("No device is connected");
        }

}

void MainWindow::serialWrite(QString message)
{
    QByteArray bytes1 = QByteArray::fromHex(message.toLocal8Bit());
    qDebug()<<bytes1;
    if(serialDeviceIsConnected == true)
    {
        serial1->write(bytes1); // Send the message to the device

    }
}


void MainWindow::serialRead()
{
    serial1->readyRead();


    if(serialDeviceIsConnected == true)
    {
        serialBuffer += serial1->readAll(); // Read the available data
        qDebug()<<"Gelen data : "<<serialBuffer;
    }
}
int sayac = 0;
void MainWindow::serialReadyRead()
{
    sayac=sayac + 1;
    qDebug()<<"Ready.r"<<sayac;
    serialRead();
}

void MainWindow::on_send_clicked()
{
    QString RFID =ui->rfiddata->toPlainText();
    serialWrite(RFID);
    qDebug()<<RFID;
}

