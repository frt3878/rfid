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
    connect(serial1, &QSerialPort::readyRead, this, &MainWindow::serialReadyRead);



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
    QString addtag ="0201";
    QByteArray bytes1 = QByteArray::fromHex(addtag.toLocal8Bit());
    QString RFID =ui->rfiddata->toPlainText();
    bytes1.append(QByteArray::fromHex(RFID.toLocal8Bit()));
    uint16_t test;
    test = CRC(bytes1,6);
    uint8_t first[2];
    first[0]= (0xFF)&(test>>8);
    first[1]=(0xFF)&test;
    bytes1.append(QByteArray::fromRawData((const char *)first,2));
    qDebug()<<"giden data  = "<<bytes1;
    serialWrite(bytes1);
    qDebug()<<RFID;
}


void MainWindow::on_remove_clicked()
{
    QString addtag ="0202";
    QByteArray bytes1 = QByteArray::fromHex(addtag.toLocal8Bit());
    QString RFID =ui->rfiddata->toPlainText();
    bytes1.append(QByteArray::fromHex(RFID.toLocal8Bit()));
    uint16_t test;
    test = CRC(bytes1,6);
    uint8_t first[2];
    first[0]= (0xFF)&(test>>8);
    first[1]=(0xFF)&test;
    bytes1.append(QByteArray::fromRawData((const char *)first,2));
    qDebug()<<"giden data  = "<<bytes1;
    serialWrite(bytes1);
    qDebug()<<RFID;
}


void MainWindow::on_allremove_clicked()
{
    QString addtag ="0203464b7f41";
    QByteArray bytes1 = QByteArray::fromHex(addtag.toLocal8Bit());
    uint16_t test;
    test = CRC(bytes1,6);
    uint8_t first[2];
    first[0]= (0xFF)&(test>>8);
    first[1]=(0xFF)&test;
    bytes1.append(QByteArray::fromRawData((const char *)first,2));
    qDebug()<<"giden data  = "<<bytes1;
    serialWrite(bytes1);

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

void MainWindow::serialWrite(QByteArray message)
{

    if(serialDeviceIsConnected == true)
    {
        serial1->write(message); // Send the message to the device

    }
}



void MainWindow::serialRead()
{



    if(serialDeviceIsConnected == true)
    {
        serialBuffer.append(serial1->readAll());
        qDebug()<<"Gelen data orjinal: "<<serialBuffer.toHex();




    }
    if( serialBuffer.length() == 4 ){
       if(serialBuffer.at(0) == 0x01)
       {
       qDebug("Function add ");
       if(serialBuffer.at(1) == 0x01){
       qDebug("add rfid succes ");
       ui->label->setText("SUCCESS");
       }
       else{
           qDebug("add rfid false ");
           ui->label->setText("FAİL");
           ui->label->setStyleSheet("color: rgb(239, 41, 41);");
       }

       }
       if(serialBuffer.at(0) == 0x02)
       {
       qDebug("Function remove ");
       if(serialBuffer.at(1) == 0x01){
       qDebug("remove rfid succes ");
       ui->label->setText("SUCCESS");
       }
       else{
           qDebug("remove rfid false ");
           ui->label->setText("FAİL");
           ui->label->setStyleSheet("color: rgb(239, 41, 41);");
       }

       }
       if(serialBuffer.at(0) == 0x03)
       {
       qDebug("Function delete all ");
       if(serialBuffer.at(1) == 0x01){
       qDebug("delete all rfid succes ");
       ui->label->setText("SUCCESS");
       }
       else{
           qDebug("delete all rfid false ");
           ui->label->setText("FAİL");
           ui->label->setStyleSheet("color: rgb(239, 41, 41);");
       }

       }

        serialBuffer.clear();

    }


}

void MainWindow::serialReadyRead()
{


    serialRead();
}



uint16_t MainWindow::CRC(QByteArray buf, int len)
{

  unsigned int temp, temp2, flag;
  unsigned char i,j;

  temp = 0xFFFF;
  for (i = 0; i < len; i++)
  {

    temp = temp ^uchar(buf[i]) ;
    for (j = 1; j <= 8; j++)
    {
      flag = temp & 0x0001;
      temp >>= 1;
      if (flag)
        temp ^= 0xA001;
    }
  }
  temp2 = temp >> 8;
  temp = (temp << 8) | temp2;
  temp &= 0xFFFF;
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
  return temp;
}
