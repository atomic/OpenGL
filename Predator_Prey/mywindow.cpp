#include "mywindow.h"

MyWindow::MyWindow()
{
    exitButton = new QPushButton("exit");
    nextButton = new QPushButton("Next");
    runButton = new QPushButton("Run");
    stopButton = new QPushButton("Stop");
    ptSize = new QLabel("Pt.");
    ptSizeSlider = new QSlider(Qt::Horizontal);

    ptSizeSlider->setMinimum(250);
    ptSizeSlider->setMaximum(500);
    ptSizeSlider->setValue(400);
    canvas = new glWidget;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(nextButton);
    buttonLayout->addWidget(runButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(ptSizeSlider);
    buttonLayout->addWidget(ptSize);


    QVBoxLayout* overall = new QVBoxLayout;
    overall->addWidget(canvas);
    overall->addLayout(buttonLayout);

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));
    connect(nextButton, SIGNAL(clicked()),
            canvas, SLOT(Next()));
    connect(runButton, SIGNAL(clicked()),
            canvas, SLOT(Run()));
    connect(stopButton, SIGNAL(clicked()),
            canvas, SLOT(Stop()));
    connect(ptSizeSlider, SIGNAL(valueChanged(int)),
            canvas, SLOT(setPtSize(int)));
    connect(ptSizeSlider, SIGNAL(valueChanged(int)),
            this, SLOT(updateptSizeText(int)));

    setLayout(overall);
    canvas->setMinimumSize(640,640);
}
