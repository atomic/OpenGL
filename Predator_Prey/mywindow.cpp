#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) :
    QWidget(parent)
{
    exitButton = new QPushButton("exit");
    runButton = new QPushButton("Run");
    stopButton = new QPushButton("Stop");
    colorButton = new QPushButton("Color");
    addButton = new QPushButton("Summon");
    polygonCount = new QLabel("0");
    radiusSlider = new QSlider(Qt::Horizontal);
    checkRotate = new QCheckBox("Rotate");
    checkTranslate = new QCheckBox("Translate");

    canvas = new glWidget;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(runButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(colorButton);
    buttonLayout->addWidget(radiusSlider);
    buttonLayout->addWidget(polygonCount);
    buttonLayout->addWidget(checkRotate);
    buttonLayout->addWidget(checkTranslate);


    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(canvas);
    overall->addLayout(buttonLayout);

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(runButton, SIGNAL(clicked()),
            canvas, SLOT(Run()));
    connect(stopButton, SIGNAL(clicked()),
            canvas, SLOT(Stop()));

    connect(this, SIGNAL(actionSignal()),
            this, SLOT(Action()));
    setLayout(overall);

    //CONNECT is placed here


    canvas->setMinimumSize(640, 480);
}
