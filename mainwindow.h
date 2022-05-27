#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_add_clicked();

    void on_remove_clicked();

    void on_allremove_clicked();

    void on_update_clicked();

    void on_connect_clicked();

    void Read_Data();
    void serialWrite(QByteArray message);



    void on_disconnect_clicked();





private:
    void serialRead();
    void serialReadyRead();
    uint16_t CRC(QByteArray buf, int len);
    Ui::MainWindow *ui;
    QByteArray serialBuffer;


};
#endif // MAINWINDOW_H
