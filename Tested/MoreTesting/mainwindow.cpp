#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.ui"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(ui->pushButton, SIGNAL->pressed(),ui->lcdNumber,SLOT->setDecMode());
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
