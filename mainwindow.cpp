#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pInsertCard = new Insertcard(this);
    tila = ShowCard;
    showInsertCard();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pInsertcard;
    pInsertCard = nullptr;
}

void MainWindow::showInsertCard()
{
    this->hide();
    pInsertCard->show();
    readCard();
    pInsertCard->exec();
}

void MainWindow::showMainWindow()
{
    pInsertCard->hide();
    this->show();
}

void MainWindow::readCard()
{
    pSerialPort = new RFIDLL(this);
    connect(pSerialPort,SIGNAL(RFIDCardDetected()),
            this,SLOT(handleSerialPortData()));
}

void MainWindow::handleStateMachine()
{
    switch(tila)
    {
    case ShowCard;
    break;

    case MainUi;
    break;

    default;
    ;
    }
}

void MainWindow::handleSerialPortData()
{
    card = pSerialPort->getRFIDCardNumber();
    disconnect(pSerialPort,SIGNAL(RFIDCardDetected()),
    this,SLOT(handleSerialPortData()));
    delete pSerialPort;
    pSerialPort = nullptr;
    tila = MainUi;
    pInsertCard->close();
    showMainWindow();
    }

    void MainWindow::on_pushButton_clicked()
