#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->button1->setProperty("pagematches", true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QVariant vd = ui->button1->property("pagematches");

    // Set all buttons to false
    ui->button1->setProperty("pagematches", false);
    ui->button2->setProperty("pagematches", false);
    ui->button3->setProperty("pagematches", false);

    // set one of the buttons to true
    if(index == 0)
        ui->button1->setProperty("pagematches", true);
    else if(index == 1)
        ui->button2->setProperty("pagematches", true);
    else
        ui->button3->setProperty("pagematches", true);

    // Update buttons style
    ui->button1->style()->polish(ui->button1);
    ui->button2->style()->polish(ui->button2);
    ui->button3->style()->polish(ui->button3);
}
