#include "mywindow.h"

MyWindow::MyWindow()
{
    exitButton = new QPushButton("exit");
    nextButton = new QPushButton("Next");
    runButton = new QPushButton("Run");
    stopButton = new QPushButton("Stop");
    ptSizeSlider = new QSlider(Qt::Horizontal);
    ptSizeSlider->setMinimum(100);
    ptSizeSlider->setMaximum(300);
    canvas = new glWidget;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(nextButton);
    buttonLayout->addWidget(runButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(ptSizeSlider);


    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(canvas);
    overall->addLayout(buttonLayout);

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(nextButton, SIGNAL(clicked()),
            canvas, SLOT(next()));
    connect(runButton, SIGNAL(clicked()),
            canvas, SLOT(Run()));
    connect(stopButton, SIGNAL(clicked()),
            canvas, SLOT(Stop()));
    connect(ptSizeSlider, SIGNAL(valueChanged(int)),
            canvas, SLOT(setPtSize(int)));

//    connect(this, SIGNAL(actionSignal()),
//            this, SLOT(Action()));
    setLayout(overall);

    //CONNECT is placed here


    canvas->setMinimumSize(480, 480);
}
