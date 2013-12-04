#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    widget = new MyPanelOpenGL;

    ui->setupUi(this);
    setWindowTitle(tr("Game Of Life"));

    menuBar = new QMenuBar;


    loadMenu = new QMenu("Load");

    loadPulsar = loadMenu->addAction(tr("Pulsar"));

    menuBar -> addMenu(loadMenu);

    this->setMenuBar(menuBar);

    connect(loadPulsar,SIGNAL(triggered()),widget,SLOT(loadPulsarText()));




}

MainWindow::~MainWindow()
{
    delete ui;
}
