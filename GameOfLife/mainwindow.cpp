#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Game Of Life"));
    ui->comboBox->addItem("Glider");
    ui->comboBox->addItem("Pentomino");
    ui->comboBox->addItem("Pulsar");
    ui->comboBox->addItem("Exploder");
    ui->comboBox->addItem("Ten");
    ui->comboBox->addItem("Spaceship");
    ui->comboBox->addItem("Glidergun");
}

MainWindow::~MainWindow()
{
    delete ui;
}
