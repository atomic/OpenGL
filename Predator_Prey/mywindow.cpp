#include "mywindow.h"

MyWindow::MyWindow()
{
    exitButton = new QPushButton("exit");
    runButton = new QPushButton("Run");
    stopButton = new QPushButton("Stop");

    canvas = new glWidget;

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(runButton);
    buttonLayout->addWidget(stopButton);


    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(canvas);
    overall->addLayout(buttonLayout);

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(runButton, SIGNAL(clicked()),
            canvas, SLOT(Run()));
    connect(stopButton, SIGNAL(clicked()),
            canvas, SLOT(Stop()));

//    connect(this, SIGNAL(actionSignal()),
//            this, SLOT(Action()));
    setLayout(overall);

    //CONNECT is placed here


    canvas->setMinimumSize(640, 480);
}
